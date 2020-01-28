#ifndef TINKER_H
#define TINKER_H
#include "libft/libft.h"
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <time.h>

#define L_MAX 2048
#define L_MIN 128

typedef struct              t_list
{
		struct t_list		*next;
		struct t_list		*prev;
		struct stat			stat_buff[L_MAX];
		char				*name;
		char				*abs_path;
}                           ls;

//initializers (inits.c)
ls	*init_ls_node(const char *name, const char *path);
ls	*init_list(const char *path);
ls	*init_cwd();
int	init_files(char **files, ls **behemoth);

//modifiers (tinker.c)
ls	*add_node(ls *node, ls *list);
int	is_dir(ls *node);
ls	*seek_end(ls *list);
char	*p_append(const char *path, const char *name);

//printers (prints.c)
int	print_node(ls *node);
int	print_node_long(ls *list);
int	print(ls **list, int *flags);
int	print_rev(ls *node, int *flags);
ls	*print_rec(ls *list, int type, int *flags);
int	print_basic(ls *node, int *flags);

//pre-wash (flags.c)
int	flag_check(char **av, int *flags);
int	parse(char **av, int *flags, char **directories, char **files);
int	is_valid(char *av_i, int *flags);
int	init_directories(char **directories, ls **behemoth);
int	init(char **files, char **directories, ls **behemoth);

//cleanup (cleans.c)
void	clean(ls **list);
void	clean_one(ls *head);
void	clean_string(char **string);

//helpers (helpers.c)
int	is_d(char *name);
int	is_file(char *name);
int	push(char **container, char *item);
int	print_invalid();
int	print_illegal(char c);

//long-print (long.c)
int	print_permissions(ls *node);
int	print_user(ls *node);
int	print_size(ls *node);
int	print_date_modded(ls *node);
char *ls_perms(int mode);
int filetypeletter(int mode);

//sort (sorts.c)
ls	*sort(ls *list, int type);
ls	*sorter(ls *list, ls *head, int type);
int	count_nodes(ls *temp);
ls	*compare(ls *head, ls *temp, int type);
ls	*update_sort(ls *sort, ls *head);
#endif
