/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbamatra <mbamatra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:29:53 by mbamatra          #+#    #+#             */
/*   Updated: 2024/04/21 08:02:56 by mbamatra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_stack_node **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->content != find_min(*a)->content) //As long as the smallest number is not at the top
	{
		if (find_min(*a)->above_med)
			ra(a);
		else
			rra(a);
	}
}

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	a->push_cost = 0;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_med))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_med)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}