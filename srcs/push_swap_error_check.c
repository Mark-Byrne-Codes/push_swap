/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:42:02 by codespace         #+#    #+#             */
/*   Updated: 2024/12/12 09:42:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

static void ft_free(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static int	ft_contains(long num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(const char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	args = argv;
	i = 1;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		i = 0;
	}
	while (args[i])
	{
		if (!ft_isnum(args[i]))
			ft_error();
		tmp = ft_atoi(args[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_error();
		if (ft_contains(tmp, args, i))
			ft_error();
		i++;
	}
	if (argc == 2)
		ft_free(args);
}



int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_putstr_fd("Usage: ./push_swap <numbers>\n", 1);
        return (1);
    }
    ft_check_args(argc, argv);

    ft_putstr_fd("Arguments are valid!\n", 1);
    return (0);
}

