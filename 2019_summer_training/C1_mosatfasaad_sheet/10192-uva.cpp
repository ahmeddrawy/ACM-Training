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
    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
int dp [101][101];
string dad , mom;
int lcs(int i , int j  ){
    if(i == sz(dad) || j == sz(mom)){
        return 0;
    }
    int &ret = dp[i][j];
    if(~ret )
        return ret;
    ret = 0 ;
    ret = lcs(i+1 , j+1);
    if(dad[i] == mom[j])
        ret = 1+ lcs(i+1 , j+1);
    else {
        ret = max(lcs(i , j+1), lcs(i + 1, j));
    }
    return ret;


}
int main() {
    smile();

    int n = 0 ;

    while(true) {
        getline(cin , dad);

        if(dad[0]=='#')break;
        getline(cin , mom);
        n++;

        clr(dp , -1);
        cout <<"Case #"<<n<<": you can visit at most ";
        cout << lcs(0 ,0)<<" cities."<<endl;


    }


}