/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:00:49 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/20 20:51:39 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0)
		return (dest);
	if (dest <= src)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	while (n--)
	{
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}
/*
int	main ()
{
	const char src[40] = "http.wwws lorem ipsim asasd";
	char dest[40] = "the dest is large";

	//printf("%s\n", memmove(dest, src, 30));
	printf("%s", ft_memmove(((void *)0), ((void *)0), 5));
	return (0);
}*/
