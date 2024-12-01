/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:42:21 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/01 17:00:35 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_min_max(t_stack *stack, int *min, int *max)
{
    int i;

    if (stack->size == 0) // Si la pile est vide
        return;

    *min = stack->data[0];
    *max = stack->data[0];
    i = 1;
    while (i < stack->size)
    {
        if (stack->data[i] < *min)
            *min = stack->data[i];
        if (stack->data[i] > *max)
            *max = stack->data[i];
        i++;
    }
}



// Trouve la médiane d'une pile (approximation simple)
int find_median(t_stack *stack)
{
    int min, max;

    find_min_max(stack, &min, &max);
    return (min + max) / 2;
}

void split_stack(t_stack *a, t_stack *b)
{
    int median;
    int i;
    int original_size;

    median = find_median(a);
    original_size = a->size;
    i = 0;
    while (i < original_size)
    {
        if (a->size == 0) // Si la pile a devient vide, arrête
            break;
        if (a->data[0] < median)
            pb(a, b);
        else
            ra(a);
        i++;
    }
}


void reinsert_sorted(t_stack *a, t_stack *b)
{
    int max;

    while (b->size > 0)
    {
        find_min_max(b, NULL, &max);
        while (b->size > 0 && b->data[0] != max)
        {
            if (b->size > 1 && b->data[1] == max)
                sb(b);
            else
                rb(b);
        }
        if (b->size > 0) // Vérifie encore une fois avant de pousser
            pa(a, b);
    }
}


void bring_min_to_top(t_stack *stack)
{
    int min;
    int pos;
    int i;

    if (stack->size == 0) // Si la pile est vide, ne rien faire
        return;
    find_min_max(stack, &min, NULL);
    pos = 0;
    i = 0;
    while (i < stack->size)
    {
        if (stack->data[i] == min)
        {
            pos = i;
            break;
        }
        i++;
    }
    if (pos <= stack->size / 2)
    {
        while (pos-- > 0)
            ra(stack);
    }
    else
    {
        while (pos++ < stack->size)
            rra(stack);
    }
}


// Fonction principale de Turkey Sort
void turkey_sort(t_stack *a, t_stack *b)
{
    if (a->size <= 1)
        return;
    split_stack(a, b);        // Étape 1 : Divise la pile
    reinsert_sorted(a, b);    // Étape 2 : Réinsère les éléments triés
    bring_min_to_top(a);      // Étape 3 : Met le plus petit en haut
}
