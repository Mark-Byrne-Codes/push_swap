/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:57:50 by mbyrne            #+#    #+#             */
/*   Updated: 2024/12/13 08:57:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (stack_a)
	{
		best_match = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->nbr < stack_a->nbr
				&& current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			stack_a->target = find_max(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	init_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	index(stack_a);
	index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_check(stack_a, stack_b);
	cheapest_check(stack_a);
}
