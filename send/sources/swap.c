/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 06:52:16 by svidot            #+#    #+#             */
/*   Updated: 2023/12/04 06:52:16 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	swap_data(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	swap(t_list *lst)
{
	if (lst && lst->next)
	{
		swap_data(&lst->content, &lst->next->content);
		return (1);
	}
	return (0);
}

int	sa(t_list **la, t_list **lb, int wflag)
{
	(void) lb;
	if (wflag)
		write(1, "sa\n", 3);
	return (swap(*la));
}

int	sb(t_list **la, t_list **lb, int wflag)
{
	(void) la;
	if (wflag)
		write(1, "sb\n", 3);
	return (swap(*lb));
}

int	ss(t_list **la, t_list **lb, int wflag)
{
	if (wflag)
		write(1, "ss\n", 3);
	if (swap(*la))
	{
		if (swap(*lb))
			return (1);
		else
		{
			swap(*la);
			return (0);
		}
	}
	return (0);
}
