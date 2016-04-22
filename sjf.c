//最短作业优先算法,求出平均等待时间
#include "stdio.h"

float SJF(int *requests, int *durations, int n)
{
    int i, j, k;
    int time = 0;
    int sum = 0;
    int nextTaskIndex;
    int nextTaskDur;
    int visit[10] = {0};
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){//挑选出一个满足请求时间小于已经过时间并且没处理过的任务
            if(requests[j] <= time){
                if(visit[j] == 0)
                {
                    nextTaskIndex = j; 
                    nextTaskDur = durations[j];
                    break;
                }
            } 
        } 
        if(j >= n){//处理这种情况:剩下的任务中没有一个请求时间小于已经过时间，即没任务可处理
             for(j = 0;j < n;j++){
                if(visit[j] == 0){
                    nextTaskIndex = j; 
                    nextTaskDur = durations[j];
                    time = requests[j];
                    sum = sum + time - requests[nextTaskIndex];
                    time += nextTaskDur; 
                    visit[nextTaskIndex] = 1;
                    break; 
                } 
             } 
             continue;
        }
        for(j = 0;j < n;j++){//选出耗时最少的任务
            if(requests[j] <= time){
                if(durations[j] < nextTaskDur){
                    if(visit[j] == 0){
                        nextTaskIndex = j; 
                        nextTaskDur = durations[j];
                    } 
                } 
            } 
        }
        sum = sum + time - requests[nextTaskIndex];
        time += nextTaskDur; 
        visit[nextTaskIndex] = 1;
    }
    return ((float)sum)/((float)n);
}

int main()
{
    int requests[4] = {0, 3, 4, 5};
    int durations[4] = {1, 1, 2, 1};
    printf("%f\n", SJF(requests, durations, 4));
    return 0;
}
