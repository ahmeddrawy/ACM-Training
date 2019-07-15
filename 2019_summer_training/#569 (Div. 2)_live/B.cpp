//
// Created by ahmed_drawy on 21/06/19.
//  #569 (Div. 2) live A

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


int main() {
    smile();
    int n ; cin>> n ;
    vector<int >mvec(n);
    vector<pii >value(n);
    vector<pii >indx(n);
    lp(i,0,n){
        cin>>mvec[i];
        value[i] = {mvec[i] , i};
    }
    sort(value.rbegin() , value.rend());
    int mn = mvec[n-1];
    int cntnegative = 0;
    int cntpositive = 0;
    int zeroIndx = -1;
    lp(i,0,n){
        if(value[i].first > 0){
//            cntpositive++;
            value[i].first = -1*(value[i].first +1);
        }
//        else {
//            value[i].first = -1*(value[i].first +1);
//            cntnegative++;
//        }
    }

    int cnt= 0 ;
    lp(i,0,n){
        if(value[i].first == 0 ){
            value[i].first = -1*(value[i].first +1);
            cnt++;
        }
        else if(value[i].first <0)cnt++;
    }
    sort(value.begin() , value.end());
    bool remove= true;
    lp(i,0,n){
        if(value[i].first != -1 && cnt&1){
            value[i].first = -1*(value[i].first +1);
            remove = false;
            break;
        }

    }
    if(remove && cnt &1){
        value[0].first = 0 ;
    }

    lp(i,0,n){
        mvec[value[i].second] = value[i].first;
    }
    for (int j = 0; j <n ; ++j) {
        cout<<mvec[j]<<" ";
    }

}