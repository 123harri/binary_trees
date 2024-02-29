#include "binary_trees.h"
#include <stdlib.h>

size_t heap_tree_size(const binary_tree_t *tree);

/**
 * heap_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: Size or 0 if tree is NULL
 */
size_t heap_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t size_l = 0, size_r = 0;

	if (tree->left)
		size_l = 1 + heap_tree_size(tree->left);

	if (tree->right)
		size_r = 1 + heap_tree_size(tree->right);

	return (size_l + size_r);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *sorted_array = NULL;

	if (!heap || !size)
		return (NULL);

	*size = heap_tree_size(heap) + 1;

	sorted_array = malloc(sizeof(int) * (*size));

	if (!sorted_array)
		return (NULL);

	for (i = 0; heap; i++)
		sorted_array[i] = heap_extract(&heap);

	return (sorted_array);
}
