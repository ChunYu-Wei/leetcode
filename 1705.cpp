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
	
	vector<int> status;
	status.resize(40000);

	for(int i = 0;i < status.size();i++){
		status[i] = 0;
	}
	int dayth = 0;
	int max_day = 0;
	int count = 0;
	do{
		if(dayth < days.size()){
			status[days[dayth]] += apples[dayth];
			if(days[dayth] > max_day) max_day = days[dayth];
		}	

		//search apple
		bool find = 0;

		for(int i = 0;i <= max_day;i++){
			if(status[i] != 0){
				find = 1;
				status[i] -= 1;
				break;
			}
		}

		if(find) count++;
		
		//update
		status.erase(status.begin());
		max_day --;
		dayth++;
	}
	while(max_day > 0 || dayth < days.size());

	cout << count << endl;
	return 0;
}
