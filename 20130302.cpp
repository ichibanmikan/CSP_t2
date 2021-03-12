#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string str;
	cin >> str;
	int result=0;
	char ch[10];
	int pt=0;
	for (int i=0; i<str.size()-1; i++){
		if(str[i]!='-'){
			ch[pt]=str[i];
			pt++;
		}
	}
	for (int i=0; i<pt; i++){
		result+=(ch[i]-'0')*(i+1);
	}
	if(result%11==10){
		if(str[12]=='X'){
			cout << "Right" << endl;
		}
		else{
			str[12]='X';
			cout << str << endl;
		}
	}
	else{
		if(result%11==(str[12]-'0')){
			cout << "Right" << endl;
		}
		else{
			str[12]=('0'+result%11);
			cout << str << endl;
		}
	}
}
