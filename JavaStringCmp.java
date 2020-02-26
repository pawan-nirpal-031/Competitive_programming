import java.util.*;
public class JavaStringCmp{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        String smallest = s.substring(0,k);
        String largest = s.substring(0, k);
        for (int i = 0; i < s.length()-k+1; i++) {
            String x = s.substring(i, i+k);
            if(x.compareTo(smallest)<0){
                smallest = x;
            }
            if(x.compareTo(largest)>0){
                largest = x;
            }
        }


        sc.close();
    }
}
