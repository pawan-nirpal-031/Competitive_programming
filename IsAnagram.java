import java.util.*;
public class isAnagram{
    static boolean say(String a,String b){
        static boolean isAnagram(String a, String b) {
            if(a.length()!=b.length()){
                return false;
            }
            a = a.toLowerCase();
            b = b.toLowerCase();
            int c[] = new int[26];
            int d[] = new int[26];
            for(int i =0;i<a.length();i++){
                c[a.charAt(i)-'a']++;
                d[b.charAt(i)-'a']++;
            }
    
            for(int i =0;i<26;i++){
                if(c[i]!=d[i]){
                    return false;
                }
            }
            return true;
        }
    }
   public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String a = sn.next();
        String b = sn.next();
        System.out.println(say(a,b));

   }
}