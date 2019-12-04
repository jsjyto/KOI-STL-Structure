#include <iostream>
#include <cstring>
using namespace std;

int n ,m;
bool visited[52][52];
int map[52][52];
int dirx[8] = {0,0,1,-1,-1,1,-1,1};
int diry[8] = {-1,1,0,0,1,1,-1,-1};

void dfs(int y, int x)
{
	if(visited[y][x] || !map[y][x])
		return;
		
	for(int i=0;i<8;i++)
	{
		int nextx = x + dirx[i];
		int nexty = y + diry[i];
		
		if(nexty <n && nexty>=0 && nextx <m && nextx >=0)
		{
				dfs(nexty,nextx);
		}
	}
}

int main()
{
	n = 1, m  = 1;
	
		
	while(n!=0 || m!= 0)
	{
		cin >> n >> m;
	memset(visited,false,sizeof(visited));
	memset(map,0,sizeof(map));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> map[i][j];
			}
		}
		
		int cnt = 0;
		
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(map[i][j] && !visited[i][j])
				{
					dfs(i,j);
					cnt++;
				}
			}
		}
		
		cout << cnt << endl << endl;
	}
	return 0;
}
