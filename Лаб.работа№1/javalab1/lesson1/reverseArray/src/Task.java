public class Task
{

    public int[] reverseArray(int[] array)
    {

        for (int i = 0; i < array.length/2; i++)
        {

            // Swap
            int temp = array[i];
            array[i] = array[array.length-i-1];
            array[array.length-i-1] = temp;

        }

        return array;

    }

}