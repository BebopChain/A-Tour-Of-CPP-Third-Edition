#include <ranges>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;
    vector<int> v1 {5,8,31,4,2,1};
    sort(v1.begin(), v1.end());
    for(const auto& e : v1)
        cout<<e<<endl;
    vector<double> v2{5.1, 8.1, 31.1,42.,2.,1.};
    sort(begin(v2), end(v2));
    for(const auto& e : v2)
        cout<<e<<endl;

    return 0;
}