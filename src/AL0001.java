public class AL0001 {
    public static void rightRotate1(int[] arr, int s, int t){
        int temp = arr[t-1];
        for(int i = t; i > s; i--){
            arr[i] = arr[i-1];
        }
        arr[s] = temp;
    }

    public static void rightRotateK(int[] arr, int s, int t, int k){
        int[] tempArray = new int[arr.length];
        for(int i = s; i < t+1; i++){
            tempArray[i] = arr[i];
        }

        for(int i = s; i < t+1; i++){
            if(i+k > t){
                arr[s+(i+k-t-1)] = tempArray[i];
            }else{
                arr[i+k] = tempArray[i];
            }
        }
    }

    public static void printArray(int[] arr){
        for(int i : arr){
            System.out.println(i);
        }
    }
    public static void main(String args[]){
        int arr[] = {1,2,3,4,5,6,7};
        rightRotateK(arr,2,5,3);
        printArray(arr);
    }
}
