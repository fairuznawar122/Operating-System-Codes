#include <bits/stdc++.h>
using namespace std;

struct p{

    int no;
    int atime;
    int ct;
    int wt;
    int tat;

};

int main(){
int n;
cout<<"No of process: ";
cin>>n;
int atime[n], ctime[n];
int satime[n], sctime[n];
int gnatt[n+1];
int qu[n-1]
struct p a[n];

for (int i=0 ; i<n; i++){
    cout<<"Process No: ";

    cin>> a[i].no;
    cout<<"Arrival time :";
    cin>> atime[i];
    a[i].atime = atime[i];
    cout<<"CPU time :";
    cin>> ctime[i];
    a[i].ct = ctime[i];
    a[i].tat = 0;
    a[i].wt =0;

}
//sorting arrival time
    while(n){

        int maxv= 1000;
        for (int i=0; i<n; i++){
            if (maxv<atime[i]){
                maxv= atime[i];
            }
            else continue;
        }
        satime[n]= maxv;
        n--;
    }
//initialiazing gnatt
    gnatt[0] = 0;

    for(int i=0; i<n; i++){
       if( a[i].atime == satime[0])
       {
           gnatt[i+1]= gnatt[0]+ a[i].ct;
           satime[0] = NULL;
           break;
       }
       else continue;
    }
//sorting cpu time
    while(n){

        int maxv= 1000;
        for (int i=0; i<n; i++){
            if (maxv<ctime[i]){
                maxv= ctime[i];
            }
            else continue;
        }
        sctime[n]= maxv;
        n--;
    }




}
