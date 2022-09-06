#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: likend list
 * Return: 0 or 1
 */

int is_palindrome(listint_t **head)
{
	int count = 0, pos_end = 0, pos_init = 0, array[1024];
	const listint_t *current = *head;

	if (head == NULL || *head == NULL)
		return (1);
	while (current != NULL)
	{
		array[count] = current->n;
		current = current->next;
		count++;
	};

	pos_end = count - 1;
	count = count / 2;
	while (pos_init <= count)
	{
		if (array[pos_init] != array[pos_end])
			return (0);
		pos_end--, pos_init++;
	}
	return (1);
}
