/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:14:16 by chunpark          #+#    #+#             */
/*   Updated: 2024/05/15 20:28:48 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdlib.h>
# include <unistd.h>
# include "../utils/libft/libft.h"

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
