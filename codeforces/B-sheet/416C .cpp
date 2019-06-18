/*
  416C  - sheet B - greedy

  25/02/19
  by ahmed_drawy



*/
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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/www/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
/// we have to give the  largest iincome for the smallest table possible
int arr[1001];
int main() {
    smile();
    int n ;cin >> n ;
    vector< pii >mvec(n);
    vector< pii >ret;
    map<pii ,queue<int > > imap;
    lp(i,0,n){
        int x , y ; cin >> x >>y;
        mvec[i] ={y, x};
        imap[{y,x}].push(i+1);
    }
    sort(mvec.rbegin() , mvec.rend() , sortpair); /// sorting the pair ascending according to first and descending according to second

    int k ; cin >> k ;
    ll ans = 0 ;
    int cnt = 0;
    inN(arr , k );
    lp(i,0, n){
        int mn = INT_MAX , indx = -1  ;
        lp(j, 0, k){ /// sequential search due to low constraints
            if(mn >= arr[j]  && arr[j]>= mvec[i].second){ /// todo check the mapping of indx don;t have collisions due to repeated pairs
                mn = arr[j];
                indx = j ;
            }
        }
        if(indx != -1) {
            cnt++ ;
            ret.push_back({imap[mvec[i]].front() , indx +1 }) ;
            imap[mvec[i]].pop();
            ans += mvec[i].first;
            arr[indx]= 0 ;
        }
    }
    cout<<cnt << " "<<ans <<endl;
    for(auto it : ret ){
        cout << it.first << " "<<it.second <<endl;
    }

}