#include "binary_trees.h"
/**
 * bst_search - Function name.
 * Description: Searches for a value in a BST.
 * @tree: ptr to the root node of the BST to search.
 * @value: int value to search in the tree.
 * Return: ptr to the node containing a value equaling "value" or
 * NULL if tree is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
if (tree != NULL)
{
if (tree->n == value)
return ((bst_t *)tree);
if (tree->n > value)
return (bst_search(tree->left, value));
return (bst_search(tree->right, value));
}
return (NULL);
}
