#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/**
 * struct PATH_DIR - path of directory
 * @name: name of directory
 * @next: next
 */

typedef struct PATH_DIR
{
	char *name;
	struct PATH_DIR *next;
} PATH_DIR;

/**
 * struct linked - ..
 * @dir: ..
 * @first: ..
 * @next: ..
 * @last: ..
 */

typedef	struct	linked
{
	char	*dir;
	struct linked *next;
	struct linked *first;
	struct linked *last;
} linked;

int		execute_command(char *argv[]);
void		free_all(char *line, char **tokens_list);
int		build_path_list(PATH_DIR **head);
PATH_DIR	*add_path(PATH_DIR **h, const char *str);
char		*_getenv(const char *key);
void		getdir(void);
void		create_linkedlist(void);
char		*_strdup(char *str);
void		free_list(linked *h);
int		_setenv(const char *name, const char *value, int overwrite);
int		_unsetenv(const char *name);
void		check_files(int argc, char **argv);

#endif
