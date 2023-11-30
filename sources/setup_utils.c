/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:51:21 by svidot            #+#    #+#             */
/*   Updated: 2023/11/30 11:54:37 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void del_arg(char *argv[])
{
	while (*++argv)
		*argv = *(argv + 1);
}

static int has_twins(int argc, int *args_arr, int tocheck)
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

static int is_overflow(char *s)
{
	long nbr;
	int isneg;

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

static void free_stdargv(char **stdargv)
{
	int i;

	i = 0;
	while (stdargv[i])
		free(stdargv[i++]);
	free(stdargv);
}

static char **make_stdargv(int *argc, char *argv[], char *argv_save[])
{
	char **stdargv_save;
	char **split_save;
	char **stdargv;
	char **split;
	size_t n_word;

	n_word = 0;
	while (*argv)
		n_word += ft_wc(*argv++);
	*argc = n_word;
	stdargv = (char **)ft_calloc(sizeof(char *), n_word + 1);
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

static void init_args_arr(int argc, char *argv[], int **args_arr)
{
	*args_arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!*args_arr)
	{
		free_stdargv(argv);
		exit(1);
	}
	while (*++argv)
		*(*args_arr)++ = ft_atoi(*argv);
	*args_arr = (*args_arr) - (argc - 1);
}