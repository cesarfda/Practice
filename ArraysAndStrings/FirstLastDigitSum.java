package com.company;

public class FirstLastDigitSum {

    public static int sumFirstAndLastDigit(int number){
        if (number < 0) // Handle negative inputs
        return -1;

        int sum = 0; // Variable where the sum will be stored.
        //int originalNumber = number; //Store original number

        if (number < 10)// Handles 1 digit numbers
           return (number * 2);

       // int digitCounter = 0; //Variable to count digits.
       sum += number % 10; // Extract the last digit
        while(number > 0){
             if(number < 10)
                sum += number;
            number = number / 10;
        }
        return sum;}
}
