/***
  61B - phase 2 2019
  27/01/19
  by -ahmed_drawy


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

void cinstring(int sz ,vector<string > &arr){
    lp(i,0,sz){

        string temp ;
        cin>>temp;
        temp.erase(remove_if(temp.begin(), temp.end(), [](char c) { return !isalpha(c); } ), temp.end());
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
//        arr[i]  = temp;
//        if(temp.size() >0)
        arr.push_back(temp);

    }

}
vector<string > s;

int main(){
	smile();
    freopen("in.txt", "r" , stdin);
    int n ;
    cinstring(3, s);
    cin >> n ;
    vector<string > ans ;
    vector<string > sd ;
    cinstring(n, ans);
    int sz = 0 ;
    for(auto it: s)
        sz+=it.size();
    sort(s.begin() , s.begin() +3);
      do{
            string temp = s[0] + s[1] +s[2];
            sd.push_back(temp);

        }
    while(next_permutation(s.begin() , s.begin()+3));
    lp(i,0,n){
        string it = ans[i];
        bool nofound = 1;
        for(auto init : sd ){

            if(it == init ){
                cout<<"ACC\n";
                nofound = 0 ;
                break;
            }
        }
        if(nofound ){
            cout<<"WA\n";
        }

    }


}


