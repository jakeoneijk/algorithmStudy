import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class strategy7_2_2 {
    public static String[] input;
    public static int index = 0;

    public static String reverseQuadTree2(){
        String head = input[index++];
        if(head.equals("b") || head.equals("w"))
            return head;
        String upperLeft = reverseQuadTree2();
        String upperRight = reverseQuadTree2();
        String lowerLeft = reverseQuadTree2();
        String lowerRight = reverseQuadTree2();
        return "x" + lowerLeft + lowerRight + upperLeft + upperRight;

    }

    public static void main(String args[]) throws Exception{


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numberOfProblem = Integer.parseInt(br.readLine());

        for(int i = 0 ; i < numberOfProblem ; i++){
            input = br.readLine().split("");
            System.out.println(reverseQuadTree2());
        }

    }
}
