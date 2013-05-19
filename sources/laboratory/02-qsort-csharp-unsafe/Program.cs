using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _02_qsort_csharp {

	class Program {

		static unsafe void Main(string[] args) {
			for (int j = 1; j < 20; j++) {
				int no_of_elements = j * 800;

				// Create array of values.
				int[] array = new int[no_of_elements];
				fixed (int* arr = array) {

					for (int i = 0; i < no_of_elements; i++) {
						array[i] = no_of_elements - i;
					}

					// Sort array and measure the time.
					DateTime t = DateTime.Now;
					quickSort(arr, 0, no_of_elements - 1);
					TimeSpan s = DateTime.Now - t;

					Console.WriteLine("Sort of {0} elements took {1,2:N3} seconds.", no_of_elements, s.TotalSeconds);
				}
			}
		}

		static unsafe void quickSort(int* array, int p, int r) {
			int q;
			if (p < r) {
				q = partition(array, p, r);
				quickSort(array, p, q - 1);
				quickSort(array, q + 1, r);
			}
		}

		static unsafe int partition(int* array, int p, int r) {
			int x = array[r];
			int i = p - 1;
			int j;
			for (j = p; j < r; j++) {
				if (array[j] <= x) {
					i += 1;
					swap(&array[i], &array[j]);
				}
			}
			swap(&array[i + 1], &array[r]);
			return i + 1;
		}

		static unsafe void swap(int* lhs, int* rhs) {
			int* temp = lhs;
			lhs = rhs;
			rhs = temp;
		}

	}

}
