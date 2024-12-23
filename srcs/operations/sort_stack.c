/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:40:49 by codespace         #+#    #+#             */
/*   Updated: 2024/12/22 12:17:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// Moves the cheapest node from stack_a to stack_b
static void	move_cheapest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median
		&& cheapest_node->target->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target, 'b');
	pb(stack_b, stack_a, false);
}

// Moves the top node from stack_b back to its target position in stack_a
static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b, false);
}

// Moves the smallest number in stack_a to the top
static void	bring_min_to_top(t_stack **stack_a)
{
	while ((*stack_a)->nbr != find_min(*stack_a)->nbr)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}

// Sorts stack_a
void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !is_stack_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	while (len_a-- > 3 && !is_stack_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_cheapest_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	bring_min_to_top(stack_a);
}
