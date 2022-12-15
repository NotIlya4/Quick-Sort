#pragma once
#include <vector>
#include "../Interfaces/ICollection.h"


template<class T>
class VectorAdapter : public ICollection<T> {
	std::vector<T> vector;
public:
	VectorAdapter(std::initializer_list<T> list) {
		this->vector = list;
	}

	int size() override {
		return this->vector.size();
	}
	T& at(int index) override {
		return this->vector.at(index);
	}
	void swapValues(int index1, int index2) override {
		T temp = this->vector.at(index1);
		this->vector.at(index1) = this->vector.at(index2);
		this->vector.at(index2) = temp;
	}
	std::vector<T>& getRaw() {
		return this->vector;
	}
};