#include "ITextBox.h"



ITextBox::ITextBox()
{
}

void ITextBox::draw(Graphics & g, int x, int y, size_t z)
{
}

void ITextBox::mousePressed(int x, int y, bool isLeft)
{
}

void ITextBox::
keyDown(int keyCode, char charecter)
{
}

short ITextBox::getLeft()
{
	return 0;
}

short ITextBox::getTop()
{
	return 0;
}

void ITextBox::getAllControls(vector<Control*>* controls)
{
}

bool ITextBox::canGetFocus()
{
	return false;
}
