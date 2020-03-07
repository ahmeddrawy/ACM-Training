
//
// Created by ahmed_drawy on 03/09/19.
/// 497uva
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
int n ;
vector<int > vec;
vector<int > path;
int dp[10000][1000];
int solve(int indx , int h){
    if(indx == n) return 0 ;
    int &ret = dp[indx][h];
    if(~ret ) return ret;
    ret  = solve(indx+1 , h)  ;
    if(vec[indx] >h){
        ret = max(ret , 1+ solve(indx+1 , vec[indx]));
    }

    return ret ;
}
void buildPath(int indx , int h ){
    if(indx == n) return  ;
    int mx1 = 0 , mx2 = 0 ;
    mx1  = solve(indx+1 , h)  ;
    if(vec[indx] >h){
        mx2 = 1+ solve(indx+1 , vec[indx]);
    }
    if(mx2 > mx1) {
        path.push_back(vec[indx]);
        buildPath(indx+1 , vec[indx]);
    }
    else buildPath(indx+1 , h);

    return ;

}
int main() {
    smile();
    int t; cin >> t;
    cin.ignore();
    cin.ignore();
    for (int z = 0; z <t ; ++z) {
        if(z) cout << endl;

        n = 0 ;
        string s ;
        vec.clear();
        int x;
        while(getline(cin , s)) {
            if(s== "")break;
            stringstream ss(s);

            ss>>x;
            vec.push_back(x);
            n++;

        }

        clr(dp , -1);
        path.clear();
        cout << "Max hits: ";
        cout << solve(0 , 0 )<<endl;
        buildPath(0 , 0);
        for(auto it : path)cout << it << endl;

    }
}