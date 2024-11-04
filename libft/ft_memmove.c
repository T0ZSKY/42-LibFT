/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:42:06 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/04 16:46:29 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*de;
	char	*sr;

	sr = (char *) src;
	de = (char *) dest;
	i = 0;
	if (de > sr)
	{
		while (n > 0)
		{
			n--;
			de[n] = sr[n];
		}
	}
	else
	{
		while (i < n)
		{
			de[i] = sr[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int main()
{
    char buffer[20] = "Hello, world!";

    printf("Avant memmove : %s\n", buffer);

    memmove(buffer + 7, buffer, 5);

    printf("Après memmove : %s\n", buffer);

    return 0;
}
*/