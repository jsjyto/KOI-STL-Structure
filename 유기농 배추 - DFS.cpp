#include <iostream>
#include <cstring> //memset
using namespace std;

const int MAX = 50;

typedef struct Dir
{
    int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int M, N, K;
int lettuce[MAX][MAX];
bool visited[MAX][MAX];

void DFS(int y, int x)
{
    if (visited[y][x])
        return;

        visited[y][x] = true;
        
        for(int i = 0; i < 4; i++)
        {
            int nextY = y + moveDir[i].y;
            int nextX = x + moveDir[i].x;
            
            if(0 <= nextY && nextY < N && 0 <= nextX && nextX < M) //���� ���� �ְ�
                if(lettuce[nextY][nextX])//�̵�
                    DFS(nextY, nextX);
		}
}

int main(void)
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
		memset(visited, false, sizeof(visited));
		memset(lettuce, 0, sizeof(lettuce));

        cin >> M >> N >> K;
        for (int j = 0; j < K; j++)
        {
            int x, y;	
            cin >> x >> y;

            lettuce[y][x] = 1;
        }
        
 		int cnt = 0;

 
        for(int j = 0; j < N; j++)
        	for(int k = 0; k < M; k++)
                //���� ��ȣ���� ���� ���߰� ������ DFS ����
                // ���ߴ� �ɾ��µ� ���� �湮 ������ �� 
                if(lettuce[j][k] && visited[j][k] == false)
                {
                    DFS(j, k);
					cnt++; //�ʿ��� ������ ���� ����
				}
        cout << cnt << endl;
    }
    return 0;
}
