#include "binary_trees.h"
/**
 * sorted_array_to_avl_recursive - Function name.
 * Description: Recursively builds an AVL tree from a sorted array.
 * @array: input array
 * @first: First index of the sorted array.
 * @last: Last index of the sorted array.
 * @parent: ptr to a parent node of the AVL tree.
 * Return: ptr to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl_recursive(int *array, int first, int last,
	avl_t *parent)
{
avl_t *new;
int mid;

if (first > last)
return (NULL);
mid = (first + last) / 2;
new = calloc(1, sizeof(avl_t));
if (!new)
return (NULL);
new->n = array[mid];
new->parent = parent;
new->left = sorted_array_to_avl_recursive(array, first, mid - 1, new);
new->right = sorted_array_to_avl_recursive(array, mid + 1, last, new);
return (new);
}
/**
 * sorted_array_to_avl - Function name.
 * Description: Builds an AVL tree from a sorted array.
 * @array: ptr to the first element of the array to be converted.
 * @size: number of elements in the array.
 * Return: ptr to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (array == NULL)
return (NULL);

return (sorted_array_to_avl_recursive(array, 0, size - 1, NULL));
}
