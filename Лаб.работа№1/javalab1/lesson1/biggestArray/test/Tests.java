import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

public class Tests {

  @Test
  public void D_biggestArrayTest() {

    Task task = new Task();

    int[] a = new int[]{};
    int[] b = new int[]{};
    Assert.assertArrayEquals("Метод biggestArray(" + Arrays.toString(a) + ", " + Arrays.toString(b) + ") должен вернуть {}", a, task.biggestArray(a, b));

    a = new int[]{1, 2, 3, 4};
    b = new int[]{1, 2, 3, 5};
    Assert.assertArrayEquals("Метод biggestArray(" + Arrays.toString(a) + ", " + Arrays.toString(b) + ") должен вернуть {1, 2, 3, 5}", b, task.biggestArray(a, b));

    a = new int[]{1, 2, 3, 5};
    b = new int[]{1, 2, 3, 5, -1};
    Assert.assertArrayEquals("Метод biggestArray(" + Arrays.toString(a) + ", " + Arrays.toString(b) + ") должен вернуть {1, 2, 3, 5}", a, task.biggestArray(a, b));
  }
}