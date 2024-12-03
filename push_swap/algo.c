/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:41:50 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/03 14:42:31 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_elements(t_stack *a)
{
    if (a->data[2] != 2)
    {
        if (a->data[0] == 2)
            ra(a); // Rotation vers le haut
        else
            rra(a); // Rotation vers le bas
    }
    if (a->data[0] > a->data[1])
        sa(a); // Swap des deux premiers éléments
}


void sort_four_to_five_elements(t_stack *a, t_stack *b)
{
    while (b->size <= 1)
    {
        if (a->data[0] == 0 || a->data[0] == 1)
            pb(a, b); // Pousser les plus petits éléments vers B
        else
            ra(a); // Rotation vers le haut
    }

    if (b->data[0] == 0)
        sb(b); // Swap des deux premiers éléments de B si nécessaire

    if (a->data[2] != 4)
    {
        if (a->data[0] == 4)
            ra(a); // Rotation vers le haut
        else
            rra(a); // Rotation vers le bas
    }

    if (a->data[0] > a->data[1])
        sa(a); // Swap des deux premiers éléments de A

    pa(a, b);
    pa(a, b);
}


int is_array_sorted(t_stack *a)
{
    int i;

    i = 0;
    while (i < a->size - 1)
    {
        if (a->data[i] > a->data[i + 1])
            return 0; // Non trié
        i++;
    }
    return 1; // Trié
}


static void radix_sort_stack_b(t_stack *a, t_stack *b, int bit_size, int bit)
{
    int b_size = b->size;

    while (b_size-- && bit <= bit_size && !is_array_sorted(a))
    {
        if (((b->data[0] >> bit) & 1) == 0)
            rb(b); // Rotation de B vers le haut
        else
            pa(a, b); // Pousser de B vers A
    }

    if (is_array_sorted(a))
    {
        while (b->size != 0)
            pa(a, b); // Pousser tous les éléments restants de B vers A
    }
}


void radix_sort(t_stack *a, t_stack *b)
{
    int bit_size;
    int size;
    int bit;

    // Calculer le nombre de bits nécessaires
    bit_size = 0;
    size = a->size;
    while (size > 1 && ++bit_size)
        size /= 2;

    bit = 0;
    while (bit <= bit_size)
    {
        size = a->size;
        while (size-- && !is_array_sorted(a))
        {
            if (((a->data[0] >> bit) & 1) == 0)
                pb(a, b); // Pousser dans B
            else
                ra(a); // Rotation de A vers le haut
        }

        radix_sort_stack_b(a, b, bit_size, bit + 1);
        bit++;
    }

    while (b->size != 0)
        pa(a, b); // Pousser tous les éléments restants de B vers A
}
