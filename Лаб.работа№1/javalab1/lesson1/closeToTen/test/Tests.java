import org.junit.Assert;
import org.junit.Test;

public class Tests {

  @Test
  public void B_closeToTenTest() {

    Task task = new Task();

    Assert.assertEquals("Метод closeToTen(8, 13) должен вернуть 8", 8, task.closeToTen(8, 13));
    Assert.assertEquals("Метод closeToTen(13, 8) должен вернуть 8", 8, task.closeToTen(13, 8));
    Assert.assertEquals("Метод closeToTen(7, 13) должен вернуть 0", 0, task.closeToTen(7, 13));
    Assert.assertEquals("Метод closeToTen(13, 7) должен вернуть 0", 0, task.closeToTen(13, 7));
    Assert.assertEquals("Метод closeToTen(10, 12) должен вернуть 10", 10, task.closeToTen(10, 12));
    Assert.assertEquals("Метод closeToTen(11, 10) должен вернуть 10", 10, task.closeToTen(11, 10));
    Assert.assertEquals("Метод closeToTen(0, 20) должен вернуть 0", 0, task.closeToTen(0, 20));
    Assert.assertEquals("Метод closeToTen(10, 10) должен вернуть 0", 0, task.closeToTen(10, 10));
  }

}