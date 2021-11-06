import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

public class Tests {
  @Test
  public void G_scoresIncreasingTest() {

    Task task = new Task();

    int[] a = new int[]{1, 3, 4};
    Assert.assertEquals("Метод scoresIncreasing(" + Arrays.toString(a) + ") должен вернуть true", true, task.scoresIncreasing(a));

    a = new int[]{1, 3, 2};
    Assert.assertEquals("Метод scoresIncreasing(" + Arrays.toString(a) + ") должен вернуть false", false, task.scoresIncreasing(a));

    a = new int[]{1, 1, 4};
    Assert.assertEquals("Метод scoresIncreasing(" + Arrays.toString(a) + ") должен вернуть true", true, task.scoresIncreasing(a));

    a = new int[]{1, 1, 2, 4, 4, 7};
    Assert.assertEquals("Метод scoresIncreasing(" + Arrays.toString(a) + ") должен вернуть true", true, task.scoresIncreasing(a));

    a = new int[]{1, 1, 2, 4, 3, 7};
    Assert.assertEquals("Метод scoresIncreasing(" + Arrays.toString(a) + ") должен вернуть false", false, task.scoresIncreasing(a));

    a = new int[]{-5, 4, 11};
    Assert.assertEquals("Метод scoresIncreasing(" + Arrays.toString(a) + ") должен вернуть true", true, task.scoresIncreasing(a));

  }
}