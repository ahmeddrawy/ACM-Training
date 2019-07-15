/*
    12504  -  uva
   9/10/18
   by ahmed_drawy
   having presentation errors
   not accepted but the idea is right


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
void fillmap(map<string , string > & map1 , string f){
    string temp , temp2 ;bool filled =0;
    lp(i,0, f.size()){
            if(!isalnum(f[i]) && temp.size() == 0 )continue;
            else if(!isalnum(f[i]) && filled ==0){
                filled =1;continue;
            }
            else if(!isalnum(f[i] ) && filled){
                map1[temp] = temp2;
                filled= 0;

                temp="";
                temp2="";
            }
            else if(filled == 0){
                temp +=f[i];
            }
            else {
                temp2+=f[i];
            }

        }

}
 template<typename T>
void printvec(  vector<T>  vec){
    for(int i = 0 ; i < vec.size() ; ++i)   cout<<vec[i]<<" ";
    cout<<endl;
}
int main(){
	smile();
	freopen("out.txt","w",stdout);
    int t ; cin >>t;
    cin.ignore();
    while(t--){
        string  f , s;

        getline(cin , f);
        getline(cin , s);
        map<string , string > map1 ;
        map<string , string > map2 ;

        fillmap(map1 , f);
        fillmap(map2 , s);
        vector  <string > plus_f;
        vector  <string > plus_s;
        set  <string > changed;

        for(auto it = map2.begin() ; it!= map2.end()  ; ++it){
                auto it2 = map1.find(it->first);
                if(it2!=map1.end()){
                    if(it2->second != it->second)
                    changed.insert( it->first);
                }
                else {

                    plus_f.push_back(it->first);
                }

        } for(auto it = map1.begin() ; it!= map1.end()  ; ++it){
                auto it2 = map2.find(it->first);
                if(it2==map2.end() ){
                    plus_s.push_back(it->first);
                }
                else {
                     if(it2->second != it->second)
                    changed.insert( it->first);
                }

        }
        sort(plus_f.begin() , plus_f.end());
        sort(plus_s.begin() , plus_s.end());
//        printvec(plus_f);
//        printvec(plus_s);
//        printvec(changed);


        if(plus_f.size())
            cout<<"+";
        for(int i = 0 ; i <  plus_f.size() ; ++ i)
            if(i)
                cout<<","<<plus_f[i];
            else cout<<plus_f[i];
        if(plus_f.size()&&( !plus_s.size() ||!changed.size() ||t>=1))
            cout<<endl;
        if(plus_s.size())
            cout<<"-";

        for(int i = 0 ; i <  plus_s.size() ; ++ i)
                 if(i)  cout<<","<<plus_s[i];
                 else   cout<<plus_s[i];
        if(plus_s.size() && (!changed.size() || t>=1))
            cout<<endl;
        if(changed.size())
            cout<<"*";
        int i = 0;
        for(string it : changed)
            if(i)
                cout<<","<<it;
            else cout<<it, ++i;
        if(changed.size())  cout<<endl;
        if(!changed.size() &&!plus_f.size() &&! plus_s.size())
            cout<<"No changes";

        if(t>=1 )cout<<endl;
    }

}

/*

3
{a:3,b:4,c:10,f:6}
{a:3,c:5,d:10,ee:4}
{x:1,xyz:123456789123456789123456789}
{xyz:123456789123456789123456789,x:1}
{first:1,second:2,third:3}
{third:3,second:2}






*/
