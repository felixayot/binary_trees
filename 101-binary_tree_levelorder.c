#include "binary_trees.h"
/**
 * bt_create_node - Function name.
 * Description: Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 * Return: ptr to the new node, or NULL otherwise.
 */
levelorder_queue_t *bt_create_node(binary_tree_t *node)
{
levelorder_queue_t *newNode;

newNode = malloc(sizeof(levelorder_queue_t));
if (newNode == NULL)
return (NULL);

newNode->node = node;
newNode->next = NULL;

return (newNode);
}
/**
 * bt_free_queue - Function name.
 * Description: Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 * Return: void
 */
void bt_free_queue(levelorder_queue_t *head)
{
levelorder_queue_t *tmp;

while (head != NULL)
{
tmp = head->next;
free(head);
head = tmp;
}
}
/**
 * bt_pint_push - Function name.
 * Description: Runs a function on a given binary tree node and
 * pushes its children into a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 * Return: void
 */
void bt_pint_push(binary_tree_t *node, levelorder_queue_t *head,
	levelorder_queue_t **tail, void (*func)(int))
{
levelorder_queue_t *new;

func(node->n);
if (node->left != NULL)
{
new = bt_create_node(node->left);
if (new == NULL)
{
bt_free_queue(head);
exit(1);
}
(*tail)->next = new;
*tail = new;
}
if (node->right != NULL)
{
new = bt_create_node(node->right);
if (new == NULL)
{
bt_free_queue(head);
exit(1);
}
(*tail)->next = new;
*tail = new;
}
}
/**
 * bt_pop - Function name.
 * Description: Pops the head of a levelorder_queue_t queue.
 * @head: A double ptr to the head of the queue.
 * Return: void
 */
void bt_pop(levelorder_queue_t **head)
{
levelorder_queue_t *tmp;

tmp = (*head)->next;
free(*head);
*head = tmp;
}
/**
 * binary_tree_levelorder - Function name.
 * Description: Goes through a binary tree using level-order traversal.
 * @tree: ptr to the root node of the tree to traverse.
 * @func: ptr to a function to call for each node.
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
levelorder_queue_t *head, *tail;

if (tree == NULL || func == NULL)
return;

head = tail = bt_create_node((binary_tree_t *)tree);
if (head == NULL)
return;

while (head != NULL)
{
bt_pint_push(head->node, head, &tail, func);
bt_pop(&head);
}
}
