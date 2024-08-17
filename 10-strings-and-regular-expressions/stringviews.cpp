#include <iostream>
#include <string>
#include <string_view>

using namespace std;
using namespace std::literals::string_view_literals;

string cat(string_view sv1, string_view sv2)
{
    string res {sv1};
    return res += sv2;
}

string compose(const string& s1, const string& s2)
{
    return s1 + "@" + s2;
}

string_view bad_string_view_return(const string& s)
{
    return s + "@";//string_view不能指向局部变量，会导致未定义行为
}

void bad_string_view_change(string_view sv)
{
    //sv[0] = 'a';//string_view不能修改指向的字符串,无法编译通过
}


int main()
{
    cout<<"hello"<<endl;;
    
    string s1 {"hello"};
    string res = compose(s1.substr(0,2), "world");
    cout<<res<<endl;

    return 0;
}