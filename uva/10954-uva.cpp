  /************ very important problem**************/
/**
   10954  - add all uva
   16/11/18
   by ahmed_drawy
    max heap priority queue  in increasing order

    accepted
    priority queue with increasing order
    pushing elements to priority queue then loop until  size > 1 add the first 2 top elements then push them to the queue
    and push them to a vector to get the sum of all theses sums
*/


#include <bits/stdc++.h>
using namespace std;
//#define push_back               pb;
//#define make_pair               mp;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
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
void printqueue(priority_queue <int , vector <int > , greater<int> >q){
    while(!q.empty())
        cout<<q.top()<<" ", q.pop();
    cout<<endl;
}
int main(){
	smile();

    while(1){
        int n ; cin >> n;
        priority_queue<int , vector <int > , greater <int> > q;
        if(!n)  return 0 ;
        vi vec ;
        lp(i,0,n ){
            int temp ; cin >>temp  ;
            q.push(temp);
        }
        ll temp = 0;

        while(q.size() > 1){
            temp = q.top();

            q.pop();
            temp += q.top();
            q.pop();
            q.push(temp);

            vec.push_back( temp);
        }

        ll ans = 0 ;
        lp(i,0, vec.size()) ans +=vec[i];
        cout<<ans<<endl;

    }

}
