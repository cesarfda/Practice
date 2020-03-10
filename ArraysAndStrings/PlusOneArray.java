package com.company;

public class PlusOneArray {
    public int[] plusOne(int[] digits) {

        if(digits[digits.length - 1] != 9)
            digits[digits.length - 1] += 1;
        else{
            digits[digits.length - 1] = 0;
            if(digits.length - 2 >= 0)
                digits[digits.length - 2] += 1;
            else
                digits[0] = 1;
        }
        return digits;

    }
}
