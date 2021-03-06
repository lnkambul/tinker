/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:23:12 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/14 09:20:51 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	main(int ac, char **av)
{
	int			flags;
	t_lust		*behemoth;
	t_cont		*nonexistent;

	flags = 0;
	if (ac > 1)
		if (!flag_check(av, &flags))
			return (0);
	behemoth = NULL;
	nonexistent = NULL;
	parse(av, &flags, behemoth, nonexistent);
	return (0);
}
