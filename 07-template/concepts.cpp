#include <iostream>
#include <concepts>

template <typename T>
concept Comparable = requires(T a, T b)
{
	{ a < b } -> std::convertible_to<bool>;
};

template <Comparable T>
void compare(T a, T b)
{
	if (a < b)
		std::cout << "a<b\n";
	else
		std::cout << "a>=b\n";
}

//template<typename T>
//void compare(T a, T b)
//{
//	std::cout << "HELLO\n";
//	return;
//}

int main()
{
	int a = 1, b = 2;
	compare(a, b);
}