/**** imp

  505B - sheet B
  07/02/19
  by -ahmed_drawy
  calculate all possible colors that can make a path from start to destination - not neccesiry the shortest
  path but path have all the color
  the constraints is small so we can loop over all the colors and calculate by a simple dfs or bfs

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


void addedge(int x , int y , int c  , vector< vector<pii> > &vec){
    vec[x].push_back({y , c});
    vec[y].push_back({x , c});

}
bool visited[105];
bool dfs(int s , int d , int c ,  vector< vector<pii> > &vec){
    visited[s] =1;
    if(s== d) return 1;
    for(auto it : vec[s]){
        if(!visited[it.first] && it.second == c){
            if(dfs(it.first , d , it.second , vec ) )
                return true ;
        }
    }
    return false ;

}

int main(){
    smile();
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r" , stdin);
    #endif // ONLINE_JUDGE
   int n , m ; cin >> n >> m ;
    vector< vector<pii> > mvec(n);
   lp(i,0,m){
        int x , y , c ;cin >> x >> y>> c;
        --x , --y;
        addedge(x , y ,c  ,mvec);
   }
   int q; cin >>q;
   lp(i,0,q){
        int x , y  ;cin >> x >> y;
        --x , --y;
        int cnt = 0 ;
        lp(i,0,100){
            clr(visited , 0 );
            if(dfs(x,y,i , mvec))cnt++;
        }
        cout<<cnt<<'\n';
   }

}
