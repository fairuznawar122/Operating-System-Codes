#include<bits/stdc++.h>
using namespace std;
struct Process{
    int index;
    vector<int > aloc;
    vector<int > max_r;
    vector<int > need;

};
int n,r, x,y, max_n,al,av;
vector<Process >v;
vector<int > available;

bool executable(Process t){

    for(int i=0;i<r;i++){
        if(t.need[i]<=available[i]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}



int main(){


    //No of Process,resource;
    cin>>n>>r;

    //No of Resource;
    for(int i=0;i<r;i++){
         printf("Resource%d : ",i+1);
        cin>>av;
        available.push_back(av);
    }

    for(int i=0; i<n; i++){
struct Process p;
        for(int j=0; j<r;j++){

            //MAX
            printf("\nMax of Process%d Resource%d : ",i+1,j+1);
            cin>>max_n;
            p.max_r.push_back(max_n);

            printf("\n Allocated of Process%d Resource%d : ",i+1,j+1);
            cin>>al;
            p.aloc.push_back(al);
            available[j]-=al;
            //need
            p.need.push_back(max_n-al);
            p.index= i+1;
        }
        v.push_back(p);
    }
    while(!v.empty()){
        for(vector<Process >::iterator it=v.begin();it!=v.end();){
                struct Process x= *it;
                if(executable(x)){
                    for(int i=0; i<r;i++){
                        available[i]+=x.aloc[i];
                    }
                    printf("\nP%d",x.index);
                    v.erase(it);
                    break;
                }
                else {
                    it++;
                }
        }
    }




return 0;
}
