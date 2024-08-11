#include <cstdlib>
#include <iostream>
//ADVICE:
//[9] Use finally() to provide RAII for types without destructors that require ¡°cleanup operations¡±; ¡ì7.3.3.3.
template<typename T>
struct Final_action
{
	explicit Final_action(T f) : act{ f } {}
	~Final_action() { act();}
	T act;
};

template<class F>
[[nodiscard]] auto finally(F f)
{
	return Final_action{ f };
}

void auto_free_test()
{
	char* buffer = (char*)malloc(100);
	auto act = finally([&] {free(buffer); std::cout << "free buffer" << std::endl; });
	//do something
	//return without use free manually
	return;
}

int main()
{
	auto_free_test();
	return 0;
}
