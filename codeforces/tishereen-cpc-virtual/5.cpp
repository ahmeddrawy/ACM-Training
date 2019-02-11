/*
   p B
   3/12/18
   by ahmed_drawy

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
const int MAX= 1000001;
int factor[MAX];
void generatePrimeFactors()
{
    factor[1] = 1;

    // Initializes all the positions with their value.
    for (int i = 2; i < MAX; i++)
        factor[i] = i;

    // Initializes all multiples of 2 with 2
    for (int i = 4; i < MAX; i += 2)
        factor[i] = 2;

    // A modified version of Sieve of Eratosthenes to
    // store the smallest prime factor that divides
    // every number.
    for (int i = 3; i * i < MAX; i++) {
        // check if it has no prime factor.
        if (factor[i] == i) {
            // Initializes of j starting from i*i
            for (int j = i * i; j < MAX; j += i) {
                // if it has no prime factor before, then
                // stores the smallest prime divisor
                if (factor[j] == j)
                    factor[j] = i;
            }
        }
    }
}
int solve(priority_queue<int > & pq ){
    int curr = pq.top();
    pq.pop();

}
set<int> primefactorization(int x ){
    set<int>ret;
    while(x>1){
        ret.insert(factor[x]);
        x/=factor[x];

    }
    return ret;

}

int arr[100005];
int main(){
	smile();
    int t ; cin >> t;
    generatePrimeFactors();
    while(t--){
        int n , temp; cin >> n ;
        vector<int >st;
        map <int , int >ress;
        map<int , int > mmap;
        lp(i,0,n){
            cin>>temp;
            if(temp >1 ){
                    auto mset =primefactorization(temp);
                    for(auto it : mset){
                        ++mmap[it];
                    }
            }
        }

        ll res = 0;
        for(auto it : mmap){

            res +=(it.second+2)/3;
        }
        cout<<res  <<'\n';

    }



}

