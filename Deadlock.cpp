#include<bits/stdc++.h>
using namespace std;

vector<char >path_list;
int n;
char check;
int s,v;
char th;


struct Process{
    int index;
    char name;
    vector<char> path;
    bool done;
};

struct Process p[50];

bool deadlock_found(){

    if(path_list.empty()) {
            return false;
    }
    for(int s=0; s<path_list.size(); s++){
            th=path_list[s];
        if(check==th){
            return true;
        }
    }
    return false;
}



void find_deadlock(int i){
    for(auto it: path_list){
        printf("%c-->",it);
    }

    printf("%c\n",check);

    if(deadlock_found()){
        printf("Cycle Detected: ");
        bool print =false;
        for(auto it: path_list){
            if(it==check) print=true;
            if(print){
                printf(" %c",it);
            }
        }
        printf("\n");
        path_list.clear();
        return;
    }

    p[i].done= true;
    if(!p[i].path.empty()){
        path_list.push_back(p[i].name);
        for( vector<char>::iterator it=p[i].path.begin(); it!=p[i].path.end();it++){
            for(int j=0; j<n; j++){
                if(*it==p[j].name){
                        check=*it;
                        *it='-1';
                        find_deadlock(j);

                }
            }
        }
    }


return;
}

int main(){

    cout<<"No of Nodes: ";
    cin>>n;
    cout<<"Nodes: "<<endl;
    getchar();
    for(int i=0; i<n; i++){
        scanf(" %c",&p[i].name);
        getchar();
        p[i].done= false;
        p[i].index= i;
    }
    int e;
    char x,y;
    cout<<"No of edges: ";
    cin >>e;
    cout<<"Edges: "<<endl;
    getchar();
    for(int i=0; i<e; i++){
        scanf("%c %c",&x, &y);
        getchar();
       for(int j=0; j<n; j++){
        if(p[j].name==x){
            p[j].path.push_back(y);
            break;
        }
       }
    }

    for(int i=0;i<n;i++){
        if(!p[i].done){
            path_list.clear();
            check=p[i].name;
            find_deadlock(i);
        }
    }

return 0;

}

