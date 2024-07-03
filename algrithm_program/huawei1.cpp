#include "huawei1.h"
#include<iostream>
#include<vector>

using namespace std;
void sprial_num(int n, int m)
{
	int k = n / m + (n % m == 0 ? 0 : 1);

	vector<vector<int>>res(m,vector<int>(k,0));

	int x = 0, y = 0;
	int step = 1;
	int round = 0;
	while (step <= n) {
		while (y < k-round&& step <= n)res[x][y++] = step++;
		y--, x++;
		while (x < m-round && step <= n)res[x++][y] = step++;
		x--,y--;
		while (y >= round && step <= n)res[x][y--] = step++;
		y++, x--;
		while (x >= round+1 && step <= n)res[x--][y] = step++;
		round++;
		x = round, y = round;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			if (res[i][j] != 0)cout << res[i][j] << " ";
			else cout << '*' << " ";
		}
		cout << endl;
	}
}

void max_property()
{
	int n;
	cin >>n;

}
