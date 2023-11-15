/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:30:47 by marvin            #+#    #+#             */
/*   Updated: 2023/11/12 19:30:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static int	has_twins(int *args, int argc, int tocheck)
{	
	int res;

	res = 0;
	while (argc--)
	{   
		if (args[argc] == tocheck)
			res++;
		if (res >= 2)
			return (res);	
	}
	return (0);
}

static int	is_overflow(char *s)
{
	long	nbr;
	int		isneg;

	nbr = 0;
	isneg = 0;	
	if (*s == '-' && ++isneg)
		s++;
	else if (*s == '+')
		s++;
	while (*s)
	{
		nbr = nbr * 10 + *s++ - 48;
		if (nbr - isneg > INT_MAX)
			return (1);
	}
	return (0);
}

static void	epur_input(char	**s)
{
	int	len;
	
	len = ft_strlen(*s);
	while (--len && ft_isspace((*s)[len]))
		(*s)[len] = 0;
	while (ft_isspace(**s) && *(*s + 1))
		(*s)++;
}

static void	init_args_arr(int **args, char *argv[],  int argc)
{
	*args = (int *) malloc(sizeof(int) * (argc - 1));	
	while (*++argv)	
		*(*args)++ = ft_atoi(*argv);
	*args = (*args) - (argc - 1);	
}


int	setup(char *argv[], char *argv_save[], int **args, int argc)
{
	char	*s;	
	int		i;

	while (*++argv)
	{ 
		s = *argv;
		epur_input(&s);
		if ((*s == '-' || *s == '+') && ft_isdigit(*(s + 1)))
			s++;
		while (*s++)		
			if (!ft_isdigit(*(s - 1)))
				return (0);
		if (is_overflow(*argv) || !**argv)
			return (0);		
	}
	init_args_arr(args, argv_save, argc);
	i = 0;
	argv = argv_save;
	while (*++argv)	
		if (has_twins(*args, argc - 1, (*args)[i++]))
			return (free(*args), 0);	
	return (1);
}

