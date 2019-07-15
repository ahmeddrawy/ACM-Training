/*
 34C- phase 2 2019
  05/02/19
  by -ahmed_drawy

*/
/// we have 3 cases 3 identical letters  , 2 pairs of identical letters , 3 pairs
///the greedy approach you have you have to make the 3 letters typo first bec, we have no option here
/// else we have to deal with the 3 pairs first to remove one letter from inside to make only one move
/// else we have  two pairs we remove from the right most pairs(actually both will work left or right)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> /  / Including tree_order_statistics_node_update

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
}
int main(){
    smile();
    freopen("in.txt", "r" , stdin);
    string s ; cin >> s;
    lp(i,2,s.size()){
        if(s[i] == s[i-1 ] && s[i] ==s[i-2 ]){
            s.erase(i , 1  );
            --i;
        }

    }
    lp(i,1, s.size()){
        if(s[i] == s[i-1]  && i+ 4 <s.size() && s[i+1] == s[i+2 ] && s[i+3] == s[i+4]){
            s.erase(i+1 , 1) ;
            --i;
        }
        else if(s[i] == s[i-1 ] && i +2 < s.size() &&s[i+1 ] == s[i+2]){
            s.erase(i+1 , 1 );
            --i;
        }

    }
    cout<<s;


}

