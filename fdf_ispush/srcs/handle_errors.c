/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:41:07 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/31 20:16:59 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		error(char *err, char *all, t_fdf *fdf)
{
	if (all != NULL)
		ft_strdel(&all);
	if (fdf != NULL)
	{
		ft_memdel((void**)&fdf->map);
		ft_memdel((void**)&fdf);
	}
	ft_putstr(err);
	exit(EXIT_FAILURE);
}
