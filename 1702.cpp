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
			while(idx < s.size() && s[idx] != '0'){
				idx++;
			}
			if(idx != s.size()) {
				s[idx] = '1';
				s[a] = '1';
				s[a+1] = '0';	
			}
			a = idx;
		}
	
	}

	cout << s << endl;
	return 0;
}
