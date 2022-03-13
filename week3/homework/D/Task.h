#define TASK

class Task{
public:
    char task_name[30];
    int task_lasttime;
    int task_num;
    int task_space;
    int *task_pos;
    int sit;//1 运行

    Task(char* s,int d,int n,int m);
    Task(){
    }
};