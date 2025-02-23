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
    const listint_t *current;
    unsigned int n;

    current = h;
    n = 0;
    while (current != NULL)
    {
        printf("%i\n", current->n);
        current_node = current->next;
        n++;
    }

    return (n);
}

/**
 * add_nodeint - adds a new node
 * @head: pointer to the head of list
 * @n: integer
 * Return: address of the new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = *head;
    *head = new;

    return (new);
}

/**
 * free_listint - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_listint(listint_t *head)
{
    listint_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}