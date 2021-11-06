package com.company;

import java.util.Calendar;
import java.util.Vector;

public class Student
{

    // Constructors
    Student(String name, int year)
    {

        //  Set year to 1 by default if user missed
        if (year < 1 || year > 4) { this.year = 1; }

        this.name = name;
        this.year = year;
        this.disciplines = new Vector<String>();

    }
    Student()
    {
        this("Student", Calendar.getInstance().YEAR);
    }


    // Methods
    public void addCourse(String discipline)
    {
        this.disciplines.add(discipline);
    }
    public void dropAll()
    {
        this.disciplines.clear();
    }
    public int getCourseCount()
    {
       return this.disciplines.size();
    }
    public String getName()
    {
        return this.name;
    }
    public int getTuition()
    {
        return this.year * 1000;
    }
    public int getYear()
    {
        return this.year;
    }
    public void printStudentInfo()
    {

        System.out.println("Name: " + this.name);
        System.out.println("Year: " + this.year);
        printStudentCourses();

    }
    private void printStudentCourses()
    {

        System.out.println("Disciplines:");
        for(String el : this.disciplines)
        {
            System.out.println("    " + el);
        }

    }


    // Variables
    private String name;
    private int year;
    private Vector<String> disciplines;

}
