/**imp
  525 B - sheet B - greedy

  24/02/19
  by ahmed_drawy

   we can optimize the solution by marking the beginings only

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
void smile() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/www/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}

int frq[200005];
int main() {
    smile();
    string s ; cin >> s;
    int m ; cin >> m;
    int sz = s.size();
    vector<int >mvec(m);
    map  <int ,int> mmap ;
    lp(i,0,m){
        cin>>mvec[i];
        frq[s.begin() +mvec[i] -1  -s.begin()]+=1;
        frq[s.begin()+sz- mvec[i] +1 -s.begin()]-=1;
        mmap[mvec[i]]++;
//        reverse( s.begin() +mvec[i] -1 ,  s.begin()+sz- mvec[i] +1); /// the end iterator is exclusive
    }
    /// marking the frq array with the segment that is reversed
    /// todo we need to check a way to get the minimum reverses possible
    lp(i,1,sz ){
        frq[i] +=frq[i-1];

    }

    cout <<endl;
    lp(i,0, sz){
        frq[i]%=2;
    }

    /// we swap the right most one with the left most one because this mean that this segment is swapped at least one time
    /// and repeat
    for(int i  = 0 , j = sz- 1 ; i < sz && j>i  ;  ){
        if(frq[i] && frq[j] && i!=j){
            swap(s[i]  , s[j]);
            ++i , --j;
        }
        else if(frq[i] && !frq[j]){
            --j;
        }
        else if(frq[j] && !frq[i]){
            ++i;
        }
        else {
            ++i , --j;
        }
    }

    cout<<s;
}