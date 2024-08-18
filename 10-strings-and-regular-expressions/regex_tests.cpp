#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // use character classes
    // alphanumeric characters ,匹配所有的 字母和数字
    regex alnum(R"(([[:alnum:]]))");
    string strAlnum {"abc123"};
    smatch match;
    cout<<"alpha character class"<<endl;
    //use regex_iterator
    for(sregex_iterator p{strAlnum.begin(), strAlnum.end(), alnum};p!=sregex_iterator{};p++)
    {
        cout << (*p)[0] <<endl;
        cout << (*p)[1] << endl;//注意:因为我们使用了捕获组，所以[1]表示第一个捕获组的内容，而[0]表示整个匹配
    }

    //alpha表示匹配所有的字母
    regex alpha {R"(([[:alpha:]]))"};
    string strAlpha {"abc123_456def"};
    cout<<"alpha character class"<<endl;
    for(sregex_iterator p{strAlpha.begin(),strAlpha.end(),alpha};p!=sregex_iterator{};p++)
    {
        cout << (*p)[0] << endl;
        cout << (*p)[1] << endl;
    }
    
    //use ? to quit Greedy Mode(that is to say: enter Lazy Mode)
    //add ? after quantifier like *+?
    regex lazyModeP {R"(([[:alpha:]]+?))"};
    regex greedyModeP {R"(([[:alpha:]]+))"};
    string strLazyModeP {"abc123_456def"};
    string strGreedyModeP {"abc123_456def"};
    cout << "Lazy Mode:" << endl;
    for (auto p = sregex_iterator(strLazyModeP.begin(), strLazyModeP.end(), lazyModeP); p != sregex_iterator(); ++p)
    {
        cout << (*p)[0] << endl;
        cout << (*p)[1] << endl;
    }
    cout << "Greedy Mode:" << endl;
    for (auto p = sregex_iterator(strGreedyModeP.begin(), strGreedyModeP.end(), greedyModeP); p != sregex_iterator(); ++p)
    {
        cout << (*p)[0] << endl;
        cout << (*p)[1] << endl;
    }

    //^在正则表达式中的作用:
    //当出现在正则表达式的开头时, ^ 表示从字符串的开头匹配, 与$是一对
    //当出现在[]中时，^表示取反negation
    regex fromStartP {R"(^(\d{4})\s*(\d{2})\s*(\d{2}))"};
    string strFromStartP {"2020 01 01"};
    cout << "^ stand for From Start:" << endl;
    if(regex_match(strFromStartP,match,fromStartP))
    {
        cout << "year:" << match[1] << endl;
        cout << "month:" << match[2] << endl;
        cout << "day:" << match[3] << endl;
    }
    cout << "^ stand for negation" << endl;
    regex negationP {R"([^abc]+)"};//注意，如果使用*来替换+,则会出现错误，因为*会匹配到空串;即会出现a也被匹配到，结果是空行
    string strNegationP {"abcdefghijklabcmnopqrstuvwxyz"};
    for(sregex_iterator p{strNegationP.begin(),strNegationP.end(),negationP};p!=sregex_iterator{};p++)
    {
        if(p->empty())
        {
            cout <<" p empty" << endl;
            continue;
        }
        cout << "p =" << p->str() <<endl;
    }

    //非捕获组,参与匹配，但是不放到捕获组中，如下的例子中，匹配到abc123de,但是捕获组只有2个,分别是123和de
    cout<< "non capture group" << endl;
    regex nonCaptureGroupP {R"((?:[[:alpha:]]+(\d{3})(\w{2})))"};
    string strNonCaptureGroupP {"abc123def456ghi789"};
    for(sregex_iterator p{strNonCaptureGroupP.begin(),strNonCaptureGroupP.end(),nonCaptureGroupP};p!=sregex_iterator{};p++)
    {
        cout << "p = " << p->str() << endl;
        cout << "p[1] = " << (*p)[1] << endl;
        cout << "p[2] = " << (*p)[2] << endl;
    }

    //|特殊字符代表着或的关系
    //使用\i,i是一个数字,来代表引用前面的第i个捕获组
    cout << "\\i 表示引用前面的捕获组" << endl;
    regex iP {R"((\d{4})([[:alpha:]]{2})\1[a|b|c]+)"};
    string strIP {"2020ab2020cb2021cd2021df"};
    for(sregex_iterator p{strIP.begin(),strIP.end(),iP};p!=sregex_iterator{};p++)
    {
        cout << "p = " << p->str() << endl;
        cout << "p[1] = " << (*p)[1] << endl;
        cout << "p[2] = " << (*p)[2] << endl;
    }
    //2021cd2021d没有匹配上的原因是:末尾的d不属于 a|b|c

    
    return 0;
}

