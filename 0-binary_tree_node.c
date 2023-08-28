#include "binary_trees.h"
/**
 * binary_tree_node - Function name
 * Description: Creates a binary tree node
 * @parent: ptr to the parent node of the node to create.
 * @value: int value to put in the new node.
 * Return: ptr to the new node, or NULL(failure).
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *newNode = malloc(sizeof(binary_tree_t));
if (newNode == NULL)
return (NULL);

newNode->n = value;
newNode->parent = parent;
newNode->left = NULL;
newNode->right = NULL;

return (newNode);
}
