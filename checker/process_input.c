#include "./includes/checker.h"

void execute_command(char *str, t_stack *a, t_stack *b)
{
    if (ft_strcmp(str, "sa\n") == 0)
        sa(a);
    else if (ft_strcmp(str, "sb\n") == 0)
        sb(b);
    else if (ft_strcmp(str, "ss\n") == 0)
        ss(a, b);
    else if (ft_strcmp(str, "pa\n") == 0)
        pa(a, b);
    else if (ft_strcmp(str, "pb\n") == 0)
        pb(a, b);
    else if (ft_strcmp(str, "ra\n") == 0)
        ra(a);
    else if (ft_strcmp(str, "rb\n") == 0)
        rb(b);
    else if (ft_strcmp(str, "rr\n") == 0)
        rr(a, b);
    else if (ft_strcmp(str, "rra\n") == 0)
        rra(a);
    else if (ft_strcmp(str, "rrb\n") == 0)
        rrb(b);
    else if (ft_strcmp(str, "rrr\n") == 0)
        rrr(a, b);
    else
        exit_with_err();
}

void process_command(t_stack *a, t_stack *b, int size)
{
    char *str;

    while (1)
    {
        str = get_next_line(0);
        if (!str)
        {
            if (is_sorted(a, size) == 1)
                ft_putstr_fd("OK\n", 1);
            else
                ft_putstr_fd("KO\n", 1);
            return;
        }
        execute_command(str, a, b);
        free(str);
    }
}