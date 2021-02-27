#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

int main(){
	vector<int> nums;
	int n;
	cin >> n;
	nums.resize(n);
	for(int i = 0;i < n;i++){
		int tem;
		cin >> tem;
		nums[i] = tem;
	}
	
	vector<vector<int> > list;
	list.resize(3);
	for(int i = 0;i < list.size();i++){
		vector<int> tem;	
	 	list[i] = tem;
	}

	for(int i = 0;i < nums.size();i++){
		list[(nums[i]%3)].push_back(nums[i]);
	}

	int sum  = 0;
	for(int i = 0;i < 3;i++){
		if(i == 0) sum += accumulate(list[i].begin(),list[i].end(),0);
		else sort(list[i].begin(),list[i].end(), greater<int>());
	}

	while(1){
	   int c1 = 0,c2 = 0,c3 = 0;
		if(list[1].size() >= 3) c1 = list[1][0] + list[1][1] + list[1][2];
		if(list[2].size() >= 3) c2 = list[2][0] + list[2][1] + list[2][2];
		if(list[1].size() >= 1 && list[2].size() >= 1) c3 = list[1][0] + list[2][0];
		int maxc = max(c1,max(c2,c3));
		if(maxc == 0) break;
		if(maxc == c3){
			sum += c3;
			list[1].erase(list[1].begin());
			list[2].erase(list[2].begin());
		}
		else if(maxc == c1){
			sum += c1;
			list[1].erase(list[1].begin());
			list[1].erase(list[1].begin());
			list[1].erase(list[1].begin());
		}
		else{
			sum += c2;
			list[2].erase(list[2].begin());
			list[2].erase(list[2].begin());
			list[2].erase(list[2].begin());	
		}
			
	
	}

	cout << sum << endl;
}
