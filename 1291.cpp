#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

//count the #digits of an int
int lenn(int n){
	int l = 0;
	while(n != 0){
		n /= 10;
		l++;
	}
	return l;
}

//cal the power
int myPow(int x, int p) {
     if (p == 0) return 1;
	   if (p == 1) return x;
	     return x * myPow(x, p-1);
}
//return the number given first and len
int cal(const int& first,const int& len){
	int num = 0;
	for(int i = 0;i < len;i++){
		num += (first+len-i-1)*myPow(10,i);
	}
	return num;
}

int main(){
	int low;
	int high;
	low = 1000;
	high = 13000;
	int len = lenn(low);
	int first = 1;
	int num = 0;
	vector<int> ans;
	while(1){	
		num = cal(first,len);
		if(num > high) break;
		else if(num >= low) ans.push_back(num);

		if(num%10 == 9){
			first = 1;
			len++;
		}	
		else first++;
	}

	for(int i = 0;i < ans.size();i++){
		cout << ans[i] << endl;
	}

	return 0;


}
