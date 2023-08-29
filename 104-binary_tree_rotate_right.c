#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Function name.
 * Description: Performs a left-rotation on a binary tree.
 * @tree: ptr to the root node of the tree to rotate.
 * Return: ptr to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *tmp, *pivot;
if (tree == NULL || tree->left == NULL)
return (NULL);

pivot = tree->left;
tmp = pivot->right;
pivot->right = tree;
tree->left = tmp;
if (tmp != NULL)
tmp->parent = tree;
tmp = tree->parent;
tree->parent = pivot;
pivot->parent = tmp;
if (tmp != NULL)
{
	if (tmp->right == tree)
		tmp->right = pivot;
	else
		tmp->left = pivot;
}
return (pivot);
}
