package com.company;
import java.util.Scanner;


public class Main
{

    public static void main(String[] args)
    {

        //startTimeSpanInteraction();
        //startBankAccountInteraction();
        //startStudentInteraction();

    }

    // These methods are created only for showing out the functionality of classes
    // don't mind it dramatically
    public static TimeSpan createTimeSpan()
    {

        Scanner in = new Scanner(System.in);

        System.out.println("Enter hours: ");
        int hours = in.nextInt();

        System.out.println("Enter minutes: ");
        int minutes = in.nextInt();

        return new TimeSpan(hours,minutes);

    }

    public static void startTimeSpanInteraction()
    {

        Scanner in = new Scanner(System.in);
        TimeSpan timeSpan = createTimeSpan();

        do
        {

            System.out.println("Choose the action");
            System.out.println("    1. getHours()");
            System.out.println("    2. getMinutes");
            System.out.println("    3. add(int hours, int minutes)");
            System.out.println("    4. addTimeSpan(@NotNull TimeSpan otherTime)");
            System.out.println("    5. getTotalHours()");
            System.out.println("    6. getTotalMinutes()");
            System.out.println("    7. subtract()");
            System.out.println("    8. scale()");
            System.out.println("    9. EXIT");


            int chosenAction;
            chosenAction = in.nextInt();

            // Input index until its successful
            while(chosenAction > 9 || chosenAction < 1) { chosenAction = in.nextInt();}

            switch (chosenAction)
            {

                case 1:
                {

                    timeSpan.printCurrentDate();
                    System.out.println(timeSpan.getHours());

                    break;

                }
                case 2:
                {

                    timeSpan.printCurrentDate();
                    System.out.println(timeSpan.getMinutes());

                    break;

                }
                case 3:
                {

                    timeSpan.printCurrentDate();

                    System.out.println("Enter hours/minutes: ");
                    timeSpan.add(in.nextInt(),in.nextInt());

                    // Print date after adding
                    timeSpan.printCurrentDate();

                    break;

                }
                case 4:
                {

                    TimeSpan localTimeSpan = createTimeSpan();

                    timeSpan.printCurrentDate();
                    localTimeSpan.printCurrentDate();

                    timeSpan.addTimeSpan(localTimeSpan);

                    System.out.println("Result:");
                    timeSpan.printCurrentDate();

                    break;

                }
                case 5:
                {

                    timeSpan.printCurrentDate();
                    System.out.println(timeSpan.getTotalHours());

                    break;

                }
                case 6:
                {

                    timeSpan.printCurrentDate();
                    System.out.println(timeSpan.getTotalMinutes());

                    break;

                }
                case 7:
                {

                    TimeSpan localTimeSpan = createTimeSpan();

                    timeSpan.printCurrentDate();
                    localTimeSpan.printCurrentDate();

                    timeSpan.subtract(localTimeSpan);

                    System.out.println("Result:");
                    timeSpan.printCurrentDate();

                    break;

                }
                case 8:
                {

                    timeSpan.printCurrentDate();

                    System.out.println("Input scaler:");
                    timeSpan.scale(in.nextInt());

                    timeSpan.printCurrentDate();

                    break;

                }
                case 9:
                {
                    return;
                }

            }


        }while(true);

    }
    public static void startBankAccountInteraction()
    {

        Scanner in = new Scanner(System.in);

        System.out.println("Enter name, balance:");
        BankAccount bankAccount = new BankAccount(in.next(),in.nextFloat());

        do
        {

            System.out.println("Choose the action");
            System.out.println("    1. deposit(double amount)");
            System.out.println("    2. getBalance()");
            System.out.println("    3. withdraw(double amount)");
            System.out.println("    4. setTransactionFee(float newTransactionFee)");
            System.out.println("    5. transfer(BankAccount receiver, double amount)");
            System.out.println("    6. printAccountData()");
            System.out.println("    7. EXIT");


            int chosenAction;
            chosenAction = in.nextInt();

            // Input index until its successful
            while (chosenAction > 7 || chosenAction < 1)
            {
                chosenAction = in.nextInt();
            }

            switch (chosenAction)
            {

                case 1:
                {

                    System.out.println("Enter deposit:");
                    bankAccount.deposit(in.nextFloat());

                    bankAccount.printAccountData();

                    break;

                }
                case 2:
                {

                    System.out.println("Current balance: "+bankAccount.getBalance());
                    break;

                }
                case 3:
                {

                    bankAccount.withdraw(in.nextFloat());
                    bankAccount.printAccountData();

                    break;

                }
                case 4:
                {

                    System.out.println("Enter new transaction fee:");
                    bankAccount.setTransactionFee(in.nextFloat());

                    bankAccount.printAccountData();
                    break;

                }
                case 5:
                {

                    System.out.println("Enter amount to transfer:");
                    bankAccount.transfer(new BankAccount(),in.nextFloat());

                    break;

                }
                case 6:
                {

                    bankAccount.printAccountData();
                    break;

                }
                case 7:
                {
                    return;
                }

            }

        }while(true);

    }
    public static void startStudentInteraction()
    {

        Scanner in = new Scanner(System.in);

        System.out.println("Enter name, year:");
        Student student = new Student(in.next(),in.nextInt());

        do
        {

            System.out.println("Choose the action");
            System.out.println("    1. addCourse(String discipline)");
            System.out.println("    2. dropAll()");
            System.out.println("    3. getCourseCount()");
            System.out.println("    4. getName()");
            System.out.println("    5. getTuition()");
            System.out.println("    6. getYear()");
            System.out.println("    7. printStudentInfo()");
            System.out.println("    8. EXIT");


            int chosenAction;
            chosenAction = in.nextInt();

            // Input index until its successful
            while (chosenAction > 8 || chosenAction < 1)
            {
                chosenAction = in.nextInt();
            }

            switch (chosenAction)
            {

                case 1:
                {

                    System.out.println("Enter new course:");
                    student.addCourse(in.next());

                    student.printStudentInfo();

                    break;

                }
                case 2:
                {

                    student.dropAll();
                    System.out.println("Cleared all courses...");

                    break;

                }
                case 3:
                {

                    System.out.println("Student has " + student.getCourseCount() + " courses");

                    break;

                }
                case 4:
                {

                    System.out.println("Student's name is " + student.getName());
                    break;

                }
                case 5:
                {

                    System.out.println("Current tuition is " + student.getTuition());
                    break;

                }
                case 6:
                {

                    System.out.println("Student is on " + student.getYear() + " year");
                    break;

                }
                case 7:
                {
                    student.printStudentInfo();
                    break;
                }
                case 8:
                {
                    return;
                }

            }

        }while(true);

    }



}
