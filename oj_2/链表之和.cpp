#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};



int main() {
	int num = 0;

	int i = 0;
	ListNode* n1 = new ListNode;
	ListNode* root1 = n1;
	while (cin >> num) {

		if (num == -1) break;
		n1->next = new ListNode(num);//插入节点
		n1 = n1->next;

	}

	ListNode* n2 = new ListNode;
	ListNode* root2 = n2;

	while (cin >> num) {

		if (num == -1) break;
		n2->next = new ListNode(num);//插入节点
		n2 = n2->next;

	}

	ListNode* sum = new ListNode;

	int next = 0;
	
	while (root1->next!=NULL || root2->next!=NULL) {
		int t1 = 0;
		int t2 = 0;
		if (root1->next != NULL) {
			t1 = root1->next->val;
			root1 = root1->next;
		}

		if (root2->next != NULL) {
			t2 = root2->next->val;
			root2 = root2->next;
		}

		int tmp = t1 + t2 + next;
	
		if (tmp >= 10) { printf("%d ", tmp - 10); next = 1; }
		else{ printf("%d ", tmp); next = 0; }
	}
	if (next == 1) { printf("1"); }
	return 0;

}