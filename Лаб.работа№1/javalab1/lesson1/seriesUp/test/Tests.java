import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

public class Tests {

  @Test
  public void E_seriesUpTest() {

    Task task = new Task();

    int[] a = new int[]{};
    Assert.assertArrayEquals("Метод seriesUp(0) должен вернуть " + Arrays.toString(a), a, task.seriesUp(0));

    a = new int[]{1};
    Assert.assertArrayEquals("Метод seriesUp(1) должен вернуть " + Arrays.toString(a), a, task.seriesUp(1));

    a = new int[]{1, 1, 2};
    Assert.assertArrayEquals("Метод seriesUp(2) должен вернуть " + Arrays.toString(a), a, task.seriesUp(2));

    a = new int[]{1, 1, 2, 1, 2, 3};
    Assert.assertArrayEquals("Метод seriesUp(3) должен вернуть " + Arrays.toString(a), a, task.seriesUp(3));

    a = new int[]{1, 1, 2, 1, 2, 3, 1, 2, 3, 4};
    Assert.assertArrayEquals("Метод seriesUp(4) должен вернуть " + Arrays.toString(a), a, task.seriesUp(4));

    a = new int[]{1, 1, 2, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6};
    Assert.assertArrayEquals("Метод seriesUp(6) должен вернуть " + Arrays.toString(a), a, task.seriesUp(6));
  }


}