//
// Created by ahmed_drawy on 17/08/19.
// virtual contest Educational Codeforces Round 70
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
ll gcd(ll a , ll b)
{
    if(b==0) return a;
    a%=b;
    return gcd(b,a);
}


int main() {
    smile();
    int t ; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int len = 2;
        while(true){
            if(len*(len-1)/2>n){
                len--;
                break;
            }
            len++;
        }
        n-=(len*(len-1))/2;
        string s ;
        s+="133";
        lp(i,0,n)s+='7';
        len-=2; /// the first 2 3s
        /// moving the problem from product rule to sum rule by adding 7s then start new 3s streak
        ///because the order matter

        lp(i,0,len) s+="3";
        cout<<s;
        cout<<"7\n";


    }
}