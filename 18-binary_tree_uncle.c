#include "binary_trees.h"
/**
 * binary_tree_uncle - Function name.
 * Description: Finds the uncle of a node.
 * @node: ptr to the node to find the uncle.
 * Return: ptr to the uncle node, or NULL otherwise.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
if (node == NULL ||
node->parent == NULL ||
node->parent->parent == NULL)
return (NULL);
if (node->parent->parent->left == node->parent)
return (node->parent->parent->right);
return (node->parent->parent->left);
}
