/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbamatra <mbamatra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:58:29 by mbamatra          #+#    #+#             */
/*   Updated: 2024/04/21 06:28:08 by mbamatra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include "libft/libft.h"
#include <stdio.h>

typedef struct s_stack_node
{
	struct s_stack_node *prev;
	struct s_stack_node *next;
	struct s_stack_node *target_node;
	int	content;
	int index;
	int push_cost;
	bool above_med;
	bool cheapest;
}	t_stack_node;

void			onlyspaces(int argc, char **argv);
int                    error_syntax(char *str); 
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a, char **argv);
void			init_stack_a(t_stack_node **a, char **argv);
char			**ft_split(char const *s, char c);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack); 
t_stack_node	*get_cheapest(t_stack_node *stack);
void	check_stacks(t_stack_node **a, t_stack_node **b);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack); 
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			rev_rotate_both(t_stack_node **a,
				t_stack_node **b,
				t_stack_node *cheapest_node);
void	set_target_b(t_stack_node *a, t_stack_node *b);
void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node);
void move_a_to_b(t_stack_node **a, t_stack_node **b);
void	min_on_top(t_stack_node **a);
void	cost_analysis_a(t_stack_node *a, t_stack_node *b);
void	exit_error(t_stack_node *a, t_stack_node *b);
void	exit_error(t_stack_node *a, t_stack_node *b);
void	exit_success(t_stack_node *a, t_stack_node *b);
int		free_ptr(char **ptr);
void	free_arr(char ***arr);
void	exit_success(t_stack_node *a, t_stack_node *b);
void	clearlst(t_stack_node **lst);
void	print_stack(t_stack_node *stack);
void	free_argvs(char **argv);

#endif

/*


190942 156838 155964 155911 121723 105704 102188 97900 96158 71246 61842 60089 53504 30829 27025 
-8846 -13454 -36271 -53865 -56482 -78735 -78864 -81861 -88521 -94940 -105610 -108686 -118555 -132238 
-137506 -138762 -161021 -166291 -177233 -185843 -201762 -201915 -202241 -204957 -216546 -222081 -225882 
-230524 -236387 -237425 -267693 -278546 -286773 -300229 -300369 -304012 -318543 -331389 -334919 -353810
-355394 -355598 -355708 -364404 -380116 -386270 -390217 -397948 -409427 -425037 -425667 -436611 -452897 -481370 -489261 -494368 
 
493308 484465 482101 473759 470053 469916 463451 449468 439318 432964 398633 385787 361316 356377 
314287 303511 289847 270978 263803 223026 220454 219486 219218 214358 210229 202255 
*/