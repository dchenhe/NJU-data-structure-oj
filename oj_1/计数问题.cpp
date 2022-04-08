#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

static int count = 0;

void judge(int i, int x) {
	if (x == i) count++;
}

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	
	for (int i = 1; i < n+1; i++) {
		int m = i;
		while (m != 0) {
			judge(m % 10,x);
			m = m / 10;
		}
	}
	printf("%d", count);
	return 0;
}