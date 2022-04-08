#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	int num;
	char tmp;
	cin >> num;
	int* score = new int[num];
	int index = 0;
	for (int i = 0; i < num; i++) {
		score[i] = 0;
	} //initialize

	for (int i = 0; i < num; i++) {
		cin >> tmp;
		if (tmp == '(') s.push_back('(');
		else if (tmp == ')') {
			while (s.back() == '_') {
				s.pop_back();
				score[index - 1] = score[index] + score[index - 1];
				score[index] = 0;
				index--;
			}
			if (score[index] == 0) { score[index++]++; s.pop_back(); s.push_back('_'); continue; } //no accumulated score
			s.pop_back();
			s.push_back('_');
			score[index] = score[index] * 2;
			index++;
		}
	}
	int sum = 0;
	for (int i = index; i >= 0; i--) {
		sum += score[i];
	}
	printf("%d", sum);
	return 0;
}