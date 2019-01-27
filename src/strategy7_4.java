import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class strategy7_4 {
    public static int maxT(int a, int b, int c){
        int max = Math.max(a,b);
        max = Math.max(max,c);
        return max;
    }

    public static int maxRecycle(int[] fences){
        if (fences.length == 1){
            return fences[0];
        }
        if (fences.length < 3){
           int twoFences = fences[0]+fences[1]- Math.abs(fences[0]-fences[1]);
           return maxT(fences[0] , fences[1] , twoFences);
        }
        int middleIndex = fences.length/2;
        int[] left = new int[middleIndex];
        int[] right = new int[fences.length - middleIndex];
        System.arraycopy(fences,0,left,0,middleIndex);
        System.arraycopy(fences,middleIndex , right,0,fences.length - middleIndex);

        int leftMiddleMin = (fences[middleIndex] > fences[middleIndex-1])?(middleIndex-1):middleIndex;
        int rightMiddleMin = leftMiddleMin;
        int height = fences[leftMiddleMin];

        while (leftMiddleMin>0 && fences[leftMiddleMin] >= height){
            leftMiddleMin--;
        }
        if(leftMiddleMin != 0) leftMiddleMin++;
        if(leftMiddleMin == 0 && fences[leftMiddleMin] < height){
            leftMiddleMin++;
        }
        while (rightMiddleMin<fences.length-1 && fences[rightMiddleMin]>=height){
            rightMiddleMin++;
        }
        if (rightMiddleMin != fences.length-1)rightMiddleMin--;
        if(rightMiddleMin == fences.length-1 && fences[rightMiddleMin] < height){
            rightMiddleMin--;
        }

        int leftResult = maxRecycle(left);
        int rightResult = maxRecycle(right);
        int middleResult = (rightMiddleMin - leftMiddleMin + 1) * height;

        return maxT(leftResult,rightResult,middleResult);




    }

    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numberOfProblem = Integer.parseInt(br.readLine());

        for(int i = 0 ; i < numberOfProblem ; i++){
            int[] fences = new int[Integer.parseInt(br.readLine())];
            StringTokenizer st = new StringTokenizer(br.readLine() , " ");
            for(int j = 0 ; j < fences.length ; j++){
                fences[j] = Integer.parseInt(st.nextToken());
            }
            System.out.println(maxRecycle(fences));
        }

    }
}
