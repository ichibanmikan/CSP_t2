#include <iostream>
#include <stack>
#include <cstring>
//#include <fstream> //

using namespace std;

int main(){
	int n;
//	ifstream infile("t1.txt");//
	cin >> n;
//	infile >> n;
	string str;
	for (int i=0; i<n; i++){
		cin >> str;
//		infile >> str;
		stack<int> p;
		int a=0, b=0;
		int result=0;
		for (int j=0; j<7; j++){
			if(str[j]>='0'&&str[j]<='9'){
				p.push(str[j]-'0');
			}
			if(str[j]=='x'||str[j]=='/'){
				b=p.top();
				if(str[j]=='x'){
					a=b*(str[++j]-'0');
				}
				if(str[j]=='/'){
					a=b/(str[++j]-'0');
				}
				p.pop();
				p.push(a);
			}
			if(str[j]=='-'){
				p.push(-(str[++j]-'0'));
			}
		}
		while(!p.empty()){
			result+=p.top();
			p.pop();
		}
		if(result==24){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}
