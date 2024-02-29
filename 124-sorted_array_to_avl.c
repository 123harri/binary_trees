#include "binary_trees.h"

/**
 * create_tree - Recursively creates an AVL tree.
 *
 * @node: Pointer to the current node.
 * @array: Input array of integers.
 * @size: Size of the array.
 * @left_mode: Flag indicating whether to add on the left (1) or not (0).
 * Return: No return.
 */
void create_tree(avl_t **node, int *array, size_t size, int left_mode)
{
	size_t middle;

	if (size == 0)
		return;

	middle = size / 2;
	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (left_mode)
	{
		(*node)->left = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->left), array, middle, 1);
		create_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), 0);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->right), array, middle, 1);
		create_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), 0);
	}
}

/**
 * sorted_array_to_avl - Creates the root node and calls create_tree.
 *
 * @array: Input array of integers.
 * @size: Size of the array.
 * Return: Pointer to the root of the AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	root = NULL;

	if (size == 0)
		return (NULL);

	middle = size / 2;
	middle = (size % 2 == 0) ? middle - 1 : middle;

	root = binary_tree_node(root, array[middle]);

	create_tree(&root, array, middle, 1);
	create_tree(&root, array + middle + 1, (size - 1 - middle), 0);

	return (root);
}
