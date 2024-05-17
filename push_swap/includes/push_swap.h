/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:28:57 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/17 06:51:39 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./includes.h"

//index_node.c
void	indexing_node(t_stack *stack, int *arr);
int		*preprecess_stack(t_stack *stack, int size);

//sort_arr.c
void	copy_array(int *arr, int start, int end, int *dest);
void	set_local(int *i, int *j, int *k, int l);
void	merge(int *arr, int l, int m, int r);
void	merge_sort(int *arr, int l, int r);

//sort_stack.c
int		chunk_rotate(t_stack *stack, int chunk_value);
int		get_chunk(int size);
void	a_to_b(t_stack *a, t_stack *b, int chunk, int i);
int		get_location(t_stack *b);
void	b_to_a(t_stack *a, t_stack *b);

//sort_stack_3_5.c
void	sort_3(t_stack *a);
void	pre_sort_5(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

#endif