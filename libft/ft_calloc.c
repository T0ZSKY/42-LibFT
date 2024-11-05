/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:39:43 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/05 13:54:17 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	void	*c;
	size_t	total;

	total = nmemb * size;
	if (nmemb > 2147483647 / size)
		return (NULL);
	c = (void *)malloc(total);
	if (!c)
		return (NULL);
	ft_bzero(c, nmemb);
	return (c);
}
