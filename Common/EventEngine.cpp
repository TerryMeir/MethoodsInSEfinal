#include "EventEngine.h"
#include <vector>

using namespace std;

EventEngine::EventEngine(DWORD input, DWORD output)	//מקבל שליטה על הקונסול
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run(Control &c)	//מעבירים מראש איזה פקד נלחץ-תוכנית הריצה והמעברים בין הפקדים
{
	for (bool redraw = true;;)
	{
		if (redraw)
		{
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);
			for (size_t p = 0; p < 5; ++p)
				c.draw(_graphics, 0, 0, p);
			redraw = false;
		}

		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType) //איזה אירוע התרחש?
		{
		case KEY_EVENT:	//לחיצה מהמקלדת
		{
			auto f = Control::getFocus();	//בודקים מי כרגע בפוקוס- מקבל רפרנס לפקד שנמצא בפוקוס וניתן להפעיל עליו מתודות
			if (f != nullptr && record.Event.KeyEvent.bKeyDown)		//בודקים שהפויינטר לא 0 ושהתרחש אירוע
			{
				auto code = record.Event.KeyEvent.wVirtualKeyCode;	//לוקחים את הלחיצה שהתרחשה
				auto chr = record.Event.KeyEvent.uChar.AsciiChar;	//במידה ולחצו על תו במקלדת לוקחים את האות האסקית שלו
				if (code == VK_TAB)	//אם לחצו על מקש טאב - מעבר לפקד הבא
					moveFocus(c, f);	//מזיזים את הפוקוס
				else
					f->keyDown(code, chr);	//הפקד עצמו מפעיל את המתודה שלו לפעולה של לחיצה על מקלדת- ממומש באופן שונה בין הפקדים- למשל בטקסט בוקס לחיצה על אות צריכה לשרשר רת האות לערך הנוכחי
				redraw = true;	//בתחילת הפונקצייה בודקים את הערך הזה במידה וצריך לעדכן את המסך יתבצע עדכון ויזואלי
			}
			break;
		}
		case MOUSE_EVENT:	//לחיצה מהעכבר
		{
			auto button = record.Event.MouseEvent.dwButtonState;
			auto coord = record.Event.MouseEvent.dwMousePosition;
			auto x = coord.X - c.getLeft();
			auto y = coord.Y - c.getTop();
			if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
			{
				c.mousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
				redraw = true;
			}
			break;
		}
		default:
			break;
		}
	}
}

EventEngine::~EventEngine()
{
	SetConsoleMode(_console, _consoleMode);
}

void EventEngine::moveFocus(Control &main, Control *focused)
{
	vector<Control*> controls;
	main.getAllControls(&controls);
	auto it = find(controls.begin(), controls.end(), focused);
	do
		if (++it == controls.end())
			it = controls.begin();
	while (!(*it)->canGetFocus());	//משתנה שאומר האם הפקד הבא בהיררכיה יכול בכלל לקבל פוקוס- למשל לייבל לא יכול לקבל פוקוס לכן לא יעביר לו את השליטה
	Control::setFocus(**it);
}