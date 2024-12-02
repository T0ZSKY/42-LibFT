/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:03 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/02 14:12:23 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void print_stack(t_stack *stack)
{
    for (int i = 0; i < stack->size; i++)
    {
        printf("%d \n", stack->data[i]);
    }
    printf("\n");
}

int ft_multi(t_stack *a, char **argv, int argc)
{
    int i = 1;

    while (i < argc)
    {
        a->data[a->size] = ft_atoi(argv[i]);
        a->size++;
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int i;
    if (argc == 2)
    {
        handle_single_argument(argv[1], &a);
        b = init(a->size);
        if (ft_verif_number_solo(argv[1]) == 0)
        {
            write(1, "Error custom\n", 15);
            return (1);
        }
    }
    else
    {
        a = init(argc - 1);
        b = init(argc - 1);
        ft_multi(a, argv, argc);
        if (ft_is_number(argv) == 0)
        {
            write(1, "Error is number\n", 15);
            return (1);
        }
    }
    i = 1;
    if (!a || !b)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    if (verif_double(a) == 1)
    {
        write(1,"Error double\n", 13);
        return (1);
    }
    if (ft_verif_limite(argv) == 0)
    {
        write(1, "Error limits\n", 14);
        return (1);
    }

    radix_sort(a, b);
    // print_stack(a);
    free_stack(a);
    free_stack(b);
}
