/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbamatra <mbamatra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:24:15 by mbamatra          #+#    #+#             */
/*   Updated: 2024/04/21 04:45:57 by mbamatra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
// #include "libft.h"
#include "stdlib.h"
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return(i);
}

char *ft_strdup(char *str)
{
	int i = 0;
	int len = ft_strlen(str);
	char *dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	char *str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	modify_pointer(int *ptr)
{
	*ptr = 20;
}

int main(void)
{
	int num = 10;
	int *ptr = &num;
	printf("Before: %d\n", *ptr);
	modify_pointer(ptr);
	printf("After: %d\n", *ptr);
	printf("After: %d\n", num);
}