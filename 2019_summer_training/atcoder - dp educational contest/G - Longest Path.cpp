// Created by ahmed_drawy on 11/09/19.
///dp educational contest atcoder
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
#define cint(c) (int)c -'0';
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
#define fastin smile()

int n , m;
const int N = 1e5 +3;
vector<int>g[N];
int dp[N];
int solve(int node ){
    if(node == n)return 0;
    int &ret = dp[node];
    if(~ret)
        return ret;
    ret =0 ;
    for(auto it : g[node]){
        ret = max(ret , 1+ solve(it));
    }

    return ret;



}
//bool visited[5005];

int main() {
    fastin;
    cin >> n >> m;
    lp(i,0,m){
        int x , y ;cin >> x>>y;
        --x, --y;
        g[x].push_back(y);
    }
    clr(dp , -1);
    int ans = 0 ;
    for (int j = 0; j < n; ++j) {
        if(dp[j] ==-1)
            ans = max(ans , solve(j));
    }
    cout <<ans;

}