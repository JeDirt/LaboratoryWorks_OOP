import java.util.Arrays;

public class Task
{

    public int[] biggestArray(int[] a, int[] b)
    {

        // If sum of *a* > sum of *b* - return *a*
        return (Arrays.stream(a).sum() > Arrays.stream(b).sum()) ? a : b;

    }

}