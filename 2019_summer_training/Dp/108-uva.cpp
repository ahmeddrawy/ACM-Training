//
// Created by ahmed_drawy on 14/08/19.
// 108 uva- dp  sheet
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
//typedef first                    ft;
//typedef second                   sd;
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
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}
int kadane(int &l , int &r , int temp[] , int n ){
    int mx = INT_MIN ,  ll = 0 , curr = 0 ;
    r = -1;
    for (int i = 0; i <n ; ++i) {
        curr += temp[i];
        if(curr < 0 ){
            curr = 0 ;
            ll = i+1 ;
        }
        else {
            if(mx < curr){
                mx = curr ;
                l = ll ;
                r= i ;
            }
        }
    }
    if(r == -1) {
        mx = temp[0];
        lp(i, 0, n) {
            if (temp[i] >= mx) {
                l = r = i;
                mx = temp[i];
            }
        }
    }
    return mx ;


}
int n;
int arr[101][101];
int kadane2D(){
    int mx = INT_MIN , l = 0 , r = 0  , u = 0 , d = 0;
    puts("");
    for (int left = 0; left < n  ; ++left) {

        int temp[n];
        clr(temp , 0 );
        for (int right = left; right < n; ++right) {
            for (int i = 0; i <n ; ++i) {   /// row
                temp[i] +=arr[i][right];
            }
            int ll=  0 , rr = 0 ;
            int ret = kadane(ll , rr ,temp, n);
            if(ret >= mx ){
                mx = ret ;
//                l = left , r = right ;
//                u = ll , d = rr ;
            }
        }
    }
    return mx ;

}
int main() {
    smile();
    cin >>n;
    lp(i,0,n)
        lp(j,0,n)cin >>arr[i][j];
    cout<<kadane2D();
}
