import java.io.BufferedReader;
import java.io.InputStreamReader;

public class strategy7_2 {
    public static String reverseQuadTree(String quadTree){

        if (!quadTree.contains("x")){
            return quadTree;
        }

        if (quadTree.length() % 4 != 1){
            int indexOfUp = 0;
            int upperPartFinished = 1;
            while(true){
                if(!quadTree.substring(indexOfUp,indexOfUp+1).equals("x")){
                    upperPartFinished--;
                }else{
                    upperPartFinished += 3;
                }
                indexOfUp++;
                if(upperPartFinished == 0){
                    break;
                }

            }
            return reverseQuadTree(quadTree.substring(0,indexOfUp))+reverseQuadTree(quadTree.substring(indexOfUp));

        }else{
            int indexOfUp = 1;
            int upperPartFinished = 2;
            while(true){
                if(!quadTree.substring(indexOfUp,indexOfUp+1).equals("x")){
                    upperPartFinished--;
                }else{
                    upperPartFinished += 3;
                }
                indexOfUp++;
                if(upperPartFinished == 0){
                    break;
                }

            }
            return "x"+reverseQuadTree(quadTree.substring(indexOfUp))+reverseQuadTree(quadTree.substring(1,indexOfUp));

        }

    }
    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numberOfProblem = Integer.parseInt(br.readLine());

        for(int i = 0 ; i < numberOfProblem ; i++){
            System.out.println(reverseQuadTree(br.readLine()));
        }
    }
}
