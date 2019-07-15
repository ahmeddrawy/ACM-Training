/*
  uva - 439- sheet B

  23/02/19
  by ahmed_drawy



*/

#include <bits/stdc++.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
//#define push_bac                pb;
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
#ifndef ONLINE_JUDGE
    freopen("/home/www/Desktop/training/in.txt", "r" , stdin);
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE


}
vector <vector< int > > mvec(64*64);
int dx[] = {2  , 2 , -2  , -2 ,  1,   1   , -1 , -1 };
int dy[] = {-1 , 1 , 1  ,  -1 , -2 , 2    , 2  , -2 } ;
bool can (int x , int y ){
    return x>0 && y> 0 && x<9 && y<9 ;
}
int main() {
    smile();
    lp(i,1, 9){ /// row
        lp(j,1,9){ ///column
            lp(k,0, 8){
                int x = i + dx[k];
                int y = j + dy[k];
                if(can(x , y)){
                    mvec[i*64 + j].push_back(x*64 + y);
                    mvec[x*64 + y].push_back(i*64 + j);
                }
            }
        }
    }
    string s ,l ;
    while(cin >> s >> l ){
        int st= (s[0] - 'a' +1 ) + (s[1] - '0')*64 ;
        int ed= (l[0] - 'a' +1 ) + (l[1] - '0')*64 ;
        queue<int > mq;
        mq.push(st);
        vector<int > len (64*64 , INT_MAX);
        len[st] =  0 ;
        int cur = st , sz = 1 , dep =0;
        bool ok =1;
        for( ; ok && !mq.empty() ; ++dep , sz= mq.size() ){
            while( ok &&sz--){
                cur = mq.front(); mq.pop();
                for(auto it : mvec[cur]){
                    if(len[it] == INT_MAX){
                        mq.push(it) , len [it] = dep+1;
                        if(it == ed){
                            ok = 0 ;break;
                        }
                    }
                }
            }
        }
        cout<<"To get from "<<s<<" to "<<l<<" takes "<<len[ed]<<" knight moves.\n";

    }


}
