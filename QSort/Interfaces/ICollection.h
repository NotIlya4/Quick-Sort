#pragma once


template<class T>
class ICollection {
public:
	virtual int size() = 0;
	virtual T& at(int index) = 0;
	virtual void swapValues(int index1, int index2) = 0;
};