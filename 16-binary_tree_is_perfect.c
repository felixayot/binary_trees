#include "binary_trees.h"
/**
 * bt_node_is_leaf - Function name.
 * Description: Checks if a node is a leaf of a binary tree.
 * @node: ptr to the node to check.
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
unsigned char bt_node_is_leaf(const binary_tree_t *node)
{
if (node->left == NULL && node->right == NULL)
return (1);

return (0);
}
/**
 * bt_node_depth - Function name.
 * Description: Returns the depth of a given node in a binary tree.
 * @tree: ptr to the node to measure the depth of.
 * Return: The depth of node or 0 if node is NULL.
 */
size_t bt_node_depth(const binary_tree_t *tree)
{
if (tree->parent != NULL)
return (1 + bt_node_depth(tree->parent));

return (0);
}
/**
 * bt_get_leaf - Function name.
 * Description: Returns a leaf of a binary tree.
 * @tree: ptr to the root node of the tree to find a leaf in.
 * Return: ptr to the first encountered leaf.
 */
const binary_tree_t *bt_get_leaf(const binary_tree_t *tree)
{
if (bt_node_is_leaf(tree) == 1)
return (tree);

if (tree->left)
return (bt_get_leaf(tree->left));

return (bt_get_leaf(tree->right));
}
/**
 * bt_is_perfect_recursive - Function name.
 * Description: Recursively checks if a binary tree is perfect.
 * @tree: ptr to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 * Return: 1 if the tree is perfect, otherwise 0.
 */
int bt_is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
if (bt_node_is_leaf(tree))
{
	if (level == leaf_depth)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

if (tree->left == NULL || tree->right == NULL)
return (0);
return (bt_is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		bt_is_perfect_recursive(tree->right, leaf_depth, level + 1));
}
/**
 * binary_tree_is_perfect - Function name.
 * Description: Checks if a binary tree is perfect.
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 if tree is perfect or 0 if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (bt_is_perfect_recursive(tree, bt_node_depth(bt_get_leaf(tree)), 0));
}
