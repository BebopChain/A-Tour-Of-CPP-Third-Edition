#include <iostream>
#include <string>
#include <string_view>
using namespace std;
using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

int main()
{
    string s {"normal string"};

    auto sl = "literal string"s;

    auto svl = "string view literals"sv;

    cout<<sl<<endl;
    cout<<svl<<endl;

    return 0;
}