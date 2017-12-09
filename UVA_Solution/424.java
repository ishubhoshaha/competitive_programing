package pkg424;
import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        BigInteger a,result = BigInteger.ZERO;
        while(sc.hasNext()){
            a=sc.nextBigInteger();
            if(a.compareTo(BigInteger.ZERO)==0){
                break;
            }
            result = result.add(a);
        }
        System.out.println(result);
    }
    
}
