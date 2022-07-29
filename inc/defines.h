/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <aitoraudicana@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:41:33 by aitoraudica       #+#    #+#             */
/*   Updated: 2022/07/29 17:51:11 by aitoraudica      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*pre;
}					t_stack;
#endif