#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "sort.hpp"
#include "VectorContainer.hpp"
#include "ListContainer.hpp"
#include <vector>

using namespace std;

class SelectionSort: public Sort {
	public:
		virtual void sort(Container* container) {
			int i, j, minIndex;
			for (i = 0; i < container->size() - 1; i++) {
				for (j = i + 1; j < container->size(); j++) {
					if (container->at(j)->evaluate() < container->at(i)->evaluate()) {
						container->swap(i, j);
					}
				}
			}
		}
	
};

#endif
