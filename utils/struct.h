/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:24:23 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/17 15:24:25 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_node
{
	struct s_node	*prev;
	int				data;
	int				idx;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}				t_stack;

#endif