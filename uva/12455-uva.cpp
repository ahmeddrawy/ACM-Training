/*
   12455 uva
   23/11/18
   by ahmed_drawy
   cp3
    brute force - exhaustive recursion
    bit masking
    accepted both
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

bool solve( const vi &vec , int indx , int sum   ){
    if(sum == 0)return 1;
    if(indx == vec.size()   ){
          return sum ==0;
    }
    if(vec[indx] > sum) return solve(vec , indx+1  , sum );
    else{
        return solve(vec , indx+1 , sum -vec[indx ] ) || solve(vec,indx+1 , sum );

    }
}
//bool memo[21][2];
//bool dp(int indx , int taken){
//
//}

int main(){
	smile();
//	freopen("out.txt","w",stdout);
	int t; cin>>t;
	while(t--){
        int n , p ; cin >>n>>p;
        vi pa(p);
        inN(pa , p);

         if(solve(pa , 0 , n ))cout<<"YES\n";
        else                    cout<<"NO\n";
//        bool ans = 0;
//        for( int i  = 0; i < (1<<p) ; ++i){
//            int sum = 0 ;
//            for(int j = 0 ; j < p ; ++j){
//                if(i & (1<<j))
//                    sum +=pa[j];
//            }
//            if(sum == n){
//                ans =  1;
//                    cout<<"YES\n";
//                    break;
//            }
//
//
//        }
//        if(!ans )
//        cout<<"NO\n";


	}
}

