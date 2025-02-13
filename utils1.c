#include "pushswap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	total;

	total = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		total = total * 10 + (*str - '0');
		str++;
	}
	return (total * sign);
}

int validation(char *str)
{
	int	i;
	int check;

	i = 0;
	check = 0;
	if((!(str[0] >= '0' && str[0] <= '9') && str[1] == '\0') || str[0] == '\0')
		return(-1);
	while(str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if(!(str[i] >= '0' && str[i] <= '9'))
			return(-1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if(!str[i])
			break;
		while((str[i] == ' ' || str[i] == '\t'))
			i++;
		if((str[i] != '\0' && !(str[i] == ' ' || str[i] == '\t' || (str[i] >= '0' && str[i] <= '9')) && !(str[i] == '+' || str[i] == '-')))
			return(-1);
	}
	return(0);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*dst;

	i = 0;
	size = ft_strlen(s1);
	dst = malloc(sizeof(char) * (size + 1));
	if (dst == NULL)
		return (NULL);
	while (i < size)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
        len = slen - start;
	i = 0;
	d = malloc(sizeof(char) * (len + 1));
	if (d == NULL)
		return (NULL);
	while (i < len)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t  s1len;
    size_t  s2len;
    size_t  i;

    if (!s1 && s2)
        return ((char *)s2);
    if (s1 && !s2)
        return ((char *)s1);
    if (!s1 && !s2)
        return (NULL);
    s1len = ft_strlen(s1);
    s2len = ft_strlen(s2);
    str = malloc(sizeof(char) * (s1len + s2len + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (i < s1len)
    {
        str[i] = s1[i];
        i++;
    }
    size_t j = 0;
    while (j < s2len)
    {
        str[i + j] = s2[j];
        j++;
    }
    str[s1len + s2len] = '\0';
    return (str);
}
