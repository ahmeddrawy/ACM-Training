//
// Created by ahmed_drawy on 28/08/19.
/// c1 sheet
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
const int N = 20000000;
bool notprime[N];
vector<pii> mvec;
void sieve() {
    notprime[0] = notprime[1 ] = 1;
    for (ll i = 2; i * i < N; ++i) {
        if (notprime[i])
            continue;
        for (ll j = i * i; j < N; j += i)
            notprime[j] = 1;
    }
    vector<int > primes;
    for (int k = 1; k <N ; ++k) {
        if(!notprime[k])
            primes.push_back(k);
    }
    for (int l = 1; l <sz(primes) ; ++l) {
        if(primes[l] - primes[l-1] == 2){
            mvec.push_back({primes[l-1] , primes[l]});
        }
    }
}
int main(){
    smile();
    sieve();
    int s;
    while (cin >> s){
        s--;
        cout<<'('<<mvec[s].first<<", "<<mvec[s].second<<")\n";
    }

}