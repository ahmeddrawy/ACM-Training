/*
   p574
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
#define II ({int a; scanf(" %d", &a); a;})

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
int t , n ;
int arr[13];
vi cum(13);
set<pair<int , vector<int> > > mset;
void recur(int sum , int indx , int ncum  ){
    if(sum == 0){
        vi vec = cum ;
        sort(vec.begin() , vec.begin() +ncum , greater<int >());
        mset.insert({ncum , vec});
        return;
    }
    if(indx == n){
        return;
    }
    recur(sum , indx+1 , ncum);
    if(arr[indx] <=sum){
        cum[ncum ] =arr[indx];
        recur(sum- arr[indx] , indx+1 , ncum+1);
    }

}
bool sortfun(int & a  , int &b , int & c , int &d){
    return a>b || (a==b && c>d);
}
bool sortvectorbyelement(const pair<int , vi> & a , const pair<int , vi> & b){
    int mn = min(a.first , b.first);
        lp(i,0,mn-1){


        }
    return a.second[0] > b.second[0] ||(a.second[0] ==b.second[0] &&a.second[1] >b.second[])


}
int main(){
	smile();
	freopen("out.txt","w" , stdout);
    while(1){
        cin>>t>> n;
        if(n ==0 )break;
        lp(i,0,n)   cin>>arr[i];
        mset.clear();
        cout<<"Sums of "<<t<<":\n";
        recur(t, 0, 0);
        if(mset.size() == 0)cout<<"NONE\n";
        else{
                vector < pair<int , vector<int >  >> v;

            for(auto it : mset){
                    v.push_back({it.first , it.second});
//                auto sz = it.first;
//                auto v = it.second;
//                lp(i,0,sz){
//                    if(i)
//
//                    cout<<'+'<<v[i];
//                    else cout<<v[i];
//                }
//                cout<<'\n';
            }
            sort(v.begin() , v.end() , [](const pair<int , vector< int > > & a ,const pair<int , vector<int> >  &b ){ int mx = min(a.first , b.first); bool rt = 1;  for(int i = 0 ; i <mx ; ++i )rt = rt && a.second[i]>= b.second[i];   return rt;   });
            for(auto it :v){
                lp(i, 0 , it.first){
                        if(it.second[i] == 0  )break;
                        if(i) cout<<"+"<<it.second[i];
                        else cout<<it.second[i];

                }
                cout<<'\n';
            }
        }

    }


}

