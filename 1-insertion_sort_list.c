#include"sort.h"
/**
 * swap_nodes - Swaps two nodes in a linked list.
 * @head: ptr to head
 * @n1: Pointer to the first node.
 * @n2: Pointer to the second node.
 */
void swap_nodes(listint_t **head, listint_t **n1, listint_t **n2)
{
	listint_t *tmp;
	listint_t *tmp1 = (*n1)->next;
	listint_t *tmp2 = (*n2)->next;

	(*n1)->next = tmp2;
	(*n2)->next = tmp1;
	if (tmp2 != NULL)
		tmp2->prev = *n1;
	if (tmp1 != NULL)
		tmp1->prev = *n2;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = *n2;
	if ((*n2)->prev != NULL)
		(*n2)->prev->next = *n1;
	if (*head == *n1)
		*head = *n2;
	else if (*head == *n2)
		*head = *n1;
	tmp = (*n1)->prev;
	(*n1)->prev = (*n2)->prev;
	(*n2)->prev = tmp;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *cursor;

	if (!list || !*list)
		return;
	head = *list;
	while (head != NULL)
	{
		cursor = head->prev;
		while (cursor)
		{
			if (cursor->n > head->n)
			{
				swap_nodes(list, &cursor, &head);
				print_list(*list);
			}
			cursor = cursor->prev;
		}
		head = head->next;
	}
}
