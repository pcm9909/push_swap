/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:49:54 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/16 17:23:18 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	indexing_node(t_stack *stack, int *arr)
{
	t_node	*tmp;
	int		i;
	int		idx;
	int		node_count;

	tmp = stack->head;
	i = 0;
	idx = 0;
	node_count = 0;
	while (node_count < stack->size)
	{
		i = 0;
		while (arr[i] != tmp->data)
			i++;
		tmp->idx = i;
		tmp = tmp->next;
		node_count++;
	}
}

int	*preprecess_stack(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	t_node	*tmp;

	tmp = stack->head;
	arr = (int *)malloc(sizeof(int) * (size));
	if (!arr)
		exit_with_err();
	i = 0;
	while (i < size)
	{
		arr[i] = tmp->data;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
		i++;
	}
	return (arr);
}
