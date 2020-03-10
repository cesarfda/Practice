package com.company;

import java.util.Scanner;

public class ReverseString {

    public static void reverseStringBuiltIn() {

        System.out.println("Enter string to reverse:");
        Scanner read = new Scanner(System.in);
        String str = read.nextLine();

        StringBuilder sb = new StringBuilder(str);

        System.out.println("Reversed string is:");
        System.out.println(sb.reverse().toString());
    }
}
       /* public static String bestReverse(String str){
        if(str == null || str.isEmpty())
            return str;

        char[] characters =  str.toCharArray();
        int i = 0;
        int j = characters.length -1;
        while(i  < j){
            swap(characters, i , j);
            i++;
            j--;
        }

        return new String (characters);
        }
        public static void swap (char [] str, int i , int j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
        public static void reverseStringSimple(){
        System.out.println("Enter string to reverse:");
        Scanner read = new Scanner(System.in);
        String str = read.nextLine();
        String reverse = "";
        for(int i = str.length() -1 ; i >= 0; i--)
        {
            reverse = reverse + str.charAt(i);
        }
        System.out.println("Reversed string is:");
        System.out.println(reverse);
    }

}*/
