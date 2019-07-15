/*
   p 11565  uva
   21/11/18
   by ahmed_drawy
   math + brute force
   solving a quadratic equation for z and y and get 3 distinct number looping from 0 to MAX = 10000
   getting it in O(N)
    will try the approach of cp3
    accepted
*/


#include <bits/stdc++.h>
using namespace std;
//#define push_back               pb;
//#define make_pair               mp;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define in(a)   cin>>a;
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

int main(){
	smile();
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
        ll a, b, c;
        in(a);
        in(b);
        in(c);
        bool fo = 1;
        for(int x = 0 ; x <=10000 ; ++x){
                ll temp = (x*x - x*a )*(x*x - x*a) - 4*x*b; /// solving quadratic  equation
            if(temp >0){    /// if temp = 0 y == z


                    ll y= (-(x*x - x*a) - sqrt( temp) )/(2*x);
                    ll z= (-(x*x - x*a) + sqrt(temp ))/(2*x);

                    if(x== y || x == z)continue;    ///check if x == y or z because the answer must be 3 diff numbers
                    if(x+y+z == a && x*y*z == b && x*x +y*y +z*z ==c){
                        ll arr[3];
                    arr[0]=x ,arr[1]=y,arr[2]=z;
                    sort(arr, arr+3);
                        cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<'\n';
                        fo = 0;
                        break;
                    }
            }

        }
        if(fo)  cout<<"No solution.\n";

	}
}

