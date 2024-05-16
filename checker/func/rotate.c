/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:10:56 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/16 21:11:20 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./func.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = tmp;
	tmp->prev = stack->tail;
	stack->tail = tmp;
	tmp->next = NULL;
}

void	ra(t_stack *a)
{
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
