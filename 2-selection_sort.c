#include "sort.h"

/**
 * selection_sort - this function sorts elements in an array
 * by implementing the selection sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array thatis going to be sorted
 *
 * Description: refer to the first commented out line
 *
 * Return: Nada
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, currentMinimum;
	int temp;

	for (i = 0; i < size; i++)
	{
		currentMinimum = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[currentMinimum])
			{
				currentMinimum = j;
			}
		}
		if (currentMinimum != i)
		{
			temp = array[i];
			array[i] = array[currentMinimum];
			array[currentMinimum] = temp;
			print_array(array, size);
		}
	}
}

