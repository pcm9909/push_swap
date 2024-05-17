/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:11:17 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/17 15:11:20 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	execute_command_1(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(str, "ss\n") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(str, "pa\n") == 0)
		push(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(b, a);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(str, "rr\n") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else
		execute_command_2(str, a, b);
}

void	execute_command_2(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		exit_with_err();
}

void	process_command(t_stack *a, t_stack *b, int size)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			if (is_sorted(a, size) == 1)
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
			return ;
		}
		execute_command_1(str, a, b);
		free(str);
	}
}
