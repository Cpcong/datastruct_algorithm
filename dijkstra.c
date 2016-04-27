//Dijkstra算法
#include "stdio.h"

#define MAX_NUM 100
#define MAX_INT 9999 

int c[MAX_NUM][MAX_NUM];//记录图的两点记录长度
int dist[MAX_NUM];//记录源点到当前节点的最短距离
int pre[MAX_NUM];//记录上个节点

void PrintPath(int v, int pre[])
{
    if(pre[v] != -1){
        PrintPath(pre[v], pre); 
        printf(" to");
    }
    printf("%d", v);
}
void Dijkstra(int s, int n, int dist[], int c[][MAX_NUM], int pre[])
{
    int i;
    int v, w;
    int min;
    char flag;
    char visit[MAX_NUM] = {0}; 
    dist[s] = 0;//源节点距离置为0
    for(;;){
        flag = 0;
        min = MAX_INT;
        for(i = 0;i < n;i++){
            if(visit[i] == 0 && dist[i] < min){
                flag = 1;
                min = dist[i];//找出未访问过的最小距离节点 
                v = i;
            } 
        }
        if(flag == 0){//未找到，完成，退出
            break; 
        }
        visit[v] = 1;
        for(i = 0;i < n;i++){
            //找出v的未访问过的临接节点
            if((c[v][i] < MAX_INT) && (visit[i] == 0)){
                //若该路径更好，则进行调整
                if(dist[v] + c[v][i] < dist[i]){
                    dist[i] = dist[v] + c[v][i]; 
                    pre[i] = v;
                } 
            } 
        }
    }
    
}

int main()
{
    int n, line;
    int i, j;
    int p, q, len;
    freopen("dijkstra_data.txt", "r", stdin);
    scanf("%d", &n);//结点数
    scanf("%d", &line);//边数

    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            c[i][j] = MAX_INT;//初始化两点间距离 
        } 
    }
    for(i = 0;i < line;i++){
        scanf("%d", &p); 
        scanf("%d", &q);
        scanf("%d", &len);
        if(c[p][q] > len){
            c[p][q] = len; 
            c[q][p] = len;//无向图 
        }
    }
    for(i = 0;i < n;i++){
        dist[i] = MAX_INT;//初始化最短距离
    }
    for(i = 0;i < n;i++){
        pre[i] = -1;//初始化各个节点的上一个节点 
    }
    Dijkstra(0, n, dist, c, pre);
    PrintPath(4, pre);
    return 0;
}
