package ua.opu.model;

import java.awt.*;
import java.awt.geom.Rectangle2D;
import java.awt.geom.RoundRectangle2D;

public class RoundedRectangle extends DrawShape
{

    public RoundedRectangle() {}

    public RoundedRectangle(Point startPoint, Point endPoint) {super(startPoint, endPoint);}

    @Override
    public Shape getShape(Point startPoint, Point endPoint)
    {

        return new RoundRectangle2D.Double(Math.min(startPoint.getX(),
                                           endPoint.getX()),
                                           Math.min(startPoint.getY(),
                                           endPoint.getY()),
                                           Math.abs(startPoint.getX() - endPoint.getX()),
                                           Math.abs(startPoint.getY() - endPoint.getY()), 55.0, 55.0);

    }

}
