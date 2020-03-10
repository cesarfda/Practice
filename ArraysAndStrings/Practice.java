package com.company;

public class Practice {
    static int getEvenDigitSum(int number){
        if (number < 0) // Handle negative inputs
            return -1;
        int sum = 0;
        do{
            int lastDigit = number % 10; //Extract last digit
            if(lastDigit % 2 == 0) //Check if last digit is Even
            sum += lastDigit; //Add even to sum
            number /=  10;
        }while(number > 0);

    return sum;}
    public static boolean hasSharedDigit(int number1, int number2){
    if(number1 < 10 || number1 >99) //2 digits number only
        return false;
    if(number2 < 10 || number2 >99)//2 digits number only
        return false;

        int lastDigit1 = number1 % 10; //Extract last digit
        int lastDigit2 = number2 %10; //Extract last digit
        int firstDigit1 = (number1 /10) % 10; //Extract first digit
        int firstDigit2 = (number2/ 10) %10; //Extract first digit

        //Compare for shared digits
        return lastDigit1 == lastDigit2 || lastDigit1 == firstDigit2 || firstDigit1 == lastDigit2 || firstDigit1 == firstDigit2;// Share digit not found.
    }
    public static boolean hasSameLastDigit(int number1, int number2, int number3){
        if(isValid(number1)&&isValid(number2)&&isValid(number3))
        {
            int lastDigit1 = number1 % 10; //Extract last digit
            int lastDigit2 = number2 % 10; //Extract last digit
            int lastDigit3 = number3 % 10; //Extract last digit

            //Compare for shared digits
            return lastDigit1 == lastDigit2 || lastDigit1 == lastDigit3 || lastDigit3 == lastDigit2;
        }
        return false;// Share digit not found.
    }
    private static boolean isValid(int number){
        //2 digits number only
        return number >= 10 && number <= 1000;
    }
    public static int getGreatestCommonDivisor(int number1, int number2){
        if (number1 < 10 || number2 <10)
            return -1;
        int gcd = 0;
        for(int i = 1; i <= number1 && i <= number2; i++)
            if (number1 % i == 0 && number2 % i == 0)
                gcd = i;
        return gcd;
    }
    public static void printFactors(int number){
        if (number <1)
            System.out.println("Invalid Value");
        for(int i = 1; i <= number; i++)
        {
            if(number % i == 0)
                System.out.println(i);
        }
    }
    public static boolean isPerfectNumber(int number){
        if (number <1)
            return false;
        int sum = 0;
        for(int i = 1; i < number; i++)
        {
            if(number % i == 0)
                sum += i;
        }
        if (sum == number)
            return true;
        return false;
    }

    public static void numberToWords(int number){
    int numberToPrint = reverse(number);
    int digitCount = getDigitCount(number);
       do{
            int lastDigit = numberToPrint % 10;
            numberToPrint /=  10;
            printNumber(lastDigit);
        }while(numberToPrint > 0);
    if(digitCount > 0){
        for(int i = 1; i <= digitCount; i++)
            printNumber(0);
    }

    }
    public static int reverse(int number){
        int reverse = 0;
        do{
            int lastDigit = number % 10; //Extract last digit
            reverse  *= 10;
            reverse += lastDigit;
            number /=  10;
        }while(number > 0);
        return reverse;
    }
    public static int getDigitCount(int number){
        if(number < 0)
            return -1;
        int count = 0;
        if(number > 10) {
            do {
                count++;
                number /= 10;
            } while (number > 0);
        }
        else
            return 1;
        return count;
    }
    public static void printNumber(int number){
        switch(number) {
            case 1:
                System.out.println("ONE");
                break;
            case 2:
                System.out.println("TWO");
                break;
            case 3:
                System.out.println("THREE");
                break;
            case 4:
                System.out.println("FOUR");
                break;
            case 5:
                System.out.println("FIVE");
                break;
            case 6:
                System.out.println("SIX");
                break;
            case 7:
                System.out.println("SEVEN");
                break;
            case 8:
                System.out.println("EIGHT");
                break;
            case 9:
                System.out.println("NINE");
                break;
            default:
                System.out.println("ZERO");
                break;
        }
    }

    public static String bestReverse(String str){
        if(str == null || str.isEmpty())
            return str;
        char [] reversedString = str.toCharArray();
        int i = 0;
        int j = reversedString.length - 1;
        while (i < j){
            char temp = reversedString[i];
            reversedString[i] = reversedString[j];
            reversedString[j] = temp;
            i++;
            j--;
        }
        return new String(reversedString);
    }




    public static void arrayReverse(int [] toBeReversed){
        int i = 0;
        int j = toBeReversed.length - 1;
        while ( i < j) {
            int temp = toBeReversed[i];
            toBeReversed[i] = toBeReversed[j];
            toBeReversed[j] = temp;
            i++;
            j--;
        }
    }


}
