#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	int num;
	cin >> num;
	int* poker = new int[num];
	int* pointer = new int[num];
	int point = 0;
	for (int i = 0; i < num; i++) {
		cin >> poker[i];
		pointer[i] = i+1;
	}

	int end = num - 1;

	while(point != num) {
		cout << poker[point] << " ";
		point = pointer[point];
		int tmp = pointer[point];
		if (tmp == 4) { cout << poker[point] << " "; return 0; }
		pointer[point] = pointer[end];
		pointer[end] = point;
		end = point;
		point = tmp;
	}

	return 0;
}