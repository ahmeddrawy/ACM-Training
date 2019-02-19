/**
    *   saved codes from HANAFY
     1 - REMOVE NON ALPHA AND TRANSFORM TO LOWER
     2 - MERGE SORT AND COUNT INVERSIONS
     3 - SOME BIT MANITPULATION TRICKS
     4 - GET ALL SUBSETS WITH SIZE R
     5 - MODULO POWER
     6 - SIEVE - PRIME FACTORIZATION
     7 -  modulo power
     8 - all divisors by sieve
     9 - INCREASE RANGE (I, J) IN ARRAY
    10 - DFS counting connected component
    11 - BFS building path
    12 - the amount of numbers divisible by M in a range from A to B
    13 - power mod
    14 - prefix matrix sum
    15 - rand numbers without collisions
    16 - don't ceil the negative
    17 - dividing sk to k elements and max them
    18 - GCD  and LCM and number theory notes
        18.1 - gcd and lcm
        18.2 - permutations and combinations from product rule
        18.3 - stirling numbers
            18.3.1 - # of permutations to divide n elements to k groups
            18.3.2 - # of permutations of n elements with k permutation cycles
        18.4 - Bell numbers  - # of partions of a set of of size n
        18.5 - power in log (p)
        18.6 - get the a^1 + a^2 + ... + a^n
        18.7 - intro to combinatrics from top coder
*/

///     1-    code to remove all not alpha chars from a string and transform to lower
string temp ;
temp.erase(remove_if(temp.begin(), temp.end(), [](char c) { return !isalpha(c); } ), temp.end());
transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

///     2-  Merge sort and count inversions

ll cnt = 0;
void Merge(int A[] , int left , int mid , int right){
    ll p = left , q = mid +1 ;
    int Arr[right - left +1];
    int  k = 0 ;
    for(int i = left ;i <=right  ; ++i){
        if(p>mid)                   ///if the first part is finished
            Arr[k++] = A[q++];
        else if(q>right)            /// if the second is finished
            Arr[k++]= A[p++];
        else if(A[p] <=A[q])            /// check if the first part element smaller than the second one
            Arr[k++] = A[p++];
        else{
            cnt+=mid - p +1,Arr[k++] = A[q++];  /// counting inversions
//            cout<<q<<" <= q == p => "<<p <<" left "<<left<<" mid "<<mid<<" right "<<right <<endl;
        }

    }
    for(int i = 0 ; i < k ; ++i)
        A[left++] = Arr [i];
}
void mergesort(int arr[] , int left , int right){
    if(left<right){
        int mid = left +(right-left)/2;
        mergesort(arr , left , mid);
        mergesort(arr , mid+1 , right);
        Merge(arr, left , mid , right);


    }

}
///     3- BIT MANIPULATION TRICKS
 isOn(S, j) (S & (1 << j))
setBit(S, j) (S |= (1 << j))
clearBit(S, j) (S &= ~(1 << j))
toggleBit(S, j) (S ^= (1 << j))
lowBit(S) (S & (-S))
setAll(S, n) (S = (1 << n) - 1)
modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2 *haven't understood this yet
isPowerOfTwo(S) (!(S & (S - 1)))            // done
nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))  // TBD
turnOffLastBit(S) ((S) & (S - 1))       // turn off last unset bit from right
turnOnLastZero(S) ((S) | (S + 1))       //turn on last unset bit from right
turnOffLastConsecutiveBits(S) ((S) & (S + 1))
turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))


///     4-GET  ALL SUBSETS OF SIZE R
void combination( int indx , int  i , int data[] ){
    if(indx == R){
//        sort(data , data+7);
        lp(i,0,5)   cout<<data[i]<<' ';
        cout<<data[5];
        cout<<'\n';
        return;
    }
    if(i>=k)return ;
    data[indx ]= arr[i];            /// include current indx
    combination(indx+1 , i+1 , data);   ///INDX INCLUDED
    combination(indx , i+1 , data);     ///INDX NOT INCLUDED


}
///     5- MODULO POWER
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
///       6 - seive - prime factorization
const int N = 1e6 + 5, MOD = 1e9 + 7;
int factor[N];
int sieve() {
	for (int i = 2; i * i < N; ++i) {
		if (factor[i])
			continue;
		for (int j = i * i; j < N; j += i)
			factor[j] = i;
	}
}
set<int> factorize(int x) {
	set<int> ret;
	int prev = -1;
	while (x > 1) {
		if (factor[x] == 0)
			factor[x] = x;
		ret.insert(factor[x]);
		x /= factor[x];
	}
	return ret;
}

