#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <iterator>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
typedef unsigned long long int ull;
typedef long double ld;
ull Fast_Exp(ull a,ull n) // O(log(n)) time 
{
    ull x =0;
    if (n==0)
    {
       return  1;
    }
    else if (n==1)
    {
        return  a;
    }
    else
    {
        x = Fast_Exp(a,n/2);
        if (n%2==0)
        {
            return x*x;
        }
        else
        {
            return x*a*x;
        }  
    }
    
}
ull gcd_euclid(ull a, ull b)//Important : [ make sure function call for this function is done like this : gcd_euclid(min(a,b),max(a,b)) ]
{
    if (b%a==0)
    {
        return a;
    }
    else
    {
        return gcd_euclid(b%a,a);
    }
    
    
}
int main()
{
    
   
   return 0;
}