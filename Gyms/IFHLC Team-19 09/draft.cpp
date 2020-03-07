/// ACM-ICPC-Swiss-Subregional 2017 - by ahmed_drawy 09/10/19
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v));
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
#define debug(x) cerr << x<<endl;
const double EPS = (1e-7);
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
//    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}
int randomF() {
    return  (rand() * RAND_MAX + rand()) % 1000000;

}

int MOD ;
int mod(ll x){
    return (x%MOD + MOD)%MOD;
}
long long add(long long x, long long y)
{
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}
ll multipy(ll x , ll y ){
    return ((x%MOD) *(y%MOD))%MOD;
}


int main() {
    smile();
//    freopen("alter.in", "r", stdin);
//    freopen("alter.out", "w", stdout);
    vector<int > mvec;
    for (int m = 1; m <=30 ; ++m) {
        mvec.push_back(m);
    }
    random_shuffle(mvec.begin() , mvec.end());
    random_shuffle(mvec.begin() , mvec.end());
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
//    for (int n = 0; n <sz(mvec) ; ++n) {
//        cout << mvec[n];
//    }
//    return 0 ;
//    fclose(stdout);
    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "r" , stdin);
//    for (int n = 0; n <sz(mvec) ; ++n) {
//        cout << mvec[n] ;
//    }
//    return 0 ;
    string s ;
    cin >> s;
    if(s.size() <= 9 ){
        for (int i = 0; i <s.size() ; ++i) {
            cout << s[i] << " ";
        }

    }
    else {
        map < int , int> mmap ;
        int range= 9 + (s.size() - 9)/2;
        for (int j = 0; j <sz(s) ; ++j) {
            mmap[s[j] -'0']++;
        }

        string res = s ;
        int indx = 0 ;
        map<int , bool >done;
        for (int i = 0  ; i <sz(s) ; ++i) {
            if(mmap[s[i]-'0'] ==1  &&  (s[i]- '0')>=1 ){
                done[s[i]-'0'] =1;
                if(i +1<sz(s)) {
                    res.insert(i + indx + 1, " ");
                }
                if(i+indx >0) {
                    res.insert(i + indx , " ");
                    indx++;
                }
                indx++;
            }

        }
//        cout <<res<<endl;
        vector<string > tobe;
        for (int k = 1; k <=range ; ++k) {
            if(!done[k])
                tobe.push_back(to_string(k));
        }
        int cnt = 0 ;
//        for (int l = 1; l <sz(res) ; ++l) {
//            if(res[l] != ' ' && res[l-1] != ' '){
//                if(!done[res[l] - '0']&& !done[res[l-1]-'0']&& (res[l] -'0')+ (res[l-1] -'0')*10 >range && res[l-1]!='0') {
//                    res.insert(l, " ");
//                    done[res[l] - '0'] = 1;
//                    done[res[l-1]-'0'] = 1;
//                }
//            }
//
//        }
        while(true){
            bool yes=  0;
            cnt++;
            for(int k = range; k >=10;--k) {
                string curr = to_string(k);
                if(done[k]) continue;
                yes =1;
                if(curr.size() != 2)
                    continue;

//                string curr = to_string(num);
                int cnt = 0;
                int indx = 0;
                for (int i = 1; i < sz(res); ++i) {
                    if (curr[0] == res[i - 1] && curr[1] == res[i]) {
                        cnt++;
                        indx=  i;
                    }
                }
                if (cnt == 1) {
                    res.insert(indx+ 1," " );
                    res.insert(indx- 1," " );
                    done[k] = 1;

//                    curr = " ";
                }
            }
            if(!yes || cnt >100)
                break;
        }

        for (int l = 2; l <sz(res) ; ++l) {
            if(res[l] == res[l-1] && res[l-2 ] ==res[l] && res[l]!=' '){
                done[res[l] -'0'] =1;
                done[res[l-1]*10 +res[l-2]] =1;
                res.insert(l , " ");
            }
//            else if(res[l]!=' ' && res[l-1]!=' ' &&)

        }
        for (int l = 1; l <sz(res) ; ++l) {
            if(res[l] != ' ' && res[l-1] != ' '){
                if(!done[res[l] - '0']&& !done[res[l-1]-'0']&& (res[l] -'0')+ (res[l-1] -'0')*10 >range && res[l-1]!='0') {
                    done[res[l] - '0'] = 1;
                    done[res[l-1]-'0'] = 1;
                    res.insert(l, " ");

                }
            }

        }
////        for (int m = 0; m <sz(res) ; ++m) {
////
////        }
        for (int m = 10; m <= range ; ++m) {
            string temp = to_string(m);
            temp = ' '+ temp + ' ';
            int f = res.find(temp);

            if(f==string ::npos){
                cout << temp <<" ";
            }
            else {
                int f2 = res.find(temp , f+1);
                if(f2!= string ::npos) {
                    done[res[f] - '0'] =1;
                    done[res[f+1] - '0'] =1;
                    res.insert(f +2, " ");

                    --m;
                }
            }
        }
        for (int m = 1; m <= range ; ++m) {
            string temp = to_string(m);
            string tt =' '+ temp + ' ';
            if(res.find(tt)!=string ::npos){
                int nw= -1 ;
                while(true){
                    int f=res.find(temp, nw+1);
                    if(f!= string ::npos){
                        if(res[f-1] !=' '){

                        }
                    }
                }
            }
        }
        cout <<range<<endl;
        cout <<res<<endl;
//        bool no =0;

//        if(no) cout <<"NO \n";
//        else cout <<"YES\n";
    }
    return  0 ;
}
---
/// ACM-ICPC-Swiss-Subregional 2017 - by ahmed_drawy 09/10/19
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v));
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
#define debug(x) cerr << x<<endl;
const double EPS = (1e-7);
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}
int randomF() {
    return  (rand() * RAND_MAX + rand()) % 1000000;

}

