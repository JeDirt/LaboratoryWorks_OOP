package ua.opu;

import ua.opu.view.DrawFrame;
import javax.swing.*;

public class Main
{

    public static void main(String[] args)
    {

        // Create GUI
        SwingUtilities.invokeLater(() -> new DrawFrame("Программа Draw"));

    }

}