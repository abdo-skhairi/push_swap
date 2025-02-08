#include <pushswap.h>

int validation(char *str)
{
	static int	i;
	static int check;

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
		if((str[i] != '\0' && !(str[i] == ' ' || str[i] == '\t' || (str[i] >= '0' && str[i] <= '9'))))
			return(-1);
	}
	return(0);
}

int main(int ac, char **av)
{
	if(ac >= 2)
	{
		int i = 1;
		while(i <= ac - 1)
		{
			if(validation(av[i]) == -1)
			{
				printf("Error");
				exit(1);
			}
			i++;
		}
	}
}
