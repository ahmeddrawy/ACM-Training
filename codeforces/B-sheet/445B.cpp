/*
    445B- B sheet
  05/02/19
  by -ahmed_drawy

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
vector<int > vec[55];
bool visited [55];
int n , m ;
int ddcnt=0 ;
void dfs(int node){
	visited[node] = true;
	for(auto i: vec[node])
	{
		int child = i;
		if (!visited[i]){
			dfs(i);
            ddcnt++; /// counting here to  skip the first cnt of the first node of the connected component
                    /// counting don't include the last node so we decreased our count for each connected component by 1
                    ///for e.q 1 -> 2 , 2 ->3 , the cnt will be 2
		}
	}

}

void addedge(int x , int y){
    vec[x].push_back(y);
    vec[y].push_back(x);

}
/// ans = 2^ n - number of  connected  components

int main(){
    smile();
    freopen("in.txt", "r" , stdin);
    cin >> n >> m;
    lp(i,0,m ){
        int x , y ; cin >> x >>y ;
        addedge(x-1,y-1);
    }
    int cnt = 0 ;
    lp(i,0,n){
        if(!visited[i]){
            cnt++;
            dfs(i);

        }
    }
    cout<<(1LL << (n- cnt ));
///    cout<<(1LL<<ddcnt); /// right too

}

