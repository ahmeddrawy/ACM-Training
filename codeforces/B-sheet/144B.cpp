/*
   problem  - 352 B
   18/01/19
   by ahmed_drawy
    sheet B

   technique  : implementation
   self notes :
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

int dcomp(double x , double y)
{
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile(){
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
}
//struct point {
//    int x ,  y;
//    point(int x = 0 , int y = 0 ){
//        this->x =  x;
//        this->y = y;
//    }
//
//    bool operator ()(const point & p ){
//        return  x>p.x ;
//    }
//
//};

map <pii , bool > visited ;
double dist (  pair<int, int> &x,   pair<int , int> &y)  {
        double ans = (x.first - y.first ) *(x.first - y.first )  + (x.second - y.second )*(x.second - y.second );
        return sqrt(ans );
}
int main(){
	smile();

	freopen("in.txt", "r" , stdin);
    int xa,ya, xb,yb , n, mx, my,r ; cin >>xa>>ya>>xb>>yb>>n; ;
    pii p ;
    lp(i,min(xa,xb ) , max(xa,xb ) +1){
        p.first = i;
        p.second = ya;
        visited[p] = 0 ;
        p.second = yb;
        visited[p] = 0 ;
    }

    lp(i,min(ya,yb )+1 , max(ya,yb ) ){
        p.first = xa ;p.second = i;
     visited[p] = 0;
     p.first = xb ;
     visited[p] = 0;
    }
    pii p2;
    lp(i,0,n){
        cin>>mx>>my>>r;
        p2.first = mx ;
        p2.second = my ;
        for(auto it : visited){
            p = it.first ;
            if(dist(p2 , p ) <=r){
                visited[p] = 1;
            }
        }
    }
    int ans = 0 ;
    for(auto it : visited ){
        if(it.second == false ){
            ans++;
        }
    }
    cout<<ans ;
}



