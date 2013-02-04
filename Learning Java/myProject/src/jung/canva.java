package jung;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dialog;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Label;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class canva extends Frame implements Runnable,MouseListener
{
/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
Canvas cv;
Thread thr;
Point pts[]=new Point[15];
Point p;
int ptctr=-1;
double x,y;

public canva (String s)
	{
		super(s);
		for(int i=1;i<15;i++)
		{
			pts[i]=new Point();
		}
		setSize(500,500);
		cv=new Canvas();
		thr=new Thread(this,"Thread");
		add(cv, BorderLayout.SOUTH);
		addWindowListener(new WindowAdapter()
			{
				public void windowClosing(WindowEvent e)
				{
				System.exit(0);
				}
			}
		);
		addMouseListener(this);
		setVisible(true);
	}

		public void mouseClicked(MouseEvent e) 
			{
				if(ptctr<15)
				{
					ptctr++;
					p=e.getLocationOnScreen();
					System.out.println(""+p);
					pts[(ptctr)]=p;
					thr.start();
				}
				else
				{
					
					new dialogbox(this, true);
				}
			}

	class dialogbox extends Dialog 
	{
		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		Label l1;
		Button ext;
		public dialogbox(Frame parent, boolean modal )
		{
			super(parent,modal);
			l1=new Label("15 points have been clicked");
			ext=new Button("Exit");
			add (l1);
			ext.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					System.exit(0);
					
				}
			});
			add(ext);
			
		}
	}


@Override
	public void paint(Graphics g) 
	{
	
		g.setColor(Color.DARK_GRAY );
		
		for(int j=0; j<=ptctr; j++)
		{
			x=pts[j].getX();
			y=pts[j].getY();
			g.fillOval((int)x,(int)y,7,7);
		}
	}
	
	public void run()
	{
		while (true)
		{
			
			this.repaint(100);
			try 
			{
				Thread.sleep(500,50);
			} 
			catch (InterruptedException e) 
			{
				System.out.println("INTERRUPTED EXCEPTION");
				e.printStackTrace();
			}
		}
	}
	public static void main(String a[])
		{
			new canva("Canvas");
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
