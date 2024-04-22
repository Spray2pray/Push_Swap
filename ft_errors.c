/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbamatra <mbamatra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:05:47 by mbamatra          #+#    #+#             */
/*   Updated: 2024/04/21 06:31:49 by mbamatra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clearlst(t_stack_node **lst)
{
	t_stack_node	*current;
	t_stack_node	*nextone;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		nextone = current->next;
		free(current);
		current = nextone;
	}
	*lst = NULL;
}

void	exit_error(t_stack_node *a, t_stack_node *b)
{
	if (a)
		clearlst(&a);
	if (b)
		clearlst(&b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	exit_success(t_stack_node *a, t_stack_node *b)
{
	if (a)
		clearlst(&a);
	if (b)
		clearlst(&b);
	exit(EXIT_SUCCESS);
}

int	free_ptr(char **ptr)
{
	if (!ptr || !*ptr)
		return (0);
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (1);
}

void	free_arr(char ***arr)
{
	int	i;

	i = 0;
	if (arr || *arr)
		return ;
	while ((**arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}
