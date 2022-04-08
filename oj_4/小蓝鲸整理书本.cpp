#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;



int main() {
	string input;
	getline(cin, input);
	int* stack = new int[input.size()];
	int record[26] = { 0 };
	int visit[26] = { 0 };

	for (int i = 0; i < input.size(); i++) {
		record[input[i] - 'a']++;
		stack[i] = 0;
	}
	int index = -1;
	for (int i = 0; i < input.size(); i++) {
		int tmp = input[i] - 'a' + 1;
		if (visit[tmp - 1]) { record[tmp - 1]--; continue; };
		if (index == -1) {
			stack[++index] = tmp;
			record[tmp-1]--;
			visit[tmp - 1] = 1;
		}
		else {
			while (stack[index] >= tmp && record[stack[index] - 1] > 0) {
				visit[stack[index] - 1] = 0;
				index--;
				if (index == -1) break;
			}

			stack[++index] = tmp;
			visit[tmp - 1] = 1;
			record[tmp - 1]--;
		}
	}

	for (int i = 0; i < input.size() && stack[i]; i++) {
		cout << char(stack[i] - 1 + 'a');
	}
}
