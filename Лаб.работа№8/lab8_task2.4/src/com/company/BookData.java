package com.company;

import java.util.*;

public class BookData implements Comparable<BookData>
{

    public static void main(String[] args)
    {

        ArrayList<BookData> arr = new ArrayList();

        BookData book1 = new BookData("book", "author", 44, 445);
        BookData book2 = new BookData("notbook", "notauthor", 233, 762);
        BookData book3 = new BookData("magazine", "forbes", 321, 222);
        BookData book4 = new BookData("xd", "notxd", 4121, 440);

        arr.add(book1);
        arr.add(book2);
        arr.add(book3);
        arr.add(book4);

        sort(arr);
        printList(arr);

    }



    private String title;
    private String author;

    private int reviews;
    private double total;


    public double getRating() {  return total / reviews;}
    public String getTitle() {  return title;}


    public BookData(final String title, final String author, final int reviews, final double total)
    {

        this.title = title;
        this.author = author;

        this.reviews = reviews;
        this.total = total;

    }
    public BookData(){ this("","",0,0);}


    @Override
    public int compareTo(BookData obj) { return 0;}


    private static void sort(ArrayList<BookData> arr)
    {

        Collections.sort(arr,
                (obj1, obj2) ->
                {

                    int result = 0;

                    if (obj1.getRating() == obj2.getRating())
                    {

                        result = obj1.title.compareTo(obj2.title);
                        return result;

                    }

                    return obj1.getRating() > obj2.getRating() ? -1 : 1;

                });

    }

    private static void printList(ArrayList<BookData> arr)
    {

        for (int i = 0; i < arr.size(); i++)
        {
            System.out.println(arr.get(i).getTitle());
            System.out.println(arr.get(i).getRating());
        }

    }

}

