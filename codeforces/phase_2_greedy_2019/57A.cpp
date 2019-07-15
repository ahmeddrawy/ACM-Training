/*
  57A - phase 2 2019
  04/02/19
  by -ahmed_drawy

*/


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

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
int n ;
bool can (int x){
return x == 0 || x == n;
}

int main(){
	smile();
      freopen("in.txt", "r" , stdin);
    int  x,y,r,c ;
    cin >>n>>x>>y>>r>>c;
    if(x== r && can(x)){
        cout<<abs(y - c);
    }
    else if(y== c && can(y) ){
        cout<<abs(x-r);
    }
    else {
        int per = 4 * n , f= 0 ;
        if(can(x) ){

            f = abs(n-y);
            if(c == n ){
                f+=abs(x-r);
            }
            else {
                f+=n;
                if(can(r)){
                    f+=abs(n-c);
                }
                else {
                    f+=n;
                    if(x== n)
                        f+=abs(r);
                    else
                        f+=abs(n-r);
                }
            }
        }
        else if(can(y)){
           f = abs(n-x);
            if(r == n ){
                f+=abs(y-c);
            }
            else {
                f+=n;
                if(can(c)){
                    f+=abs(n-r);
                }
                else {
                    f+=n;
                    if(y == n )
                        f+=abs(c);
                    else
                    f+=abs(n- c);
                }
            }
        }

        cout<<min(f , per - f);
    }

}

