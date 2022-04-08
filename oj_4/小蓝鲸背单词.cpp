#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int nums[1000000] = { 0 };
int index[1000000] = { 0 };
int ans[1000000] = { 0 };
int main() {
	
	int i = 0;
	int num;
	while (cin >> num) {
		nums[i++] = num;
		if (cin.get() == '\n')
			break;
	}
	int sum = i - 1;
	int m = 0;
	for (int j = sum; j >= 0; j--) {
		if (j == sum) { ans[j] = 0; m = max(m, nums[j]); continue; }
		else{
			if (nums[j] < nums[j + 1]) {
				ans[j] = 1;
			}
			else if(nums[j] < m) {
				int tmp = ans[j + 1] + j+1;
				while (nums[j] > nums[tmp]) {
					tmp = ans[tmp] + tmp;
				}
				ans[j] = tmp - j;
			}
			else {
				ans[j] = 0;
				m = nums[j];
			}
		}
	}
	for (int i = 0; i <= sum; i++) {
		cout << ans[i]<<" ";
	}
}