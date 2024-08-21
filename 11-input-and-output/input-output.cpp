#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>
#include <format>
#include <sstream>
#include <span>

using namespace std;
using namespace std::literals::string_view_literals;

vector<int> read_ints(istream &is, string_view delimiter = "Q"sv) {
  vector<int> res;
  for (int num; is >> num;) {
    res.push_back(num);
  }
  if (is.eof())
    return res;
  else if (is.fail()) {
    is.clear();
    string str;
    if (is >> str && str == delimiter)
      return res;
    is.setstate(ios::failbit);
  }
  return res;
}

class Entry {
public:
  Entry() { name = "", age = 0; }
  Entry(string_view name, int age) : name{name}, age{age} {}
  friend ostream &operator<<(ostream &os, const Entry &e);

private:
  string name;
  int age;
};

ostream &operator<<(ostream &os, const Entry &e) {
  return os << "{" << e.name << "," << e.age << "}";
}

// read from pair like {"name",age}
istream &operator>>(istream &is, Entry &e) {
  string name;
  int age;

  char c1, c2;
  if (is >> c1 && c1 == '{' && is >> c2 && c2 == '"') {
    while (is.get(c1) && c1 != '"')//使用get来读取空白符号,因为name中可能有空白符号 如 Bill Gates
      name += c1;
    if (is >> c1 && c1 == ',') {
      if (is >> age >> c2 && c2 == '}') {
        e = {name, age};
        return is;
      }
    }
  }
  is.setstate(ios_base::failbit);
  return is;
}

//使用format和vformat来输出
void print_format()
{
    string fmt_str1 = format("{2:} {1:} {0:} ",123.35678,1234.45678,123.456789,123.4567890);
    string fmt_str2 = format("{0:.8}", 123.4567890);
    string fmt_str3 = format("{0:} {0:e} {0:a} {0:.5f} {0:g}", 123.4567890);
    cout<<fmt_str1<<endl;
    cout<<fmt_str2<<endl;
    cout<<fmt_str3<<endl;

    //vformat()通常不被直接使用
}

//一个使用stringstream实现的简易转换函数
template<typename Source=string, typename Target=string>
Target to(Source source)
{
    stringstream ss;
    Target result;
    if( !(ss<<source) || !(ss>>result) || !(ss>>ws).eof() )
        throw runtime_error{"to<>() error"};
    return result;
}

int main() {
//   vector<int> v = read_ints(cin);
//   for (auto i : v)
//     cout << i << " ";
//   cout << endl;

//   Entry e;
//   while (cin >> e)
//     cout << e << endl;

  print_format();

  cout<<"test to function"<<endl;
  cout<<to<double,string>(1.2)<<endl;
  cout<<to<double>(1.2)<<endl;
  cout<<to<>(1.2)<<endl;
  cout<<to(1.2)<<endl;//最简化形式，因为Source推断使用了double,Target使用了默认的string

  cout<<to<int>(123)<<endl;
  cout<<to(123)<<endl;

  ios_base::sync_with_stdio(false);

  return 0;
}