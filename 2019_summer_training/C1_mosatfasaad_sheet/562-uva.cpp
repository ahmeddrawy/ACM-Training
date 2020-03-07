
//
// Created by ahmed_drawy on 03/09/19.
/// Manthan, Codefest 19 (open for everyone, rated, Div. 1 + Div. 2)
#include <bits/stdc++.h>
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
int dp[101][50001];
int dp2[50001];
int arr[101];
int  m , sum;
int solve(int indx , int currSum  ){
    if(indx == m ){
        return abs(sum - 2*currSum );
    }
    int &ret = dp[indx][currSum];
    if(~ret )
        return  ret;

    ret = min( solve(indx+1 , currSum + arr[indx]), solve(indx+1 , currSum)  );
    return ret ;
}
int main() {
    smile();
    int n ; cin >> n ;
    while(n--){
        cin >> m ;
        clr(dp , -1);

        inN(arr, m);
        sum = 0;
        lp(i,0,m)
            sum +=arr[i];
        cout << solve(0 , 0) <<endl;
        continue;
        clr(dp , 0 );
        for (int indx = 0; indx <m ; ++indx) {
            for (int k = sum ; k >0 ; --k) {
                if(arr[indx]<=k){
                    dp2[k] = max(dp2[k] , arr[indx ] + dp2[k-arr[indx]]);
                }
//                dp[j][k] = dp[j-1][k] +arr[j] *(k ==0? 1: -1);
            }
        }
        cout << sum - dp2[sum]<<endl;
    }

}