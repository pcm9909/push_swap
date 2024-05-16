/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:11:50 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/16 21:12:28 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./func.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	tmp->prev = stack->head;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	if (tmp->next)
		tmp->next->prev = tmp;
}

void	sa(t_stack *a)
{
	swap(a);
}

void	sb(t_stack *b)
{
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
