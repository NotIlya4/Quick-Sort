#include <iostream>
#include "QSort/Include/QSort.h"
#include "QSort/GeneralAdapters/StackAdapter.h"
#include "QSort/GeneralAdapters/VectorAdapter.h"



using T = int;

int main() {
	VectorAdapter<T> vectorAdapter{5,1,3,8,0,4};
	StackAdapterFactory<BeginEnd> stackFactory;
	QSort<T>::qsort(vectorAdapter, stackFactory);

	for (T& i : vectorAdapter.getRaw()) {
		printf("%d, ", i);
	}
}