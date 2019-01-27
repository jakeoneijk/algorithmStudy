import java.io.BufferedReader;
import java.io.InputStreamReader;

public class strategy7_6 {

    public static int hug(String[] sexOfIdol , String[] sexOfFan){
        if(sexOfIdol.length > sexOfFan.length){
            return 0;
        }
        return 0;
    }

    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numberOfProblem = Integer.parseInt(br.readLine());

        for(int i = 0 ; i < numberOfProblem ; i++){
           String[] sexOfIdol =  br.readLine().split("");
           String[] sexOfFan = br.readLine().split("");
        }
    }
}
