#include "binary_trees.h"
/**
 * bst_inorder_successor - Function name.
 * Description: Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 * Return: The minimum value in the BST.
 */
bst_t *bst_inorder_successor(bst_t *root)
{
while (root->left != NULL)
root = root->left;
return (root);
}
/**
 * bst_delete - Function name.
 * Description: Deletes a node from a BST.
 * @root: ptr to the root node of the BST.
 * @node: ptr to the node to delete from the BST.
 * Return: ptr to the new root node after node deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
bst_t *parent = node->parent, *successor = NULL;
if (node->left == NULL)
{
if (parent != NULL && parent->left == node)
parent->left = node->right;
else if (parent != NULL)
parent->right = node->right;
if (node->right != NULL)
node->right->parent = parent;
free(node);
return (parent == NULL ? node->right : root);
}

if (node->right == NULL)
{
if (parent != NULL && parent->left == node)
parent->left = node->left;
else if (parent != NULL)
parent->right = node->left;
if (node->left != NULL)
node->left->parent = parent;
free(node);
return (parent == NULL ? node->left : root);
}

successor = bst_inorder_successor(node->right);
node->n = successor->n;

return (bst_delete(root, successor));
}
/**
 * bst_remove_recursive - Function name.
 * Description: Recursively removes a node from a BST.
 * @root: ptr to the root node of the tree to remove a node from.
 * @node: ptr to the current node in the tree.
 * @value: int value to remove from the tree.
 * Return: ptr to the root node after value removal.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
if (node != NULL)
{
if (node->n == value)
return (bst_delete(root, node));
if (node->n > value)
return (bst_remove_recursive(root, node->left, value));
return (bst_remove_recursive(root, node->right, value));
}
return (NULL);
}
/**
 * bst_remove - Function name.
 * Description: Removes a node from a BST.
 * @root: ptr to the root node of the tree to remove a node from.
 * @value: int value to remove in the tree.
 * Return: ptr to the new root node after value removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
return (bst_remove_recursive(root, root, value));
}
