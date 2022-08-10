#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Write a function in C that inserts a number
 * into a sorted singly linked list.
 *
 * @head: pointer to head of list
 * @number: number of items to insert_node
 * Return: listint_t*
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *next_head = NULL;
	listint_t *current = NULL;
	listint_t *new;

	if (*head == NULL && head == NULL)
		return (NULL);

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	while (current != NULL)
	{
		next_head = current;
		current = current->next;
		if (current->n > number)
			break;
		if (current->n < number && current->next == NULL)
			break;
	}

	if (current->n < number && current->next == NULL)
	{
		current->next = new;
		new->next = NULL;
	}

	if (next_head->n < number && current->n > number)
	{
		next_head->next = new;
		new->next = current;
	}

	if (next_head->n > number && next_head->next == NULL && current->n > number)
	{
		next_head->next = new;
		new->next = NULL;
	}

	return (*head);
}