#pragma once
#include "IStack.h"


template<class T>
class IStackFactory {
public:
	virtual IStack<T>* createStack() = 0;
};