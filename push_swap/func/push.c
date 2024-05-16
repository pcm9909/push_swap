/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:55:37 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/15 17:56:31 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./func.h"

void	push(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!src->head)
		return ;
	tmp = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	dst->size++;
	src->size--;
	if (!dst->head)
	{
		dst->head = tmp;
		dst->tail = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = dst->head;
		dst->head->prev = tmp;
		dst->head = tmp;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
