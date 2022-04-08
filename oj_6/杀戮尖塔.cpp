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

TreeNode* pnode[20001] = { NULL };

int countPath(TreeNode* root, long int targetSum, bool tmp = true) {
    if (root == NULL) return 0;
    int sumPath = 0;
    sumPath +=  countPath(root->left, targetSum - root->val, false);
    sumPath += countPath(root->right, targetSum - root->val, false);
    sumPath += tmp ? (countPath(root->right, targetSum, true) + countPath(root->left, targetSum, true)) : 0;
    sumPath += (targetSum == root->val) ? 1 : 0;
    return sumPath;
}

int main()
{   
    long int tar = 0;
    int num = 0;
    cin >> tar >> num;

    int w = 0;
    cin >> w;
    TreeNode* root = new TreeNode(w);
    int front = 20000;
    int rear = 20000;
    pnode[rear--] = root;
    for (int i = 1; i < num;) {
        TreeNode* tmp = pnode[front--];
        string st1;
        string st2;
        if (tmp == NULL) { cin >> st1; cin >> st2; pnode[rear--] = NULL; pnode[rear--] = NULL; i = i + 2; continue; }

        cin >> st1;
        i++;
        if (st1 == "null") {
            pnode[rear--] = NULL;
        }
        else {
            tmp->left = new TreeNode(atoi(st1.c_str()));
            pnode[rear--] = tmp->left;
        }
        if (i  < num) {
            cin >> st2;
            i++;
            if (st2 == "null") {
                pnode[rear--] = NULL;
            }
            else {
                tmp->right = new TreeNode(atoi(st2.c_str()));
                pnode[rear--] = tmp->right;
            }
        }
    }

    int m = countPath(root, tar, true);
    cout << m;
    return 0;
}

