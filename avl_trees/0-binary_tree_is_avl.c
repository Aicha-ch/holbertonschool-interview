#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>

/**
 * max - Returns the maximum of two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The maximum of a and b
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree. If tree is NULL, return 0
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_bst - Helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - Helper function to check if a binary tree is a valid AVL
 * @tree: Pointer to the root node of the tree to check
 * @height: Pointer to the height of the tree
 *
 * Return: 1 if tree is a valid AVL, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int *height)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if (!is_avl_helper(tree->left, &left_height) ||
		!is_avl_helper(tree->right, &right_height))
		return (0);

	*height = 1 + max(left_height, right_height);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	return (is_avl_helper(tree, &height));
}