/**
   problem  - 225 C
   17/01/19
   by ahmed_drawy
   sheet  B
   technique  : DP
   self notes : no need to 2D we just has to preprocess the cost of each column
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
int n , m , x , y ;
int arr[1001][2];
int dp[1001][2][1001];
int solve(int indx , bool clr , int sz  ){
//    cout<<indx<<" " << clr <<" " << sz<<" " <<arr[indx][clr ]<<endl;
    if(indx == m ){ ///base case
        if(sz >= x && sz<= y ) /// if  x<= last subsequence length  <=y
            return 0;
        return 10000;

    }
    int & ret= dp[indx][clr][sz];
    if(~ret) return ret ;
    ret = INT_MAX;
    /// if you want to increase one black column so add to ans the cost of this column to be white which is arr[indx][!clr]

    if(sz < x ){    ///must increase to reach  x
            ret = min(ret , arr[indx][!clr] + solve(indx +1 , clr , sz+1));
    }
    else { /// increase to reach y if not reached or change /// if y is reached change only

            if(sz < y){
                ret = min(ret , arr[indx][!clr] + solve(indx +1 , clr , sz+1));
            }
            ret = min(ret , arr[indx][clr] + solve(indx +1 , !clr , 1));

    }
    return ret;

}
string s[1001];
int main(){
	smile();
// 	freopen("in.txt", "r" , stdin);
    cin >> n >>  m >> x >> y;

    lp(i,0,n)cin >>s[i];
    lp(j,0,m){
        int black = 0 , white = 0 ;
        lp(i,0,n){
            if(s[i][j] == '.'){
                white++;
            }
            else {
                black++;
            }

        }
        arr[j][0] = white ;
        arr[j][1] = black ;
    }
    clr(dp, -1);


    cout<<min(solve(0,1,0),solve(0,0,0));

}



