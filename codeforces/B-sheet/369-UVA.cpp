/**imp

  369 - Combinations -UVA - sheet B
  16/02/19
  by ahmed_drawy



*/

#include <bits/stdc++.h>

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
    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE


}
const int N = 1e3 + 5;
ll factor[N];
void sieve() {
    for (int i = 2; i * i < N; ++i) {
        if (factor[i])
            continue;
        for (int j = i * i; j < N; j += i)
            factor[j] = i;
    }
}
void factorize(int x , map<ll , int> &mmap) {
    while (x > 1) {
        if (factor[x] == 0)
            factor[x] = x;
        mmap[factor[x]]++;
        x /= factor[x];
    }
}
long long power(long long base, int exp)
{
    if (!exp)
        return 1LL;
    ll sq = power(base, exp/2);
    sq = (sq * sq);
    if (exp&1)
        sq = (sq * base);
    return sq;
}


/// we first has the nCk = (n* n-1 * n-2 * ... n-k +1 )/(k * k-1 * ... * 2 *1)
///then we prime factorize them to factorize as much as possible

int main(){
    smile();
    sieve();
    int n , m  ;
    while(cin >> n >>  m) {
        if(!n && !m )break;
        map<ll, int> num;
        map<ll, int> denum;
        for (int i = n; i > n - m; --i) {
            factorize(i, num);
        }
        for (int i = m; i > 0; --i) {
            factorize(i, denum);
        }
        lp(i, 1, 101) {
            if (num[i] >= denum[i]) {
                num[i] -= denum[i];
                denum[i] = 0;
            }
        }
        ll x = 1;
        lllp(i, 1, 101) {
            if (num[i]) {
                x *= power(i, num[i]);
            }
        }
        ll y = 1;
        lllp(i, 1, 101) {
            if (denum[i]) {
                y *= power(i, denum[i]);
            }
        }
        cout<<n<<" things taken "<<m<<" at a time is "<<x/y<<" exactly.\n";

    }

}