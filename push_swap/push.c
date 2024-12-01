/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:22:10 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/01 16:50:09 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void push(t_stack *src, t_stack *dest)
{
    int i;

    if (src->size == 0)
        return;

    i = dest->size;
    while (i > 0)
    {
        dest->data[i] = dest->data[i - 1];
        i--;
    }

    dest->data[0] = src->data[0];
    dest->size++;

    i = 0;
    while (i < src->size - 1)
    {
        src->data[i] = src->data[i + 1];
        i++;
    }
    src->size--;
}

void pa(t_stack *a, t_stack *b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    push(a, b);
    write(1, "pb\n", 3);
}
