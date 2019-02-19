
/*
   D1 - #540 (Div. 3) - live

  19/02/19
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

int n , m ;
int dp[101][10005];
int arr[101];
int solve(int indx , int pages   ){
//    cout<<indx << " "<<pages<<endl;
    if(pages <= 0 )
        return 0;
    if(indx == n ){
        if(pages <= 0 )
            return 0;
        else
            return 1001;
    }
//    int & ret =dp[indx][pages];
    if(~ret )return  ret ;
    int ret = 1001;
    int ans = 0 ;

    for(int i = 0 , j = indx ; j<n ; ++i , ++j){
        ans +=max(0,  arr[j] - i );
        ret = min(ret ,1+ solve(j+1 , pages - ans  ));
    }
    return ret;
}
int main() { /// todo upsolve again and check the hard version
    smile();
    cin >> n >> m ;
    clr(dp , -1);

    inN(arr ,n );
    sort(arr , arr+ n  , greater<int>());
    int ret= solve(0 , m );
    if(ret <=n)
        cout<<ret;
    else
        cout<<-1;
}

