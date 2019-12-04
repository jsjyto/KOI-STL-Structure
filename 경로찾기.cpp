#include <iostream>
#include <cstring>
using namespace std;
 
int n;
bool visited[100];
int map[100][100];
int result[100][100];

void dfs(int s, int u) {
 
    for(int i=0; i<n;i++) 
	{
        if(map[u][i] && !visited[i]) 
		{
            visited[i] = 1;
            result[s][i] = 1;
            dfs(s, i);
        }
    }
}
 
int main() {
 

    scanf("%d", &n);
 
    for(int i=0; i<n; i++) {    // digraph input
        for(int j=0; j<n; j++)
            scanf("%d", &map[i][j]);
    }
 
 
 
    for(int i=0; i<n; i++) {
    	memset(visited,false,sizeof(visited));
        dfs(i, i);
        
    }
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}

