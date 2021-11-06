package com.company;

public class BankAccount
{

    // Constructors
    BankAccount(String name, double balance)
    {

        this.name = name;
        this.balance = balance;

        this.transactionFee = 0;
    }
    BankAccount()
     {
         this("User",0);
     }


    // Methods
    public void deposit(double amount)
    {

        // Check if amount to add is valid
        if(amount <= 0)
        {
            System.out.println("Impossible to make deposit, wrong amount!");
            return;
        }
        else
        {
            balance += amount;
            System.out.println("Operation has been done successful!");
        }

    }
    public double getBalance()
    {
        return this.balance;
    }
    public void withdraw(double amount)
    {

        // Amount to withdraw can't be negative or 0
        if(amount <= 0)
        {
            System.out.println("Impossible to finish withdraw, invalid amount!");
            return ;
        }
        else
        {

            // Check if it is possible to withdraw and stay balance positive or 0
            if(balance >= amount - transactionFee)
            {
                balance -= amount - transactionFee;
                System.out.println("Operation has been successful!");
            }
            else
            {
                System.out.println("Impossible to finish withdraw, invalid balance!");
                return;
            }

        }

    }
    public void setTransactionFee(float newTransactionFee)
    {

        if(newTransactionFee < 0 )
        {
            System.out.println("Invalid fee value!");
            return;
        }
        this.transactionFee = newTransactionFee;

    }
    public void transfer(BankAccount receiver, double amount)
    {

        if(amount < 1)
        {
            System.out.println("Can't transfer incorrect amount!");
            return ;
        }
        else
        {

            // Check if we can transfer validly
            if(this.balance >= amount + transactionFee)
            {
                this.balance -= amount + transactionFee;
                receiver.balance += amount;

                System.out.println("Transfer has been successfully done!");
            }
            else
            {
                System.out.println("Can't transfer, invalid balance!");
                return;
            }

        }

    }
    public void printAccountData()
    {

        System.out.println("Name: " + this.name);
        System.out.println("Balance: " + this.balance);
        System.out.println("Transaction fee: " + this.transactionFee);

    }


    // Variables
   private String name;
   private double balance;
   private double transactionFee;

}
