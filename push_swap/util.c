/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:31:03 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/02 01:12:32 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long ft_atol(const char *str)
{
    long long result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
        i++;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int ft_is_number(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        
        // Ignorer les espaces au début de l'argument
        while (argv[i][j] == ' ')
            j++;

        // Gérer le signe '-' s'il est présent
        if (argv[i][j] == '-' && argv[i][j + 1] != '\0')
            j++;  // Passer le signe '-'

        // Vérifier les autres caractères après les espaces et le signe
        while (argv[i][j])
        {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' ')  // Vérifier que c'est un chiffre ou un espace
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int ft_verif_number_solo(char *argv)
{
    int i;

    i = 0;
    while (argv[i])
    {
        // Ignorer les espaces
        if (argv[i] == ' ')
            i++;
        
        // Gérer le signe '-' au début d'un nombre
        else if (argv[i] == '-' && (i == 0 || argv[i - 1] == ' '))
            i++;
        
        // Vérifier si c'est un chiffre
        else if (argv[i] < '0' || argv[i] > '9')
            return (0);

        // Passer à l'indice suivant
        i++;
    }
    return (1);
}

int ft_verif_limite(char **argv)
{
    int i;
    long num;

    i = 1;
    while (argv[i])
    {
        num = ft_atol(argv[i]);
        if (num < INT_MIN || num > INT_MAX)
            return (0);
        i++;
    }
    return (1);
}

void free_split(char **split_args)
{
    int i = 0;
    while (split_args[i])
    {
        free(split_args[i]);
        i++;
    }
    free(split_args);  // Libère le tableau de pointeurs une fois que tous les éléments ont été libérés
}