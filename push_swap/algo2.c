// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   algo2.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/03 14:05:54 by tomlimon          #+#    #+#             */
// /*   Updated: 2024/12/03 14:20:59 by tomlimon         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void sort_three_elements(t_stack *a)
// {
//     if (a->data[0] > a->data[1] && a->data[0] > a->data[2])
//         ra(a);
//     if (a->data[1] > a->data[0] && a->data[1] > a->data[2])
//         rra(a);
//     if (a->data[0] > a->data[1])
//         sa(a);
// }

// void sort_four_to_five_elements(t_stack *a, t_stack *b)
// {
//     while (a->size > 3)
//     {
//         assign_sorted_indices(a, b);

//         int min_index = find_index(a, 0);
//         bring_to_top(a, min_index);
//         pb(a, b);
//     }
//     sort_three_elements(a);
//     while (b->size > 0)
//         pa(a, b);
// }


// void radix_sort(t_stack *a, t_stack *b)
// {
//     int max_bits;
//     int bit;

//     if (a->size == 3)
//     {
//         sort_three_elements(a);
//         return;
//     }
//     if (a->size <= 5)
//     {
//         sort_four_to_five_elements(a, b);
//         return;
//     }

//     assign_sorted_indices(a, b);
//     max_bits = get_max_bits(a);
//     bit = 0;
//     while (bit < max_bits)
//     {
//         move_elements_by_bit(a, b, bit);
//         bit++;
//     }
// }

