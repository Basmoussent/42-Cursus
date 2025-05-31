
#include "RPN.hpp"

int	main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please enter an inverted Polish expression\n";
		return 1;
	}
	try
	{
		hsilop(argv[1]);
	}
	catch (RPNException & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
