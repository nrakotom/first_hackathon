/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:47:34 by fharifen          #+#    #+#             */
/*   Updated: 2024/05/27 12:37:06 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

int	count_word(const char *s, char c)
{
	int		count;
	size_t	i;
	int		j;

	j = 0;
	count = 1;
	i = 0;
	while (s[j])
	{
		if (s[j] != c && i == 0)
		{
			count++;
			i = 1;
		}
		else if (s[j] == c)
			i = 0;
		j++;
	}
	return (count);
}

void	*ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	**ft_push_word(char **res, char const *s, char c)
{
	size_t	i;
	int		start;
	int		j;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			res[j] = ft_substr(s, start, i - start);
			if (!res[j])
				return (ft_free(res));
			start = -1;
			j++;
		}
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc(count_word(s, c), sizeof(char *));
	if (!res)
		return (NULL);
	res = ft_push_word(res, s, c);
	return (res);
}
