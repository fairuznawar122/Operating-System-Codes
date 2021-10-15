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
#define print cout<<*it<<" " 
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

int ef=0;
int efBestFit=0,efWorstFit=0;
vi tempH,tempR;
int main() {

    #ifndef ONLINE_JUDGE
    freopen("C:/Users/Lenovo/Desktop/OS Session 9/FirstFit//input.txt", "r", stdin);
    freopen("C:/Users/Lenovo/Desktop/OS Session 9/FirstFit//output.txt", "w", stdout);
    #endif

    string s,s1;
    getline(cin, s);

    vi holes,requests;
    stringstream is(s); 
    int tmp;
    while(is >> tmp) {
    holes.push_back(tmp);
    }
  
    getline(cin, s1);
    stringstream iss(s1); 
    int tmp1;
    while(iss >> tmp1) {
    requests.push_back(tmp1);
    }
    
    tempH=holes;
    tempR=requests;

//-----------------------FIRST FIT ---------------------------------
    cout<<"First Fit :"<<endl;
    bool allocated=false;
    for(int i=0;i<sz(requests);i++){
      allocated=false;
     cout<<requests[i]<<"---->";
      for(int j=0;j<sz(holes);j++){
        if(requests[i]<=holes[j]){
          holes[j]-= requests[i];
          allocated=true;
          break;
        }
        else{
          continue;
        }
      }
      if(!allocated){
       cout<<"Can't be allocated."<<endl;
        for(int i=0;i<sz(holes);i++){
          ef+=holes[i];
        }
        break;
      }
      tr(holes,it){
        print;
      }
      cout<<endl;
    }
    cout<<"External Fragmentation : "<<ef<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;

//--------------------------Best Fit-----------------------------
vii difference;
cout<<"Best Fit :"<<endl;
holes=tempH;
requests=tempR;


  for(int i=0;i<sz(requests);i++){
    cout<<requests[i]<<"---->";
    for(int j=0;j<sz(holes);j++){
      if(holes[j]>=requests[i])
      difference.push_back(make_pair((holes[j]-requests[i]),j));
      else{
        continue;
      }
    }
    if(difference.empty()){
      for(int x=0;x<sz(holes);x++){
        efBestFit+=holes[i];
      }
    }
    sort(all(difference));
    holes[difference[0].second]= difference[0].first;
    difference.clear();
    tr(holes,it){
      print;
    }
    cout<<endl;
  }
  cout<<"External Fragmentation : "<<efBestFit<<endl;
  cout<<endl;
  cout<<endl;
  cout<<endl;
//--------------------------Worst Fit-----------------------------
difference.clear();
cout<<"Worst Fit :"<<endl;
holes=tempH;
requests=tempR;
bool found=true;
int foundIndex;
  for(int i=0;i<sz(requests);i++){
    found=true;
    
    for(int j=0;j<sz(holes);j++){
      if(holes[j]>=requests[i])
      difference.push_back(make_pair((holes[j]-requests[i]),j));
      else{
        continue;
      }
    }
    if(difference.empty()){
      found=false;
      for(int x=0;x<sz(holes);x++){
        efWorstFit+=holes[x];
      }
    }
    
    sort(difference.begin(),difference.end(), [] (const pair<int,int> &a,  const pair<int,int> &b)  { return (a.first > b.first); });
    holes[difference[0].second]= difference[0].first;
    difference.clear();
    if(!found){
      foundIndex=i;
      break;
    }
    cout<<requests[i]<<"---->";
      tr(holes,it){
      print;
    }
    
    cout<<endl;
  }
  for(int i=foundIndex ;i<sz(requests);i++){
    cout<<requests[i]<<"---->"<<"Can Not be Allocated"<<endl;
  }

  cout<<"External Fragmentation : "<<efWorstFit<<endl;
return 0;
}
/*input
50 200 70 115 15
100 10 35 15 23 6 25 55 88 40
*/
