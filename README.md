# Competitive_programming

https://www.codechef.com/FEB20B/problems/CASH (nice one)

https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm  (permutaion genrator)


One line Palindrome Checker in java :
Imp thing to note as String is immutable it does not have any reverse method but StringBuilder does so :>

"
Scanner sc=new Scanner(System.in);
String s=sc.next();
System.out.println( s.equals(new StringBuilder(s).reverse().toString())?"Yes":"No" );

"
