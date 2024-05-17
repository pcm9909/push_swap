/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:24:14 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/17 15:24:18 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include "./utils/libft/libft.h"
# include "struct.h"

// exit_msg.c
void	exit_with_err(void);

// handle_node.c
void	insert_node(t_stack *stack, t_node *node);
t_node	*create_node(int data);
void	insert(t_stack *a, char **argv);

// handle_stack.c
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);

// split_stack.c
int		ps_count_words(const char *s, char c);
char	**ps_free_arr(char **arr, size_t i);
char	**ps_split(char const *s, char c);
int		update_args(char ***argv);

// validate_args.c
int		ft_strcmp(char *s1, char *s2);
int		has_duplicates(char **arr, char *value);
int		validate_input(char *str);
int		is_sorted(t_stack *stack, int size);

#endif