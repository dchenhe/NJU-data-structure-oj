#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) { val = x; left = NULL; right = NULL; }
};

int a[10001] = {0};

TreeNode* pnode[20001] = { NULL };

int get_max(int* a,int left,int right) {
    int index = left;
    for (int i = left+1; i < right; i++) {
        if (a[i] > a[index]) {
            index = i;
        }
    }
    return index;
}

int num = 0;

void recursive(TreeNode* & root, int left, int right) {
    if (left >= right) { return; }
    int t = get_max(a, left, right);
    root = new TreeNode(a[t]);
    recursive(root->left, left, t);
    recursive(root->right, t + 1, right);
}

void tranversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    int front = 20000;
    int rear = 20000;
    int count = 0;
    cout << root->val << " ";
    pnode[rear--] = root->left;  
    pnode[rear--] = root->right;  
    int i = 1;
    while (front!=rear&&i!=num) {
        TreeNode* tmp = pnode[front--];
        if (tmp == NULL) {
            cout << "-1" << " "; continue;
        }
        i++;
        cout << tmp->val << " ";
        pnode[rear--] = tmp->left;
        pnode[rear--] = tmp->right;
    }
}

int main()
{   
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }
    TreeNode* root = NULL;
    recursive(root,0,num);
    tranversal(root);
}

