// Created by ahmed_drawy on 07/09/19.
/// 2019 ICPC Malaysia National
#include <bits/stdc++.h>
#include <string.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define inf 0x3f3f3f3f
//#define dbg (v)    for(auto it : v)cout<<it<<' ';
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
#define endl '\n'
#define cint(c) (int)c -'A';
#define itc(c) (char)c +'A';
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
const int MOD = 1000000007;
ll dp[2001][1<<9];

map<pii , bool> mmap;
int n , e ;
long long add(long long x, long long y){
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}

bool valid(int indx ){
    return indx >=0 && indx<n;
}
ll solve(int i , int msk  ){

    if(i == n)
        return 1;
    ll &ret = dp[i][msk];
    if(~ret)
        return ret;
    ret = 0 ;
    for (int l = e; l >= 0; --l) {
        int d = e-l;
        if(!mmap[{i , i-d}] && !(msk&(1<<l)) && valid(i-d)) {
            int nwmsk = msk | (1<<l);
            nwmsk>>=1;
            ret = add(ret , solve(i+1, nwmsk));
        }
    }
    for (int l = e+1; l <= 2*e; ++l) {
        int d = l-e;
        if(!mmap[{i , i+d}] && !(msk&(1<<l)) && valid(i+d)) {
            int nwmsk = msk | (1<<l);
            nwmsk>>=1;
            ret = add(ret , solve(i+1, nwmsk));
        }
    }

    return ret%MOD;


}

int main() {
    smile();
    int k ;
    cin >> n >> e >> k ;
    lp(i,0,k){
        int x, y ; cin >> x >> y;
        mmap[{x-1,y-1}]=1;
    }
    clr(dp , -1);
    cout << solve(0,0);
}