public class Task
{

    public int[] seriesUp(int n)
    {

        // Allocate memory for the future array
        int[] Array = new int[n*(n+1)/2];

        // External counter to set values of array by sample
        int iteratorCount = 0;

        // Stops when we reach value of @param *a*
        for (int i = 1; i <= n; ++i)
        {

            // Keeps the sample and fills an array
            for (int j = 1; j <= i; ++j)
            {
                Array[iteratorCount++] = j;
            }

        }

        return Array;

    }

}