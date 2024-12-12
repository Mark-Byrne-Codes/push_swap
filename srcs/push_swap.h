#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
    long nbr;
    long index;
    struct s_stack *next;
    struct s_stack *prev;
}   t_stack;

void	ft_check_args(int argc, char **argv);
void ft_error(void);

#endif