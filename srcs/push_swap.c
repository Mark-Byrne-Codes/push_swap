/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:42:09 by codespace         #+#    #+#             */
/*   Updated: 2024/12/12 09:42:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack(char **argv, long *stack_a, long *stack_b)
{
    
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