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
#define what_is(x) cout << x << endl;//for error purpose-> what_is(a_variable)
vector<int> split(const string &s, char delimiter) {
    vector<int> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}



int movSSTF=0;
vi v;
vi sv;
int currentHead;
int currentHeadIndex;

void smallestSeekTime(int index){
    int diff1,diff2;
    if(index>0){
         diff1=sv[index]-sv[index-1];
    }
    if(index<sz(sv)){
         diff2=sv[index+1]-sv[index];
    }
    if(diff1<diff2){
        currentHead=sv[index-1];
        movSSTF+=diff1;
    }
    else if(diff2<diff1){
        currentHead=sv[index+1];
        movSSTF+=diff2;
    }
    vi::const_iterator it=sv.begin()+index;
    sv.erase(it);
    for(int i=0;i<sz(sv);i++){
            if(sv[i]==currentHead){
                currentHeadIndex=i;
                break;
            }
    }

    return;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("D:/OS LAB AFTER MID/OS/Disk//input.txt", "r", stdin);
    freopen("D:/OS LAB AFTER MID/OS/Disk//output.txt", "w", stdout);
#endif

    int h;
    cin>>h;
    int low,high;
    cin>>low>>high;

    string s,tmp;
    getchar();
    getline(cin,s);
    vi small,large;
    int movCSCAN=0;
    istringstream tokenStream(s);
    while (getline(tokenStream, tmp, ',')) {
        v.push_back(stoi(tmp));
    }
    //----------------------CSCAN-----------------------
    tr(v,it){
        if(*it<h)
            small.push_back(*it);
        else
            large.push_back(*it);
    }
    sort(all(small));
    sort(all(large));
    int currentPoint=h;
    what_is(currentPoint);
    for(int i=0;i<sz(large);i++){
        movCSCAN+= abs(large[i]-currentPoint);
        currentPoint=large[i];
        what_is(currentPoint);
    }
    if(currentPoint<high){
        movCSCAN+= abs(high-currentPoint);
        what_is(high);
    }
    movCSCAN+=(high-low);
    currentPoint=low;
    what_is(currentPoint);
    for(int i=0;i<sz(small);i++){
        movCSCAN+= abs(small[i]-currentPoint);
        currentPoint=small[i];
        what_is(currentPoint);
    }
   cout<<"CSCAN-->Total Cylinder Movement: "<<movCSCAN<<endl;
    /*tr(large,it){
        print;
    }*/
//-----------------------------------SSTF------------------------------------
    sv=v;
    sv.push_back(h);
    sort(all(sv));

    currentHead=h;
    for(int i=0;i<sz(sv);i++){
            if(sv[i]==currentHead){
                currentHeadIndex=i;
                break;
            }
    }

    while(sz(sv)>2){
        what_is(currentHead)

    
    smallestSeekTime(currentHeadIndex);
    }

    movSSTF+= (sv[1]-sv[0]);
    cout<<"SSTF-->Total Cylinder Movement: "<<movSSTF<<endl;


    return 0;
}
