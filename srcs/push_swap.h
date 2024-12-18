/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:42:12 by codespace         #+#    #+#             */
/*   Updated: 2024/12/18 10:10:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
    int     nbr;
    int     index;
    bool    cost;
    bool    above_median;
    bool    cheapest;
    struct  s_stack *target;
    struct  s_stack *next;
    struct  s_stack *prev;
}   t_stack;

//Handle Errors
int	valid_numbers(char *str);
int	error_dup(t_stack *stack_a, int n);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **stack_a);

//Stack Initialization
void	init_stack_a(t_stack **stack_a, char **argv);

//

#endif