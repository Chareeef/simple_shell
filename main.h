#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

extern char **environ;

/**
 * struct PATH_DIR - path of directory
 * @name: name of directory
 * @next: next path
 */
typedef struct PATH_DIR
{
	char *name;
	struct PATH_DIR *next;
} PATH_DIR;

/**
 * struct linked - a single directory node
 * @dir: directory's name
 * @first: first directory
 * @next: next directory
 * @last: last directory
 */
typedef	struct	linked
{
	char	*dir;
	struct linked *next;
	struct linked *first;
	struct linked *last;
} linked;

/* FUNCTIONS PROTOTYPES */

int		execute_command(char *argv[]);
void		free_all(char *line, char **tokens_list);
char		*_getenv(const char *key);
char		**dup_environ();
void		*_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void		create_linkedlist(void);
void		free_list(linked *h);
int		cd(char **commandline, char *path);
int		cd_exec(char **args);
int		_setenv(const char *name, const char *value, int overwrite);
int		_unsetenv(const char *name);
char		*prompt_command(void);
char		**split_str_to_arr(char *line);
char		*search_exec(char *first_arg);
int		builtin_exec(char **args, char *line);
int		builtin_exec2(char **args);
char		*_memcpy(char *dest, char *src, unsigned int n);
void		printenv(void);
int		_putchar(char c);
void		print_number(int n);
void		print_error(char **commandline, char *command, int error);
void		write_program_name(char *program_name);
void		write_error(char *message);
char		*_strcpy(char *dest, char *src);
char		*_strncpy(char *dest, char *src, int n);
int		_strlen(const char *s);
char		*_strchr(char *s, char c);
char		*_strdup(char *str);
char		*_strcat(char *dest, const char *src);
int		_strcmp(char *s1, char *s2);
int		_strncmp(const char *s1, const char *s2, size_t n);
char		*_strtok(char *str, char *delims);
int		stat_to_int(char *s);

#endif
