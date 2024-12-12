/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:42:05 by codespace         #+#    #+#             */
/*   Updated: 2024/12/12 11:58:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (0);

    stack_a = NULL;
    ft_check_args(argv, argc);
    stack_a = initialize_stack(argv, argc);
    if (!stack_a)
        ft_error();
    stack_b = NULL;
    push_swap(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);

    return (0);
}
