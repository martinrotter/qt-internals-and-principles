#include <ctime>
#include <iostream>

#include "quicksort.h"

using namespace std;


int main(int argc, char *argv[]) {
    for (int j = 1; j < 20; j++) {
	int no_of_elements = j * 800;

	// Create array of values.
	int *array = new int[no_of_elements];

	for (int i = 0; i < no_of_elements; i++) {
	    array[i] = no_of_elements - i;
	}

	// Sort array and measure the time.
	clock_t t;

	t = clock();
	QuickSort::quickSort(array, 0, no_of_elements - 1);
	t = clock() - t;

	cout << "Sort of " << no_of_elements
	     << " elements took " << ((float)t)/CLOCKS_PER_SEC
	     << " seconds.\n";
	delete [] array;
    }


    return 0;
}

