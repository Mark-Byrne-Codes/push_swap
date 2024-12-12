/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:42:09 by codespace         #+#    #+#             */
/*   Updated: 2024/12/12 12:05:01 by codespace        ###   ########.fr       */
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
t_stack *initialize_stack(char **argv, int argc)
{
    t_stack *stack_a = NULL;
    t_stack *new_node;
    long num;
    int i = 0;

    if (argc == 2)
        argv = ft_split(argv[1], ' ');

    while (argv[i])
    {
        num = ft_atoi(argv[i]);
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
        {
            ft_free(argv);
            return (NULL);
        }
        new_node->nbr = num;
        new_node->index = -1;
        new_node->next = stack_a;
        if (stack_a)
            stack_a->prev = new_node;
        new_node->prev = NULL;
        stack_a = new_node;
        i++;
    }
    if (argc == 2)
        ft_free(argv);
    return (stack_a);
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