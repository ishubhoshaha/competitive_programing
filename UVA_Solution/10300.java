package pkg10300;
import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases,caseno;
        cases=sc.nextInt();
        for(caseno=1;caseno<=cases;caseno++){
            int numberOfFarmers = sc.nextInt();
            BigInteger grossTotal= BigInteger.ZERO;
            for(int i=0;i<numberOfFarmers;i++){
                BigInteger space,animal,constant,result;
                space=sc.nextBigInteger();
                animal=sc.nextBigInteger();
                constant=sc.nextBigInteger();
                result=space.multiply(constant);
                grossTotal = grossTotal.add(result);
            }
            System.out.println(grossTotal);
        }
    }
    
}
