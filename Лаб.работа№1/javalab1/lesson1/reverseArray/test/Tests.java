import org.junit.Assert;
import org.junit.Test;

import org.junit.Assert;
import org.junit.Test;

public class Tests {

  @Test
  public void C_reverseArray() {

    Task task = new Task();

    Assert.assertArrayEquals("Метод reverseArray({1, 2, 3}) должен вернуть {3, 2 ,1}", new int[]{3, 2, 1}, task.reverseArray(new int[]{1, 2, 3}));
    Assert.assertArrayEquals("Метод reverseArray({}) должен вернуть {}", new int[]{}, task.reverseArray(new int[]{}));
    Assert.assertArrayEquals("Метод reverseArray({1}) должен вернуть {1}", new int[]{1}, task.reverseArray(new int[]{1}));
    Assert.assertArrayEquals("Метод reverseArray({1, 2, 1}) должен вернуть {1, 2 ,1}", new int[]{1, 2, 1}, task.reverseArray(new int[]{1, 2, 1}));
    Assert.assertArrayEquals("Метод reverseArray({0, 2, 3}) должен вернуть {3, 2 ,0}", new int[]{3, 2, 0}, task.reverseArray(new int[]{0, 2, 3}));
  }
}