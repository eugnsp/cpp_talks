#include <iostream>
#include <vector>
#include <tuple>

int main()
{
	std::vector<char> vec{'a', 'b', 'c'};
	std::cout << size(vec) << std::endl;			// Works before C++20
	
	std::tuple<char, char, char> tuple{'a', 'b', 'c'};
	std::cout << get<1>(tuple) << std::endl;		// Needs C++20, compile with -std=c++2a flag
}
