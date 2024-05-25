/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:12:33 by pmorello          #+#    #+#             */
/*   Updated: 2024/05/25 10:28:54 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"

int	ft_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ft_ra(t_stack **stack_a)
{
	if (ft_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	ft_rb(t_stack **stack_b)
{
	if (ft_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
