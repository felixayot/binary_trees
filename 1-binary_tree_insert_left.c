#include "binary_trees.h"
/**
 * binary_tree_insert_left - Function name
 * Description: Inserts a node as the left-child of another node.
 * @parent: ptr to the node to insert the left-child in.
 * @value: int value to store in the new node.
 * Return: ptr to the created node, or NULL(Failure)
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *newNode;
if (parent == NULL)
return (NULL);

newNode = binary_tree_node(parent, value);
if (newNode == NULL)
return (NULL);

if (parent->left != NULL)
{
newNode->left = parent->left;
parent->left->parent = newNode;
}
parent->left = newNode;
return (newNode);
}
