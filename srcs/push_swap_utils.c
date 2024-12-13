/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:37:04 by codespace         #+#    #+#             */
/*   Updated: 2024/12/13 10:02:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int stack_len(t_stack *stack)
{
    int count;

    if (!stack)
        return (0);
    count = 0;
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);       
}

t_stack *find_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

bool    stack_sorted(t_stack *stack)
{
    if(!stack)
        return (1);
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}   