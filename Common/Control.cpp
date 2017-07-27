#include "Control.h"



Control::Control()
{
}

Control * Control::getFocus()
{
	return NULL;
}

void Control::setFocus(Control & control)
{
}


void Control::draw(Graphics & g, int x, int y, size_t z)
{
}

void Control::mousePressed(int x, int y, bool isLeft)	//צריך לבדוק בתוך הפאנל איזה פקד נמצא בקאורדינטה ויעביר את הלחיצה לפקד שנמצא בנקודה הזו
{
}

void Control::keyDown(int keyCode, char charecter)
{
}

short Control::getLeft()
{
	return 0;
}

short Control::getTop()
{
	return 0;
}

void Control::getAllControls(vector<Control*>* controls)
{
}

bool Control::canGetFocus()
{
	return false;
}

Control::~Control()
{
}
