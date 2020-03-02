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
#define MOD 1000000007;
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define forit0(i,n) for(ll i =0;i<n;i++)
#define forit(i,l,r) for(ll i =l;i<=r;i++) // run in inclusive range [l to r]
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} // array output macro 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} //array input macro
#define getl(s) getline(cin,s);
class Solution{
    public:
    int gmax;
    Solution(){
        gmax =0;
    }


    int pach(bool **a,int row,int col){
        if(a[row][col]==0){
            return 0;
        }
        int size =1;
       // cout<<"row now : "<<row<<" col now : "<<col<<endl;
        a[row][col] =0;
        for (int r = row-1; r <=row+1; r++)
        {
            for (int c = col - 1; c <= col+1; c++)
            {
               if(r != row || c != col){
                    size+= pach(a,r,c);
               }
            }
            
        }
        return size;
    }


    int rec(bool **a,int rows,int cols){
            for (int i = 1; i <=rows; i++){
                for(int j =1;j<=cols;j++){
                    int c =0;
                    if(a[i][j]!=0){
                        c = pach(a,i,j);
                    }
                    if(c>gmax){
                        gmax = c;
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
    int n;
    int m;
    cin>>n>>m;
    bool **a =  new bool*[n+2];
    //cout<<"here";
    for (int i = 0; i <= n+1; i++)
    {
        a[i] = new bool[m+2];
    }
    for (int i = 0; i <=n+1; i++)
    {
        for(int j =0;j<=m+1;j++){
            a[i][j] =0;
        }
    }
     for (int i = 1; i <=n; i++)
    {
        for(int j =1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    
    Solution s;
    cout<<s.rec(a,n,m);
    return 0;
}