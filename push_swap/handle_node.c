/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:47:55 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/15 17:49:34 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	insert_node(t_stack *stack, t_node *node)
{
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
		stack->size++;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
		stack->size++;
	}
}

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit_with_err();
	new_node->data = data;
	new_node->idx = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	insert(t_stack *a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		insert_node(a, create_node(ft_atoi(argv[i])));
		i++;
	}
}
