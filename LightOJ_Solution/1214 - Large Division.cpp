//package pkg1214;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.io.*;
class Main {
    public static void main(String[] args) {
        int cases,caseno;
        Scanner sc = new Scanner(System.in);
        cases=sc.nextInt();
        for(caseno=1;caseno<=cases;caseno++)
        {
            BigInteger a,b,c;
            a=sc.nextBigInteger();
            b=sc.nextBigInteger();
            if(a.compareTo(BigInteger.ZERO)<0)
                a=a.multiply(BigInteger.valueOf(-1));
            if(b.compareTo(BigInteger.ZERO)<0)
                b=b.multiply(BigInteger.valueOf(-1));
            c=a.mod(b);
            //if(a.mod(b).equals(BigInteger.ZERO))
            if(c.intValue()==0)
                System.out.printf("Case %d: divisible\n",caseno);
                //System.out.println("Case "+caseno+": divisible");
            else
                System.out.printf("Case %d: not divisible\n",caseno);
                //System.out.println("Case "+caseno+": not divisible");
        }
    }
}