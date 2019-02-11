/*
  pC 524 codeforces - v contest
   30/11/18
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
int n , m ;
int x[4];
int y[4];
struct point{
    ll x , y;

};
point points[4];
ll overlappingArea(point l1, point r1,
                    point l2, point r2)
{
    ll left = max(l1.x, l3.x);
    ll right = min(l2.x , l4.x);
    ll bottom = max(l1.y , l3.y);
    ll top = min(l2.y , l4.y);
    if(left < right && bottom < top){
        return
    }
}
int main(){
	smile();
	int t ; cin>>t;
	while(t--){
        cin>>n>>m;
        lp(i,0,4)   cin>>points[i].x>>points[i].y;
        ll black = (n*m +1)/2;
        ll white = n* m - black;
        ll area = ((abs(points[0].x - points[1].x) +1) *(abs(points[0].y - points[1].y) +1));
        ll area2 = ((abs(points[2].x - points[2].x) +1) *(abs(points[3].y - points[3].y) +1));
//        ll common = overlappingArea(points[0].x,points[0].y ,points[1].x,points[1].y ,points[2].x,points[2].y, points[3].x,points[3].y );
//        cout<<"area "<<area<<endl;
    ll common = overlappingArea(points[0] , points[1], points[2],points[3]);

        if(area &1){
            if(points[0].x &1){
                black -= area/2;
                white += area/2;
            }
            else {
                black -=((area+1)/2);
                white +=((area+1)/2);

            }
        }
        else {
            black -= (area/2);
            white +=(area/2);
        }
        cout<<white<<" xx "<<black<<'\n';
//        lp(i,0,2)   cin>>y[i]>>x[i];
//         area = ((abs(x[0] - x[1]) +1) *(abs(y[0] - y[1]) +1));
         cout<<"common "<<common<<endl;
        if(area2 &1){
            if(x[0] &1){
//                white -= ((area )/2);
                black += ((area2)/2);
            }
            else {
//                white-=(area);
                black+=(area2);

            }
        }
        else {
//            white -= area;
            black += area2;
        }
        white -=common;
        black +=common;
        cout<<white<<" x "<<black<<'\n';

	}



}

