#include "binary_trees.h"
/**
 * binary_tree_nodes - Function name.
 * Description: Counts the nodes with at least 1 child in a binary tree.
 * @tree: ptr to the root node of the tree to count the number of nodes.
 * Return: number of nodes or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t count = 0;
if (tree == NULL)
return (0);

count += (tree->left || tree->right);
count += binary_tree_nodes(tree->left);
count += binary_tree_nodes(tree->right);
return (count);
}
