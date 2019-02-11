/*
  342A - phase 2 2019
  27/01/19
  by -ahmed_drawy


  the numbers from 1 to 7 only so number of 1s must be n/3
  all the groups you have must have
  1 2 (4 or 6)
    or
    1 3 6
    this is your only options so if you have 5 or 7 or frq[1] !=n/3 you can't split
    so you have to check if the frq(1) == frq(2) + frq (3)  == frq(6)+ frq(4) == n/3
    else
    cout<<-1;
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
int arr[100005];
int main(){
	smile();
//   	freopen("in.txt", "r" , stdin);
    int n ; cin >> n ;
    map <int , int > mmap ;
    lp(i,0,n){
        cin >> arr[i];
        mmap[arr[i]]++;
    }
    if(mmap[1] != n/3 || mmap[5] ||mmap[7]){
        cout<<-1;
        return 0 ;
    }
    else {/// you must have n/3 1s
        if(mmap[1] == (mmap[2] + mmap[3] ) && mmap[1] ==(mmap[4] + mmap[6])
           && mmap[2] + mmap[3] == mmap[4]+ mmap[6] && mmap[2] >=mmap[4]){
            lp(i,0,mmap[4]){
                cout<<"1 2 4\n";
            }
            lp(i,0,mmap[6] - mmap[3]){
                cout<<"1 2 6\n";
            }
            lp(i,0,mmap[3]){
                cout<<"1 3 6\n";
            }
        }
        else cout<<-1;
    }

}



