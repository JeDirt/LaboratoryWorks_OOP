import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

public class Tests {
  @Test
  public void F_canSplitTest() {

    Task task = new Task();

    int[] a = new int[]{1};
    Assert.assertEquals("Метод canSplit(" + Arrays.toString(a) + ") должен вернуть false", false, task.canSplit(a));

    a = new int[]{10, 10};
    Assert.assertEquals("Метод canSplit(" + Arrays.toString(a) + ") должен вернуть true", true, task.canSplit(a));

    a = new int[]{1, 1, 1, 2, 1};
    Assert.assertEquals("Метод canSplit(" + Arrays.toString(a) + ") должен вернуть true", true, task.canSplit(a));

    a = new int[]{2, 1, 1, 2, 1};
    Assert.assertEquals("Метод canSplit(" + Arrays.toString(a) + ") должен вернуть false", false, task.canSplit(a));

    a = new int[]{1, 1, 1, 1, 4};
    Assert.assertEquals("Метод canSplit(" + Arrays.toString(a) + ") должен вернуть true", true, task.canSplit(a));

    a = new int[]{2, 1, 1, 1, 4};
    Assert.assertEquals("Метод canSplit(" + Arrays.toString(a) + ") должен вернуть false", false, task.canSplit(a));

    a = new int[]{2, 3, 4, 1, 2};
    Assert.assertEquals("Метод canSplit(" + Arrays.toString(a) + ") должен вернуть false", false, task.canSplit(a));

    a = new int[]{1, 2, 3, 1, 0, 2, 3};
    Assert.assertEquals("Метод canSplit(" + Arrays.toString(a) + ") должен вернуть true", true, task.canSplit(a));

    a = new int[]{1, 2, 3, 1, 0, 1, 3};
    Assert.assertEquals("Метод canSplit(" + Arrays.toString(a) + ") должен вернуть false", false, task.canSplit(a));

    a = new int[]{1, 1, 1, 2, 1};
    Assert.assertEquals("Метод canSplit(" + Arrays.toString(a) + ") должен вернуть true", true, task.canSplit(a));
  }
}