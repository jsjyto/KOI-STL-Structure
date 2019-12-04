#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;

const int MAX = 100;

typedef struct Dir
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N;
int area[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];

//물에 잠기지 않는 높이만 temp에 복사
void copy(int depth)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (area[i][j] > depth)
				temp[i][j] = area[i][j];
}

//전형적인 DFS
void DFS(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;

		if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
			if (!visited[nextY][nextX] && temp[nextY][nextX])
				DFS(nextY, nextX);
	}
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> area[i][j];

	int result = 1;
	
	//물에 잠기는 높이 1~100
	for (int depth = 1; depth <= MAX; depth++)
	{
		memset(visited, false, sizeof(visited));
		memset(temp, 0, sizeof(temp));
		copy(depth);

		//Component 최대 개수 구한다
		int cnt = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!visited[i][j] && temp[i][j])
				{
					DFS(i, j);

					cnt++;
				}
		result = max(result, cnt);
	}

	cout << result << endl;

	return 0;
}
