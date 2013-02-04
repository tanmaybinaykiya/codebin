package abbstract;
public class Shapes 
{

public void Area(){}
}
class Circle extends Shapes
{
	int r;
	Circle()
	{}
	Circle(int r)
	{
		this.r=r;
	}
	public void Area()
	{
		double A=3.142857*(r*r);
		System.out.println("Area of Circle is: "+A);
	}
}
class Rectangle extends Shapes
{
	int length, breadth;
	Rectangle()
	{}
	Rectangle(int length,int breadth)
	{
		this.length=length;
		this.breadth=breadth;
	}
	public void Area()
	{
		double A=(length*breadth);
		System.out.println("Area of Rectangle is: "+A);
	}
}
abstract class Triangle extends Shapes
{
	public abstract void Area(); 
}

class RightAngledTriangle
{
	int height, base;
	RightAngledTriangle()
	{
		
	}
	RightAngledTriangle(int b,int h)
	{
		this.height=h;
		this.base=b;
	}
	public void Area()
	{
		double A= (0.5*(base*height));
		System.out.println("Area of Right Angled Triangle is: "+A);
	}
}	
class EquilateralTriangle
{
	int side;
	EquilateralTriangle()
	{
		}
	EquilateralTriangle(int s)
	{
		this.side=s;
	}
	public void Area()
	{
		double A= (1.732/4*(side*side));
		System.out.println("Area of Triangle is: "+A);
	}
}	

class IsoscelesTriangle
{
	int height, base;
	IsoscelesTriangle()
	{
		
	}
	IsoscelesTriangle(int b,int h)
	{
		this.height=h;
		this.base=b;
	}
	public void Area()
	{
		double A= base*height;
		System.out.println("Area of Triangle is: "+A);
	}
}
