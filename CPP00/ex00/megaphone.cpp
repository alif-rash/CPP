#include <iostream>
#include <cctype>

void	print_args(char *args)
{
	while (*args != '\0')
	{
		if (std::isalpha(*args))
			std::cout << (char)std::toupper(*args);
		else
			std::cout << *args;
		args++;
	}
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac)
		{
			print_args(av[i]);
			i++;
			if (i < ac)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
