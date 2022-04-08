#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

string dig[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string thousands[] = {"", "Thousand", "Million", "Billion"};


void recursion(string& s, int curNum) {
    if (curNum == 0)
        return;
    if (curNum < 10) {
        s = s + dig[curNum] + " ";
    }
    else if (curNum < 20) {
        int curPos = curNum - 10;
        s = s + teens[curPos] + " ";
    }
    else if (curNum < 100) {
        int curPos = curNum / 10;
        curNum -= curPos * 10;
        s = s + tens[curPos] + " ";
        recursion(s, curNum);
    }
    else {
        int curPos = curNum / 100;
        s = s + dig[curPos] + " " + "Hundred ";
        recursion(s, curNum % 100);
    }

}


int main() {
	int num;
	cin >> num;
	if (num == 0) {
		printf("Zero");
	}
	string ans;
	for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000) {
		int curNum = num / unit;
		if (curNum != 0) {

			num -= curNum * unit;
			string str;
			recursion(str, curNum);
			ans = ans + str + thousands[i] + " ";
		}
	}
    if (ans.back() == ' ') {
        ans.pop_back();
    }
    cout << ans;
	return 0;
}