package jung;

import java.awt.Point;


public class MathsCheck {

	Point a,b,c,d;
	boolean bool;
	
	public MathsCheck() 
	{
		a=new Point(5,5);
		b=new Point(4,4);
		c=new Point(5,6);
		d=new Point(6,5);
		bool=checkIntersection(a, b, c, d);
		System.out.println(""+bool);
	}
	public static void main(String[] args) 
	{
		
	new MathsCheck();

	}
	public boolean checkIntersection(Point a,Point b,Point c,Point d)
	{
			double x1,x2,x3,x4,y1,y2,y3,y4;
			x1=a.getX();
			x2=b.getX();
			x3=c.getX();
			x4=d.getX();
			y1=a.getY();
			y2=b.getY();
			y3=c.getY();
			y4=d.getY();
			
			double x,B,C,D;
			B=(x2-x1)*(y4-y3);
			C=(y2-y1)*(x4-x3);
			D=(y3-y1)*(x2-x1)*(x4-x3);
			x=((B*x3)-(C*x1) - D)/(B-C);
			
			if ((((x1<=x)&&(x<=x2))||((x1>=x)&&(x>=x2)))&&(((x3<=x)&&(x<=x4))||((x3>=x)&&(x>=x4))))
			{
				return true;
			}
			else
			{
				return false;
			}
	}
}