///  7 -        modulo power
long long power(long long base, int exp)
{
    if (!exp)
        return 1LL;
    ll sq = power(base, exp/2);
    sq = (sq * sq)%MOD;
    if (exp&1)
        sq = (sq * base)%MOD;
    return sq;
}
const int N = 1000005;
int arr[N] ;
///        8- all divisors by sieve
void seive(){

    for(int i = 1; i  < N ; ++i){
        for(int  j = i ; j<N ; j+=i){
            arr[j]++;

        }
    }

}


///     9 - INCREASE RANGE (I, J) IN ARRAY  , zero based  , then get the cuma array
arr[i] +=k ;
arr[j+1 ] -=k ;
lp(i,1,n )arr[i ] +=arr[i-1];
///     10 - dfs counting connected component
vector<int > vec[55];
bool visited [55];
int n , m ;
int ddcnt=0 ;
void dfs(int node){
	visited[node] = true;
	for(auto i: vec[node])
	{
		int child = i;
		if (!visited[i]){
			dfs(i);
            ddcnt++; /// counting here to  skip the first cnt of the first node of the connected component
                    /// counting don't include the last node so we decreased our count for each connected component by 1
                    ///for e.q 1 -> 2 , 2 ->3 , the cnt will be 2
		}
	}

}

void addedge(int x , int y){
    vec[x].push_back(y);
    vec[y].push_back(x);

}
///         11 - BFS and building path

map<int , vector<pair<int , int > > > mmap;

int bfs(int s, int d , vector<vector<int> > & g ){
    vector<int>len(g.size(), INT_MAX);
    vector<int > par(g.size() , -1);
//    cout<<">>" <<s<<" "<<d<<endl;
    int cur = s , sz = 1 , dep =0;
    len[s] = 0;
    bool ok =1;
    queue<int >q ;
    q.push(s);
    for(; ok&& !q.empty() ; ++dep , sz = q.size()){
//            puts("a");

        while(ok &&sz--){
            cur = q.front();
//             cout<<cur<<endl;
            q.pop();
            for(auto it : g[cur] ){
                if(len[it]== INT_MAX){
//                        cout<<"it "<<it<<endl;
                    q.push(it)  ,len[it] = dep+1,par[it] =cur ;
                    if(it == d){
                        ok =0 ;
                        break;
                    }
                }
            }
        }
    }
//    puts("aa");
    int ret = INT_MAX ;

    while(d!=-1 ){
            cout<<d << endl;        /// if you want to build path only
            d=par[d];

            /// here check the min flow of the path of colors for example
        map<int , int > clr ; /// we have d , p[d] , p[p[d]] , then d = p[d]
        int p = par[d ];
        int grand = par[p];
        for(auto it : mmap[d]){

            if(it.first == p){
                clr[it.second]++;
            }
        }
        for(auto it : mmap[grand]){

            if(it.first == p){
                clr[it.second]++;
            }
        }
        int cnt = 0 ;
        if(p == -1) break;

        for(auto it :clr){
            if(grand != -1  && it.second == 2)
                    cnt++;
            else if(grand  == -1  && it.second ==1 )
                cnt++;


        }

        d = par[d];
        ret =min(ret , cnt );

    }
    return ret ;


}
void addedge(int x , int y , vector<vector<int> > &vec){
    vec[x].push_back(y);
    vec[y].push_back(x);

}
///     12-  the amount of numbers divisible by M in a range from A to B

int solution(int A, int B, int M) {
    return (B / M) - (A / M) +(A % M == 0 || B%M == 0);
}


///     13 - power mod

int pw (int a, int b)
{
    int p = 1;
    while (b--)
        p = (1LL * p * a) % mod;
    return p;
}
///     14- prefix matrix sum
/// first get the cumulative sum of columns then that of rows or vice versa
const int N = 1e4 +5;
int arr[N][N];
void perfixMATRIX(int n , int m ){
    lp(j,0,m)
    lp(i,1,n)
        arr[i][j]+=arr[i-1][j];
    lp(i,0,n)
    lp(j,1,m)
        arr[i][j]+=arr[i][j-1];
}


