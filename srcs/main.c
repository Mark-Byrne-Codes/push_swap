#include "push_swap.h"

int main(int argc, char **argv) {
    long stack_a;
    long stack_b;

    if (argc < 2)
        return (-1);
    argv = parse_args(argc, argv);
    push_swap(argv, &stack_a, &stack_b);
    
    return 0;
}