int MOD ;
int mod(ll x){
    return (x%MOD + MOD)%MOD;
}
long long add(long long x, long long y)
{
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}
ll multipy(ll x , ll y ){
    return ((x%MOD) *(y%MOD))%MOD;
}


int main() {
    smile();
//    freopen("joke.in", "r", stdin);
//    freopen("joke.out", "w", stdout);
    string s; cin>>s;
    if(s.size()<=9){
        for(auto it : s){
            cout << it << " ";
        }
        return 0 ;
    }
    int range= 9 + (sz(s )-9)/2;
//    map<int, int >frq;
//    map<int, vector<int> >indices;
//    for (int i = 1; i <=range ; ++i) {
//        frq[i%10]++;
//
//    }
//    string res =s;
//    for (int j = 0; j <sz(res) ; ++j) {
//        int i = res[j]-'0';
//        indices[i%10].push_back(j);
//    }






    string res= s;
    map<int , int >done ;
//    for (int j = 0; j < ; ++j) {
    for (int j = 1; j < sz(res); ++j) {
        if(res[j-1] == '0')
            res.insert(j, " ");
        else if(res[j-1] !=' '&& res[j] !=' ' &&  (res[j-1] - '0')*10 + res[j]-'0' > range) {
            res.insert(j, " ");
//            done[]
        }
    }
    cout <<res<<endl;
    for (int i = range; i >= 1; --i) {
        string temp = to_string(i);
        int f = res.find(temp);
        if (f != string::npos) {
            int f2 = res.find(temp, f + 1);
            if (f2 == string::npos) {
                res.insert(f, " ");

                res.insert(f+temp.size()+1, " ");
                done[i] = 1;
            }
        }
    }
    int f1 = -1;
    int f2 = -1;
    for (int k = -1; k <sz(res) ; ++k) {
        f1 = res.find(" ",k+ 1);
        if(f1 == -1)
            break;
        f2 = res.find(" ",f1+1);
        if(f2 == -1)
            f2= sz(res ) -1;
        if(f2 - f1>1){
            string t ;
            int cnt = f2 - f1-1;
            int r = 0;
            for (int i = f1+1; i <f2 ; ++i) {
                t+=res[i];
                r+=(res[i] - '0')*pow(10, cnt-1);
                cnt--;
            }
            if(r<=range)
                done[r] =1;
        }
    }
    for(int i = 1  ; i <= range ; ++i)
        if(!done[i])
            cout << i << " ";
    cout <<endl;
    cout <<res<<endl;

    return  0 ;
}