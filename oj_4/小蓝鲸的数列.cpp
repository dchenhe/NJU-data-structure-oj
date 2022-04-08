#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

long long int a[1000001], b[1000001];
long long int head_a = 1, head_b = 1;
long long int la = 0, lb = 0, total = 1;
long long int x, t;
int main()
{   

    while (scanf("%d%d", &x, &t))
    {
        while (total < t)
        {
            a[++la] = (x * 2) + 1;
            b[++lb] = 3 * x + 1;
            if (a[head_a] > b[head_b])     x = b[head_b++];
            else if (a[head_a] < b[head_b])  x = a[head_a++];
            else
            {
                x = a[head_a++];
                head_b++;
            }
            total++;
        }
        cout << x << endl;
    }
    return 0;
}

