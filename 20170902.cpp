#include <iostream>
#include <algorithm>

using namespace std;

struct lesson{
	int no;
	int time;
	int solu;
};

bool cmp(lesson l1, lesson l2){
	if(l1.time!=l2.time){
		return l1.time<l2.time;
	}
	if(l1.solu!=l2.solu){
		return l1.solu>l2.solu;
	}
	return l1.no<l2.no;
}

struct keys{
	int no;
	bool iskon;
};

int main(){
	int n, k;
	cin >> n >> k;
	lesson ales[2005];
	keys ak[1005];
	int a1, a2, a3;
	int temp=0;
	for (int i=0; i<k; i++){
		cin >> a1 >> a2 >> a3;
		ales[temp].no=a1;
		ales[temp].solu=1; //==1ÊÇ½è 
		ales[temp].time=a2;
		temp++;
		ales[temp].no=a1;
		ales[temp].solu=2; //==2ÊÇ»¹ 
		ales[temp].time=a2+a3;
		temp++;
	}
	for (int i=0; i<n; i++){
		ak[i].iskon=false;
		ak[i].no=i+1;
	}
	sort(ales, ales+temp, cmp);
	for (int i=0; i<temp; i++){
		if(ales[i].solu==1){
			for (int j=0; j<n; j++){
				if(ak[j].no==ales[i].no&&ak[j].iskon==false){
					ak[j].iskon=true;
					break;
				}
			}
		}
		else if(ales[i].solu==2){
			for (int j=0; j<n; j++){
				if(ak[j].iskon==true){
					ak[j].no=ales[i].no;
					ak[j].iskon=false;
					break;
				}
			}
		}
	}
	for (int i=0; i<n; i++){
		cout << ak[i].no << ' ';
	}
	return 0;
}
