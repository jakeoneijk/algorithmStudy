import java.util.Scanner;

public class baekjoon1065 {
    public static boolean hansoo(int number){

        int testNumber = number;
        int cd = (testNumber/10) % 10 - testNumber % 10;

        while (testNumber >= 10){
            if(((testNumber/10) % 10 - testNumber % 10) != cd){
                return false;
            }
            testNumber = testNumber/10;
        }

        return true;
    }
    public static void main(String args[]){
       int number = new Scanner(System.in).nextInt();
       int count=0;
       for (int i = 1 ; i <= number; i++){
           if(hansoo(i)){
               count++;
           }
       }

       System.out.println(count);
    }
}
