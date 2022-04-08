#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main() {
	string input;
	int count1 = 0;
	getline(cin, input);
	for (int i = input.size() - 1; i >= 0; i--) {
		if (input[i] == '1') count1++;
	}

	if (input.size()==1 && input[0] == '0') { printf("0"); return 0; }
	int count0 = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 0) { count0++; }
		else { count1--; }
		if (count1 == count0) { printf("%d", i+1); return 0; }
	}
	printf("-1");
	return 0;
}