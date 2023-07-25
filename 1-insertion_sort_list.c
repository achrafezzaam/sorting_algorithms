#include "sort.h"
/**
 * swap - Swap two elements of a doubly linked list
 * @head: The first element of the linked list
 * @left: The first element to swap
 * @right: The second element to swap
 *
 * Return: A pointer to the second element swaped
 */
listint_t *swap(listint_t **head, listint_t *left, listint_t *right)
{
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
	if (left->next != NULL)
		left->next->prev = left;
	if (right->prev != NULL)
		right->prev->next = right;
	else
		*head = right;
	print_list(*head);
	return (right);
}
/**
 * insertion_sort_list - Sort a doubly linked list using the insertion
 *			 sort algorithm
 * @list: The first element of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *buff = (*list)->next, *pos = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (buff != NULL)
	{
		pos = buff;
		while (buff->prev != NULL && buff->n < buff->prev->n)
		{
			buff = swap(list, buff->prev, buff);
		}
		buff = pos->next;
	}
}
