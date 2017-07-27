#pragma once
#include "../Common/IComponent.h"
#include <string>
class ITextBox :public IComponent
{
private:
	string value;
	int curser;
	int max_size;
public:
	ITextBox();
	virtual void draw(Graphics& g, int left, int top, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char charecter);
	virtual short getLeft();
	virtual short getTop();
	virtual void getAllControls(vector<Control*>* controls);
	virtual bool canGetFocus();
};

