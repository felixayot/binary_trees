#include "binary_trees.h"
/**
 * binary_tree_height - Function name.
 * Description: Measures the height of a binary tree.
 * @tree: ptr to the root node of the tree to measure height.
 * Return: height of tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t l = 0, r = 0;
if (tree == NULL)
return (0);

l = (size_t)tree->left;
if (l)
{
l = 1 + binary_tree_height(tree->left);
}
else
{
l = 0;
}

r = (size_t)tree->right;
if (r)
{
r = 1 + binary_tree_height(tree->right);
}
else
{
r = 0;
}

if (l > r)
{
return (l);
}
else
{
return (r);
}

}
