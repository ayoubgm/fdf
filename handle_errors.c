/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:41:07 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/18 14:10:53 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        error(char *err)
{
    ft_putstr(err);
    exit(0);
}