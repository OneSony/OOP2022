#ifndef TASK
#define TASK
#include"Task.h"
#endif

class Server{
    int n;//几张卡
    int *card_list;
    Task task_list[201];
    int task_num;

public:
    Server(int N,int M){
        n=N;
        card_list=new int[n];
        task_num=0;

        for(int i=0;i<n;i++){
            card_list[i]=M;
        }
    }

    ~Server(){
        delete[] card_list;
    }

    void tick();
    int submit_task(Task task);
    int cancel_task(char*);
};