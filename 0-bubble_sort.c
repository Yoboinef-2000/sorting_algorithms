#include "sort.h"

/**
 * bubble_sort - this function sorts an array by implementing
 * the bubble sort algorithm.
 *
 * @array: the array that is going to be sorted
 * @size: size of the array that is going to be sorted
 *
 * Description: refer to the first commented out line
 *
 * Return: Nada
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp  = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		print_array(array, size);
		i++;
	}
}

