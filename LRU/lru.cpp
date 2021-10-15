#include<bits/stdc++.h>

using namespace std;

typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000 
#define f first
#define s second
#define PI acos(-1)
#define rep(i, a, b) for (int i = int(a); i != int(b); i++) 
#define eb emplace_back
#define mt make_tuple
#define mp make_pair
#define sz(c) c.size()
#define print cout<<*it<<endl 
#define present(container,element)(container.find(element)!=container.end())
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
#define all(c) c.begin(),c.end()
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define pow2(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m)
#define LSOne(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2s
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define lambdaAscSort [](int a,int b){ return a<b; }
#define what_is(x) cout << #x << x << endl;//for error purpose-> what_is(a_variable)

string s;
vi v;
int position,frame_index;
vi frame;
int noPages,noFrames,noRefrences,pf=0,ph=0;
 
bool pageIncluded(int current){

    for(int x=0;x<noFrames;x++){
        if (frame[x]==current){
            return true;
        }
    }
    return false;
}

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/Lenovo/Desktop/OS/LRU//input.txt", "r", stdin);
    freopen("C:/Users/Lenovo/Desktop/OS/LRU//output.txt", "w", stdout);
    #endif

    cin>>noPages>>noFrames>>noRefrences;
    getchar();
    getline(cin, s);

    stringstream is(s); 
    int tmp;
    while(is >> tmp) {
    v.push_back(tmp);
    }

    

    for(int i=0;i<noRefrences;i++){
        int current = v[i];
        /*tr(frame,it){
            cout<<*it<<" ";   
        }
        cout<<endl;*/

        if(i<noFrames){
            pf++;
            frame.push_back(current);
        }
        else if(pageIncluded(current)){
            ph++;
        }
        else{
            int k;
            position=1000;
            for(int j=0;j<noFrames;j++){

                for( k=i-1;k>=0;k--){
                  
                    if(v[k]==frame[j]){
                        if(position>k){
                            position=k;
                            frame_index=j;
                        }
                        break;
                    }
                    
                }
            }
            
            frame[frame_index]=v[i];
            pf++;
            
        }
        
    }
    int rate;
    rate=ceil(((float)pf/(float)noRefrences)*100);
    cout<<"Page Fault In LRU: "<<pf<<endl;
    cout<<"Fault Rate: "<<rate<<"%"<<endl;
    return 0;

}
/*Input
8
3
22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
*/