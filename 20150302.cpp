#include <iostream>
#include <algorithm>

using namespace std;

struct str{
	int no;
	int time;
};

bool cmp(str ss1, str ss2){
	if(ss1.time!=ss2.time){
		return ss1.time>ss2.time;
	}
	return ss1.no<ss2.no;
}

int main(){
	int n;
	cin >> n;
	int array[1005];
	str s[1005];
	for (int i=0; i<n; i++){
		cin >> array[i];
	}
	sort(array, array+n);
	int temp=array[0];
	int stemp=0;
	for (int i=0; i<1000; i++){
		s[i].no=1005;
		s[i].time=0;
	}
	for (int i=0; i<n; i++){
		if(temp==array[i]){
			s[stemp].no=temp;
			s[stemp].time++;
		}
		else{
			stemp++;
			s[stemp].no=array[i];
			s[stemp].time++;
		}
		temp=array[i];
	}
	sort(s, s+stemp+1, cmp);
	for (int i=0; i<=stemp; i++){
		cout << s[i].no << ' ' << s[i].time << endl;
	}
	return 0;
}
