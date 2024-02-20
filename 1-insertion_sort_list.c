#include "sort.h"

/**
 * insert_into_sorted - this is a part of the insertion sort algo,
 * i cut it down so I can pass the betty checks.
 * Betty a b****.
 *
 * @sortedPart: the sortedPart of the list
 * @currentNode: the unsortedPart of the list
 *
 * Description: refer to the first commented out line
 *
 * Return: Nada
 */
void insert_into_sorted(listint_t *sortedPart, listint_t *currentNode)
{
	listint_t *temp;

	temp = sortedPart;

	while (temp->next != NULL && temp->next->n < currentNode->n)
	{
		temp = temp->next;
	}
	currentNode->next = temp->next;

	if (temp->next != NULL)
	{
		temp->next->prev = currentNode;
	}
	temp->next = currentNode;
	currentNode->prev = temp;
}

/**
 * print_combined_lists - this is a part of the insertion sort algo,
 * I only cut it down so I can pass the betty checks.
 * Betty a b****.
 *
 * @sortedPart: the sortedPart of the list
 * @unsortedPart: the unsortedPart of the list
 *
 * Description: refer to the first commented out line
 *
 * Return: Nada
 */
void print_combined_lists(listint_t *sortedPart, listint_t *unsortedPart)
{
	listint_t *combined;

	combined = sortedPart;

	while (combined != NULL)
	{
		printf("%d", combined->n);
		if (combined->next != NULL)
		{
			printf(", ");
		}
		combined = combined->next;
	}

	if (unsortedPart != NULL)
	{
		printf(", ");
		print_list(unsortedPart);
	}
}
/**
 * insertion_sort_list - this function sorts a given list
 * by implementing the insertion sort algrorithm
 *
 * @list: the list that is going to be sorted
 *
 * Description: refer to the first commented out line
 *
 * Return: Nada
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *currentNode;
	listint_t *sortedPart, *unsortedPart;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	sortedPart = NULL;
	unsortedPart = *list;

	while (unsortedPart != NULL)
	{
		currentNode = unsortedPart;
		unsortedPart = unsortedPart->next;
		if (sortedPart == NULL || currentNode->n <= sortedPart->n)
		{
			currentNode->next = sortedPart;
			currentNode->prev = NULL;
			if (sortedPart != NULL)
			{
				sortedPart->prev = currentNode;
			}
			sortedPart = currentNode;
		}
		else
		{
			insert_into_sorted(sortedPart, currentNode);
		}
		print_combined_lists(sortedPart, unsortedPart);
	}
	printf("\n");
	*list = sortedPart;
}

