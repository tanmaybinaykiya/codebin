package jung;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.TextArea;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;



public class GUIlinesnpoints extends Frame implements MouseListener
{
	
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	Point pt;
	Point pts[]=new Point[Constants.max_points];
	lines line[]=new lines[Constants.max_lines]; 
	Point vertices[];
	int currpoints=-1,currlines=-1;
	TextArea t1;
	public GUIlinesnpoints()
	{
		setSize(500,500);
		t1 = new TextArea();
		add(t1,BorderLayout.SOUTH);
		addWindowListener(new wndowlistner());
		addMouseListener(this);
		setVisible(true);
	}
	@Override
	public void paint(Graphics g) 
	{
		
		for (int i=0; i<=currpoints; i++)
		{
			int x=(int)pts[i].getX();
			int y=(int)pts[i].getY();
			g.fillOval(x, y, 5, 5);
		}
		for (int i=0; i<=currlines; i++)
		{
				int x1=(int)line[i].getA().getX();
				int y1=(int)line[i].getA().getY();
				int x2=(int)line[i].getB().getX();
				int y2=(int)line[i].getB().getY();
			if((x1==x2)&&(y1==y2))
			{
				currlines--;
			}	
			else
			{
				g.drawLine(x1, y1, x2, y2);	
			}
		}
	}
	
	public static void main(String[] args) 
	{
		new GUIlinesnpoints();
	}
	
	class wndowlistner extends WindowAdapter
	{
		@Override
		public void windowClosing(WindowEvent e) 
		{
			dispose();
		}
	}
	@Override
	public void mouseClicked(MouseEvent e) 
	{
		currpoints++;
		pt=e.getLocationOnScreen();
		String s=t1.getText();
		String s2=( "  "+pt);
		s=s.concat(s2);
		t1.setText(s);
		pts[currpoints]=new Point();
		pts[currpoints]=pt;
		this.repaint();
	}

	@Override
	public void mousePressed(MouseEvent e) {
	currlines++;	
	t1.setText(t1.getText().concat( "  "+e.getLocationOnScreen()));
	line[currlines]=new lines();
	line[currlines].setA(e.getLocationOnScreen());
	}
	@Override
	public void mouseReleased(MouseEvent e) 
	{
		t1.setText(t1.getText().concat( "  "+e.getLocationOnScreen()));
		line[currlines].setB(e.getLocationOnScreen());	
		this.repaint();
	}
	
	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
}
class lines
{
	Point a,b;
	public lines()
	{}
	public lines(Point a,Point b)
	{
		this.a=a;
		this.b=b;
	}
	public Point getA() 
	{
		return a;
	}
	public void setA(Point a) 
	{	
		this.a = a;
	}
	public Point getB() 
	{
		return b;
	}
	public void setB(Point b) 
	{
		this.b = b;
	}
}	

