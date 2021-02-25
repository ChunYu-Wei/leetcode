#include<iostream>
#include<vector>

using namespace std;

class ListNode{
	public:
	   ListNode(){}

	public:
	   int idx;
	   int flag; //0:white 1:gray 2:black
	   vector<ListNode*> children;

};



void DFS(ListNode* n,bool* ans){
   if(n->flag == 0){
		n->flag = 1;
		for(int i = 0;i < n->children.size();i++){
			DFS(n->children[i],ans);
		}
		n->flag = 2;
   }
   else if(n->flag == 1){
   		*ans = false;
   }


}

int main(){

	int numCourses = 2;
	vector<vector<int> > prerequisites;
	vector<int> tem1;
	vector<int> tem2;
	tem1.push_back(1); tem1.push_back(0);
	tem2.push_back(0); tem1.push_back(1);
	prerequisites.push_back(tem1); prerequisites.push_back(tem2);

	vector<ListNode*> courses;
	for(int i = 0;i < numCourses;i++){
		ListNode* tem = new ListNode();
		tem->idx = i;
		tem->flag = false;
		courses.push_back(tem);
	}
	
	for(int group_i = 0; group_i < prerequisites.size();group_i++){
		int idx1 = prerequisites[group_i][0];	
		int idx2 = prerequisites[group_i][1];

		courses[idx1]->children.push_back(courses[idx2]);
	}

	bool temb = true;
	bool* ans = &temb;
	for(int i = 0;i < numCourses;i++) DFS(courses[i],ans);
	cout << *ans << endl;

	


}
