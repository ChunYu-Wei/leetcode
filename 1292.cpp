#include<iostream>
#include<vector>
using namespace std;


bool func(const int& grid, vector<vector<int> >& mat, vector<vector<int> >& prefix_sum,const int& threshold){
	for(int i = grid-1;i < mat.size();i++){
		for(int j = grid-1;j < mat[0].size();j++){
			int sum;
			if(i == grid-1 && j == grid-1) sum = prefix_sum[i][j];
			else if(i == grid-1) sum = prefix_sum[i][j] - prefix_sum[i][j-grid]	;
			else if(j == grid-1) sum = prefix_sum[i][j] - prefix_sum[i-grid][j]	;
			else sum = prefix_sum[i][j] - prefix_sum[i-grid][j] - prefix_sum[i][j-grid] + prefix_sum[i-grid][j-grid];
			if(sum <= threshold) return true;				
		}
	}
	return false;
}

int main(){
	int n,m;
    cin >> n >> m;	
	
	vector<vector<int> > mat;
	mat.resize(n);
	for(int i = 0;i < n;i++){
		vector<int> tem_a;
		tem_a.resize(m);
		for(int j = 0;j < m;j++){
		   int tem;
		   cin >> tem;
		  tem_a[j] = tem; 
		}
		mat[i] = tem_a;
	}
	
	int threshold;
	cin >> threshold;
	
	vector<vector<int> > prefix_sum;
	prefix_sum.resize(n);
	for(int i = 0;i < n;i++) prefix_sum[i].resize(m);

	//cal prefix sum
	for(int i = 0; i < n;i++){
		for(int j = 0;j < m;j++){
			if(i == 0 && j ==0) prefix_sum[i][j] = mat[i][j];
			else if(i == 0) prefix_sum[i][j] = prefix_sum[i][j-1] + mat[i][j];
			else if(j == 0) prefix_sum[i][j] = prefix_sum[i-1][j] + mat[i][j];
			else prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + mat[i][j];
		}
	}

	int grid = 1;
	while(func(grid,mat,prefix_sum,threshold)){
	   grid++;
	}
	grid--;
	cout << grid << endl;


	return 0;


}
