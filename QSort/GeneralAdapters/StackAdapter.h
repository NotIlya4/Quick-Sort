#pragma once
#include "../Interfaces/IStack.h"
#include "../Interfaces/IStackFactory.h"
#include <stack>


template<class T>
class StackAdapter : public IStack<T> {
	std::stack<T> stack;

public:
	T peek() {
		return this->stack.top();
	};
	void pop() {
		this->stack.pop();
	};
	void push(T newElement) {
		this->stack.push(newElement);
	};
	bool empty() {
		return this->stack.empty();
	};
};


template<class T>
class StackAdapterFactory : public IStackFactory<T>{
public:
	IStack<T>* createStack() {
		return new StackAdapter<T>;
	};
};