/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:51:28 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/16 23:51:24 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

//sort_arr.c
void	merge(int *arr, int l, int m, int r);
void	merge_sort(int *arr, int l, int r);

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

//process_input.c
void	execute_command(char *str, t_stack *a, t_stack *b);
void	process_command(t_stack *a, t_stack *b, int size);

#endif
