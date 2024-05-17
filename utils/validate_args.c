/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:16:30 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/17 04:49:40 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	has_duplicates(char **arr, char *value)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (arr[i] && cnt <= 1)
	{
		if (ft_strcmp(arr[i], value) == 0)
			cnt++;
		i++;
	}
	if (cnt == 1)
		return (0);
	else
		return (1);
}

int	validate_input(char *str)
{
	int		i;
	char	*nbr;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	nbr = ft_itoa(ft_atoi(str));
	if (ft_strncmp(str, nbr, ft_strlen(str)) != 0)
	{
		free(nbr);
		return (0);
	}
	free(nbr);
	return (1);
}

int	is_sorted(t_stack *stack, int size)
{
	int		i;
	t_node	*tmp;

	tmp = stack->head;
	i = 0;
	while (i < size - 1)
	{
		if (tmp->data < tmp->next->data)
			;
		else
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
