#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

char mazeMatrix[1000][1000];

int cx;
int cy;
int d;


struct Node
{
	Node* next;
	int x, y, z;
};

class que {
private:

public:
	Node* begin;
	Node* end;
	int m, n, q;
	que() {
		begin = new Node;
		begin->next = NULL;
		end = begin;
		m = 0;
		n = 0;
		q = 0;
	}
	void pop() {
		if (begin != end) {
			m = begin->next->x;
			n = begin->next->y;
			q = begin->next->z;
			begin = begin->next;
		}
	}

	void push(int x1,int y1,int z1) {
		end->next = new Node;
		end = end->next;
		end->x = x1;
		end->y = y1;
		end->z = z1;
	}

	bool empty() {
		if (begin == end) { return true; }
		return false;
	}
};



class maze {

public:
	int row;
	int col;
	int fr, fc;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	maze(const int r, const int c) {
		row = r;
		col = c;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				scanf(" %c",&mazeMatrix[i][j]);
				if (mazeMatrix[i][j] == 'S') {
					fr = i;
					fc = j;
				}
			}
		}
	}

	int bfs(int m, int n) {
		int flag = 1;
		// 入口加入队列
		que q;
		q.push(m,n,0);

		mazeMatrix[m][n] = '1';
		while (!q.empty()) {
			q.pop();
			cx = q.m;
			cy = q.n;
			d = q.q;
			// 遍历四个方向相邻坐标
			if (mazeMatrix[cx][cy] == '2' && flag) {
				mazeMatrix[cx][cy] = '1';
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						if (mazeMatrix[i][j] == '*' && (i != cx || j != cy)) {
							q.push(i,j,d+1);
							mazeMatrix[i][j] = '1';
							flag = 0;
						}
					}
				}
			}
			for (int k = 0; k < 4; ++k) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				// 新坐标合法且不为1
				if (nx >= 0 && nx < row && ny >= 0 && ny < col && mazeMatrix[nx][ny] != '1' &&mazeMatrix[nx][ny]!='2') {
					if (mazeMatrix[nx][ny] == 'E') {
						// 新坐标为出口，返回距离作为答案
						return d + 1;
					}
					// 新坐标为0且不为出口
					if (mazeMatrix[nx][ny] != '*') mazeMatrix[nx][ny] = '1';
					else mazeMatrix[nx][ny] = '2';

					q.push(nx,ny,d+1);
				}
			}
		}
		// 不存在到出口的路径，返回 -1
		return -1;
	}
};


int main() {
	int r;
	int c;
	scanf("%d",&r);
	scanf("%d",&c);
	maze mymaze(r, c);
	int tmp = mymaze.bfs(mymaze.fr, mymaze.fc);
	if (tmp == -1) printf("-1");
	else printf("%d", tmp);
	return 0;
}