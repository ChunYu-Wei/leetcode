struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr){}
	ListNode(int x) : val(x), next(nullptr){}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
}

class Solution {
public:
	ListNode* swapNodes(ListNode* head, int k){

		int count = 1;
		ListNode* a = head;
		while(a->next != nullptr){
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
}

int main(void){
	ListNode* tem1 = 

}
