#include "pushswap.h"

static	size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static void	cfree(char **p)
{
	size_t	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free (p);
}

static	char	**check(char **p, char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	end = 0;
	while (s[i] && i < ft_count(s, c))
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		p[i++] = ft_substr(s, start, (end - start));
		if (!p[i - 1])
		{
			cfree(p);
			return(NULL);
		}
	}
	p[i] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	p = (char **)malloc(sizeof(char *) * (count + 1));
	if (!p)
		return (NULL);
	return (check(p, s, c));
}
