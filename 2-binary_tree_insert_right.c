#include "binary_trees.h"
/**
 * binary_tree_insert_right - Function name.
 * Description: Inserts a node as the right-child of another node.
 * @parent: ptr to the node to insert the right-child in.
 * @value: int value to store in the new node.
 * Return: ptr to the created node, NULL (Failure).
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *newNode;
if (parent == NULL)
return (NULL);

newNode = binary_tree_node(parent, value);
if (newNode == NULL)
return (NULL);

if (parent->right != NULL)
{
newNode->right = parent->right;
parent->right->parent = newNode;
}
parent->right = newNode;
return (newNode);
}
