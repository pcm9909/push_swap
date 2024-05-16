/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:28:57 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/16 03:03:40 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../func/func.h"
# include "./includes.h"

//exit_msg.c
void	exit_with_err(void);

//handle_node.c
void	insert_node(t_stack *stack, t_node *node);
t_node	*create_node(int data);
void	insert(t_stack *a, char **argv);

//handle_stack.c
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);

//index_node.c
void	indexing_node(t_stack *stack, int *arr);
int		*preprecess_stack(t_stack *stack, int size);
void	copy_array(int arr[], int start, int end, int dest[]);
void	merge(int arr[], int l, int m, int r);
void	merge_sort(int arr[], int l, int r);

//sort_stack_3_5.c
void	sort_3(t_stack *stack);
void	pre_sort_5(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

//sort_stack.c
int		chunk_rotate(t_stack *deque, int chunk_value);
int		get_chunk(int size);
void	a_to_b(t_stack *a, t_stack *b, int chunk, int i);
int		get_location(t_stack *b);
void	b_to_a(t_stack *a, t_stack *b);

//split_stack.c
int		ps_count_words(const char *s, char c);
char	**ps_free_arr(char **arr, size_t i);
char	**ps_split(char const *s, char c);
int		update_args(char ***argv);

//validate_args.c
int		ft_strcmp(char *s1, char *s2);
int		has_duplicates(char **arr, char *value);
int		validate_input(char *str);
int		is_sorted(t_stack *stack, int size);

#endif
