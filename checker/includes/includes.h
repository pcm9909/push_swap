/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:48:27 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/16 20:51:16 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../utils/libft/libft.h"
# include "../utils/get_next_line/get_next_line.h"

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
