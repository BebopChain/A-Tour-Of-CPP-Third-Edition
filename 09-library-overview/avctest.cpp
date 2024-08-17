#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <set>
int main()
{
    using namespace std;

    ifstream avcdat1 {"/Users/linus/Desktop/bfly_bak/usr/users/e3000/gen_files/20240811.avcdat2"};
    
    if(!avcdat1.good())
        cout<<"not good"<<endl;
    else
        cout<<"file good"<<endl;
    string line;
    set<string> ts;


    std::regex pattern("^([^,]+),\\s*([^,]+),\\s*([^,]+)\\s*$");
    std::smatch matches;
    while(getline(avcdat1, line))
    {
        //cout<<line<<endl;
        if(regex_search(line, matches, pattern))
        {
            string lt = matches[2];
            auto pr = ts.insert(lt);
            if(!pr.second)
                cout<<line<<endl;
        }
    }
    return 0;

}