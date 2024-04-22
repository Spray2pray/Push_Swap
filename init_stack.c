/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbamatra <mbamatra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:28:07 by mbamatra          #+#    #+#             */
/*   Updated: 2024/04/21 08:10:01 by mbamatra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long		ft_atoi(const char *str)
{
	int								sign;
	int								counter;
	unsigned long long				result;

	result = 0;
	counter = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign *= -1;
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9') || counter++ > 10)
				return(2147483648);
		if (result > LLONG_MAX / 10 || (result == LLONG_MAX / 10
				&& (*str - '0') > LLONG_MAX % 10))
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		result = result * 10 + (*(str++) - '0');
	}
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->prev = NULL;
	node->content = n;
	node->next = NULL;
	node->target_node = NULL;
	// node->index = 0;
	// node->push_cost = 0;
	node->above_med = false;
	node->cheapest = false;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	// print_stack(*a);
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a, argv);
		n = ft_atoi(argv[i]);
		if (n == 2147483648 || n > INT_MAX || n < INT_MIN)
			free_errors(a, argv);
		if (error_duplicate(*a, (int)n))
			free_errors(a, argv);
		append_node(a, (int)n);
		i++;
	}
	// while(argv[j])
	// 	free(argv[j++]);
	// free(argv);
}


t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

// void	init_struct(t_stack_node *node)
// {
// 	node->prev = NULL;
// 	node->next = NULL;
// 	node->target_node = NULL;
// 	// node->content = n;
// 	node->index = 0;
// 	node->push_cost = 0;
// 	node->above_med = false;
// 	node->cheapest = false;
// }
// int	lst_max(t_stack_node *stack)
// {
// 	int	max;

// 	max = INT_MIN;
// 	while (stack)
// 	{
// 		if (stack->content > max)
// 			max = stack->content;
// 		stack = stack->next;
// 	}
// 	return (max);
// }

// void	print_stack(t_stack_node *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d ", stack->content);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }


void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_med)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_med)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}