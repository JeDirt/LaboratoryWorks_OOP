import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class Tests {
  private Task task;

  @Before
  public void setUp() {
    task = new Task();
  }

  @Test()
  public void A_sleepInTest() {
    String msg = "Метод sleepIn() работает некорректно, ожидаемый результат работы метода не соответствует фактическому, " +
            "внимательно прочитайте условие задания";

    assertFalse(msg, task.sleepIn(true, false));
    assertTrue(msg, task.sleepIn(false, false));
    assertTrue(msg, task.sleepIn(false, true));
    assertTrue(msg, task.sleepIn(true, true));
  }
}