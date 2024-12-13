/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:57:50 by mbyrne            #+#    #+#             */
/*   Updated: 2024/12/13 08:33:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	index(stack_a);
	index(stack_b);
	set_target(stack_a, stack_b);
	cost_check(stack_a, stack_b);
	cheapest_check(stack_a);
}
