package com.company;

import java.util.Arrays;
import java.util.function.Predicate;

public class Task4<T>
{

    public static void main(String[] args) {}

    public T[] filter(T[] arr, Predicate<T> pred)
    {

        T[] result = (T[])new Object[arr.length];

        int counter = 0;

        for (T i : arr)
        {

            if (pred.test(i))
            {
                result[counter] = i;
                counter++;
            }

        }

        return Arrays.copyOfRange(result, 0, counter);

    }

}
