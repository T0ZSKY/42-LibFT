/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:08:36 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/01 16:42:30 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init(int size)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    
    stack->data = malloc(sizeof(int) * size);
    if (!stack->data)
    {
        free(stack);
        return NULL;
    }
    
    stack->size = 0;
    stack->max = size;
    return stack;
}



void free_stack(t_stack *stack)
{
    if (stack)
    {
        if (stack->data)
        {
            free(stack->data);
        }
        free(stack);
    }
}

