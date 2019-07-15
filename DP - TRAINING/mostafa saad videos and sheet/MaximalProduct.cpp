/*
   problem  - SRM 8760
   8/12/18
   by ahmed_drawy

   technique  : dp to get the maximal product of k numbers their sum == s
   self notes :     looping over the remainder exclusive
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
typedef tree<
        pair<int, int>, // change type
        null_type,
        less<pair<int, int> >, // change type
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
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
const int MAXK = 21 ;
const int REM = 101 ;
long long  dp [MAXK][REM];
int s , k;
long  long solve  (int indx , int rem ){
    if(indx == k)return  rem == 0;  /// base case return 1 if rem == 0 and  0 otherwise
    if(rem == 0)    return 0 ;       /// invalid case
    long  long & ret= dp[indx][rem];
    if(~ret)    return  ret;
    ret = 0;
    for(long i = 1 ; i<= rem ; ++i){
        ret = max(ret , i *solve( indx +1 , rem - i));
    }
    return ret ;
}

int main(){
	smile();
//	freopen("in.txt", "r" , stdin);
//	freopen("out.txt" , "w" , stdout);

    cin >>s>>k ;
    clr(dp, -1 );
    cout<<solve(0,s);
}
DNA DNA:: operator + (DNA &obj ){
    char * arr =  new [this->len + obj.len + 1  ];
    arr[this->len + obj.len] = '\0';
    for(int i = this->startIndx, j = 0  ; i  <=  this->endIndx , ; ++i , ++j ){
        arr[j] = this->seq[i];
    }
    for(int i = obj.startIndx, j = 0  ; i  <=  obj.endIndx , ; ++i , ++j ){
        arr[j] = obj.seq[i];
    }
    DNA ret(arr, this->type);
    return ret ;

}
Sequence Sequence:: operator ==(Sequence & obj){
    if(this->len != obj.len)
        return false ;
    for(int i = 0 ; i < len ; ++i){
        if(this->seq[i] != obj.seq[i])
            return false;
    }
    return  true;
}



