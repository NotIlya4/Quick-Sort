#pragma once


template<class T>
class IStack {
public:
	virtual T peek() = 0;
	virtual void pop() = 0;
	virtual void push(T newElement) = 0;
	virtual bool empty() = 0;
};