#include <iostream>
//#include <fstream>//

using namespace std;

struct jm{
	int lxquguocs;
	bool isquguo;
	bool isdouliu;
};

int main(){
	int n, k, t, xl, yd, xr, yu;
	jm jma[25];
	int x, y;
//	ifstream infile("t1.txt");//
	cin >> n >> k >> t >> xl >> yd >> xr >> yu; /**/
//	infile >> n >> k >> t >> xl >> yd >> xr >> yu;
	for (int i=0; i<n; i++){
		jma[i].isdouliu=false;
		jma[i].isquguo=false;
		jma[i].lxquguocs=0;
		int ju=0;
		int temp=0;
		for (int j=0; j<t; j++){
			cin >> x >> y;/**/
//			infile >> x >> y;
			if(x>=xl&&x<=xr&&y>=yd&&y<=yu){
				ju++;
				jma[i].isquguo=true;
			}
			else{
				if(ju>jma[i].lxquguocs){
					jma[i].lxquguocs=ju;
//					cout << "***" << jma[i].lxquguocs << endl;
				}
				ju=0;
			}
			if(j==t-1){
				if(ju>jma[i].lxquguocs){
					jma[i].lxquguocs=ju;
//					cout << "***" << jma[i].lxquguocs << endl;
				}				
			}
		}
	}
	int numdouliu=0;
	int numjingguo=0;
	for (int i=0; i<n; i++){
		if(jma[i].lxquguocs>=k){
			jma[i].isdouliu=true;
		}
		if(jma[i].isquguo==true){
			numjingguo++;
		}
		if(jma[i].isdouliu==true){
			numdouliu++;
		} 
	}
	cout << numjingguo << endl;
	cout << numdouliu << endl;
	return 0;
}
