#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_insert - Write a function that inserts a value into a Max Binary Heap
 *
 * @root: is a double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *previus = *root;

	

	if (*root == NULL)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}
	if (previus->n < value)
	{
		previus->left = binary_tree_node(previus, value);
		return (previus->left);
	}
	else
	{
		previus->right = binary_tree_node(previus, value);
		return (previus->right);
		
	}
}
