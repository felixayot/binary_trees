#include "binary_trees.h"
/**
 * binary_tree_is_leaf - Function name.
 * Description: Checks if a node is a leaf.
 * @node: ptr to the node to check.
 * Return: 1 if node is a leaf, 0 if not and node is NULL.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
if (node == NULL || node->left != NULL || node->right != NULL)
{
return (0);
}
else
{
return (1);
}
}
