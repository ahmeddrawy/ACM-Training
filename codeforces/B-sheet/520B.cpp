/*

   problem  -520 B
   20/01/19
   by ahmed_drawy
    sheet B
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
int dp[20005];
int n , m ;
int solve(int indx ){
    if(indx == m )
        return 0 ;
    int &ret = dp[indx] ;
    if(~ret ) return ret;
    ret = 1<<20;
    if(indx <m)
        ret = min( ret , 1 + solve(indx*2 ));
    if(indx -1 > 0 )
        ret = min(ret,  1 + solve(indx-1 ));
    return ret;

}
int main(){
	smile();
 	freopen("in.txt", "r" , stdin);
    cin >> n >> m ;
    clr(dp , -1);
    cout<<solve(n );

    return 0 ;

    puts("a");
    if(n >= m ){
        cout<< n - m ;
    }
    else {
        int ans = INT_MAX;
        int l ;
        lp(i,0,n-1){
                if(n-i <= 0 )break;
               l = ceil(log2(double(m)/ (n-i)) ) ;
//               cout<<n-i<<" ";
//               cout<<l <<" "<<(m/(n-i))<<endl;
               ans = min(ans , i+ l + abs(m -  (int )(pow(2 ,l) ) *(n-i )  ));
               ans =min  (ans , i + l + abs( m -(int) pow(2, l-1 ) * (n-i)));

        }
        cout<<ans;
    }

}




