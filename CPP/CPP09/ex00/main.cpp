
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Enter one file name as argument\n";
		return 1;
	}
	std::string	input(argv[1]);

	BitcoinExchange	bce = BitcoinExchange();
	try
	{
		bce.loadCsv("data.csv");
		bce.loadInput(input);
	}
	catch (BitcoinExchange::CsvParsingException & e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	//bce.printExchange();
	return 0;
}
