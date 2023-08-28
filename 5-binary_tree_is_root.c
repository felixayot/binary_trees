#include "binary_trees.h"
/**
 * binary_tree_is_root - Function name
 * Description: Checks if a given node is root.
 * @node: ptr to the node to check.
 * Return: 1 if node is root, 0 if not and node is NULL.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
if (node == NULL || node->parent != NULL)
{
return (0);
}
else
{
return (1);
}
}
