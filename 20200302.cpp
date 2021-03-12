#include <iostream>
#include <algorithm>

using namespace std;

struct st{
	int wd;
	int value;
};
st stua[1000005];

bool cmp(st s1, st s2){
	return s1.wd<s2.wd;
}

int main(){
	int n, u, v;
	cin >> n >> u >> v;
	long long result=0;
	for (int i=0; i<u+v; i++){
		cin >> stua[i].wd >> stua[i].value;
	}
	sort(stua, stua+u+v, cmp);
	for (int i=1; i<u+v; i++){
		if(stua[i].wd==stua[i-1].wd){
			result+=stua[i].value*stua[i-1].value;
		}
	}
	cout << result << endl;
	return 0;
}
