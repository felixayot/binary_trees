#include "binary_trees.h"
/**
 * binary_tree_depth - Function name
 * Description: Measures the depth of a node in a binary tree.
 * @tree: ptr to the node to measure the depth.
 * Return: depth of the node or 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
if (tree == NULL || tree->parent == NULL)
return (0);

return (1 + binary_tree_depth(tree->parent));
}
