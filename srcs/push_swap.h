/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:42:12 by codespace         #+#    #+#             */
/*   Updated: 2024/12/13 06:49:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
    int nbr;
    int index;
    bool cost;
    bool above_median;
    bool cheapest;
    struct s_stack *target;
    struct s_stack *next;
    struct s_stack *prev;
}   t_stack;

//Handle Errors


#endif