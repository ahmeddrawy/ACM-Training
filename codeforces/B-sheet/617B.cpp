/*********************
   problem  - 617 B
   18/01/19
   by ahmed_drawy
    sheet B
    IMPORTANT
   technique  : dp
   self notes :
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
ll dp [101][5];
int arr[101];
int n ;
ll solve( int indx  = 0  , int cnt = 0   ){
    if(cnt ==2 ) return 0 ;
    if(indx == n )
        return cnt ;
    ll & ret = dp[indx][cnt];
    if(~ret) return ret ;
    ret = 0 ;
    if(cnt <1 ){
        if(arr[indx] == 1){
            ret += solve(indx +1 , 1);
            ret +=solve(indx +1 , 0 );
        }
        else
            ret += solve(indx +1 , cnt );
    }
    else if(cnt == 1){
        ret += solve(indx+1 , cnt + arr[indx] );
        if(arr[indx] == 0 )
            ret += solve(indx+1 , 0);
    }
    return ret;
}

int main(){
	smile();
	freopen("in.txt", "r" , stdin);
    clr(dp , -1 );
    cin >> n ;
    lp(i,0,n) cin >>arr[i];
    cout<<solve();
}



