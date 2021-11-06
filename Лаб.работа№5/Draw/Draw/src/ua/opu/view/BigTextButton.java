package ua.opu.view;

import javax.swing.*;
import java.awt.*;


// Class with bigger default font size
public class BigTextButton extends JButton
{

    public BigTextButton(String text)
    {
        super(text);
        this.setFont(new Font("Arial", Font.PLAIN, 22));
    }

}
