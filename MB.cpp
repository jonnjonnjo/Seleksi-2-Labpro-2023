#include <bits/stdc++.h>
using namespace std;
 
// Define Template          Python++
// Math
const int MOD = 1e9+7;
const long long INF = INT32_MAX;
#define intlen(num)         to_string(num).size()
// Data Structure and Algorithm
#define pb push_back
#define ms(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define all(vec)            vec.begin(),vec.end()
#define arrsize(arr)        sizeof(arr)/sizeof(int)
#define sortarr(arr)        sort(arr,arr+arrsize(arr));
#define sortvec(vec)        sort(all(vec));
#define minarr(arr)         *min_element(arr,arr+arrsize(arr))
#define minvec(vec)         *min_element(all(vec))
#define maxarr(arr)         *max_element(arr,arr+arrsize(arr))
#define maxvec(vec)         *max_element(all(vec))
#define sumarr(arr)         accumulate(arr,arr+arrsize(arr),0)
#define sumvec(vec)         accumulate(all(vec),0)
#define reversearr(arr)     reverse(arr,arr+arrsize(arr));
#define reversevec(vec)     reverse(all(vec));
#define range(i,s,e)        for(int i=s;i<e;i++)
#define range2(i,s,e)       for(int i=s;i>=e;i--)
#define fors(var,arr)       for(auto &var:arr)
// Input Output Manage
#define fastIO              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fileread            freopen("input.txt","r",stdin);
#define fileout             freopen("output.txt","w",stdout);
#define inputarr(arr,am)    int arr[am];fors(num,arr)cin>>num;
#define inputvec(vec,am)    vector<int> vec(am);fors(num,vec)cin>>num;
#define input(var)          int var;cin>>var;
#define input2(a,b)         int a,b;cin>>a>>b;
#define inputs(var)         string var;cin>>var;
#define print(var)          cout<<(var)<<endl;
#define prints(var)         cout<<(var)<<" ";
#define print2(var1,var2)   cout<<(var1)<<" "<<(var2)<<endl;
#define printp(paired)      cout<<(paired.first)<<" "<<(paired.second)<<endl;
#define printyes(cond)      cout<<(cond?"YES":"NO")<<endl;
#define printarr(arr)       fors(num,arr){cout<<num<<" ";};cout<<endl;
#define printmap(hashmap)   fors(paired,hashmap)cout<<(paired.first)<<" : "<<(paired.second)<<endl;
#define endline             cout<<endl;
#define test                input(t); while(t--)
#define int long long
 
 
int n,x;
const int maxn = 1e6 + 1;
int c[maxn];
int dp[maxn];
 
 
 /*
    Basically just CSES problem
    https://cses.fi/problemset/task/1636
    go try submit ur solution in here before submit it to the vjudge
 
 */
 
 
int32_t main(){
#ifndef ONLINE_JUDGE
    //fileread
    #define debug print("test")
#else
    #define debug
#endif
    fastIO
 
    cin >> n >> x;
 
    range(i,0,n) cin >> c[i];
 
    dp[0] = 1;
 
    for(int i = 0;i <n;i++)
    {
        for(int j = 0;j <=x;j++)
        {
            if(j - c[i] >=0)
                dp[j] = (dp[j] + dp[j - c[i]])%MOD;
        }
    }
 
    cout << dp[x];
 
 
 
    return 0;
}
