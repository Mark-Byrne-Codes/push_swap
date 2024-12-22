/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:42:12 by codespace         #+#    #+#             */
/*   Updated: 2024/12/22 12:16:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Main functions
void	init_stack_a(t_stack **stack_a, char **argv);
void	sort_three(t_stack **stack_a);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
// Stack utility functions
int		stack_len(t_stack *stack);
t_stack	*find_last(t_stack *stack);
bool	stack_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
// Input validation and error handling
char	**parse_args(int argc, char **argv);
int		valid_numbers(char *str);
int		error_dup(t_stack *stack_a, int n);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);
void	free_split(char **str);
// Stack node preparation
void	init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
// Operations
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);

#endif
