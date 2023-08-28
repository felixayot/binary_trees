#include "binary_trees.h"
/**
 * binary_tree_inorder - Function name
 * Description: Goes through a binary tree using in-order traversal.
 * @tree: ptr to the root node of the tree to traverse.
 * @func: ptr to a function to call for each node.
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
{
return;
}
else
{
binary_tree_inorder(tree->left, func);
func(tree->n);
binary_tree_inorder(tree->right, func);
}
}
