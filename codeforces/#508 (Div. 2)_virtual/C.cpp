/*
   problem  - C
   10/12/18
   by ahmed_drawy
   508 div2 - codeforces - virtual contest
   technique  :
   self notes :
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
//int cnt = 0 ;
void play1(priority_queue<int > & p1 , priority_queue<int >& p2 ,ll &s1 ){
//    ++cnt;
//    cout<<"cnt = "<<cnt<<endl;
    if(!p1.empty()&&p1.top() > p2.top()){
//            puts("a");
//            cout<<"p1.top "<<p1.top()<<endl;
        s1+=p1.top();
        p1.pop();
	}
	else if(!p2.empty() && p1.top() <= p2.top()){
//	    puts("b");
        p2.pop();
	}
	else if(p2.empty() && !p1.empty()){
//	    puts("c");
	    s1+=p1.top();
        p1.pop();

	}
	else if(p1.empty() && !p2.empty()){
        p2.pop();
	}
	else{
//            puts("both empty");
        return ;
	}
	return ;
}

void print(priority_queue<int >q){
//    puts("printing pq ");
    while(!q.empty()){
        cout<<q.top()<<' ';
        q.pop();
    }
    cout<<'\n';
}
int main(){
	smile();
	priority_queue<int > p1;
	priority_queue<int > p2;
	ll s1 = 0 ;
	ll s2 = 0 ;
	int n ; cin >> n;
	lp(i,0,n){
        int temp ;cin >> temp ;
        p1.push(temp);
	}
	lp(i,0,n){
        int temp ;cin >> temp ;
        p2.push(temp);
	}

	lp(i,0,n){
        play1(p1,p2,s1);
        play1(p2,p1,s2);
	}
	cout<<s1-s2;







}



