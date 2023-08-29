#include "binary_trees.h"
/**
 * avl_insert_recursive - Function name.
 * Description: Recursively inserts a value into an AVL Tree.
 * @tree: double ptr to the root node of the AVL tree to insert into.
 * @parent: parent node of the current working node.
 * @new: double ptr to store the new node.
 * @value: int value to insert into the AVL tree.
 * Return: ptr to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
	avl_t **new, int value)
{
int factor;

if (*tree == NULL)
return (*new = binary_tree_node(parent, value));

if ((*tree)->n > value)
{
(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
if ((*tree)->left == NULL)
return (NULL);
}
else if ((*tree)->n < value)
{
(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
if ((*tree)->right == NULL)
return (NULL);
}
else
return (*tree);

factor = binary_tree_balance(*tree);
if (factor > 1 && (*tree)->left->n > value)
*tree = binary_tree_rotate_right(*tree);
else if (factor < -1 && (*tree)->right->n < value)
*tree = binary_tree_rotate_left(*tree);
else if (factor > 1 && (*tree)->left->n < value)
{
(*tree)->left = binary_tree_rotate_left((*tree)->left);
*tree = binary_tree_rotate_right(*tree);
}
else if (factor < -1 && (*tree)->right->n > value)
{
(*tree)->right = binary_tree_rotate_right((*tree)->right);
*tree = binary_tree_rotate_left(*tree);
}

return (*tree);
}
/**
 * avl_insert - Function name.
 * Description: Inserts a value into an AVL tree.
 * @tree: double ptr to the root node of the AVL tree to insert into.
 * @value: int value to insert into the AVL tree.
 * Return: ptr to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *new = NULL;

if (tree == NULL)
return (NULL);
if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}
avl_insert_recursive(tree, *tree, &new, value);
return (new);
}
