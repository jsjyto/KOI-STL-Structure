#include <iostream>

#include <queue>

#include <cstring>

using namespace std;

 

const int MAX = 100;

 

typedef struct

{

        int y, x;

}Dir;

 

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

enum{CHEESE=1, PREAIR, AIR};

 

int N, M;

int lastCnt;

int cheese[MAX][MAX];

bool visited[MAX][MAX];

 

bool allClear(void)

{

        int cnt = 0;

        for(int i=0; i < N; i++)

                 for(int j = 0; j < M; j++)

                         if (cheese[i][j] == CHEESE)

                                 cnt++;

       

        if (cnt)

                 lastCnt = cnt;

 

        return cnt ? false : true;

}

 

//BFS2()에서 표시한 칸을 공기로 바꾸는 과정

void PreairToAir(void)

{

        for (int i = 0; i < N; i++)

                 for (int j = 0; j < M; j++)

                         if (cheese[i][j] == PREAIR)

                                 cheese[i][j] = AIR;

}

 

//공기를 표시하는 과정

void BFS1(void)

{

        memset(visited, 0, sizeof(visited));

 

        queue<pair<int, int> > q;

        q.push({ 0, 0 });

        while (!q.empty())

        {

                 int y = q.front().first;

                 int x = q.front().second;

                 q.pop();

 

                 for (int i = 0; i < 4; i++)

                 {

                         int nextY = y + moveDir[i].y;

                         int nextX = x + moveDir[i].x;

                         if(0<=nextY && nextY < N && 0 <= nextX && nextX < M)

                                 if (!visited[nextY][nextX] && (!cheese[nextY][nextX] || cheese[nextY][nextX] == 3))

                                 {

                                          cheese[nextY][nextX] = AIR;

                                          q.push({ nextY, nextX });

                                          visited[nextY][nextX] = true;

                                 }

                 }

        }

}

 

//곧 녹을 치즈를 표시하는 과정

void BFS2(void)

{

        memset(visited, 0, sizeof(visited));

 

        queue<pair<int, int> > q;

        q.push({ 0, 0 });

        while (!q.empty())

        {

                 int y = q.front().first;

                 int x = q.front().second;

                 q.pop();

 

                 for (int i = 0; i < 4; i++)

                 {

                         int nextY = y + moveDir[i].y;

                         int nextX = x + moveDir[i].x;

                         if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && !visited[nextY][nextX])

                         {

                                 if (cheese[nextY][nextX] == AIR)

                                 {

                                          q.push({ nextY, nextX });

                                          visited[nextY][nextX] = true;

                                 }

                                 //곧 녹을 치즈를 표시하는 과정

                                 if (cheese[y][x] == AIR && cheese[nextY][nextX] == CHEESE)

                                 {

                                          cheese[nextY][nextX] = PREAIR;

                                          q.push({ nextY, nextX });

                                          visited[nextY][nextX] = true;

                                 }

                         }

                 }

        }

}

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cin >> N >> M;

 

        for (int i = 0; i < N; i++)

                 for (int j = 0; j < M; j++)

                         cin >> cheese[i][j];

 

        int result = 0;

        while (1)

        {

                 if (allClear())

                         break;

                

                 BFS1();

                 BFS2();

                 PreairToAir();

                 result++;

        }

        cout << result << "\n";

        cout << lastCnt << "\n";

        return 0;

}
