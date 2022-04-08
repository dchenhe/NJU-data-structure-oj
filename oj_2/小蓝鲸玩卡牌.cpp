#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int my[1000000] = { 0 };

int main() {
    long int num;
    int count1 = 0;
    cin >> num;
    
    int i = 0;
    int tmp;
    while(cin >> tmp) {
        my[i++] = tmp;
        char c = getchar();
        if (c == '\n') { break; }
    }
    long int target;
    cin >> target;

    int ret = 0;
    int min = INT32_MAX;
    for (int i = 0, j = 0; i < num; i++) {
        while (j < num && ret < target) {
            ret += my[j++];
        }

        if (ret >= target) {
            min = min > j - i ? j - i : min;
        }
        ret -= my[i];
    }
    if (min != INT32_MAX) { printf("%d", min); }
    else { printf("0"); }
    return 0;
}