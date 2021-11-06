public class Task
{

    public int closeToTen(int a, int b)
    {

        // Getting absolute values of numbers
        int x = Math.abs(10-a);
        int y = Math.abs(10-b);


        // Check for 3 conditions simultaneously
        return ( x < y ) ? a : (x > y) ? b : ( 0 ) ;

    }

}