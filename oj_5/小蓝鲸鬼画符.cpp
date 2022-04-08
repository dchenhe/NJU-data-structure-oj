#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

void sort(int** a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
        
            if (a[j][0] > a[j + 1][0]) {
                swap(a[j][0], a[j + 1][0]);
            }
        }
    }
}

int main()
{   
    int num;
    cin >> num;
    int** dot = new int*[num];
    int** ans = new int* [num];
    for (int i = 0; i < num; i++) {
        dot[i] = new int[2];
        ans[i] = new int[2];
        cin >> dot[i][0];
        cin >> dot[i][1];
    }

    sort(dot, num);
    int j = 0;
    int i = 0;
    for (i = 0; i < num-1; ) {
        ans[j][0] = dot[i][0];
        if (dot[i + 1][0] > dot[i][1]) {
            ans[j][1] = dot[i][1];
            j++;
            i++;
            continue;
        }
        while ( dot[i + 1][0] <= dot[i][1]) {
            ans[j][1] = max(dot[i + 1][1],dot[i][1]);
            i++;
            if (i >= num - 1) {
                break;
            }
        }
        i++;
        j++;
    }

    if (i == num - 1) {
        ans[j][0] = dot[i][0];
        ans[j][1] = dot[i][1];
    }
    else {
        j = j - 1;
    }
    for (int c = 0; c <= j; c++) {
        cout << ans[c][0] << " " << ans[c][1] << endl;
    }

    return 0;
}

