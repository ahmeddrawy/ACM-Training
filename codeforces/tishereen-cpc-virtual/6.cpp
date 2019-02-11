/*
   pI
   5/12/18
   by ahmed_drawy

*/


#include <bits/stdc++.h>
using namespace std;
//#define push_back               pb;
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
bool sortpair( const pair<int , int> & x, const pair<int , int> & y)
{

    return  x.first != y.first ? x.first < y.first : x.second > y.second ;


}
int dcomp(double x , double y)
{
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile(){
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
}

void printarr(int arr [] , int n){
lp(i,0,n) cout<<arr[i]<<" ";cout<<endl;
}

void printset(int n ){
    stack <int> myst;
    while(n)    myst.push(n%2), n/=2;
    while(!myst.empty())    cout<<myst.top(), myst.pop();
    cout<<endl;
}
int arr[100005];
const int MOD = 1000000007;
template <typename T>
T modpow(T base, int exp) {
  base %= MOD;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

unsigned long long choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    r%=MOD;
     return r;
}

int comb(int n  ){
    ll sum = 0;
    lp(i,2,n+1){
        sum +=choose(i,2);
        sum%=MOD;
    }
    sum+=n;
    sum%=MOD;

    return sum;

}
int main(){
	smile();

    int t , n , q , l , r, tt; cin >> t;

     while(t-- ){
        cin >> n >>q;
        lp(i,0, n ){
            cin >> arr[i];
            arr[i] =(arr[i] & 1);
        }
        lp(i,1, n ) arr[i] +=arr[i-1];
        lp(i,0,q){
            cin>> l >>r>>tt;
            int odd = 0;
            if(l >1)
               odd = arr[r-1] -arr[l-2] ;
            else
                odd = arr[r-1];

            if(tt==0){
                    cout<<modpow(2LL, r-l+1) - modpow(2LL,odd ) <<'\n';
//                cout<<comb(r-l+1)  - comb(odd)<<endl;
            }
            else {
                    cout<<modpow(2LL,odd ) -1LL<<'\n';
//                    cout<<comb(odd)<<endl;
            }
        }

     }


}

