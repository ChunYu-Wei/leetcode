#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> apples;			
	vector<int> days;
	
	int in_n;
	
	cin >> in_n;
	for(int i = 0;i < in_n;i++){
	   int tem2;
	   cin >> tem2 ; 
	   apples.push_back(tem2);
	}

	for(int i = 0;i < in_n;i++){
	   int tem2;
	   cin >> tem2 ; 
	   days.push_back(tem2);
	}


	return 0;
}
