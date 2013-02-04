package jung;

import java.awt.Point;

public class GUIpolygons {

}

class Shapes 
{
	Point vertices[]= new Point[Constants.max_vertices];
	public Point[] getVertices() 
	{
		return vertices;
	}

	public void setVertices(Point[] vertices) 
	{
		this.vertices = vertices;
	}
}