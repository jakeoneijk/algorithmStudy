import java.util.Scanner;

public class Insight0002 {
    public static int payMethod(int leftMoney, int billType, int[] bills){
        if(billType == 0){
            if (leftMoney % bills[0] == 0){
                return 1;
            }else {
                return 0;
            }
        }else{
            int result = 0;
            for(int i = 0; i <= leftMoney / bills[billType]; i++){
                result += payMethod(leftMoney - bills[billType]*i , billType-1 , bills);
            }
            return result;
        }

    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("input number of bills");
        int bills[] = new int[Integer.parseInt(sc.nextLine())];
        System.out.println("input bills");
        String billsString[] = sc.nextLine().split(" ");
        for(int i = 0 ; i < bills.length; i++){
            bills[i] = Integer.parseInt(billsString[i]);
        }
        System.out.println("input money");
        int inputMoney = Integer.parseInt(sc.nextLine());

        System.out.println(payMethod(inputMoney , bills.length-1 , bills));
    }
}
