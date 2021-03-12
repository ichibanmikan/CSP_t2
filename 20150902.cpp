#include <iostream>

using namespace std;

bool isrunnian(int a){
	if(a%400==0||(a%4==0&&a%100!=0)){
		return true;
	}
	return false;
}

struct result{
	int mon;
	int day;
};

int armon[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int amon[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

result getResult(int a, bool isr){
	result re;
	if(isr==true){
		for (int i=0; i<12; i++){
			a-=armon[i];
			if(a<=0){
				a+=armon[i];
				re.mon=i+1;
				re.day=a;
				return re;
			}
		}
	}
	if(isr==false){
		for (int i=0; i<12; i++){
			a-=amon[i];
			if(a<=0){
				a+=amon[i];
				re.mon=i+1;
				re.day=a;
				return re;
			}
		}		
	}
}

int main(){
	int year, days;
	cin >> year >> days;
	result res=getResult(days, isrunnian(year));
	cout << res.mon << endl;
	cout << res.day << endl;
	return 0;
}
