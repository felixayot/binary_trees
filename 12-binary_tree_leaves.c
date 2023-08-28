#include "binary_trees.h"
/**
 * binary_tree_leaves - Function name.
 * Description: Counts the leaves in a binary tree.
 * @tree: ptr to the root node of the tree to count the number of leaves.
 * Return: number of leaves or 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
size_t count = 0;
if (tree == NULL)
return (0);

count += (!tree->left && !tree->right);
count += binary_tree_leaves(tree->left);
count += binary_tree_leaves(tree->right);
return (count);
}
