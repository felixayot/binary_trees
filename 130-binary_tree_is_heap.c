#include "binary_trees.h"
/**
 * binary_tree_size - Function name.
 * Description: Measures the size of a binary tree.
 * @tree: ptr to the root node of the tree to measure the size.
 * Return: size of tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t size = 0;
if (tree == NULL)
return (0);

size += 1;
size += binary_tree_size(tree->left);
size += binary_tree_size(tree->right);
return (size);
}
/**
 * bt_is_complete_recursive - Function name.
 * Description: Recursively checks if tree is complete.
 * @tree: ptr to the root node of the tree to check.
 * @index: node index in the tree.
 * @value: number of nodes in the tree.
 * Return: 1 if tree is complete, 0 otherwise.
 */
int bt_is_complete_recursive(const binary_tree_t *tree, int index, int value)
{
if (tree == NULL)
return (1);

if (index >= value)
return (0);

return (bt_is_complete_recursive(tree->left, (2 * index) + 1, value) &&
bt_is_complete_recursive(tree->right, (2 * index) + 2, value));
}
/**
 * bt_is_complete - Function name.
 * Description: Checks if tree is complete.
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 if tree is complete, 0 otherwise.
 */
int bt_is_complete(const binary_tree_t *tree)
{
size_t value;

if (tree == NULL)
return (0);

value = binary_tree_size(tree);

return (bt_is_complete_recursive(tree, 0, value));
}
/**
 * bt_check_parent - Function name.
 * Description: Recursively checks if parent has
 * a greater value than its childs.
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 if parent has a greater value, 0 otherwise
 */
int bt_check_parent(const binary_tree_t *tree)
{
if (tree == NULL)
return (1);

if (tree->n > tree->parent->n)
return (0);

return (bt_check_parent(tree->left) && bt_check_parent(tree->right));
}
/**
 * binary_tree_is_heap - Function name.
 * Description: Checks if a binary tree is valid Max Binary Heap.
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
if (!bt_is_complete(tree))
return (0);

return (bt_check_parent(tree->left) && bt_check_parent(tree->right));
}
