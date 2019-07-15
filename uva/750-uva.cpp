/*
   p750  uva
   26/11/18
   by ahmed_drawy
   backtracking
   accepted

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
bool arr[9][9];
bool valid(int r ,int c){
        bool diagonal = 1 ;
        lp(i,0,c )
            diagonal = diagonal && !arr[r][i];
//        lp(i,0,r )               // no need to check  the current column
//            diagonal = diagonal&& !arr[i][c];
        int i =r, j = c;
        for(; i >=0 && j>=0 ; --i , --j){
            diagonal = diagonal && !arr[i][j];
        }
        i = r, j = c;
        for( ; i <8 &&j>=0 ; ++i , --j)
            diagonal = diagonal && !arr[i][j];

    return r>=0 &&r<8 &&c>=0 && c<8 &&diagonal ;
}


void printchess(){
lp(i,0,8){
        lp(j,0,8)cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
vector<int >vec(8);
vector < vector<int> > mset;
int x , y;

void queens( int c ){
    if(c==8 && vec[y]  ==x){
//            for(int i = 0  ; i <)
            mset.push_back(vec);
//        lp(i,0,8)   cout<<vec[i]+1<<" ";
//        cout<<endl;
//        printchess();
    }
    lp(i,0, 8){
            if(valid(i , c )){
                arr[i][c] =1;
                vec[c] =i;
                queens( c+1  );
                arr[i][c] =0;
            }

    }

}
int main(){
	smile();
//	freopen("out.txt ", "w" , stdout);
	int t; cin>>t;
    while(t--){
        cin>>x>>y;
        --x , --y;
//        arr[r][c] = 1;
//        vec[r] = c;
        lp(i,0,8)   vec[i]  = 0;
        lp(i,0,8)
            lp(j,0,8) arr[i][j] = 0;
        mset.clear();
        queens( 0 );
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n\n" ;
        int i = 1 ;
        for(auto  it: mset){
                cout<<setw(2)<<i;
                cout <<"     ";
                ++i;
            for(auto in : it)   cout<<" "<<in+1;
            cout<<"\n";

        }
        if(t )cout<<"\n";

    }
}

