/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:56:06 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/05 23:36:57 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int calculate_size(int nb)
{
    int size;
    int temp;

    size = 1;
    temp = nb;
    while (temp / 10 != 0)
    {
        size++;
        temp = temp / 10;
    }
    if (nb < 0)
    {
        if (nb == -2147483648)
            return (11);
        size++;
    }
    return (size);
}

char *handle_negative_case(int *nb, int *neg)
{
    char *result;

    if (*nb == -2147483648)
        return (ft_strdup("-2147483648"));
    if (*nb < 0)
    {
        *neg = 1;
        *nb = -*nb;
        result = malloc(sizeof(char) * (calculate_size(*nb) + 1));
        if (!result)
            return (NULL);
        result[0] = '-';
    }
    else
    {
        result = malloc(sizeof(char) * (calculate_size(*nb) + 1));
        if (!result)
            return (NULL);
    }
    return result;
}

void fill_number_in_result(int nb, char *result, int size, int neg)
{
    int i = 0;

    while (i < size - neg)
    {
        result[size - 1 - i] = nb % 10 + '0';
        nb = nb / 10;
        i++;
    }
    result[size] = '\0';
}

char *ft_itoa(int nb)
{
    int neg;
    int size;
    char *result;

    neg = 0;
    size = calculate_size(nb);
    result = handle_negative_case(&nb, &neg);
    if (!result)
        return (NULL);
    
    fill_number_in_result(nb, result, size, neg);
    
    return (result);
}


