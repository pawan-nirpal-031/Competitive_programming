 
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
#define MOD 1000000007;
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define forit0(i,n) for(ll i =0;i<n;i++)
#define forit(i,l,r) for(ll i =l;i<=r;i++) // run in inclusive range [l to r]
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} // array output macro 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} //array input macro
#define getl(s) getline(cin,s);
class soln{
    int gmax =0;
    public:
        int pachProcess(pair<bool,bool> **a,int i,int j){

        }
        int retAns(pair<bool,bool> **a,int n,int m){

            for (int i = 1; i <= n; i++){

                for (int j = 1; j <= m; j++)
                {
                   if(a[i][j].first==1 && a[i][j].second==0){
                       a[i][j].second = 1;
                       

                   }
            
                }
        
        }


            return gmax;
        }
        

};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    pair<bool,bool> **a;
    a = new pair<bool,bool> *[n+2];
    for (int i = 0; i <=n+1; i++){
        a[i] = new pair<bool,bool>[m+2];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j].first;
            a[i][j].second = 0;
            
        }
        
    }

    
    return 0;
}