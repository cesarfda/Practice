package com.company;

public class LastTest {
    public static int fib(int number){
        int fib [] = new int[number+1];
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= number; i++)
            fib[i] = fib[i-1] + fib[i-2];
        return fib[number];
    }
    public static String reverse (String str){
        if(str.isEmpty() || str == null)
            return str;
        char []reversed = str.toCharArray();
        int i = 0;
        int j = reversed.length - 1;
        while(i < j){
            char temp = reversed[i];
            reversed[i] = reversed[j];
            reversed[j] = temp;
            i++;
            j--;
        }
        return new String(reversed);
    }
}
