/*
    11062  -  uva
    20/11/18
   by ahmed_drawy
   strings and set
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
vector<string > svec;
vector<char> sss;
void solve(string s, vector<string > &mymap ,int indx){

    stringstream ss(s) ;
    string temp;
    while(!ss.eof()){
        ss>>temp;
        auto st = 0 ;
        for(int i = 0 ; i < temp.size() ; ++i){
            if(!isalpha(temp[i]) &&i !='-' ){
                mymap.push_back(temp.substr(st ,i));
                st = i+1;
            }

        }
        temp.erase(remove_if(temp.begin(), temp.end(), [](char c) { return !isalpha(c) &&c!='-'; } ), temp.end());
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        mymap.push_back(temp);

    }

}
void solve2(string temp ){
    for(int i = 0 ; i <temp.size() ; ++i){
        if(i !=temp.size()-1)
            if(isalpha(temp[i]) || temp[i]=='-' )
                sss.push_back(tolower(temp[i]));
            else
                sss.push_back(' ');
    }
    if(temp[temp.size()-1]!='-'){
        if(isalpha(temp[temp.size()-1]))
            sss.push_back(tolower(temp[temp.size()-1]));
        sss.push_back(' ');
    }

}

int main(){
	smile();
//	freopen("in.txt","r", stdin );
//	freopen("out.txt","w", stdout );
	string line ;
	vector<string >myset;
	while(getline(cin , line) ){
        solve2(line);
	}
//	lp(i,0,svec.size()){
//        solve(svec[i] , myset , i);
//	}
	set<string >ans;
	string temp;
	for(auto it :sss){
        if(it==' '){

            ans.insert(temp);

            temp="";
        }
        else
        temp+=it;

	}

//    lp(i,1,myset.size()){
//            if(myset[i-1][myset[i-1].size() -1]  =='-'){
//                myset[i-1].erase(myset[i-1].end() -1);
//                bool fo= 0;
//                for(int j = 0 ; j < myset[i].size() ; ++j){
//                    if(myset[i][j] =='-' &&j!=myset[i].size() -1){
//                        myset[i-1] +=myset[i].substr(0,j);
//                        ans.insert(myset[i-1]);
//                        ans.insert(myset[i].substr(j+1));
//                        fo = 1;
//                    }
//
//                }
//                if(!fo){
//                    myset[i-1]+=myset[i];
//                    myset[i] = myset[i-1];
//                }
//            }
//            else {
//                ans.insert(myset[i-1]);
//            }
//
//    }
    for(auto it : ans ){
            if(it!="")
            cout<<it<<'\n';

    }

}
/*

Adve-
ntu-
res
in
Dis-
ney-
land
Two blon-
des were goi-
ng
to Disneyland
when they came to a
fork in the road.
The sign read: "Disneyland
Left."
So they went home.
*/
