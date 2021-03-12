#include <iostream>

using namespace std;

struct dl{
	int typ;
	int time;
};

int main(){
	int r, y, g;
	cin >> r >> y >> g;
	int n;
	cin >> n;
	int result=0;
	dl da;
	int n0=0, n1=0;
	for (int i=0; i<n; i++){
		cin >> da.typ >> da.time;
		if(da.typ==0){
			result+=da.time;
		}
		else{
			if(da.time>result){
				if(da.typ==1){
					result+=(da.time-result);
				}
				else if(da.typ==2){
					result+=(da.time-result+r);
				}
				else if(da.typ==3){
					result+=0;
				}
			}
			else{
				int temp=result;
				temp-=da.time;
				while(temp>=y+r+g){
					temp-=(y+r+g);
				}
				if(da.typ==1){
					if(temp>=g){
						temp-=g;
						if(temp>=y){
							temp-=y;
							result+=(r-temp);
						}
						else{
							result+=(y-temp+r);
						}
					}
					else{
						result+=0;
					}
				}
				else if(da.typ==2){
					if(temp>=r){
						temp-=r;
						if(temp>=g){
							temp-=g;
							result+=(y-temp+r);
						}
						else{
							result+=0;
						}
					}
					else{
						result+=(r-temp);
					}
				}
				else if(da.typ==3){
					if(temp>=y){
						temp-=y;
						if(temp>=r){
							temp-=r;
							result+=0;
						}
						else{
							result+=(r-temp);
						}
					}
					else{
						result+=(y-temp+r);
					}
				}
			}
//			int ju=0;
//			int temp=result;
//			int temptype=da.typ;
//			while(temp>0){
//				if(temptype==1){
//					if(ju==0){
//						temp-=da.time;
//						ju=1;
//					}
//					else{
//						temp-=r;
//					}
//					temptype=3;
//				}
//				else if(temptype==2){
//					if(ju==0){
//						temp-=da.time;
//						ju=1;
//					}
//					else{
//						temp-=y;
//					}
//					temptype=1;
//				}
//				else if(temptype==3){
//					if(ju==0){
//						temp-=da.time;
//						ju=1;
//					}
//					else{
//						temp-=g;
//					}
//					temptype=2;
//				}
//			}
//			if(temptype==1){
//				result+=(-temp);
//				result+=r;
//			}
//			else if(temptype==3){
//				result+=(-temp);
//			}
//			else if(temptype==2){
//				if(temp==0){
//					result+=(y+r);
//				}
//			}
		}
	}
	cout << result << endl;
	return 0;
} 
