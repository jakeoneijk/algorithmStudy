import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
public class baekjoon2448 {

    public static String[] printTree3(String[] tree){
        String indentation="";
        String[] result = new String[tree.length*2];
        for (int i = 0 ; i < tree[tree.length-1].length()/2+1; i++){
            indentation += " ";
        }

        for (int i = 0; i < tree.length; i++){
            result[i] = indentation+tree[i]+indentation;
            result[i+tree.length] = tree[i]+" "+tree[i];
        }

        return result;
    }

    public static String[] treeRecursive(String[] tree,int n){
        int k = n;
        String[] result = printTree3(tree);
        while(k > 2){
            result = printTree3(result);
            k = k/2;
        }
        return result;
    }

    public static void main(String args[]) throws Exception{
        String[] starTree = {"  *  "," * * ","*****"};
        double input = Double.parseDouble(new BufferedReader(new InputStreamReader(System.in)).readLine());
        input = input/3;

        String[] aa = treeRecursive(starTree,(int)input);

        for (int i = 0 ; i < aa.length ; i++){
            System.out.println(aa[i]);
        }

    }
}
