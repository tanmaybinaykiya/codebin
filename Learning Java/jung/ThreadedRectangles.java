package jung;

import java.awt.*;
import java.awt.event.*;

public class ThreadedRectangles extends Frame implements Runnable 
{
	Thread thr;
	Point p_start,p_end;
	int i;
	public ThreadedRectangles() 
	{
		setSize(500,500);
		
		thr.start();
		
		
		
		
		setVisible(true);
	}
	public void paint(Graphics g) 
	{
		g.setColor(Color.black);
		if(i==2)
		{
				
		}
	}
	class Mouseaction extends MouseAdapter 
	{
		public void mousePressed(MouseEvent e) 
		{
			p_start=e.getPoint();
		}
		
		
		public void mouseReleased(MouseEvent e) 
		{
		}
	}
	public void run() 
	{
		repaint();
	}
	public static void main(String[] args) 
	{
		new ThreadedRectangles();
	}
}