///     15 - rand numbers without collisions
(rand() * RAND_MAX + rand()) % 1000000
///     16 - don't ceil the negative

///     17 -  to divide the sum evenly on K partions you shouldn't ceil
int remi = sk%k;
lp(i,0,k){
cout<<sk/k +(remi> 0 ) <<" " , remi--;
}

///     18- gcd and lcm and number theory video
/// gcd eliminate the cycles by mod
int gcd (int a , int b ){
    if(b== 0) return  a;
    return  gcd(b , b%a);
}



/// a = 2^3 * 7^6 , b = 2^2 *7^3
/// gcd = 2^min(3 , 2 ) *7^min(6 , 3)
/// lcm = 2^max(3,2) *7^max(6,3)
then lcm = a*b/gcd(a , b );


/**
  permutations from rule of product
  first you have n options then n-1 options then n-2  ... 1
  p(n) = n*n-1 * n-2 * .... * 1 = n!
  p(n,r) = n* n-1 * n-2 * ... (n-r+1)

   p(n , r) = n! /(n-r)! = c(n , r) * r!
   p with repitions  =n^n

   take care of the overflow
   some values get very high






 */

/*     todo
    check the stirling numbers - # of permutations to divide n elements to k groups
                               - # of permutations of n elements with k permutation cycles
    check the Bell number - # of partions of a set of of size n


 */
/**
 * power in O(log p)
 * 10^16 = 10^8 * 10^8
 * 10^17 = 10^8 * 10^8 * 10
 */
 int pow (int b , int p ){
     if(p == 0 )return  1;
     int sq = pow(b , p/2);
     sq *=sq;

     if(p&1 )sq *=b; /// if odd

    return  sq ;

 }
//  todo     check then code in mostafa saad video https://www.youtube.com/watch?v=YklnFXpq0ZE
/**
 *      calcualting a^1 + a^2 + a^3 + a^4 + ... +a^n
 *
 *      at  n == 6
 *      a^1 + a^2 + a^3 + .. +a^6 = a^1 + a^2 + a^3 + (a^1 * a^3 + a^2 *a^3 + a^3 * a^3)
 *                                  = ,,    ,,   + a^3(a^1 + a^2 + a^3)
 *     take the (a + a^2 + a^3 )common factor
 *                                   = (1 + a^3 )*(a + a^2 + a^3)
 */

/** intro to combinatorics  https://www.topcoder.com/community/competitive-programming/tutorials/basics-of-combinatorics/
 * =>    When we choose k objects from n-element set in such a way that
 *        the order matters and each object can be chosen only once
 *              p(n, k ) = n! / (n-k)!
 *
 * =>     The number of possible choices of k objects from a set of n objects when order is important and one object can be chosen more than once:
 *          n * k
 *
 * =>     The number of different permutations of n objects, where there are n1 indistinguishable objects of type 1, n2 indistinguishable objects of type 2,…,
 *          and nk indistinguishable objects of type k (n1+n2+…+nk=n), is:
 *          Cn(n1 , n2 ... nk ) = n!/(n1! n2! ... nk!)
 *
 * =>      In combinations we choose a set of elements (rather than an arrangement, as in permutations) so the order doesn’t matter.
 *          The number of different k-element subsets (when each element can be chosen only once) of n-element set is
 *          nCk = n! / (k! n-k !)
 *
 * =>       Let’s say we choose k elements from an n-element set, the order doesn’t matter and each element can be chosen
 *          more than once. In that case, the number of different combinations is:
 *          (n+k -1 ) C k = (n+k-1 )/ k!*(n-1)!
 *
 *
 *
 *
 */

/// generating the combination by next permutation
vector<bool> mvec(n);
std::fill(mvec.end() - r, mvec.end(), true); /// nCr
double ans  = 0 ;
ll cnt  = 0 ;
do {
    ans++;
    vector<int > temp ;
    lp(i,0,n){
    if(mvec[i]){
            temp.push_back(arr[i]); /// the element selected now
        }
    }


    if(__gcd(temp[0] , temp[1]) == 1)
    cnt++;

}
while(next_permutation(mvec.begin() , mvec.end()));