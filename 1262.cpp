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
		sort(list[i].begin(),list[i].end(), greater<int>());
		if(i == 0) sum += accumulate(list[i].begin(),list[i].end(),0);
		else if(i == 1){
			int nu = list[i].size() - list[i].size()%3;
			for(int j = 0;j < nu;j++) sum += list[i][j];	
		} 
		else if(i == 2){
			int nu = list[i].size() - list[i].size()%3;
			for(int j = 0;j < nu;j++) sum += list[i][j];	
		} 
	}

	int head1 = list[1].size() - list[1].size()%3;
	int head2 = list[2].size() - list[2].size()%3;
	int left1 = list[1].size()%3;
	int left2 = list[2].size()%3;
	int left = (left1>left2) ? left2 : left1 ;	
	for(int i = 0;i < left;i++){
		sum += list[1][head1+i] + list[2][head2+i];
	}

	cout << sum << endl;
}
