
#include <iostream>


int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int j = 1; j < ac; j++)
		{
			for(int i = 0; av[j][i]; i++)
				std::cout << static_cast<char>(toupper(av[j][i]));
			if (j + 1 != ac)
				std::cout << " ";
		}
	}
	else
		std::cout << "* LOUD CRICKET NOISES *";
	std::cout << "\n";

	return 0;
}