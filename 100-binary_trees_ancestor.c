#include "binary_trees.h"
/**
 * binary_trees_ancestor - Function name.
 * Description: Finds the lowest common ancestor of two nodes.
 * @first: ptr to the first node.
 * @second: ptr to the second node.
 * Return: ptr to the lowest common ancestor node
 * of the two given nodes, otherwise NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
binary_tree_t *mum, *dad;

if (first == NULL || second == NULL)
return (NULL);
if (first == second)
return ((binary_tree_t *)first);

mum = first->parent, dad = second->parent;
if (first == dad || !mum || (!mum->parent && dad))
return (binary_trees_ancestor(first, dad));
else if (mum == second || !dad || (!dad->parent && mum))
return (binary_trees_ancestor(mum, second));
return (binary_trees_ancestor(mum, dad));
}
