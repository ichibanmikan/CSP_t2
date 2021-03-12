#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string form;
    cin >> form;
    stringstream str1;
    vector<char> vec;
    map<char, char> issign;
    for (int i=0; i<form.size(); i++)
    {
        vec.push_back(form[i]);
        if (form[i+1]==':')
        {
            issign[form[i]]='s';
            i++;
        }
        else
        {
            issign[form[i]]='u';
        }
    }
    int n;
    cin >> n;
    string name, command;
    vector<string> vecstr;
    for (int i=0; i<n; i++)
    {
        cin >> name;
        int num=0;
        getchar();
        getline(cin, command);
        // cout << command;
        // for (int j=0; j<command.size(); j++)
        // {
        //     if(command[j]!=' ')
        //     {
                
        //     }
        // }
        // while(s)
    }
    system("pause");
    return 0;
}
