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
    freopen("C:/Users/Lenovo/Desktop/NON CONTIGUOUS//input.txt", "r", stdin);
    freopen("C:/Users/Lenovo/Desktop/NON CONTIGUOUS//output.txt", "w", stdout);
    #endif

    int tc,n,x,y,temp,blocks,fileSize;
    char fileName;
    cin>>blocks;
    cin>>tc;
    vector< char > memory(blocks,'#');
    vector< pair< char, vector< int > > > v;

    while(tc--){
      vi temp;
      bool allocated=false;
      int spaceFound=0;
      cin>>fileName>>fileSize;

      for(int i=0;i<blocks;i++){
        if(memory[i]=='#'){
          //empty space found
          spaceFound++;
          temp.push_back(i);
        }
        if(spaceFound==fileSize){
          allocated=true;
          break;
        }
      }
      if(allocated){
        for(int i=0; i<fileSize;i++){
        memory[temp[i]]=fileName;
        }
        cout<<"File "<<fileName<<" Allocated"<<endl;
        v.push_back(make_pair(fileName,temp));

      }
      else{
        cout<<"File "<<fileName<<" can't be allocated"<<endl;
      }

    }

    //Manually Changing A's Locations
    memory[1]='#';
    memory[2]='#';
    memory[3]='#';
    memory[19]='A';
    memory[9]='A';
    memory[8]='A';
    vi t= {0,8,9,19};
    v[0]= make_pair('A',t);


    //Searching
    cout<<endl;
    cout<<endl;
    cout<<"File Search : "<<endl;
    int tcSearch;
    cin>>tcSearch;
    char searchedFile;
    while(tcSearch--){
      cin>>searchedFile;
      int foundIndex=0;
      bool found=false;
      for(int i=0;i<sz(v);i++){
        if(v[i].first==searchedFile){
          foundIndex=i;
          found=true;
          break;
        }
      }
      if(found){
        cout<<"File "<<searchedFile<<" found in the blocks : ";
        for(int i=0; i<sz(v[foundIndex].second);i++){
          cout<<v[foundIndex].second[i]+1<<" ";
        }
        cout<<endl;
      }
      else{
        cout<<"File "<<searchedFile<<" NOT found."<<endl;
      }
    }

    return 0;
}