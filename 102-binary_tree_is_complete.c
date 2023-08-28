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
 * bt_push - Function name.
 * Description: Runs a function on a given binary tree node and
 * pushes its children into a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * Return: void
 */
void bt_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
levelorder_queue_t *new;

new = bt_create_node(node);
if (new == NULL)
{
bt_free_queue(head);
exit(1);
}
(*tail)->next = new;
*tail = new;
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
 * binary_tree_is_complete - Function name.
 * Description: Checks if a binary tree is complete.
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
levelorder_queue_t *head, *tail;
unsigned char flag = 0;

if (tree == NULL)
return (0);

head = tail = bt_create_node((binary_tree_t *)tree);
if (head == NULL)
exit(1);

while (head != NULL)
{
if (head->node->left != NULL)
{
if (flag == 1)
{
bt_free_queue(head);
return (0);
}
bt_push(head->node->left, head, &tail);
}
else
flag = 1;
if (head->node->right != NULL)
{
if (flag == 1)
{
bt_free_queue(head);
return (0);
}
bt_push(head->node->right, head, &tail);
}
else
flag = 1;
bt_pop(&head);
}
return (1);
}
