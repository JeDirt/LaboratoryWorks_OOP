package com.company;

import org.jetbrains.annotations.NotNull;

import java.time.Year;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;


public class TimeSpan
{

    // Constructors
    TimeSpan(int hours, int minutes)
    {

        // If any wrong input, just zero it out as default value
        if(hours < 0 || minutes < 0)
        {
            System.out.println("Time has been zeroed out cause of invalid input!\nKeep mind next time!");
            hours = minutes = 0;
        }


        // Set current day values as date and given hours/minutes
        currentTime = new Date
                (
                        Year.now().getValue(),
                        Calendar.getInstance().get(Calendar.MONTH),
                        Calendar.getInstance().get(Calendar.DATE),
                        hours,
                        minutes
                );

    }
    TimeSpan()
    {

        // Default constructor as midnight
        this(0, 0);

    }


    // Methods
    public int getHours()
    {
        return this.currentTime.getHours();
    }
    public int getMinutes()
    {
        return this.currentTime.getMinutes();
    }


    public void add(int hours, int minutes)
    {

        // Check if input values are valid to add
        if(!isValidInput(hours,minutes))
        {

            System.out.println("Invalid values input!");
            return;

        }


        // Set new time
        this.currentTime.setHours(currentTime.getHours() + hours);
        this.currentTime.setMinutes(currentTime.getMinutes() + minutes);

    }
    public void addTimeSpan(@NotNull TimeSpan otherTime)
    {

        // Set current object's time as sum of given object's parameters with current
        this.currentTime.setHours(this.getHours() + otherTime.getHours());
        this.currentTime.setMinutes(this.getMinutes() + otherTime.getMinutes());

    }
    public void subtract(@NotNull TimeSpan otherTime)
    {

        // Set current object's time as difference of given object's parameters with current
        this.currentTime.setHours(this.getHours() - otherTime.getHours());
        this.currentTime.setMinutes(this.getMinutes() - otherTime.getMinutes());

    }
    public void scale(int factor)
    {

        if(factor < 1)
        {
            System.out.println("You've entered negative factor, its set to 1 for the save!");
            factor = 1 ;
        }

        this.currentTime.setHours(this.getHours() * factor);
        this.currentTime.setMinutes(this.getMinutes() * factor);

    }
    public float getTotalHours()
    {
        return (float) this.currentTime.getHours() + (float) this.currentTime.getMinutes() / 60;
    }
    public int getTotalMinutes()
    {
        return this.currentTime.getHours()*60 + this.currentTime.getMinutes();
    }


    public void printCurrentDate()
    {
        System.out.println(this.currentTime);
    }
    private boolean isValidInput(int hours,int minutes)
    {

        // True only when hours/minutes > 0
        return !(hours < 0 || minutes < 0);

    }


    // Variables
    private Date currentTime;

}
