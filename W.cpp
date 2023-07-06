#include <bits/stdc++.h>
using namespace std;
 
// Define Template          Python++
// Math
const long double PI = acos(-1);
#define intlen(num)         to_string(num).size()
// Data Structure and Algorithm
#define all(vec)            (vec).begin(),(vec).end()
#define arrsize(arr)        sizeof(arr)/sizeof(int)
#define sortarr(arr)        sort(arr,arr+arrsize(arr));
#define sortvec(vec)        sort(all(vec));
#define minarr(arr)         *min_element(arr,arr+arrsize(arr))
#define minvec(vec)         *min_element(all(vec))
#define maxarr(arr)         *max_element(arr,arr+arrsize(arr))
#define maxvec(vec)         *max_element(all(vec))
#define sumarr(arr)         accumulate(arr,arr+arrsize(arr),0LL)
#define sumvec(vec)         accumulate(all(vec),0LL)
#define reversearr(arr)     reverse(arr,arr+arrsize(arr));
#define reversevec(vec)     reverse(all(vec));
#define range(i,s,e)        for(int i=s;i<e;i++)
#define range2(i,s,e)       for(int i=s;i>=e;i--)
#define fors(var,arr)       for(auto &var:arr)
// Input Output Manage
#define endl "\n"
#define debug(x)    cout<<(#x)<<" : "<<(x)<<endl;
#define debughere cout << "HERE\n";
#define test        cout<<"test"<<endl;
#define fastIO              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define floatprecision      cout<<fixed<<setprecision(9);
#define fileread            freopen("input.txt","r",stdin);
#define fileout             freopen("output.txt","w",stdout);
#define query               cin>>QUERY;while(QUERY--)
#define inputarr(arr,am)    int arr[am];fors(num,arr)cin>>num;
#define inputvec(vec,am)    vector<int> vec(am);fors(num,vec)cin>>num;
#define input(var)          int var;cin>>var;
#define input2(a,b)         int a,b;cin>>a>>b;
#define inputs(var)         string var;cin>>var;
#define print(var)          cout<<(var)<<endl;
#define prints(var)         cout<<(var)<<" ";
#define print2(var1,var2)   cout<<(var1)<<" "<<(var2)<<endl;
#define printp(paired)      cout<<(paired.first)<<" "<<(paired.second)<<endl;
#define printyes(cond)      cout<<((cond)?"YES":"NO")<<endl;
#define printarr(arr)       fors(num,arr){cout<<num<<" ";};cout<<endl;
#define printmap(hashmap)   for(auto[x,y]:hashmap)cout<<x<<" : "<<y<<endl;
#define endline             cout<<endl;
// Macro
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define mii map<int,int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue
#define mp make_pair
#define ms multiset
// Oneliner Function
ll sigma(ll num){return (num*(num+1))/2;}
ll gcd(ll a, ll b){return (a==0?b:gcd(b%a,a));}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll binpow(ll a,ll b,ll m=INT64_MAX){ll r=1;a%=m;while(b){if(b&1)r=(r*a)%m;a=(a*a)%m;b>>=1;}return r;}
ll invmod(ll a,ll m){return gcd(a,m)==1?binpow(a,m-2,m):0;}
ll lsb(ll x){return log2(x&-x)+1;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define int long long
#define float long double
int QUERY;
// Constant
const int MOD = 1e9+7;
const long long INF = 1e18;
const int maxn = 2e5+5;


struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N+10, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};
 
void open(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
} 
 
struct matrix {
    long long mat[2][2];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < 2; k++) {
                  c.mat[i][j] =(c.mat[i][j]+ a.mat[i][k] * b.mat[k][j])%MOD;
              }
          }
        }
        return c;
    }
};

matrix matpow(matrix base, long long n) {
    matrix ans{ {
      {1, 0},
      {0, 1}
      /*
      f(n) f(n-1)
      f(n-1) f(n)
      normal fibbonaci sequence
      0,1,1,2,3,5,...
      */
    } };
    while (n) {
        if(n&1)
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }
    return ans;
}

long long fib(int n) {
    matrix base{ {
      {1, 1},
      {1, 0}
    } };
    return matpow(base, n).mat[0][1];
}



void solve(){
    int freq[26] = {0};
    input(q)
    range(i,0,q){
        string temp;
        cin >> temp;
        range(j,0,temp.size()) freq[temp[j]-'a']++;
    }

    int minim = INF;
    minim = min({freq[22],freq[0],freq[3],freq[20],freq[7]});
    print(minim)
}
 
 
int32_t main(){
    fastIO
 
 
     solve();
 
 
    return 0;
}