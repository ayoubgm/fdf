/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 04:51:50 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:50:12 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 32
# define SWAP_FREE(x, y, z) x = y; y = z; free(x);

typedef struct		s_line
{
	int				fd;
	char			*save;
	struct s_line	*next;
}					t_line;

int					get_next_line(const	int	fd, char **line);
#endif
