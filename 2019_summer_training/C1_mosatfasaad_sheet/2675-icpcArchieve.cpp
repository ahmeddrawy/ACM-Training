
//
// Created by ahmed_drawy on 03/09/19.
/// 10325 uva - c1 sheet
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
#endif // ONLINE_JUDGE
}
/**another solution
 * int dp [101][101];
int a[101];
int p[101];

int c ;
int solve(int i , int lst ){
    if(i == c){
        if(lst== c )return 0;

        return INT_MAX;
    }
    int  &ret= dp[i][lst];
    if(~ret )
        return ret ;
    int sum = 10 ;
    for (int j = lst; j <=i ; ++j) {
        sum+=a[j];
    }
    ret = INT_MAX;
    ret = (sum)*p[i] +solve(i+1 , i+1);

    ret = min(ret , solve(i+1 , lst));

    return ret;
}

 *
 *
 *
 */
int dp [101][100001];
int a[101];
int p[101];

int c ;
int solve(int i , int rem ){
    if(i == c){
        if(rem== 0 )return 0;

        return INT_MAX;
    }
    int  &ret= dp[i][rem];
    if(~ret )
        return ret ;
    ret = INT_MAX;
    ret = (a[i] + rem +10)*p[i] +solve(i+1 , 0);
    ret = min(ret , solve(i+1 , rem +a[i]));

    return ret;
}
int main() {
    smile();

    int t ; cin >> t;
    while (t-- ){
        cin >> c;
        clr(dp ,-1);
        lp(i,0,c)cin>>a[i]>>p[i];
        cout << solve(0,0)<<endl;
    }

}