import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class strategy8_2 {
    static int[][] cache;
    static BufferedReader br;
    static ArrayList<String> ss  = new ArrayList<String>();
    public static void solveProblem() throws Exception{
        String[] standard = br.readLine().split("");
        int timeOfProblem = Integer.parseInt(br.readLine());
        for(int i = 0 ; i < timeOfProblem ; i++){
            cache = new int[100][100];
            String compare = br.readLine();
            String[] compareArray = compare.split("");
            if(solve1Problem(standard , compareArray , 0 , 0) == 1){
                ss.add(compare);
            }
        }
    }

    public static int solve1Problem(String[] standard , String[] compare , int standardIndex , int compareIndex) throws Exception{
        if(cache[standardIndex][compareIndex] != 0){
            return cache[standardIndex][compareIndex];
        }
        if(standardIndex == standard.length-1){
            if(standard[standardIndex].equals("*")){
                return cache[standardIndex][compareIndex] = 1;
            }else if(standard[standardIndex].equals("?")){
                if(compareIndex == compare.length-1){
                    return cache[standardIndex][compareIndex] = 1;
                }else{
                    return cache[standardIndex][compareIndex] = 2;
                }
            }else{
                if(compareIndex == compare.length-1){
                    if(standard[standardIndex].equals(compare[compareIndex])){
                        return cache[standardIndex][compareIndex] = 1;
                    }else{
                        return cache[standardIndex][compareIndex] = 2;
                    }

                }else{
                    return cache[standardIndex][compareIndex] = 2;
                }
            }
        }

        if(compareIndex == compare.length-1){
            if(standard[standardIndex].equals(compare[compareIndex]) && standard[standardIndex+1].equals("*") && standardIndex == standard.length-2){
                return cache[standardIndex][compareIndex] = 1;
            }
            return cache[standardIndex][compareIndex] = 2;
        }

        if(standard[standardIndex].equals("*")){
            return cache[standardIndex][compareIndex] = ((solve1Problem(standard,compare,standardIndex+1,compareIndex) ==1)||(solve1Problem(standard,compare,standardIndex,compareIndex+1)==1)||(solve1Problem(standard,compare,standardIndex+1,compareIndex+1) ==1))?1:2;
        }

        if(standard[standardIndex].equals("?")){
            return cache[standardIndex][compareIndex] = solve1Problem(standard,compare,standardIndex+1,compareIndex+1);
        }

        if(standard[standardIndex].equals(compare[compareIndex])){
            return cache[standardIndex][compareIndex] = solve1Problem(standard,compare,standardIndex+1,compareIndex+1);
        }else{
            return cache[standardIndex][compareIndex] = 2;
        }

    }

    public static void main(String args[]) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        int timeOfProblem = Integer.parseInt(br.readLine());
        for(int i = 0 ; i < timeOfProblem ; i++){
            solveProblem();
        }

        for(String i : ss){
            System.out.println(i);
        }
    }
}
