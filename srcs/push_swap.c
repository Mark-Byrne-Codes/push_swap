/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:42:09 by codespace         #+#    #+#             */
/*   Updated: 2024/12/12 10:05:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack(char **argv, t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int j;
    long num;

    i = 1;
    while (argv[i])
    {
        num = ft_atoi(argv[i]);
        stack_b = malloc(sizeof(t_stack));
        if (!stack_b)
            ft_error();
        stack_b->nbr = num;
        stack_b->index = i - 1;
        stack_b->next = NULL;
        stack_b->prev = NULL;
        stack_b->next = stack_a;
        stack_a->prev = stack_b;
        stack_a = stack_b;
        i++;
    }
}

void push_swap(char **argv, long *stack_a, long *stack_b) {
    *stack_a = 0;
    *stack_b = 0;
    sort_stack(argv, stack_a, stack_b);
    if(is_sorted(stack_a, stack_b))
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
}