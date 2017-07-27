#pragma once
#include "Graphics.h"
#include "Control.h"
enum BorderType{};
class IComponent: public Control
{
	virtual void draw() = 0;
	virtual void setvisibility(bool visibility) = 0;
	virtual void setForeground(Color color) = 0;
	virtual void setBackgroundColor(Color color) = 0;
	virtual void setBorder(BorderType border) = 0;
public:
	IComponent();
	virtual ~IComponent();
};

