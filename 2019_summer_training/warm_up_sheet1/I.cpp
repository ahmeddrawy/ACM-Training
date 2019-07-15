/*
    summer 2019 - warm up sheet - I
     by ahmed_drawy




*/
#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;

#define make_pair               mp;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2 *haven't understood this yet
#define isPowerOfTwo(S) (!(S & (S - 1)))            // done
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))  // TBD
#define turnOffLastBit(S) ((S) & (S - 1))       // turn off last unset bit from right
#define turnOnLastZero(S) ((S) | (S + 1))       //turn on last unset bit from right
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define inf 0x3f3f3f3f
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
//typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/www/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x)
{
    return (x%modul + modul)%modul;
}
const int N = 1001;
vector<int > g[N];
vector<int > cost(N);
bool removed[N];
int calcost(int indx ){
    int res = 0 ;
    for(auto it : g[indx]){
        res += !removed[it] * cost[it];     /// calcc if not removed
    }
    return res;
}
void markREMOVED(int indx){
    removed[indx] =1;
}
int main() {
    smile();
    int n , m ; cin >> n >> m ;
    map<int ,int >frq;
    lp(i,0,n){
        cin >>cost[i];
    }
    lp(i,0,m){
        int x , y ; cin >> x >> y;
        --x ,--y;
        g[x].push_back(y);
        g[y].push_back(x);
        frq[x]++;
        frq[y]++;
    }
    vector<pair <int , int > > graph ;  /// cost and indx
    lp(i,0,n){
        graph.push_back({cost[i] ,i });
    }
    sort(graph.rbegin() , graph.rend());    /// remove the ones with the highest costs first , greedy approach ,
    /// if you dont remove it you may have to pay it
    ll ans = 0 ;
    lp(i,0,n){
        auto curr  = graph[i];
        vector<pair<pair<int ,int> , int  > > res ; /// frq , cost
        res.push_back({{frq[curr.second] ,cost[curr.second] }, curr.second});
        while(true){        /// take all the nodes with the same cost and remove the one with the highest frq first
            if(graph[i+1] == curr){
                res.push_back({{frq[graph[i+1].second] ,cost[graph[i+1].second] } , graph[i+1].second }) ;
                ++i;
            }
            else break;
        }
        sort(res.rbegin() , res.rend());
        lp(j,0,res.size() ){
            ans += calcost(res[j].second);
            markREMOVED(res[j].second);
        }

    }
    cout<<ans;
}
