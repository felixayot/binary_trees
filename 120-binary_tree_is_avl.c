#include "binary_trees.h"
/**
 * avl_height - Function name.
 * Description: Measures the height of a binary tree.
 * @tree: ptr to the root node of the tree to measure the height.
 * Return: the height of tree, or 0 if tree is NULL.
 */
size_t avl_height(const binary_tree_t *tree)
{
size_t l = 0, r = 0;
if (tree)
{

if (tree->left)
l = 1 + avl_height(tree->left);
else
l = 1;

if (tree->right)
r = 1 + avl_height(tree->right);
else
r = 1;

if (l > r)
return (l);
else
return (r);
}
else
return (0);
}
/**
 * is_avl_recursive - Function name.
 * Description: Recursively checks if a binary tree is a valid AVL Tree.
 * @tree: ptr to the root node of the tree to check.
 * @low: int value of the smallest node already visited.
 * @high: int value of the largest node already visited.
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int is_avl_recursive(const binary_tree_t *tree, int low, int high)
{
size_t l, r, margin;

if (tree != NULL)
{
if (tree->n < low || tree->n > high)
return (0);

l = avl_height(tree->left);
r = avl_height(tree->right);
if (l > r)
margin = l - r;
else
margin = r - l;

if (margin > 1)
return (0);
else
return (is_avl_recursive(tree->left, low, tree->n - 1) &&
	is_avl_recursive(tree->right, tree->n + 1, high));
}
else
return (1);
}
/**
 * binary_tree_is_avl - Function name.
 * Description: Checks if a binary tree is a valid AVL Tree.
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_avl_recursive(tree, INT_MIN, INT_MAX));
}
