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
int n ;
int arr[55];
int dp[55][1001];
int solve (int indx , int rem ){
//    if(rem == 0 )return 0 ;
    if(indx == n ){
        return rem;
    }
    int &ret = dp[indx][rem];
    if(~ret )return ret;
    ret= rem ;
    if(indx != n-1)
        ret= solve(indx+1, rem);
    if(arr[indx] <=rem){
        ret = min(ret, solve(indx+1, rem - arr[indx]));
    }
    return  ret ;

}
vector<int > pv;
void path (int indx , int rem ){
//    if (rem == 0 )return ;
    if(indx == n ){
        return ;
    }
    int mx1= 2000 , mx2= 2001 ;
    if(indx != n-1)
        mx1= solve(indx+1, rem);
    if(arr[indx] <=rem){
        mx2 = solve(indx+1, rem - arr[indx]);
    }
    if(mx1 < mx2){
        path(indx+1, rem);
    }
    else if(mx2 <=mx1) {/// equal we have to choose the appeared first; which is the current indx
        pv.push_back(indx);
        path(indx+1, rem-arr[indx]);
    }

    return   ;

}
int main() {
    smile();
    int t ;
    while(true){
        cin >> t;
        if(!t)
            break;
        cin >> n ;
        lp(i,0,n)cin >>arr[i];
        clr(dp , -1);
        int ret=  t- solve(0,t);
        pv.clear();
        path(0,t);

        for(auto it : pv) cout << arr[it]<<" ";
        cout << ret  ;
        cout << endl;

    }

}