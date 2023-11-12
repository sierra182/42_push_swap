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

#include "setup.h"

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

static int	init_args_arr(int **args, char *argv[],  int argc)
{
	*args = (int *) malloc(sizeof(int) * (argc - 1));
	
	while (*++argv)	
		*(*args)++ = ft_atoi(*argv);
	*args = (*args) - (argc - 1);	
}

int	has_error(char *argv[], char *argv_save[], int **args, int argc)
{
	char	*s;	
	int		i;

	while (*++argv)
	{ 
		s = *argv;		
		if ((*s == '-' || *s == '+') && ft_isdigit(*(s + 1)))
			s++;
		while (*s++)		
			if (!ft_isdigit(*(s - 1)))
				return (1);
		if (is_overflow(*argv))
			return (1);		
	}
	init_args_arr(args, argv_save, argc);
	i = 0;
	argv = argv_save;
	while (*++argv)	
		if (has_twins(*args, argc - 1, (*args)[i++]))
			return (free(*args), 1);	
	return (0);
}

int	*init_list(t_list **lst, int argc, char *argv[], int *args)
{
	t_list	*new;
	
	while (*++argv)
	{			
		new = ft_lstnew((void *) args++);
		ft_lstadd_back(lst, new);
	}		
}