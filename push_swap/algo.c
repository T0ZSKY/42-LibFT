/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:21:16 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/02 15:12:48 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bring_to_top(t_stack *a, int index)
{
    if (index <= a->size / 2)
    {
        while (index > 0)
        {
            ra(a);
            index--;
        }
    }
    else
    {
        while (index < a->size)
        {
            rra(a);
            index++;
        }
    }
}

int find_index(t_stack *a, int value)
{
    int i;

    i = 0;
    while (i < a->size)
    {
        if (a->data[i] == value)
            return (i);
        i++;
    }
    return (-1);
}

int find_min(t_stack *a)
{
    int min;
    int i;

    min = a->data[0];
    i = 1;
    while (i < a->size)
    {
        if (a->data[i] < min)
            min = a->data[i];
        i++;
    }
    return (min);
}

void assign_sorted_indices(t_stack *a)
{
    int *sorted;
    int i;
    int j;
    int temp;

    i = 0;
    sorted = malloc(sizeof(int) * a->size);
    if (!sorted)
        return;
    while (i < a->size)
    {
        sorted[i] = a->data[i];
        i++;
    }

    i = 0;
    while (i < a->size - 1)
    {
        j = i + 1;
        while (j < a->size)
        {
            if (sorted[i] > sorted[j])
            {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < a->size)
    {
        j = 0;
        while (j < a->size)
        {
            if (a->data[i] == sorted[j])
            {
                a->data[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
    free(sorted);
}


void normalize_stack(t_stack *a, int offset)
{
    int i;

    i = 0;
    while (i < a->size)
    {
        a->data[i] -= offset;
        i++;
    }
}

void restore_stack(t_stack *a, int offset)
{
    int i;

    i = 0;
    while (i < a->size)
    {
        a->data[i] += offset;
        i++;
    }
}

int is_array_sorted(t_stack *a)
{
    int i;

    i = 0;
    while (i < a->size - 1)
    {
        if (a->data[i] > a->data[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void sort_three_elements(t_stack *a)
{
    if (a->data[0] > a->data[1] && a->data[0] > a->data[2])
        ra(a);
    if (a->data[1] > a->data[0] && a->data[1] > a->data[2])
        rra(a);
    if (a->data[0] > a->data[1])
        sa(a);
}

void sort_four_to_five_elements(t_stack *a, t_stack *b)
{
    while (a->size > 3)
    {
        assign_sorted_indices(a);

        int min_index = find_index(a, 0);
        bring_to_top(a, min_index);
        pb(a, b);
    }
    sort_three_elements(a);
    while (b->size > 0)
        pa(a, b);
}

void optimized_rotate(t_stack *a, t_stack *b, int bit)
{
    int i;
    int size;

    i = 0;
    size = a->size;
    while (i < size)
    {
        if (((a->data[0] >> bit) & 1) == 0)
            pb(a, b);
        else
            ra(a);
        i++;
    }
}

void radix_sort(t_stack *a, t_stack *b)
{
    int bit;
    int offset;

    if (a->size == 3)
    {
        sort_three_elements(a);
        return;
    }

    if (a->size <= 5)
    {
        sort_four_to_five_elements(a, b);
        return;
    }

    offset = find_min(a);
    if (offset < 0)
        normalize_stack(a, offset);

    bit = 0;
    while (!is_array_sorted(a))
    {
        optimized_rotate(a, b, bit);
        while (b->size > 0)
            pa(a, b);
        bit++;
    }

    if (offset < 0)
        restore_stack(a, offset);
}
