#include "binary_trees.h"
/**
 * binary_tree_recursive - Function name.
 * Description: Recursively checks if a binary tree is full.
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 if tree is full or 0 otherwise.
 */
int binary_tree_recursive(const binary_tree_t *tree)
{
if (tree != NULL)
{
if ((tree->left != NULL && tree->right == NULL) ||
(tree->left == NULL && tree->right != NULL) ||
binary_tree_recursive(tree->left) == 0 ||
binary_tree_recursive(tree->right) == 0)
return (0);
}

return (1);
}
/**
 * binary_tree_is_full - Function name.
 * Description: Checks if a binary tree is full.
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 if tree is full or 0 if tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (binary_tree_recursive(tree));
}
