/**
   problem  - E
   13/01/19
   by ahmed_drawy
   upsolving - round 531 div3
   technique  :/// if pos = max(pos , lst[arr[i]]) == i then a closed segment found
                    e.q 1 2 1 2 3
                        2 3 2 3 4
                        when pos  == 3 == i then the first segment
                        2^m-1 because initially the first segment start with zero so we have 2 choices for
                        every segment excluding the first (increase the curr  or leave it )
   self notes :
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
int arr[200005];
const int MOD = 998244353;
long long power(long long base, int exp)
{
    if (!exp)
        return 1LL;
    ll sq = power(base, exp/2);
    sq = (sq * sq)%MOD;
    if (exp&1)
        sq = (sq * base)%MOD;
    return sq;
}
int main(){
	smile();
	freopen("in.txt", "r" , stdin);
    map<int , int >frq ;
    map<int , int >lst ;
    vector<int > mvec;
    int n ; cin >> n ;
    lp(i,0,n){
        cin >> arr[i];
        lst[arr[i]] = i ;
    }
    bool breaked  = 0 ;
    ll seg = 0 ;
    int pos = -1;
    lp(i,0, n ){
         pos = max(pos, lst[arr[i]] );
         if(pos == i ){
            ++seg;
         }
    }
//    lp(i,0,n){
//        mvec.push_back(arr[i]);
//        ++f[arr[i]];
//        breaked = 0 ;
//        for(auto it : mvec){
//            if(f[it] != frq[it]){
//               breaked = 1;
//                break ;
//            }
//            if(breaked ) break ;
//        }
//        if(!breaked ){
//            ++seg ;
//            mvec.clear();
//            f.clear();
//        }
//    }
    cout<<power(2LL , seg -1);
}



