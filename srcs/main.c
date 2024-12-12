/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:42:05 by codespace         #+#    #+#             */
/*   Updated: 2024/12/12 10:00:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv) {
    t_stack stack_a;
    t_stack stack_b;

    if (argc < 2)
        return (-1);
    ft_check_args(argv, argc);
    push_swap(argv, &stack_a, &stack_b);
    
    return 0;
}