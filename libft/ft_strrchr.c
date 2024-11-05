/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:40:07 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/05 12:55:16 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	carr;
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	carr = (char) c;
	while (s[i])
	{
		if (s[i] == carr)
			result = (char *) &s[i];
		i++;
	}
	if (s[i] == carr)
		result = (char *) &s[i];
	if (result != NULL)
		return (result);
	return (NULL);
}
