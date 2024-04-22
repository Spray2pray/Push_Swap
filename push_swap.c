/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbamatra <mbamatra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:09:51 by mbamatra          #+#    #+#             */
/*   Updated: 2024/04/21 06:33:32 by mbamatra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	print_asd(char **split)
// {
// 	int	i;

// 	i = 0;
// 	printf("(");
// 	while (split[i])
// 	{
// 		printf("%s ", split[i]);
// 		i++;
// 	}
// 	printf(")\n");

// }

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

char	*build_avs_str(char **argv)
{
	static char		*tmp;
	static char		*avs_str;
	int				i;

	i = -1;
	avs_str = NULL;
	while (argv[++i])
	{
		if (!avs_str)
		{
			avs_str = ft_strdup(argv[i]);
			if (!avs_str)
				exit_error(NULL, NULL);
		}
		else
		{
			tmp = ft_strjoin(avs_str, " ");
			if (free_ptr(&avs_str) && !tmp)
				exit_error(NULL, NULL);
			avs_str = ft_strjoin(tmp, argv[i]);
			if (free_ptr(&tmp) && !avs_str)
				exit_error(NULL, NULL);
		}
	}
	return (avs_str);
}


void	free_argvs(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	char		*avs_str;
	// int			 i = 0;
	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	onlyspaces(argc, argv);
	avs_str = build_avs_str(++argv);
	if (!avs_str)
		exit_error(NULL, NULL);
	argv = ft_split(avs_str, ' ');
	free(avs_str);
	// free_ptr(&avs_str);
	init_stack_a(&a, argv);
	// free_arr(&argv);
	free_argvs(argv);
	// free(argv);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	exit_success(a, b);
	return(0);
}
