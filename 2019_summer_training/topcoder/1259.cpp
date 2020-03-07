
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
int n ;
int arr[55];
int dp[55][55][3];
int solve(int left , int curr , int state){
    if(curr == n )return 1 ;
    int &ret = dp[left][curr][state];
    if(~ret ) return  ret;
    ret = 0  ;
    int s2 = arr[curr ] -arr[left] >0 ? 1 : arr[curr ]== arr[left] ? 0 : -1;
    if(s2 != state){
        ret = max(ret, 1 + solve(curr, curr + 1, s2));
        ret = max(ret, solve(left, curr + 1, state));
//        ret = max(ret,1 +  solve(left+1, curr + 1, state));

    }
    else ret = max(ret , solve(left , curr +1 , state));

    return  ret;
}
class ZigZag{
public:
    vector<int > arr ;
    int longestZigZag(vector <int> sequence){
        arr = sequence;
        clr(dp , -1);
        return max(solve(0 ,1 , 0 ) , max(solve(0, 1, 2) , solve(0,1,1)) );
    }
    int solve(int left , int curr , int state){
        if(curr == n )return 1 ;
        int &ret = dp[left][curr][state];
        if(~ret ) return  ret;
        ret = 0  ;
        int s2 = arr[curr ] -arr[left] >0 ? 1 : arr[curr ]== arr[left] ? 0 : -1;
        if(s2 != state){
            ret = max(ret, 1 + solve(curr, curr + 1, s2));
            ret = max(ret, solve(left, curr + 1, state));
//        ret = max(ret,1 +  solve(left+1, curr + 1, state));

        }
        else ret = max(ret , solve(left , curr +1 , state));

        return  ret;
    }
};
int main() {
    smile();
    cin >> n ;
    inN(arr , n );

    cout << max(solve(0 ,1 , 0 ) , max(solve(0, 1, 2) , solve(0,1,1)) );
}