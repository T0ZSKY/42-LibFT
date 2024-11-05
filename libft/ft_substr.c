/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:15:33 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/05 15:32:59 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	len_str;
	char			*result;

	i = 0;
	len_str = ft_strlen((char *) s);
	if (start >= len_str)
		return (NULL);
	result = malloc(sizeof (char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len || result[i] != '\0')
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
