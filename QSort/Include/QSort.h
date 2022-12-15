#pragma once
#include <memory>
#include "../Interfaces/ICollection.h"
#include "../Interfaces/IStackFactory.h"
#include "../Interfaces/IStack.h"


class BeginEnd {
public:
	int begin;
	int end;

	BeginEnd(int begin, int end) {
		this->begin = begin;
		this->end = end;
	}
};


template<class T>
class QSort {
public:
	static void qsort(ICollection<T>& collection, IStackFactory<BeginEnd>& stackFactory) {
		// initialize stack
		std::shared_ptr<IStack<BeginEnd>> stack(stackFactory.createStack());

		// add initial value to stack
		stack->push(BeginEnd(0, collection.size() - 1));

		while (!(stack->empty())) {
			// peek array interval from stack
			int leftBorder = stack->peek().begin;
			int rightBorder = stack->peek().end;
			stack->pop();

			// initialize pointers
			int leftPointer = leftBorder;
			int rightPointer = rightBorder;

			// pivot value
			int pivotValue = collection.at((leftPointer + rightPointer) / 2);


			// partition begins
			while (leftPointer <= rightPointer) {

				// left pointer skips collection value if its less than pivot value
				while (collection.at(leftPointer) < pivotValue) {
					leftPointer++;
				}

				// right pointer skips collection value if its bigger than pivot value
				while (collection.at(rightPointer) > pivotValue) {
					rightPointer--;
				}

				if (leftPointer <= rightPointer) {
					collection.swapValues(leftPointer, rightPointer);

					leftPointer++;
					rightPointer--;
				}
			}
			// partition ends


			// conditions to add array interval to stack to sort it again

			// less array iterval condition
			if (leftBorder < rightPointer) {
				stack->push(BeginEnd(leftBorder, rightPointer));
			}

			// greater array interval condition
			if (leftPointer < rightBorder) {
				stack->push(BeginEnd(leftPointer, rightBorder));
			}
		}
	}
};