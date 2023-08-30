#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
/**
 * struct levelorder_queue_s - Level-order traversal queue.
 * @node: A node of a binary tree.
 * @next: The next node to traverse to in the binary tree.
 */
typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_recursive(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
unsigned char bt_node_is_leaf(const binary_tree_t *node);
size_t bt_node_depth(const binary_tree_t *tree);
const binary_tree_t *bt_get_leaf(const binary_tree_t *tree);
int bt_is_perfect_recursive(const binary_tree_t *tree,
	size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second);
levelorder_queue_t *bt_create_node(binary_tree_t *node);
void bt_free_queue(levelorder_queue_t *head);
void bt_pint_push(binary_tree_t *node, levelorder_queue_t *head,
	levelorder_queue_t **tail, void (*func)(int));
void bt_pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
void bt_push(binary_tree_t *node, levelorder_queue_t *head,
	levelorder_queue_t **tail);
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int is_valid_bst_recursive(const binary_tree_t *tree, int low, int high);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);
size_t avl_height(const binary_tree_t *tree);
int is_avl_recursive(const binary_tree_t *tree, int low, int high);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
	avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_inorder_successor(avl_t *root);
avl_t *avl_delete(avl_t *root, avl_t *node);
avl_t *avl_remove_recursive(avl_t *root, avl_t *node, int value);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl_recursive(int *array, int first, int last,
	avl_t *parent);
avl_t *sorted_array_to_avl(int *array, size_t size);
int bt_is_complete_recursive(const binary_tree_t *tree, int index, int value);
int bt_is_complete(const binary_tree_t *tree);
int bt_check_parent(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);

#endif /* _BINARY_TREES_H_ */
