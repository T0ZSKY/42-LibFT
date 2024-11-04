/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:34:50 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/04 15:57:15 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*memcpy(void *dest, const void *src, size_t n)
{
	char	*de;
	char	*sr;
	size_t	i;

	i = 0;
	sr = (char *) src;
	de = (char *) dest;
	while (i < n)
	{
		de[i] = sr[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main()
{
    char src[20] = "Hello, world!";
    char dest[20];

    printf("Avant memcpy : %s\n", dest);

    memcpy(dest, src, strlen(src) + 1);

    printf("Après memcpy : %s\n", dest);

    return 0;
}
*/