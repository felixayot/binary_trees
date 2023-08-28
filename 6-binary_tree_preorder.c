#include "binary_trees.h"
/**
 * binary_tree_preorder - Function name.
 * Description: Goes through a binary tree using pre-order traversal.
 * @tree: ptr to the root node of the tree to traverse.
 * @func: ptr to a function to for each node. Value in the node must
 * must be passed as parameter in this function.
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
{
return;
}
else
{
func(tree->n);
binary_tree_preorder(tree->left, func);
binary_tree_preorder(tree->right, func);
}
}
