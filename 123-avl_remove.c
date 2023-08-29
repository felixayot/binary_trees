#include "binary_trees.h"
/**
 * avl_inorder_successor - Function name.
 * Description: Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the AVL Tree to search.
 * Return: The minimum value in the AVL Tree.
 */
avl_t *avl_inorder_successor(avl_t *root)
{
while (root->left != NULL)
root = root->left;
return (root);
}
/**
 * avl_delete - Function name.
 * Description: Deletes a node from a AVL Tree.
 * @root: ptr to the root node of the AVL Tree.
 * @node: ptr to the node to delete from the AVL Tree.
 * Return: ptr to the new root node after node deletion.
 */
avl_t *avl_delete(avl_t *root, avl_t *node)
{
avl_t *parent = node->parent, *successor = NULL;
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

successor = avl_inorder_successor(node->right);
node->n = successor->n;

return (avl_delete(root, successor));
}
/**
 * avl_remove_recursive - Function name.
 * Description: Recursively removes a node from a AVL Tree.
 * @root: ptr to the root node of the tree to remove a node from.
 * @node: ptr to the current node in the tree.
 * @value: int value to remove from the tree.
 * Return: ptr to the root node after value removal.
 */
avl_t *avl_remove_recursive(avl_t *root, avl_t *node, int value)
{
if (node != NULL)
{
if (node->n == value)
return (avl_delete(root, node));
if (node->n > value)
return (avl_remove_recursive(root, node->left, value));
return (avl_remove_recursive(root, node->right, value));
}
return (NULL);
}
/**
 * avl_remove - Function name.
 * Description: Removes a node from an AVL tree.
 * @root: ptr to the root node of the tree from which a node is to be removed.
 * @value: int value to remove from the tree.
 * Return: ptr to the new root node after value removal.
 */
avl_t *avl_remove(avl_t *root, int value)
{
return (avl_remove_recursive(root, root, value));
}
