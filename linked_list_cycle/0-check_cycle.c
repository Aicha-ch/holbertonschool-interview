#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - prints a list
 * @h: pointer to the head
 * Return: nodes number
 */
size_t print_listint(const listint_t *h)
{
    const listint_t *current_node;
    unsigned int node_number;

    current_node = h;
    node_number = 0;
    while (current_node != NULL)
    {
        printf("%i\n", current_node->n);
        current_node = current_node->next;
        node_number++;
    }

    return (node_number);
}

/**
 * add_nodeint - adds a new node
 * @head: pointer to the head of list
 * @n: integer
 * Return: address of the new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new_node;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = *head;
    *head = new_node;

    return (new_node);
}

/**
 * free_listint - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_listint(listint_t *head)
{
    listint_t *current_node;

    while (head != NULL)
    {
        current_node = head;
        head = head->next;
        free(current_node);
    }
}