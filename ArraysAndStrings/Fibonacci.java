package com.company;

public class Fibonacci {
    static int fibDynamic(int number){
        int f[] = new int[number+1];// 1 Extra space to handle case 0.
        int i;
        f[0]=0;
        f[1]=1;
        for (i = 2; i<=number; i++){
            f[i]= f[i-1] + f[i-2];
        }
        return f[number];
    }

    static int fib(int n)
    {
        if (n <= 1)
            return n;
        return fib(n-1) + fib(n-2);
    }
}
