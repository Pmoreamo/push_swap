/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:27:22 by pmorello          #+#    #+#             */
/*   Updated: 2024/05/25 10:34:36 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"

static int	ft_get_min(t_stack **stack, int val)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

static void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = ft_get_min(stack_a, -1);
	next_min = ft_get_min(stack_a, min);
	if (ft_is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
	}
	else
	{
		if (head->next->index == min)
			ft_ra(stack_a);
		else
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
	}
}

static void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	if (ft_is_sorted(stack_a))
		return ;
	distance = ft_get_distance(stack_a, ft_get_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
		ft_rra(stack_a);
	if (ft_is_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ft_get_distance(stack_a, ft_get_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (distance == 4)
		ft_rra(stack_a);
	if (ft_is_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (ft_is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
}
