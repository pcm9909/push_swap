/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:06:25 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/16 20:06:35 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	copy_array(int *arr, int start, int end, int *dest)
{
	int	i;

	i = 0;
	while (i < end - start + 1)
	{
		dest[i] = arr[start + i];
		i++;
	}
}

void	set_local(int *i, int *j, int *k, int l)
{
	*i = 0;
	*j = 0;
	*k = l;
}

void	merge(int *arr, int l, int m, int r)
{
	int	i;
	int	j;
	int	k;
	int	*left;
	int	*right;

	set_local(&i, &j, &k, l);
	left = (int *)malloc((m - 1 + 2) * sizeof(int));
	right = (int *)malloc((r - m + 1) * sizeof(int));
	copy_array(arr, l, m, left);
	copy_array(arr, m + 1, r, right);
	while (i < m - l + 1 && j < r - m)
	{
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < m - l + 1)
		arr[k++] = left[i++];
	while (j < r - m)
		arr[k++] = right[j++];
	free(left);
	free(right);
}

void	merge_sort(int *arr, int l, int r)
{
	int	m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
