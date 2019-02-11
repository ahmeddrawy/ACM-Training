/*

   problem  -1105C
   20/01/19
   by ahmed_drawy
    round 533 div2
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
int dcomp(double x , double y)
{
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile(){
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
}
ll dp[200005][4];
const int mod = 1e9  + 7;
ll n , l , r;
ll frq[4];
int solve(int cnt  , int sum ){
    if(cnt == n){
        return sum == 0;
    }
    ll &ret = dp[cnt][sum];
    if(~ret ) return ret ;
    ret = 0 ;
    for(int i = 0 ; i<=2; ++i){ ///reduction
        ret += ((frq[i])* solve(cnt+1 , (sum + i)%3 ))%mod  ;
        ret%=mod;
    }
    return ret ;

}
bool valid(ll a,ll n){ /// arithemtic sequence
                        /// a + (n-1) d <= d
                        /// a is l , l+1 , l+2 , d = 3
    return a + (n-1) *3 <= r;

}
ll BS(int a){ /// binary search on arithemtic sequence 1111100000
                /// a +  (n-1)*d <= r     /// a is l ,  l +1 , l +2
                /// d is 3
    ll st = 0 , e=1<<30;

    while(st<e){
        ll mid = st + (e - st +1 )/2;
//        cout<<mid<<endl;

        if( valid(a , mid) ){
            st = mid ;
        }
        else {
            e= mid -1 ;
        }
    }
    return st ;

}
int main(){
	smile();
 	freopen("in.txt", "r" , stdin);
    cin >>n >> l >> r;
    lp(i,0,3){
        frq[(l+i ) %3 ] = BS(l+i);
    }


    clr(dp , -1);
    cout<<solve( 0 , 0);

}




