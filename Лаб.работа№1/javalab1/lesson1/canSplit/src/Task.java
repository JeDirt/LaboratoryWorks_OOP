public class Task
{

    public boolean canSplit(int[] a)
    {

        // Trying to split array in every point and check if valid condition
        for(int i = 0; i < a.length; i++)
        {

            // Every split we count sums of left and right parts
            int LeftPartSum = 0;
            for (int j = 0; j < i; j++)
            {
                LeftPartSum += a[j];
            }


            int RightPartSum = 0;
            for (int j = i; j < a.length; j++)
            {
                RightPartSum += a[j];
            }


            // If true - we split successfully
            if(LeftPartSum == RightPartSum){return true;}

        }

        return false;

    }

}
