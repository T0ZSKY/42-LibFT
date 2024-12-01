/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:12:15 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/01 16:47:05 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack *stack)
{
    int i;
    int first;

    if (stack->size <= 1)
        return;
    first = stack->data[0];
    i = 0;
    while (i < stack->size - 1)
    {
        stack->data[i] = stack->data[i + 1];
        i++;
    }
    stack->data[stack->size - 1] = first;
}

void ra(t_stack *a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}



