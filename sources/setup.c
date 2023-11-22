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
#include "operations.h"
#include <stdlib.h>
#include <limits.h>

static int	has_twins(int argc, int *args_arr, int tocheck)
{	
	int res;

	res = 0;
	while (argc--)
	{   
		if (args_arr[argc] == tocheck)
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

static void	free_stdargv(char **stdargv)
{
	int i;

	i = 0;
	while (stdargv[i])	
		free(stdargv[i++]);	
	free(stdargv);
}

static void	init_args_arr(int argc, char *argv[], int **args_arr)
{
	*args_arr = (int *) malloc(sizeof(int) * (argc - 1));
	if (!*args_arr)
	{
		free_stdargv(argv);
		exit(1);
	}
	while (*++argv)	
		*(*args_arr)++ = ft_atoi(*argv);
	*args_arr = (*args_arr) - (argc - 1);	
}

static char	**make_stdargv(int *argc, char *argv[], char *argv_save[])
{
	char	**stdargv_save;
	char 	**split_save;
	char	**stdargv;
	char	**split;
	size_t	n_word;

	n_word = 0;
	while (*argv)	
		n_word += ft_wc(*argv++);	
	*argc = n_word;		
	stdargv = (char **) ft_calloc(sizeof(char *), n_word + 1);
	if (!stdargv)
		exit(1);
	stdargv_save = stdargv;	
	while (*argv_save)
	{
		split = ft_split(*argv_save++, 32);
		split_save = split;
		while (*split)		
			*stdargv++ = *split++;			
		free(split_save);
	}
	return (stdargv_save);	
}

void	init_list(t_list **lst, int argc, int *args_arr)
{
	int		*args_arr_save;
	t_list	*new;

	args_arr_save = args_arr;
	while (--argc)
	{			
		new = ft_lstnew((void *) args_arr++);
		if (!new)
		{
			free(args_arr_save);
			ft_lstclear(lst, NULL);
			exit(1);
		}
		ft_lstadd_back(lst, new);
	}		
}

void	init_op_arr_simpl(int (*op_arr[]) (t_list **, t_list **, int))
{			
	op_arr[SB_SIMPL] = sb;	
	op_arr[RB_SIMPL] = rb;
	op_arr[RRB_SIMPL] = rrb;	
}

void	init_op_arr(int (*op_arr[]) (t_list **, t_list **, int))
{
	op_arr[PA] = pa;
	op_arr[PB] = pb;	
	op_arr[SA] = sa;
	op_arr[SB] = sb;
	op_arr[SS] = ss;
	op_arr[RA] = ra;
	op_arr[RB] = rb;
	op_arr[RR] = rr;
	op_arr[RRA] = rra;
	op_arr[RRB] = rrb;
	op_arr[RRR] = rrr;	
}

void	init_op_char_arr(char **op_char_arr)
{
	op_char_arr[PA] = "pa\n";
	op_char_arr[PB] = "pb\n";
	op_char_arr[SA] = "sa\n";
	op_char_arr[SB] = "sb\n";
	op_char_arr[SS] = "ss\n";
	op_char_arr[RA] = "ra\n";
	op_char_arr[RB] = "rb\n";
	op_char_arr[RR] = "rr\n";
	op_char_arr[RRA] = "rra\n";
	op_char_arr[RRB] = "rrb\n";
	op_char_arr[RRR] = "rrr\n";
}

void	init_op_char_arr_simpl(char **op_char_arr)
{	
	op_char_arr[SB_SIMPL] = "sb\n";
	op_char_arr[RB_SIMPL] = "rb\n";
	op_char_arr[RRB_SIMPL] = "rrb\n";
}

int	setup(int *argc, char *argv[], char *argv_save[], int **args_arr)
{
	char	*s;	
	int		i;

	argv = make_stdargv(argc, argv, argv);
	argv_save = argv;	
	while (*++argv)
	{ 
		s = *argv;		
		if ((*s == '-' || *s == '+') && ft_isdigit(*(s + 1)))
			s++;
		while (*s++)		
			if (!ft_isdigit(*(s - 1)))
				return (free_stdargv(argv_save), 0);
		if (is_overflow(*argv) || !**argv)
			return (free_stdargv(argv_save), 0);		
	}
	init_args_arr(*argc, argv_save, args_arr);
	i = 0;
	argv = argv_save;
	while (*++argv)	
		if (has_twins(*argc - 1, *args_arr, (*args_arr)[i++]))
			return (free(*args_arr), free_stdargv(argv_save), 0);
	free_stdargv(argv_save);
	return (1);
}

