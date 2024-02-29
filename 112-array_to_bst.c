#include "binary_trees.h"
#include <stdlib.h>

void free_tree(bst_t *tree);
/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{
			free_tree(root);
			return (NULL);
		}
	}

	return (root);
}

/**
 * free_tree - Frees a binary tree.
 * @tree: Pointer to the root node of the tree.
 */
void free_tree(bst_t *tree)
{
	if (tree)
	{
		free_tree(tree->left);
		free_tree(tree->right);
		free(tree);
	}
}
