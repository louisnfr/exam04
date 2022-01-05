#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIDE_OUT	0
#define SIDE_IN		1

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_BREAK	2

typedef struct	s_list
{
	char			**args;
	int				length;
	int				type;
	int				pipes[2];
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

int	ft_strlen(char *str)
{
}

int	show_error(char *str)
{
}

int	exit_fatal(void)
{
}

void	*exit_fatal_ptr(void)
{
}

char	*ft_strdup(char *str)
{
}

int	add_arg(t_list *cmd, char *arg)
{
}

int	list_push(t_list **list, char *arg)
{
}

int	list_rewind(t_list **list)
{
}

int	list_clear(t_list **cmds)
{
}

int	parse_arg(t_list **cmds, char *arg)
{
}

int	exec_cmd(t_list *cmd, char **env)
{
}

int	exec_cmds(t_list **cmds, char **env)
{
}

int	main(int ac, char **av, char **env)
{
}
