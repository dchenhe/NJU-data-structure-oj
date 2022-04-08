#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* data = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	//dp question
	int* d = new int[n];
	d[0] = data[0];
	int i = 1;
	int days = 1;
	int maxVal = d[0];
	while (i < n) {
		int tmp = d[i - 1] + data[i];
		d[i] = tmp > data[i] ? tmp : data[i];
		maxVal = maxVal > d[i] ? maxVal : d[i];
		i++;
	}
	//if (maxVal < 0) maxVal = 0;
	printf("%d", maxVal);
	return 0;
}