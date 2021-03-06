#pragma once
#include "Graphics.h"
#include <vector>

using namespace std;

class Control
{

protected:
	short left;
	short top;
	
public:
	Control();
	static Control* getFocus();
	static void setFocus(Control& control);
	
	

	void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char charecter);
	virtual short getLeft();
	virtual short getTop();
	virtual void getAllControls(vector<Control*>* controls);
	virtual bool canGetFocus();
	~Control();
};

