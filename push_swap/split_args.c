/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:20:01 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/15 20:13:11 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	ps_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ps_free_arr(char **arr, size_t i)
{
	while (i > 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ps_split(char const *s, char c)
{
	char			**arr;
	static int		i;
	static int		j;
	int				k;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ps_count_words(s, c) + 2));
	if (!arr)
		return (NULL);
	while (++i < ps_count_words(s, c) + 1)
	{
		while (s[j] == c)
			j++;
		k = j;
		while (s[j] && s[j] != c)
			j++;
		arr[i] = ft_substr(s, k, j - k);
		if (!arr[i])
			return (ps_free_arr(arr, i));
	}
	arr[0] = ft_strdup("trick");
	arr[i] = NULL;
	return (arr);
}

int	update_args(char ***argv)
{
	if (ft_strchr((*argv)[1], ' '))
	{
		*argv = ps_split((*argv)[1], ' ');
		return (0);
	}
	return (1);
}
