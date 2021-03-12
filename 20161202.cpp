#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	if(n<=3500){
		cout << n << endl;
	}
	else if(n>=3597&&n<=4955){
		cout << (n-3500)*100/97+3500 << endl;
	}
	else if(n>=5045&&n<=7655){
		cout << (n-4955)*100/90+5000 << endl;
	}
	else if(n>=7735&&n<=11255){
		cout << (n-7655)*100/80+8000 << endl;
	}
	else if(n>=11330&&n<=30755){
		cout << (n-11255)*100/75+12500 << endl;
	}
	else if(n>=30825&&n<=44755){
		cout << (n-30755)*100/70+38500 << endl;
	}
	else if(n>=44820&&n<+61005){
		cout << (n-44755)*100/65+58500 << endl;
	}
	else{
		cout << (n-61005)*100/55+83500 << endl;
	}
	return 0;
}
