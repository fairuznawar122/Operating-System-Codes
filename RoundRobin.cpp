#include<bits/stdc++.h>
using namespace std;


struct Process{

    int index, arrival_time, cpu_time, remaining_time;
    vector<pair<int,int> >duration;
};
int main(){

    int n, wait_time, turn_around_time, start_time, end_time, quantum, avg_waiting_time, avg_tat;
    bool prev;

    vector<pair<int,int> >:: iterator it2,it;


    printf("No of Process : ");
    scanf("%d",&n);
    struct Process p[n], current;

    for(int i=0; i<n; i++){
    printf("\nEnter Arrival Time & CPU Time of Process %d: ",i+1);
    scanf("%d %d",&p[i].arrival_time ,&p[i].cpu_time );
    p[i].index=i;
    p[i].remaining_time= p[i].cpu_time;
    }
    printf("Time Quantum : ");
    scanf("%d",&quantum);


    queue<Process>q;
    prev= false;
    q.push(p[0]);

    while(!q.empty()){

        current = q.front();
        q.pop();
        if(prev){
          start_time = end_time;
        }
        else{
            start_time= current.arrival_time;
        }
        prev= true;
        current.remaining_time -= quantum;
        if(current.remaining_time<=0){
            end_time= quantum+current.remaining_time+start_time;
        }
        else{
            end_time= start_time+quantum;
        }

        for(int i=0; i<n ; i++){
            if(current.index== p[i].index){
                p[i].remaining_time= current.remaining_time;
                p[i].duration.push_back(make_pair(start_time,end_time));
                break;
            }
        }

        for(int i=0; i<n; i++){
            if(p[i].index==current.index){
                continue;
            }
            if((p[i].remaining_time>0)){
                    q.push(p[i]);
            }
        }

        printf("%d----->%d--->p%d\n",start_time,end_time,current.index+1);
    }







return 0;
}
