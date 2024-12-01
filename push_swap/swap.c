/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:39:14 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/01 16:48:44 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_top(t_stack *stack)
{
    int temp;

    if (stack->size < 2)
        return;
    temp = stack->data[0];
    stack->data[0] = stack->data[1];
    stack->data[1] = temp;
}

void sa(t_stack *a)
{
    swap_top(a);
    write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
    swap_top(b);
    write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    if (a->size >= 2)
        swap_top(a);
    if (b->size >= 2)
        swap_top(b);
    write(1, "ss\n", 3);
}

