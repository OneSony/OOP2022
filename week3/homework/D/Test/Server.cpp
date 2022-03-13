#include<string.h>
#include"Server.h"

int Server::submit_task(Task task){
    int *space_buf=new int[task.task_num];
    int space_buf_cursor=0;
    bool flag=0;//1 found

    for(int i=0;i<n;i++){
        if(card_list[i]>=task.task_space){
            space_buf[space_buf_cursor]=i;
            space_buf_cursor++;
            if(space_buf_cursor==task.task_num){
                flag=1;
                break;
            }
        }
    }

    if(flag==0){
        delete[] space_buf;
        return 0;
    }

    //可以提交任务
    for(int i=0;i<task.task_num;i++){
        card_list[space_buf[i]]-=task.task_space;
    }

    //添加到task列表
    strcpy(task_list[task_num].task_name,task.task_name);
    task_list[task_num].sit=1;
    task_list[task_num].task_lasttime=task.task_lasttime;
    task_list[task_num].task_num=task.task_num;
    task_list[task_num].task_space=task.task_space;
    task_list[task_num].task_pos=new int[task.task_num];

    for(int i=0;i<task.task_num;i++){
        task_list[task_num].task_pos[i]=space_buf[i];
    }

    task_num++;//指向下一个空的

    return 1;
}

int Server::cancel_task(char* s){
    int flag=0;//1 found
    int i;
    for(i=0;i<task_num;i++){
        if(0==strcmp(task_list[i].task_name,s)&&task_list[i].sit==1){//相同同时正在运行
            task_list[i].sit=0;
            for(int ii=0;ii<task_list[i].task_num;ii++){
                card_list[task_list[i].task_pos[ii]]+=task_list[i].task_space;
            }
            flag=1;
            break;
        }
    }
    
    if(flag==0){
        return 0;//not found
    }

    return 1;
}

void Server::tick(){
    for(int i=0;i<task_num;i++){
        if(task_list[i].sit==1){
            task_list[i].task_lasttime--;
            if(task_list[i].task_lasttime==0){
                task_list[i].sit=0;
                for(int ii=0;ii<task_list[i].task_num;ii++){
                    card_list[task_list[i].task_pos[ii]]+=task_list[i].task_space;
                }
            }
        }
    }
}