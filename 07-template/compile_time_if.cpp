#include <iostream>
#include <vector>
#include <type_traits>

template<typename T>
void update(T arg)
{
	if constexpr (std::is_trivially_copyable_v<T>)
		std::cout << "is_trivially_copyable" << std::endl;
	else
		std::cout << "not trivially copyable" << std::endl;
}

int main()
{
	std::vector<int> vec{ 1,2,3,4,5 };
	char buf[1024] = "this is a test";
	update(vec);
	update(buf);
	return 0;
}