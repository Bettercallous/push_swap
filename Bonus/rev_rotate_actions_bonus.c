/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_actions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:43:13 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/13 21:43:13 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last_node;
	t_stack	*before_last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = ft_stacklast(*stack);
	before_last_node = get_stack_before_last(*stack);
	tmp = *stack;
	*stack = last_node;
	(*stack)->next = tmp;
	before_last_node->next = NULL;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
