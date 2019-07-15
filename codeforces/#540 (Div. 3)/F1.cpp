/*
   E - #540 (Div. 3) - upsolving

  22/02/19
  by ahmed_drawy



*/

#include <bits/stdc++.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
//#define push_bac                pb;
//#define make_pair               mp;
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



typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;


const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/www/Desktop/training/in.txt", "r" , stdin);
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE


}
ll n , k ;
const int N = 300005;
vector<vector<int > > mvec(N);
bool visited[N];
int arr[N];
vector<pii> mp;

void dfs(int par  , int &b   , int &r ){
    visited[par] =1;
    for(auto it : mvec[par] ){
        if(!visited[it]){
            if(arr[it] == 1){
                r++;
            }
            else if(arr[it ]) b++;

            dfs(it, b , r);

        }
    }

}
int main() {
    smile();
    cin >> n ;
    lp(i,0, n ){
        cin >>arr[i+1] ;
    }
    int x , y;
    lp(i,0,n-1){
        cin >>x>>y;
        mvec[x].push_back(y);
        mvec[y].push_back(x);
        mp.push_back({x,y});
    }
    int ans = 0 , b1 = 0 , b2= 0 , r1 = 0  , r2 = 0;
    lp(i,0,n-1){
        auto it = mp[i];
        memset(visited , 0 , sizeof(visited));
        b1 = arr[it.first]== 2;
        r1 = arr[it.first] ==1;
        b1= arr[it.second] == 2;
        r2 = arr[it.second] ==1;
        visited[it.second] =1;
        dfs(it.first ,b1 , r1 );
        memset(visited , 0 , sizeof(visited));
        visited[it.first] =1;
        dfs(it.second,b2, r2);
        if(b1 == r2 && b2 == 0 && r1 == 0){
            ans++;
        }
        else if(b2 == r1 && b1 == 0 && r2 == 0)ans++;

    }
    cout<<ans;



}
