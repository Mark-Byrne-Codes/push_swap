/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:34:29 by codespace         #+#    #+#             */
/*   Updated: 2024/12/22 12:17:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// Rotates the top node of the stack to the bottom
static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

// Rotates the top node of stack a to the bottom
void	ra(t_stack **stack_a, bool print)
{
	rotate(stack_a);
	if (!print)
		ft_printf("ra\n");
}

// Rotates the top node of stack b to the bottom
void	rb(t_stack **stack_b, bool print)
{
	rotate(stack_b);
	if (!print)
		ft_printf("rb\n");
}

// Rotates the top node of both stacks to the bottom
void	rr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		ft_printf("rr\n");
}

//Rotates both stacks to move their respective target nodes to the top
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
