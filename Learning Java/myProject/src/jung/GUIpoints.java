package jung;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class GUIpoints extends Frame implements MouseListener
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	static int max_points=15; 
	Point pt;
	Point pts[]=new Point[max_points];
	
	int currpoints=-1;
	public GUIpoints()
	{
		setSize(500,500);
		addWindowListener(new wndowlistner());
		addMouseListener( new MouseAdapter() {
			public void mouseClicked(MouseEvent e) 
			{
				currpoints++;
				pt=e.getLocationOnScreen();
				System.out.println(""+pt);
				pts[currpoints]=new Point();
				pts[currpoints]=pt;
				repaint();
			}

		});
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
	}
	
	public static void main(String[] args) 
	{
	new GUIpoints();
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
		System.out.println(""+pt);
		pts[currpoints]=new Point();
		pts[currpoints]=pt;
		this.repaint();
	}

	@Override
	public void mousePressed(MouseEvent e) {
		
		// TODO Auto-generated method stub
		
	}
	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
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