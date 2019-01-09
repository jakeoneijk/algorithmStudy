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
        if(n == 2){
            return printTree3(tree);
        }else{
            return treeRecursive(printTree3(tree),n/2);
        }
    }

    public static void main(String args[]){
        String[] starTree = {"  *  "," * * ","*****"};
        double input = new Scanner(System.in).nextInt();
        input = input/3;

        String[] aa = treeRecursive(starTree,(int)input);

        for (int i = 0 ; i < aa.length ; i++){
            System.out.println(aa[i]);
        }

    }
}
