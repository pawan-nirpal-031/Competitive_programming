import java.io.*;
import java.util.*;

public class Solution {
   static StringBuilder ans;
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        char[] a = sc.next().toCharArray();
        char[] b = sc.next().toCharArray();
        if(a.length != b.length) {
            Arrays.sort(a);
            for(int i=a.length-1;i>=0;--i) System.out.print(a[i]);
        }else {
            int[] map = new int[10];
            for(char x : a) map[x-'0']++;
            ans = new StringBuilder();
            f(0,true,b,map);
            System.out.println(ans);
        }
        
        //out.close();
    }
    private static void f(int i,boolean tight, char[] b, int[] map) {
        if(i == b.length) return;
        int st = tight ? b[i]-'0':9;
        int dig = st;
        while(map[dig] == 0) --dig;
        ans.append((char)(dig+'0'));
        map[dig]--;
        f(i+1,tight&(dig == st),b,map);
    }

}