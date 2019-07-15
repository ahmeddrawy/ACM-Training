//
// Created by ahmed_drawy on 20/06/19.
//  #560 (Div. 3)_virtual D

#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;

#define make_pair               mp;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2 *haven't understood this yet
#define isPowerOfTwo(S) (!(S & (S - 1)))            // done
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))  // TBD
#define turnOffLastBit(S) ((S) & (S - 1))       // turn off last unset bit from right
#define turnOnLastZero(S) ((S) | (S + 1))       //turn on last unset bit from right
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define inf 0x3f3f3f3f
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
//typedef vector<vector<int> >    adj;
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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE

    freopen("/home/www/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}
int factorize (ll x){
    set<ll > ret;
    ret.insert(1);
    ret.insert(x);
    for (ll i = 2; i*i <=x ; ++i) {
        if(x%i ==0 ){
            ret.insert(i);
            ret.insert(x/i);
        }
    }
    return ret.size();

}
int main() {
    smile();
    int q ; cin >> q;
    while (q--){

        int n ; cin >> n ;
        vector<ll >mvec(n);
        lp(i,0,n)cin>>mvec[i];
        sort(mvec.begin() , mvec.end());
        set<ll> mset;
        for (int j = 0 , k = n-1; j <n/2 ; ) {
            mset.insert(mvec[j++] * mvec[k--]);
        }
        if(n%2 !=0)
            mset.insert(mvec[(n/2) ] *mvec[(n/2 )]);
        if(mset.size()>1){
            cout<<-1<<endl;
        }
        else {
            if(factorize(*mset.begin()) == n+2)
                cout<<*mset.begin()<<endl;
            else
                cout<<-1<<endl;
        }
    }
}
