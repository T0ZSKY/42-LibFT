/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:39:43 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/05 17:20:25 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;
	size_t	total;

	total = nmemb * size;
	if (nmemb > 2147483647 / size)
		return (NULL);
	c = malloc(total);
	if (!c)
		return (NULL);
	ft_bzero(c, total);
	return (c);
}
