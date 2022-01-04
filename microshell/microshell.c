#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SIDE_OUT	0
#define SIDE_IN		1

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_BREAK	2

typedef struct s_list
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
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	show_error(char const *str)
{
	if (str)
		write(STDERR, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int	exit_fatal(void)
{
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	*exit_fatal_ptr(void)
{
	show_error();
	exit(EXIT_FAILURE);
	return (NULL);
}

char	*ft_strdup(char const *str)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return (exit_fatal_ptr());
	i = -1;
	while (str[++i])
		copy[i] = str[i];
	copy[i] = 0;
	return (copy);
}

int	add_arg(t_list *cmd, char *arg)
{
	char	**tmp;
	int		i;

	tmp = NULL;
	tmp = malloc(sizeof(char *) * (cmd->length + 2));
	if (!tmp)
		return (exit_fatal());
	i = -1;
	while (++i < cmd->length)
		tmp[i] = cmd->args[i];
	if (cmd->length > 0)
		free(cmd->args);
	cmd->args = tmp;
	cmd->args[i++] = ft_strdup(arg);
	cmd->args[i] = 0;
	cmd->length++;
	return (EXIT_SUCCESS);
}


