#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{   
    int num;
    cin >> num;
    int* maxC = new int[num];
    int* maxD = new int[num];
    int** ans = new int* [num];

    for (int i = 0; i < num; i++) {
        maxC[i] = 0;
        maxD[i] = 0;
    }
    for (int i = 0; i < num; i++) {
        ans[i] = new int[num];
        for (int j = 0; j < num; j++) {
            cin >> ans[i][j];
            maxD[i] = max(maxD[i], ans[i][j]);
            maxC[j] = max(maxC[j], ans[i][j]);
        }
    }
    int ret = 0;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            ret += min(maxD[i], maxC[j]) - ans[i][j];
        }
    }
    cout << ret;


    return 0;
}

