#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{   
    string w;
    getline(cin, w);
    string s = w;
    for (int i = 0; i < w.size() / 2; i++)
    {
        swap(w[i],w[w.size() - i - 1]);  // 将第i个字符元素和第n-i-1个元素对调
    }

    int j = 0;
    int* next = new int[s.size()];
    next[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[j] != s[i]) {
            j = next[j-1];
        }
        if (s[j] == s[i]) {
            j++;
            next[i] = j;
        }
        else {
            next[i] = 0;
        }
    }

    int maxN = 0;

    for (int i = 0, j = 0; i < s.size(); i++) {
        while(w[i] != s[j]&&j>0){
            j = next[j - 1];
        }
        if (w[i] == s[j]) {
            if (i == s.size() - 1) { maxN = j; }
            j++;
        }
    }

    cout << w.size() - maxN - 1;

    return 0;
}

