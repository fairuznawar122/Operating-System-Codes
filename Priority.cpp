
#include<bits/stdc++.h>
using namespace std;

struct Process {

    int arrival,cpu, start_time,end_time, index,priority;
    bool done;
};

bool compareIndex(Process a, Process b) {

    return a.index<b.index;
}
bool compare(Process a, Process b) {

    return a.priority<b.priority;
}


int main() {

    int nprocess,waiting_time,turn_around,start_time,end_time,least_priority;
    bool prev_process;
    queue<Process> q;

    printf("No of process: ");
    scanf("%d",&nprocess);
    struct Process p[nprocess],current;
    for(int i=0;i<nprocess;i++) {
        printf("Process %d enter arrival time and cpu time and priority: ",i+1);
        scanf("%d %d %d",&p[i].arrival,&p[i].cpu,&p[i].priority);
        p[i].index=i;
    }

    sort(p,p+nprocess,compare);

    q.push(p[0]);
    prev_process= false;

    while(!q.empty()){
        current = q.front();
        q.pop();

        if(prev_process){
          start_time= end_time;
        }
        else{
            start_time= current.arrival;
        }
        prev_process= true;
        end_time = start_time+current.cpu;

        for(int i=0; i<nprocess; i++){
            if(current.index==p[i].index){
                p[i].done = true;
                p[i].start_time= start_time;
                p[i].end_time= end_time;
            }
        }

       for(int i=0; i<nprocess; i++){
            if(!p[i].done){
                q.push(p[i]);
            }
        }

    printf("%d----->%d--->p%d\n",start_time,end_time,current.index+1);
    }

    for(int i=0; i<nprocess; i++){
        waiting_time= p[i].start_time - p[i].arrival;
        turn_around= p[i].cpu + waiting_time;
        printf("Process%d----->Waiting Time: %d TurnAround Time--->%d\n",i+1,waiting_time,turn_around);
    }



    return 0;
}
