/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:39:23 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/02 01:11:39 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "./libft/libft.h"
#include <limits.h>


typedef struct s_stack
{
    int *data;
    int size; 
    int max;
} t_stack;




//--------------------------swap------------------------//

void ss(t_stack *a, t_stack *b);
void sb(t_stack *b);
void sa(t_stack *a);
void swap_top(t_stack *stack);


//--------------------------push------------------------//

void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);


//--------------------------rotate------------------------//

void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rotate(t_stack *stack);

//--------------------------reverse_rotate------------------------//

void reverse_rotate(t_stack *stack);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

//--------------------------utils------------------------//

t_stack *init(int max);
void free_stack(t_stack *stack);

//--------------------------verif------------------------//

int	verif_double(t_stack *stack);

//--------------------------algo------------------------//

void radix_sort(t_stack *a, t_stack *b);
int	ft_is_number(char **argv);
int ft_verif_limite(char **argv);
void handle_single_argument(char *arg, t_stack **a);
void free_split(char **split);
int ft_verif_number_solo(char *argv);




#endif