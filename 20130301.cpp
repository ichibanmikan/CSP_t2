//拓展题2 20130301
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PAIR;

bool cmp(const PAIR& p1, const PAIR& p2)
{
    if (p1.second!=p2.second)
    {
        return p1.second>p2.second;
    }
    else
    {
        return p1.first<p2.first;
    }
}

int main()
{
    map<int, int> num_time;
    int num, n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> num;
        num_time[num]++;
    }
    map<int, int>::iterator iter;
    vector<PAIR> vec_pair;
    for (iter=num_time.begin(); iter!=num_time.end(); iter++)
    {
        vec_pair.push_back(*iter);
    }
    sort(vec_pair.begin(), vec_pair.end(), cmp);
    cout << vec_pair[0].first << endl;
    system("pause");
    return 0;
}