/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:09:31 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/28 15:09:31 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_last(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (*stack != NULL)
		ft_stacklast(*stack)->next = new;
	else
		*stack = new;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack	*get_stack_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
