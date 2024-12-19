/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:34:10 by codespace         #+#    #+#             */
/*   Updated: 2024/12/19 06:39:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swaps the first two nodes of the stack
static void	swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

// Swaps the first two nodes of stack a
void	sa(t_stack	**stack_a, bool print)
{
	swap(stack_a);
	if (!print)
		ft_printf("sa\n");
}


// Swaps the first two nodes of stack b
void	sb(t_stack **stack_b, bool print)
{
	swap(stack_b);
	if (!print)
		ft_printf("sb\n");
}

// Swaps the first two nodes of both stacks
void	ss(t_stack **stack_a, t_stack **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (!print)
		ft_printf("ss\n");
}