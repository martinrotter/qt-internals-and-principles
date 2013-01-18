#ifndef QUICKSORT_H
#define QUICKSORT_H


class QuickSort {
    public:
	static void quickSort(int *array, int p, int r);

    protected:
	static int partition(int *array, int p, int r);
	static void swap(int *lhs, int *rhs);
};

#endif // QUICKSORT_H
