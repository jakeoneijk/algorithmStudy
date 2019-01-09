public class Insight0001 {

    static long record[][] = new long[200][200];

    public static long choose(int n , int r){

        if (record[n][r] > 0){
            return record[n][r];
        }

        if(r==0 || n ==r){
            return record[n][r] = 1;
        }else{
            return record[n][r] = choose(n-1,r-1)+choose(n-1,r);
        }
    }

    public static void main(String args[]){
        System.out.println(choose(3,2));
    }
}
