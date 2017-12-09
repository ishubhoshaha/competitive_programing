package pkg10106;
import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        BigInteger a,b,c;
        while(sc.hasNext()){
            a=sc.nextBigInteger();
            b=sc.nextBigInteger();
            c=a.multiply(b);
            System.out.println(c);
        }
    }
}
