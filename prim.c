//利用prim算法在一个无向图中找出最小生成树
//prim算法基本上和求最短路径的dijkstra算法一样
//一个无向图G的最小生成树就是由该图的那些连接G的所有顶点的边构成的树,且其总价值最低

#include "stdio.h"

#define MAX_NUM 100
#define MAX_INT 9999

int dist[MAX_NUM];
int c[MAX_NUM][MAX_NUM];
int pre[MAX_NUM];


void Prim(int s, int n, int dist[], int c[][MAX_NUM], int pre[])
{
    int min;
    int i;
    int visit[MAX_NUM] = {0};
    int v;
    int flag;
    dist[s] = 0; 
    for(;;){
        min = MAX_INT;
        flag = 0;
        for(i = 0;i < n;i++){
            if((min > dist[i]) && (visit[i] == 0)){
                min = dist[i]; 
                v = i;
                flag = 1;
            } 
        }
        if(flag == 0){
            break; 
        }
        visit[v] = 1;
        for(i = 0;i < n;i++){
            if((c[v][i] < MAX_INT) && (visit[i] == 0)){
                if(c[v][i] < dist[i]){
                    dist[i] = c[v][i]; 
                    pre[i] = v;
                }
            } 
        }
    }
    for(i = 0;i < n;i++){
        printf("i:%d, pre[i]:%d, dist[i]:%d\n", i, pre[i], dist[i]);
    }

}
int main()
{
    int n, line;
    int i, j;
    int p, q, len;
    freopen("prim_data.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &line);
    for(i = 0;i < n;i++){
        dist[i] = MAX_INT; 
        for(j = 0;j < n;j++){
            c[i][j] = MAX_INT; 
        }
    }

    for(i = 0;i < line;i++){
        scanf("%d", &p); 
        scanf("%d", &q); 
        scanf("%d", &len); 
        c[p][q] = len;
        c[q][p] = len;
        //printf("c[%d][%d]: %d\n", p, q, c[p][q]);
    }
    Prim(0, n, dist, c, pre);
    return 0;
}
