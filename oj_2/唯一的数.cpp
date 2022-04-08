#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int i = 0;
	int tmp[100] = { 0 };
	int ret = 0;
	int num = 0;
	while (cin >> num) {
		if (tmp[num] > 0) { ret -= num; tmp[num] = -1; }
		else if(tmp[num] == 0) { ret += num; }
		if (tmp[num] != -1) {
			tmp[num]++;
		}
		char ch = getchar();
		if (ch == '\n')
			break;
	}
	printf("%d", ret);
	return 0;
}