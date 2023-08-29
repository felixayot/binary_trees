#include "binary_trees.h"
/**
 * is_valid_bst_recursive - Function name.
 * Description: Recursively checks if a binary tree is a valid BST.
 * @tree: ptr to the root node of the tree to check.
 * @low: int value of the smallest node already visited.
 * @high: int value of the largest node already visited.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_valid_bst_recursive(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (is_valid_bst_recursive(tree->left, low, tree->n - 1) &&
			is_valid_bst_recursive(tree->right, tree->n + 1, high));
	}
	return (1);
}
/**
 *  binary_tree_is_bst - Function name.
 *  Description: Checks if a binary tree is a valid Binary Search Tree.
 *  @tree: ptr to the root node of the tree to check.
 *  Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (is_valid_bst_recursive(tree, INT_MIN, INT_MAX));
}
