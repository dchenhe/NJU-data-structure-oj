#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

struct dListNode {
	int val;
	dListNode* next;
	dListNode* back;
	dListNode() : val(0), next(nullptr), back(nullptr) {}
	dListNode(int x) : val(x), next(nullptr), back(nullptr) {}
	dListNode(int x, dListNode* next, dListNode* back) : val(x), next(next), back(back) {}
};

dListNode* buildList(int x) {
	dListNode* first = new dListNode(1);
	dListNode* cur = first;
	for (int i = 1; i < x; i++) {
		cur->next = new dListNode(i + 1,nullptr,cur);
		cur = cur->next;
	}
	cur->next = first;
	first->back = cur;

	return first;
}

int main() {
	int n,num,id;
	cin >> n >> num >> id;
	dListNode* cur = buildList(n);
	while (cur->val != id) { cur = cur->next; }

	int i = 1;

	while (cur->next != cur) {
		if (i == num) {
			printf("%d ", cur->val);
			dListNode* tmp = cur->next;
			tmp->back = cur->back;
			cur->back->next = tmp;
			cur = cur->next;
			i = 0;
		}
		else { cur = cur->next; }
		i++;
	}

	printf("%d\n",cur->val);
	cur = buildList(n);
	while (cur->val != id) { cur = cur->next; }

	i = 1;

	while (cur->next != cur) {
		if (i == num) {
			printf("%d ", cur->val);
			dListNode* tmp = cur->back;
			tmp->next = cur->next;
			cur->next->back = tmp;
			cur = cur->back;
			i = 0;
		}
		else { cur = cur->back; }
		i++;
	}
	printf("%d\n", cur->val);

	return 0;
}