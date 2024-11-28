/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:03 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/28 23:32:03 by tomlimon         ###   ########.fr       */
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
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int i;
    if (argc < 2)
    {
        write(1, "error\n", 6);
        return (1);
    }
    a = init(argc - 1);
    b = init(argc - 1);
    i = 1;
    if (!a || !b)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    while(i < argc)
    {
        a->data[a->size] = ft_atoi(argv[i]);
        a->size++;       
        i++;
    }
    if (verif_double(a) == 1)
    {
        write(1,"Error\n", 6);
        return (1);
    }
    radix_sort(a, b);
    print_stack(a);
    free_stack(a);
    free_stack(b);
}