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
const int N = 3000 +3;
int dp[N][N];
string s, t;
int lcs(int i , int j ){
    if(i == n || j ==m )
        return 0 ;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    ret = 0;
    if(s[i] == t[j])
        ret =1 +  lcs(i+1 , j+1);
    else {
        ret = max(ret, lcs(i + 1, j));
        ret = max(ret, lcs(i, j + 1));
    }
    return ret;
}
void build(int i , int j){
    if(i == n || j ==m )
        return  ;
    if(s[i] == t[j]) {
        cout << s[i];
        build(i+1, j+1);
        return ;
    }
    if(dp[i+1][j] > dp[i][j+1] )
        build(i+1, j);
    else build(i, j+1);
    return ;

}
int main() {
    fastin;
    cin >> s >> t;
    n = sz(s), m = sz(t);
    for (int i = n-1; i >=0 ; --i) {
        for (int j = m-1; j>=0 ; --j) {
            int &ret = dp[i][j];
            ret = 0;
            if(s[i] == t[j])
                ret =1 +  dp[i+1][j+1];
            else {
                ret = max(ret, dp[i + 1][j]);
                ret = max(ret, dp[i][j+1]);

            }
        }
    }
//    clr(dp , -1);
//    lcs(0,0);
    build(0,0);


}