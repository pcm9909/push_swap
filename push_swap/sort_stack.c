/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:02:33 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/15 18:05:38 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	chunk_rotate(t_stack *deque, int chunk_value)
{
	t_node	*p;
	int		i;

	i = 0;
	p = deque->head;
	while (p->idx > chunk_value)
	{
		p = p->next;
		i++;
	}
	if (i <= deque->size / 2)
		return (1);
	return (-1);
}

int	get_chunk(int size)
{
	return (0.000000053 * size * size + 0.03 * size + 14.5);
}

void	a_to_b(t_stack *a, t_stack *b, int chunk, int i)
{
	int	head;

	while (a->size != 0)
	{
		head = a->head->idx;
		if (head <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((head > i) && (head <= i + chunk))
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (head > i + chunk)
		{
			if (chunk_rotate(a, i + chunk) > 0)
				ra(a);
			else
				rra(a);
		}
	}
}

int	get_location(t_stack *b)
{
	t_node	*p;
	int		i;

	p = b->head;
	i = 0;
	while (p->idx != b->size - 1)
	{
		p = p->next;
		i++;
	}
	if (i <= (b->size - 1) / 2)
		return (1);
	return (-1);
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int	location;

	while (b->size != 0)
	{
		location = get_location(b);
		if (location > 0)
		{
			while (b->head->idx != b->size - 1)
				rb(b);
		}
		else
		{
			while (b->head->idx != b->size -1)
				rrb(b);
		}
		pa(a, b);
	}
}
