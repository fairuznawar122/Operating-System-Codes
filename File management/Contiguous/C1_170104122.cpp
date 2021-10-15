/*Input 
200
3
A 4
B 400
C 40
2
A
D
*/


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

int main() {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/Lenovo/Desktop/OS FILE MANAGEMENT//input.txt", "r", stdin);
    freopen("C:/Users/Lenovo/Desktop/OS FILE MANAGEMENT//output.txt", "w", stdout);
    #endif

//-------------------Contiguous allocation--------------------------
    int blocks, tc,fileSize;
    char fileName;
    cin>>blocks;
    cin>>tc;
    int blockSequeceSize, sequenceStart;
    bool allocated=false;
    vector <char> memory(blocks,'#');
    while (tc--)
    {
      cin>>fileName>>fileSize;
      blockSequeceSize= 0;
      sequenceStart=0;
      if(fileSize>blocks){
        cout<<"File "<<fileName<<" cannot be created"<<endl;
        continue;
      }
      else{
        for(int i=0; i<blocks; i++){
        if(blockSequeceSize>=fileSize){
          allocated=true;
          break;
        }
        if(memory[i]=='#'){
          blockSequeceSize++;
        }
        if(blockSequeceSize==1){
          sequenceStart=i;
        }
      }
      if(allocated){
        for(int j=sequenceStart;j<fileSize;j++){
        memory[j]=fileName;
        }
        cout<<"File "<<fileName<<" created"<<endl;
      }
      else
      {
        cout<<"File "<<fileName<<" cannot be created"<<endl;
        what_is(fileSize);
      }
      }
    }
    //searching
    cout<<endl;
    cout<<endl;
    cout<<"Searching Result : "<<endl;
    int tcSearch, startIndex,size=0;
    char fileSearch;
    cin>>tcSearch;
    bool found=false;
    while(tcSearch--){
      cin>>fileSearch;
      size=0;
      for(int i=0; i<blocks;i++){
        if(memory[i]==fileSearch){
          size++;
          found=true;
        }
        if(size==1){
          startIndex=i;
        }
      }
      if(found){
        cout<<"File "<<fileSearch<<" Found in the blocks : ";
        for(int i=startIndex;i<size;i++){
          cout<<i+1<<" ";
        }
      }
      else
      {
        cout<<endl;
        cout<<"File "<<fileSearch<<" Not Found"<<endl;
      }
      found=false;


    }



    return 0;
}