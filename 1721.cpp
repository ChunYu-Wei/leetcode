#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL){}
	ListNode(int x) : val(x), next(NULL){}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* swapNodes(ListNode* head, int k){

		int count = 1;
		ListNode* a = head;
		while(a->next != NULL){
			a = a->next;
			count++;	
		}
		
		a = head;
		for(int i = 0;i < k - 1;i++){
			a = a->next;
		}
		ListNode* b = head;
		for(int i = 0;i < count-k;i++){
			b = b->next;
		}

		count = b->val;
		b->val = a->val;
		a->val = count;
	}

	void printNodes(ListNode* head){
		if(head != NULL) {
			cout << head->val << " " ;
			printNodes(head->next);
		}
	}
};

int main(void){
	ListNode tem;
	ListNode tem2;
	ListNode tem3;
	ListNode tem4;
	ListNode tem5;

	ListNode* ptem;
	ListNode* ptem2;
	ListNode* ptem3;
	ListNode* ptem4;
	ListNode* ptem5;

	tem.val = 1;
	tem2.val = 2;
	tem3.val = 3;
	tem4.val = 4;
	tem5.val = 5;

	ptem = &tem;
	ptem2 = &tem2;
	ptem3 = &tem3;
	ptem4 = &tem4;
	ptem5 = &tem5;

	ptem->next = ptem2;
	ptem2->next = ptem3;
	ptem3->next = ptem4;
	ptem4->next = ptem5;
	
	Solution s;

	s.printNodes(ptem);
	cout << endl;
	s.swapNodes(ptem,2);
	s.printNodes(ptem);



}
