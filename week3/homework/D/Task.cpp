#include<string.h>
#include"Task.h"

Task::Task(char* s,int d,int n,int m){
    strcpy(task_name,s);
    task_lasttime=d;
    task_num=n;
    task_space=m;
}