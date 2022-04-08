#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int a[10001] = { 0 };

int main()
{   
    int num;
    cin >> num;
    int index = -1;
    for (int i = 0; i < num; i++) {
        int tmp = 0;
        cin >> tmp;
        if (tmp < 0) {
            if (index == -1) {
                a[++index] = tmp;
            }
            else if (a[index] < 0) {
                a[++index] = tmp;
            }
            else if (a[index] > 0) {
                if (abs(a[index]) > abs(tmp)) {
                    continue;
                }
                else {
                    int flag = 0;
                    while (index >= 0 && abs(a[index]) <= abs(tmp) && a[index]>0 ) {
                        index--;
                        if (abs(a[index+1]) == abs(tmp)) {
                            flag = 1;
                            break;
                        }
                    }
                    if ((index < 0 || a[index] < 0) && flag == 0) { a[++index] = tmp; }
                    continue;
                }
            }
        }
        else {
            a[++index] = tmp;
        }
    }
    for (int i = 0; i <= index; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

