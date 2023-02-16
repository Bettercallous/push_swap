/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:24:19 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/16 22:45:12 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_stack **stack_a)
{
	int		max;
	t_stack	*ptr;

	ptr = *stack_a;
	max = ptr->value;
	while (ptr->next)
	{
		if (ptr->next->value > max)
			max = ptr->next->value;
		ptr = ptr->next;
	}
	return (max);
}

int	min_index_of_5(t_stack *stack_a)
{
	int	one;
	int	two;
	int	three;
	int	four;
	int	five;

	one = stack_a->value;
	two = stack_a->next->value;
	three = stack_a->next->next->value;
	four = stack_a->next->next->next->value;
	five = stack_a->next->next->next->next->value;
	if (one < two && one < three && one < four && one < five)
		return (0);
	else if (two < one && two < three && two < four && two < five)
		return (1);
	else if (three < one && three < two && three < four && three < five)
		return (2);
	else if (four < one && four < two && four < three && four < five)
		return (3);
	else
		return (4);
}

void	shift_min_5_to_top(t_stack **stack_a)
{
	if (min_index_of_5(*stack_a) == 0)
		return ;
	else if (min_index_of_5(*stack_a) == 1)
		ra(stack_a);
	else if (min_index_of_5(*stack_a) == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (min_index_of_5(*stack_a) == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else
		rra(stack_a);
}

int	min_index_of_4(t_stack *stack)
{
	int	first;
	int	second;
	int	third;
	int	fourth;

	first = stack->value;
	second = stack->next->value;
	third = stack->next->next->value;
	fourth = stack->next->next->next->value;
	if (first < second && first < third && first < fourth)
		return (0);
	else if (second < first && second < third && second < fourth)
		return (1);
	else if (third < first && third < second && third < fourth)
		return (2);
	else
		return (3);
}

void	shift_min_4_to_top(t_stack **stack_a)
{
	if (min_index_of_4(*stack_a) == 0)
		return ;
	else if (min_index_of_4(*stack_a) == 1)
		ra(stack_a);
	else if (min_index_of_4(*stack_a) == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else
		rra(stack_a);
}
