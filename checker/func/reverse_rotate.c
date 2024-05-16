/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:09:15 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/16 21:10:45 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./func.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = stack->head;
	stack->head->prev = tmp;
	stack->head = tmp;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
