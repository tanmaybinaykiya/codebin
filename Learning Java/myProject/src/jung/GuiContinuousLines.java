package jung;
import java.awt.*;
import java.awt.event.*;

public class GuiContinuousLines extends Frame implements MouseListener
{
	private static final long serialVersionUID = 1L;
	static int max_points=500;
	Point pt;
	Point pts[]=new Point[max_points];
	int currpoints=-1,done=-1;
	public GuiContinuousLines()
	{
		setSize(500,500);
		addWindowListener(new wndowlistner());
		addMouseListener(this);
		setVisible(true);
	}
	public void paint(Graphics g) 
	{
		if (currpoints!=-1) 
		{
			g.fillOval((int) pts[0].getX(), (int) pts[0].getY(), 3, 3);
			for (int i = 0; i < currpoints; i++) {
				int x1 = (int) pts[i].getX();
				int y1 = (int) pts[i].getY();
				int x2 = (int) pts[(i + 1)].getX();
				int y2 = (int) pts[(i + 1)].getY();
				g.drawLine(x1, y1, x2, y2);
				g.fillOval(x2, y2, 3, 3);
				if (check_Polygon(pts)) {
					int xi[] = new int[currpoints], yi[] = new int[currpoints], zi = 0;
					for (i = 0; i < currpoints; i++) {
						xi[i] = (int) pts[i].getX();
						yi[i] = (int) pts[i].getY();
						zi++;
					}
					System.out.println("POLYGON");
					g.setColor(Color.GREEN);
					g.fillPolygon(xi, yi, zi);
					done = 1;
					g.setColor(Color.black);
					g.drawString("POLYGON CREATED", 50, 50);

				}
			}
		}
	}
	public static void main(String[] args) 
	{
	new GuiContinuousLines();
	}
	class wndowlistner extends WindowAdapter
	{
		@Override
		public void windowClosing(WindowEvent e) 
		{
			dispose();
		}
	}
	public void mouseClicked(MouseEvent e) 
	{
		if (done==-1)
		{	
			currpoints++;
			pt=e.getLocationOnScreen();
			System.out.println(""+pt);
			pts[currpoints]=new Point();
			pts[currpoints]=pt;
			this.repaint();
		}
	}
	public boolean check_Polygon(Point s[])
	{ 
		if(s[0].equals(s[currpoints]))
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	public boolean checkIntersection(Point a,Point b,Point c,Point d)
	{
			double x1,x2,x3,x4,y1,y2,y3,y4,x,B,C,D;
			x1=a.getX();
			x2=b.getX();
			x3=c.getX();
			x4=d.getX();
			y1=a.getY();
			y2=b.getY();
			y3=c.getY();
			y4=d.getY();
			B=(x2-x1)*(y4-y3);
			C=(y2-y1)*(x4-x3);
			D=(y3-y1)*(x2-x1)*(x4-x3);
			x=((B*x3)-(C*x1) - D)/(B-C);
			if ((((x1<=x)&&(x<=x2))||((x1>=x)&&(x>=x2)))&&(((x3<=x)&&(x<=x4))||((x3>=x)&&(x>=x4))))
				return true;
			else
				return false;
	}
	public void mousePressed(MouseEvent e) {}
	public void mouseReleased(MouseEvent e) {}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
}