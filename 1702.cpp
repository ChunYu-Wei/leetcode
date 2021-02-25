#include<iostream>
#include<string>

using namespace std;

int main(void){
	string binary;
	cin >> binary;

	string s = binary;	
	
	int a = 0;
	while(a+1 < s.length()){
		if(s[a] == '0' && s[a+1] == '0'){
			s[a] = '1';
			a++;
		}
		else if(s[a] == '0' && s[a+1] == '1'){
		   int idx = a+2;
		   int zero_cnt = 0;
		   while(idx < s.length()){
		   		if(s[idx] == '0') zero_cnt++;
				idx++;
		   }

		   for(int i = 0;i < zero_cnt;i++) s[a+i] = '1';
		   s[a+zero_cnt] = '0';
		   for(int i = a + zero_cnt + 1; i < s.length();i++) s[i] = '1';
		   a = s.length();
		}
		else a++;
	}

	cout << s << endl;
	return 0;
}
