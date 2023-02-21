/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:33:32 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/15 11:33:32 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int		ft_isdigit(int c);
int		is_sorted(t_stack *stack);
char	**is_correct_input(char **av);
long	ft_atoi(const char *str);
void	exit_error(char *message);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*fill_stack(char **av);
void	mini_sort(t_stack **stack_a, t_stack **stack_b, int size);
int		min_index_of_5(t_stack *stack_a);
void	shift_min_5_to_top(t_stack **stack_a);
int		min_index_of_4(t_stack *stack);
void	shift_min_4_to_top(t_stack **stack_a);
int		ft_stacksize(t_stack *stack);
void	free_stack(t_stack **stack);
void	stack_add_last(t_stack **stack, t_stack *new_node);
void	ft_putstr(char *str, int fd);
t_stack	*ft_newstack(int value);
t_stack	*get_stack_before_last(t_stack *stack);
void	big_sort(t_stack **stack_a, t_stack **stack_b, int *tab, int size);
int		get_rotation(t_stack *stack, int number);
int		get_index_from_arr(int *tab, int number, int tab_size);
int		get_number_index(t_stack *stack, int number);
void	replace_value_with_index(t_stack *stack_a, int *tab, int size);
void	sort_ref_array(int *tab, int size);
int		*fill_ref_array(int size, char **av);
int		max_value(t_stack **stack_a);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
int		ft_strlcat(char *dst, const char *src, int dstsize);
void	free_strs(char **str);

#endif