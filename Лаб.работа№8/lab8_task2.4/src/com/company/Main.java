package com.company;

import java.util.Arrays;

public class Main
{

    public static void main(String[] args)
    {

        Printer myPrinter = new Printer();

        Integer[] intArray = {1, 2, 3};
        String[] stringArray = {"Hello", "World"};
        Double[]arr = {5.5,67.2,8.1};

        myPrinter.printArray(intArray);
        myPrinter.printArray(stringArray);
        myPrinter.printArray(arr);

    }

}

class Printer<T>
{

    void printArray(T arr)
    {
        System.out.println(Arrays.toString((Object[]) arr));
    }

}

// or

class PrinterNotGeneric
{
    <T>void printArray(T arr){System.out.println(Arrays.toString((Object[]) arr));}
}