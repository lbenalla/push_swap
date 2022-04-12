#include "push_swap.h"

//validation
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
int is_space_digit(char c)
{
	if (c == ' ' || c =='\t' || is_digit(c))
		return (1);
	else
		return (0);
}
void N_valid(char *s)
{
	char *stk;
	stk = s;
	while(*s)
	{
		if (is_space_digit(*s))
			s++;
		else if(*s == '-' && is_digit(*(s + 1)) && (s == stk || *(s - 1) == ' '|| *(s - 1) == '\t'))
			s++;
		else if(*s == '+' && is_digit(*(s + 1)) && (s == stk || *(s - 1) == ' '|| *(s - 1) == '\t'))
			s++;
		else
			exit(1);
	}
}

void validation(char **av,int ac)
{
	int i;

	i = 1;
	while(i < ac)
	{
		N_valid(av[i]);	
		i++;
	}
}