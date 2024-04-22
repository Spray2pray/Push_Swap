/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbamatra <mbamatra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:25:32 by mbamatra          #+#    #+#             */
/*   Updated: 2024/04/19 19:02:55 by mbamatra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	onlyspaces(int argc, char **argv)
{
	int i = 1;
	int counter;
	int j;
	while (argc  - 1 >= i)
	{
		counter = 0;
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				counter++;
			j++;
		}
		i++;
		if (j == counter)
		{
			write(2, "Error\n", 6);
			exit(1);	
		}
	}
}

int error_syntax(char *str)
{
	int i = 0;
	if (!str)
		return(1);
	while(str[i])
	{
		if (!(ft_isspace(str[i]) || ft_issign(str[i]) || ft_isdigit(str[i])))
			return(1);
		if ((ft_issign(str[i])) && (!ft_isdigit(str[i + 1])))
			return(1);
		i++;
	}
	return(0);
}

int	error_duplicate(t_stack_node *stack, int n)
{
	if (!stack)
		return(0);
	while (stack)
	{
		if (stack->content == n)
			return(1);
		stack = stack->next;
	}
	return(0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->content = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a, char **argv)
{
	int j;

	j = 0;
	while(argv[j])
		free(argv[j++]);
	free(argv);
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
