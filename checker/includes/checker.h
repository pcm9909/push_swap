/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:51:28 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/17 05:40:37 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./includes.h"

//process_input.c
void	execute_command_1(char *str, t_stack *a, t_stack *b);
void    execute_command_2(char *str, t_stack *a, t_stack *b);
void	process_command(t_stack *a, t_stack *b, int size);

#endif
