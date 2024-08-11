#include <iostream>
#include <type_traits>
#include <string>
template<typename T, typename T2>
constexpr bool isAssignable = std::is_assignable<T, T2>::value;

template<typename T>
void testing()
{
	static_assert(isAssignable<T&, double>, "can't assign double to T!");

	//static_assert(isAssignable<T&, std::string>, "can't assign string to T!");
}

int main()
{
	testing<double>();

	testing<std::string>();

	return 0;
}