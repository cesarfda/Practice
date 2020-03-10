package com.company;

public class NumberPalindrome {
        public static boolean isPalindrome(int number){
            int reverse = 0; // Variable where the number will be stored backwards.
            if (number < 0) //Handles negative inputs
                number = number * (-1);
            int originalNumber = number; //Variable where the original number is kept to compare with reverse
            do{
                int lastDigit = number % 10; //Extract last digit
                reverse  *= 10;
                reverse += lastDigit;
                number /=  10;
            }while(number > 0);

            if(originalNumber == reverse)
                return true;
            else
                return false;
        }
}

