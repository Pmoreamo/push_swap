/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:46:57 by pmorello          #+#    #+#             */
/*   Updated: 2024/05/25 10:15:54 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// Stack
typedef struct s_list
{
	int				digit;
	int				index;
	struct s_list	*next;
}				t_stack;

// Util functions
t_stack	*ft_lstnew(int value);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
int		ft_lstsize(t_stack *head);

//libft utils
void	ft_putendl_fd(char *str, int fd);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *str, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);

void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		ft_is_sorted(t_stack **stack);
int		ft_get_distance(t_stack **stack, int index);
void	ft_free_stack(t_stack **stack);
void	ft_free(char **str);

// Algorithm utils
void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_simple_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_index_stack(t_stack **stack);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);

// Instruction functions
int		ft_swap(t_stack **stack);
int		ft_push(t_stack **stack_to, t_stack **stack_from);
int		ft_rotate(t_stack **stack);
int		ft_reverse_rotate(t_stack **stack);

int		ft_sa(t_stack **stack_a);
int		ft_sb(t_stack **stack_b);
int		ft_ss(t_stack **stack_a, t_stack **stack_b);
int		ft_pa(t_stack **stack_a, t_stack **stack_b);
int		ft_pb(t_stack **stack_b, t_stack **stack_a);
int		ft_ra(t_stack **stack_a);
int		ft_rb(t_stack **stack_b);
int		ft_rr(t_stack **stack_a, t_stack **stack_b);
int		ft_rra(t_stack **stack_a);
int		ft_rrb(t_stack **stack_b);
int		ft_rrr(t_stack **stack_a, t_stack **stack_b);

#endif
