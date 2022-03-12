/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:41:43 by guhernan          #+#    #+#             */
/*   Updated: 2020/12/05 14:42:34 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checked if s[] = '\0' ; if s[] is full of separators ;
** if there is a separator at the end or at the beginning of s[];
** if there is no separators in s[] or just one word ;
** if it's protected ; if there is any leaks ;
*/

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void		ft_init(size_t *i, size_t *k, size_t *len, size_t *start)
{
	*i = 0;
	*k = 0;
	*len = 0;
	*start = 0;
}

static char		**ft_douballoc(char const *s, char c, char **arr, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	k;
	size_t	start;

	ft_init(&i, &k, &len, &start);
	while (k < size)
	{
		if (s[i] != c)
		{
			if (len == 0)
				start = i;
			len++;
		}
		if ((s[i] == c && len != 0) || (s[i] == '\0' && len != 0))
		{
			if (!(arr[k++] = ft_substr(s, start, len)))
				return (NULL);
			len = 0;
		}
		i++;
	}
	return (arr);
}

static void		*ft_dblfree(char **arr, size_t nword)
{
	size_t j;

	j = 0;
	while (j++ <= nword)
		free(arr[j]);
	free(arr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	size_t	nword;
	char	**arr;

	if (s == NULL)
		return (0);
	nword = ft_countword(s, c);
	if (!(arr = malloc(sizeof(char *) * (nword + 1))))
		return (NULL);
	arr[nword] = NULL;
	if (!(ft_douballoc(s, c, arr, nword)))
		if (ft_dblfree(arr, nword))
			return (NULL);
	return (arr);
}
