/* accepted
   D2 - #540 (Div. 3) - upsolving

  22/02/19
  by ahmed_drawy



*/

#include <bits/stdc++.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
//#define push_bac                pb;
//#define make_pair               mp;
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
void smile(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/www/Desktop/training/in.txt", "r" , stdin);
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE


}

ll n , m ;
ll arr[200005];

bool can (int k){
    ll sum = 0, cnt= 0, indx = 0  ;
    for(;;cnt++){   /// cnt is the number of cups of coffee
        if(sum >= m )   return 1;
        if(indx >= n )  return sum>=m;
        for(int i = 0 ; i< k && indx <=n; ++i , ++indx ) { ///for each day add the largest in the array
            /// we loop over all days adding the largest numbers
            sum += max(0LL , arr[indx]-cnt );
        }
    }
}
int main() { /// todo up solve again and check the hard version
    smile();
    cin >> n >> m ;

    inN(arr ,n );
    sort(arr , arr+ n  , greater<ll>());
    int ans = 1;
    int l = 1 , r = n ;
    while(l < r) {
        int mid = l + (r- l )/2 ;
        if(can(mid )){
            r   = mid ;

        }
        else {
            l = mid +1 ;
        }
    }
    if(can(l)){
        cout<<l ;
    }
    else if(can(ans)){
        cout<<ans;
    }
    else
        cout << -1 ;
}
