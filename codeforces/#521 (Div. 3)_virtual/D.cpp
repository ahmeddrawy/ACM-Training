/*
    521 div3 virtual contest
   19/11/18
   by ahmed_drawy
    UPSOLVING
    binary search on the x which we can take from the array and maximize
    111110000 where this represent the array which value can we take from it
    accepted
    take care of the frequency move from 0 to MAX and keep the freq in the vector not on the frq array itself
    using priority queue to keep the element with the biggest frequency on the top
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

int arr[200005];
int frq[200005];
vector<pii> frq2;
int n  , k ;
bool can(int x ,  bool best = 0 ){
    priority_queue< pii > pq;
    lp(i,0, frq2.size()){
            pq.push({frq2[i].first, frq2[i].second});

    }
    lp(i,0,k){
        pii curr =pq.top();

        if(curr.first < x)  return 0 ;

         pq.pop();
        pq.push({curr.first-x , curr.second} );
        if(best ){

                cout<<curr.second<<" ";

        }

    }
    return 1;




}
void BS(){
    int l = 1  , r = n ;
    while(l<r){
        int mid = l + (r-l+1)/2;

        if(can(mid  )){   /// function to validate if can take mid
            l = mid ;
        }
        else
            r = mid -1;

    }
    can(l, 1);


}



int main(){
	smile();
    cin >> n >> k ;
//	vector<pii  > ve ;
	lp(i,0,  n){
	     cin>>arr[i];
	     frq[arr[i]]++;
	}
    lp(i,0,200005 ){
        frq2.push_back({frq[i] , i });

	}

//	sort(ve.begin() , ve.end());
	BS();



}
