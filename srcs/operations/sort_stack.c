/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:40:49 by codespace         #+#    #+#             */
/*   Updated: 2024/12/20 11:45:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// Moves the cheapest node from stack_a to stack_b
static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack	*cheapest_node;

    if (!stack_a || !*stack_a || !stack_b)
        return;

    cheapest_node = get_cheapest(*stack_a);
    if (!cheapest_node || !cheapest_node->target)
        return ;
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

static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !*stack_a || !stack_b || !*stack_b)
        return;

    prep_for_push(stack_a, (*stack_b)->target, 'a');
    pa(stack_a, stack_b, false);
}

static void	min_on_top(t_stack **stack_a)
{
    if (!stack_a || !*stack_a)
        return;

    while ((*stack_a)->nbr != find_min(*stack_a)->nbr)
    {
        if (find_min(*stack_a)->above_median)
            ra(stack_a, false);
        else
            rra(stack_a, false);
    }
}

void	sort_stacks(t_stack **a, t_stack **b)
{
    int	len_a;

    len_a = stack_len(*a);
    ft_printf("len_a: %d\n", len_a);
    if (len_a-- > 3 && !stack_sorted(*a))
        pb(b, a, false);
    ft_printf("works here first if");
    if (len_a-- > 3 && !stack_sorted(*a))
        pb(b, a, false);
    ft_printf("works here second if");
    while (len_a-- > 3 && !stack_sorted(*a))
    {
        ft_printf("works here while loop");
        init_nodes_a(*a, *b);
        move_a_to_b(a, b);
    }
    sort_three(a);
    while (*b)
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}