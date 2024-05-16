/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:05:52 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/15 20:30:58 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->head->idx < stack->head->next->idx)
	{
		rra(stack);
		if (stack->head->idx > stack->head->next->idx)
			sa(stack);
	}
	else if (stack->head->idx - 1 == stack->head->next->idx)
	{
		sa(stack);
		if (stack->head->idx == 1)
			rra(stack);
	}
	else
		ra(stack);
	exit(1);
}

void	pre_sort_5(t_stack *a, t_stack *b)
{
	if (a->head->idx != 0 && a->head->next->idx != 0
		&& a->head->next->next->idx != 0)
	{
		while (a->head->idx != 0)
			rra(a);
	}
	else
	{
		while (a->head->idx != 0)
			ra(a);
	}
	pb(a, b);
	if (a->head->idx != 1 && a->head->next->idx != 1)
	{
		while (a->head->idx != 1)
			ra(a);
	}
	else
	{
		while (a->head->idx != 1)
			rra(a);
	}
	pb(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	pre_sort_5(a, b);
	if (a->head->idx < a->head->next->idx)
	{
		rra(a);
		if (a->head->idx > a->head->next->idx)
			sa(a);
	}
	else if (a->head->idx - 1 == a->head->next->idx)
	{
		sa(a);
		if (a->head->idx == 3)
			rra(a);
	}
	else
		ra(a);
	pa(a, b);
	pa(a, b);
	exit(1);
}
