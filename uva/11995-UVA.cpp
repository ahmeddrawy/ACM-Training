/*
   11995 - uva
   18/11/18
   by ahmed_drawy

    run time error if pop from DS and it is empty
    WA because of freopen was not commented
    simulating the process of each DS using the DS itself
    accepted
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

int main(){
	smile();
    int n ;
//    freopen("in.txt" , "r", stdin);
//    freopen("out.txt" , "w", stdout);
    while(cin>>n){
        stack<int >mstack;
        queue<int >mqueue;
        priority_queue<int > mprqueue;
        bool s=1 , q=1, pq =1;
        lp(i,0,n){

            int cmd, obj; cin >>cmd>>obj;
            if(cmd == 1){
                mprqueue.push(obj);
                mstack.push(obj);
                mqueue.push(obj);
            }
            else {
                if(mstack.empty() || mqueue.empty() ||mprqueue.empty()){
                            s =0 , q = 0 , pq = 0;
                }
                else {

                    s =s&& mstack.top() == obj;
                    mstack.pop();

                    q = q&& mqueue.front() == obj;
                    mqueue.pop();
                    pq =pq&&mprqueue.top()==obj;
                    mprqueue.pop();

                }
            }


        }
        if(!s && !pq && !q){
            cout<<"impossible\n";
        }
        else if(s ||pq ||q){
            int sum = s + pq +q;

            if(sum == 3|| sum ==2)cout<<"not sure\n";
            else {
                if(s)   cout<<"stack\n";
                else if(q)cout<<"queue\n";
                else       cout<<"priority queue\n";
            }
        }
    }

}
/*


6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4







*/
