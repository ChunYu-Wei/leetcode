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
				// idx : first zero
				int zero_cnt = 1;

				while(s[idx+zero_cnt] == '0'){
					zero_cnt++;
				}
				cout << "zero_cnt: " << zero_cnt << "  idx:" << idx << endl;
				for(int i = 0;i < zero_cnt;i++){
					s[a+i] = '1';
				}
				s[a+zero_cnt] = '0';
				for(int i = 0;i < zero_cnt;i++){
					s[idx+i] = '1';
				}
			}

			a = idx;
		}
		else a++;
		cout << "s:" << s  << "  a:" << a << endl;		
	}

	cout << s << endl;
	return 0;
}
