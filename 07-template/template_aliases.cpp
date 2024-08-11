#include <iostream>

template<typename K, typename V>
class Map
{
public:
	Map() { std::cout << "MAP" << std::endl; }
};

template<typename T>
using string_map = Map<std::string, T>;



int main()
{
	string_map<int> sm;
	return 0;
}