/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:14:50 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/13 18:14:50 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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
t_stack	*fill_stack(char **av);
int		ft_stacksize(t_stack *stack);
void	free_stack(t_stack **stack);
t_stack	*ft_newstack(int value);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*get_stack_before_last(t_stack *stack);
char	*fill_buff(int fd);
void	ft_putstr(char *str, int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *buff, char c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		*fill_ref_array(int size, char **av);
void	sort_ref_array(int *tab, int size);
char	**ft_split(char const *s, char c);
void	free_strs(char **str);
int		ft_strlcat(char *dst, const char *src, int dstsize);
int		ft_strcmp(const char *s1, const char *s2);
void	stack_add_last(t_stack **stack, t_stack *new_node);

#endif