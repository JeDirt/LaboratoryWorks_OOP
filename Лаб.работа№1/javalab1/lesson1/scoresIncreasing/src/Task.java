public class Task
{

    public boolean scoresIncreasing(int[] a)
    {

        // Flag to check every element in loop
        boolean isNextGreater = false;

        for (int i = 0; i < a.length - 1 ; i++)
        {

            if(a[i+1] >= a[i]){ isNextGreater = true;}

            /*
            If in loop one condition hasn't succeeded, stop looping,
            flag shows last condition
            */

            else{ isNextGreater = false; break;}

        }

        return isNextGreater;

    }

}