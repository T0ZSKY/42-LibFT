/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:53:06 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/04 14:14:06 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>

int main()
{
    char buffer[20];

    memset(buffer, '-', sizeof(buffer) - 1);
    buffer[19] = '\0';

    printf("Avant memset : %s\n", buffer);

    memset(buffer, 'A', 10);

    printf("Après memset : %s\n", buffer);

    return 0;
}
*/