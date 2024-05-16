/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:28:04 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/16 23:51:38 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

static void	validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		exit_with_err();
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
	int	sorted;

	insert(a, argv);
	arr = preprecess_stack(a, a->size);
	merge_sort(arr, 0, a->size - 1);
	indexing_node(a, arr);
	free(arr);
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
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		size;

	if (argc < 2)
		exit_with_err();
	i = update_args(&argv);
	if (i == 0 && argc != 2)
		exit_with_err();
	validate_args(argc, argv);
	a = init_stack();
	b = init_stack();
	process_stack(a, argv);
	size = a->size;
	process_command(a, b, size);
	free_resources(a, b, argv, i);
}
