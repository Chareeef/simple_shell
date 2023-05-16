#include "main.h"

/**
 * free_list - free a singly linked list
 * @h: pointer to singly linked list head
 */
void free_list(linked *h)
{
	linked *tracker = NULL;

	while (h != NULL)
	{
		tracker = h;
		h = h->next;
		free(tracker->dir);
		free(tracker);
	}
}

/**
 * create_linkedlist - builds a linked list of the PATH directories.
 */

void	create_linkedlist(void)
{
	linked	*new;
	linked	*first;
	linked *current;
	linked	*last;
	char	*path;
	char	*token = NULL;

	first = NULL;
	last = NULL;
	path = _getenv("PATH");
	token = _strdup(strtok(path, ":"));
	while (token != NULL)
	{
		new = malloc(sizeof(linked));
		new->dir = token;
		new->first = NULL;
		new->next = NULL;
		new->last = NULL;
		if (first == NULL)
		{
			first = new;
			last = new;
		}
		else
		{
			last->next = new;
			last = new;
		}
		token = _strdup(strtok(NULL, ":"));
	}
	current = first;

	while (first != NULL)
	{
		first = first->next;
	}
	free_list(current);
}
