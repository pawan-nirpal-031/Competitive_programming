#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <iterator>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define forit0(i,n) for(ll i =0;i<n;i++)
#define forit(i,l,r) for(ll i =l;i<=r;i++) // run in inclusive range [l to r]
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} // array output macro 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} //array input macro
#define getl(s) getline(cin,s);


#define N 10
ll a[N][N], I[N][N];


void mul(ll I[][N],ll A[][N],ll m){
    ll res[N][N];
    for(ll i =0;i<m;i++){
        for(ll j =0;j<m;j++){
            res[i][j]=0;
            for(ll k =0;k<m;k++){
                res[i][j] =(res[i][j]%mod + ( (I[i][k]%mod*A[k][j]%mod)%mod))%mod;
            }

        }
    }
    for(ll i =0;i<m;i++){
        for(ll j =0;j<m;j++){
            I[i][j]=res[i][j];
        }
    }
}

void print(ll I[][N],ll m){
    for(ll i =0;i<m;i++){
        for(ll j =0;j<m;j++){
            cout<<I[i][j]<<' ';
        }
        cout<<endl;
    }
}
void powr(ll A[][N],ll m,ll n){
    for(ll i=0;i<m;i++){
        for(ll j =0;j<m;j++){
            if(i==j){
                I[i][j]=1;
            }else{
                I[i][j]=0;
            }
        }
    }
    while(n>0){
        if(n%2){
            n-=1;
            mul(I,A,m);
        }else{
            n/=2;
            mul(A,A,m);
        }
    }
    // I now has inputMatrix^n ie a^n
   
 

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    ll m=2,f1,f2,n;
    cin>>f1>>f2>>n;
    a[0][0]=0;
    a[0][1]=a[1][0]=a[1][1]=1;
    powr(a,m,n-1);
    cout<<(  ( ((f1%mod)*(I[0][1]%mod))%mod) + (((f2%mod)*(I[1][1]%mod))%mod)  )%mod<<'\n';
    }
    return 0;
}