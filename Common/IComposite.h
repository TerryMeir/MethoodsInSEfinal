#pragma once
#include "IComponent.h"
#include <vector>
class IComposite :
	public IComponent
{
	vector<IComponent> container;
public:
	IComposite();
	virtual ~IComposite();
	virtual void addComponent(IComponent*);
	virtual void removeComponent(IComponent*);
	virtual IComponent* getComponent(int);
};

