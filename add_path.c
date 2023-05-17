#include "main.h"

/**
 * add_node_end - add an element at the end of a singly linked list
 * @h: pointer to pointer to singly linked list head
 * @name: name to be stored in the new node
 *
 * Return: pointer to the new element, or NULL if an error occurs
 */
PATH_DIR *add_path(PATH_DIR **h, const char *name)
{
	PATH_DIR *new;
	PATH_DIR *tracker;

	if (h == NULL)
		return (NULL);

	new = malloc(sizeof(PATH_DIR));

	if (new == NULL)
		return (NULL);

	new->name = strdup(name);
	new->next = NULL;

	tracker = *h;

	if (tracker != NULL)
	{
		while (tracker->next != NULL)
		{
			tracker = tracker->next;
		}

		tracker->next = new;
	}
	else
	{
		*h = new;
	}

	return (new);
}
