#include <iostream>
#include <vector>
#include <string>
//using template function, ignoring

//fucntion object -> functor
template <typename T>
class LessThan
{
public:
	explicit LessThan(const T& v) : val{ v } {}
	bool operator()(const T& x) const { return x < val; }

private:
	const T val;
};

//using lambda function as Predicate(Î½´Ê)
template <typename C, typename P>
int count(const C& c, P pred)
{
	int ret = 0;
	for (auto x : c)
		if (pred(x))
			ret++;
	return ret;
}

int main()
{
	std::vector<int> vec{ 1,2,3,4,5 };
	LessThan lt{ 3 };
	int ncount = 0;
	for (auto x : vec)
		if (lt(x))
			ncount ++;
	std::cout << "The count of elements in vec which is less than 3 is " << ncount << std::endl;

	int x = 3;
	std::cout << "The count of elements in vec which is less than " << x << " is " <<
		count(vec, [&](int a) {return a < x; }) << std::endl;

	std::string str = "TOM";
	std::vector<std::string> svec{ "ZOO", "BIG" , "COFFEE", "TOXIC", "TO"};
	std::cout << "The count of elements in svec which is less than " << str << " is " <<
		count(svec, [&](std::string s) {return s < str; }) << std::endl;

	return 0;
}