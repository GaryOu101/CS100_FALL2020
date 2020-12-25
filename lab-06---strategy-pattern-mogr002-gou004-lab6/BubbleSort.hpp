#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "sort.hpp"
#include "VectorContainer.hpp"
#include "ListContainer.hpp"
#include <vector>

using namespace std;

class BubbleSort: public Sort {
	public:
		virtual void sort(Container* container) {
			int i, j;
			for (i = 0; i < container->size() - 1; ++i) {
				for (j = 0; j < container->size() - i - 1; ++j) {
					if (container->at(j)->evaluate() > container->at(j + 1)->evaluate()) {
						container->swap(j, j + 1);
					}
				}
			}
		}
};

#endif
