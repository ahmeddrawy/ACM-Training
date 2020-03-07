// Created by ahmed_drawy on 10/09/19.
///dp educational contest atcoder - vjudge
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

int n ;
const int N = 1e5 +3;
ll dp[N];
int h[N];
int main() {
    fastin;
    int k;
    cin >> n;
    k=2;
    inN(h, n);
    for (int l = 0; l < n; ++l) {
        dp[l] = inf;
    }
    dp[0] = 0;
    for (int j = 1; j < n; ++j) {
        for (int i = j - 1, m = 0; i >= 0 && m < k; m++, --i) {
            dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }
    cout << dp[n - 1];
}