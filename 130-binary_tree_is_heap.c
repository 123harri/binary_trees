#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * is_max_heap - Recursively checks if a binary tree
 * satisfies max heap property.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid max heap, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *tree)
{
	int left_check = 1, right_check = 1;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->n < tree->left->n)
		return (0);

	if (tree->right && tree->n < tree->right->n)
		return (0);

	if (tree->left)
		left_check = is_max_heap(tree->left);

	if (tree->right)
		right_check = is_max_heap(tree->right);

	return (left_check && right_check);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_complete;

	if (!tree)
		return (0);

	is_complete = binary_tree_is_complete(tree);

	if (!is_complete)
		return (0);

	return (is_max_heap(tree));
}
