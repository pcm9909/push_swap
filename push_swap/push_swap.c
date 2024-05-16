/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:43:00 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/15 18:23:31 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!validate_input(argv[i]) || has_duplicates(argv, argv[i]))
			exit_with_err();
		i++;
	}
}

static void	process_stack(t_stack *a, char **argv)
{
	int	*arr;

	insert(a, argv);
	is_sorted(a, a->size);
	arr = preprecess_stack(a, a->size);
	merge_sort(arr, 0, a->size - 1);
	indexing_node(a, arr);
	free(arr);
}

static void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		sort_3(a);
	if (a->size == 5)
		sort_5(a, b);
	a_to_b(a, b, get_chunk(a->size), 0);
	b_to_a(a, b);
}

static void	free_resources(t_stack *a, t_stack *b, char **argv, int i)
{
	if (i == 0)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(1);
	i = update_args(&argv);
	if (i == 0 && argc != 2)
		exit_with_err();
	validate_args(argc, argv);
	a = init_stack();
	b = init_stack();
	process_stack(a, argv);
	sort_stack(a, b);
	free_resources(a, b, argv, i);
}
