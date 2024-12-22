/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:40:47 by codespace         #+#    #+#             */
/*   Updated: 2024/12/22 12:17:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Handles sorting stack_a when it has exactly three nodes
void	sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a, false);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a, false);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a, false);
}
