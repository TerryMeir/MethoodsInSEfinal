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

void Control::mousePressed(int x, int y, bool isLeft)	//���� ����� ���� ����� ���� ��� ���� ���������� ������ �� ������ ���� ����� ������ ���
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
