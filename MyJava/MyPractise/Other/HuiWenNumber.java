import java.util.Scanner;

public class HuiWenNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String strValue = sc.nextLine();
        int value = Integer.parseInt(strValue);
        int[] values = Number2Array(value);
        int times = 0;
        StringBuilder strAnswer = new StringBuilder(Integer.toString(value));
        boolean flag = values[0] != values[values.length - 1];
        while (flag) {
            times++;
            strAnswer.append("--->");
            int v = Array2Number(values);
            for (int i = 0; i < values.length / 2; i++) {
                swap(values, i);
            }
            int value1 = Array2Number(values) + v;
            strAnswer.append(value1);
            values = Number2Array(value1);

            int flags = 0;
            for (int i = 0; i < values.length / 2; i++) {
                if (values[i] == values[values.length - 1 - i]) {
                    flags++;
                }
            }
            if (flags == values.length / 2) {
                flag = false;
            }

        }
        System.out.println(times);
        System.out.println(strAnswer);
    }

    public static int[] Number2Array(int number) {
        String value = Integer.toString(number);
        char[] array = value.toCharArray();
        int[] DecimalArray = new int[value.length()];
        for (int i = 0; i < value.length(); i++) {
            DecimalArray[i] = array[i] - 48;
        }
        return DecimalArray;
    }

    //It main act on transforming Integer Array to Number
    public static int Array2Number(int[] arr) {
        int value = 0;
        for (int i = 0; i < arr.length; i++) {
            value += Math.pow(10, arr.length - 1 - i) * arr[i];
        }
        return value;
    }

    //Swap some element of arr by the index
    public static void swap(int[] arr, int index) {
        int tmp = arr[arr.length - 1 - index];
        arr[arr.length - 1 - index] = arr[index];
        arr[index] = tmp;
    }

    //It can show all the elements of the arr in order
    public static void show(int[] arr) {
        for (int j : arr) {
            System.out.print(j + " ");
        }
        System.out.println();
    }
}