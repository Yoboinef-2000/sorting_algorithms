#include "sort.h"
/**
 * swap - swaps two pointers
 * @x: value to be swapped
 * @y: value to be swapped
 * Return: Nothing
*/
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * lomuto_partition - divides the array into partitions using the
 * last elements as a pivot
 * @array: array to be partitioned
 * @size: size of the array
 * @low: lower index
 * @high: higher index
 * Return: int number
*/
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pi, i, j;

	pi = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pi)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pi)
	{
		swap(array + i, pi);
		print_array(array, size);
	}

	return (i);
}
/**
 * quickSortup - sorts array in an ascending order using
 * quick sort algorithm
 * @array: array of ints to be sorted
 * @size: size of the array
 * @low: lower limit size
 * @high: higher limit size
 * Return: Nothing
*/
void quickSortup(int *array, size_t size, int low, int high)
{
	int pi_ind;

	if (high - low > 0)
	{
		pi_ind = lomuto_partition(array, size, low, high);

		quickSortup(array, size, low, pi_ind - 1);
		quickSortup(array, size, pi_ind + 1, high);
	}
}
/**
 * quick_sort - sorts array in an ascending order using
 * quick sort algorithm
 * @array: array of ints to be sorted
 * @size: number of elements in the array
 * Return: Nothing
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSortup(array, size, 0, size - 1);
}
