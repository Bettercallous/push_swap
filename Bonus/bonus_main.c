/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:42:36 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/13 21:42:36 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	exec_action(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(str, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(str, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(str, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(str, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(str, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(str, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(str, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(str, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		exit_error("Error\n");
}

static void	read_and_exec_actions(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_next_line(0);
	while (tmp)
	{
		if (!tmp)
			return ;
		exec_action(stack_a, stack_b, tmp);
		free(tmp);
		tmp = get_next_line(0);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		*arr;
	int		stack_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		exit_error("Error\n");
	stack_a = fill_stack(ac, av);
	stack_b = NULL;
	stack_size = ft_stacksize(stack_a);
	arr = fill_ref_array(stack_size, av);
	sort_ref_array(arr, stack_size);
	read_and_exec_actions(&stack_a, &stack_b);
	if (!stack_b && is_sorted(stack_a) == 1)
		ft_putstr("OK\n", 1);
	else
		ft_putstr("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
