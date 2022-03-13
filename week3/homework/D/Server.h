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
    Server(int N,int M);

    ~Server(){
        delete[] card_list;
    }

    void tick();
    int submit_task(Task task);
    int cancel_task(char*);
};