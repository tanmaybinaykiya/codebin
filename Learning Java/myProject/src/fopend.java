import java.awt.*;
import java.awt.event.*;

public class fopend extends Frame implements WindowListener, ActionListener 
{
	FileDialog fd;
	public fopend()
	{
		setSize(500,500);
		fd = new FileDialog(this, "Open");
		add(fd);
		setVisible(true);
	}
	public static void main(String[] args) 
	{
		new fopend();
	}
	
	public void windowClosing(WindowEvent e) 
	{
		dispose();
	}
	public void actionPerformed(ActionEvent e) 
	{
		
	}
	public void windowOpened(WindowEvent e) {}
	public void windowClosed(WindowEvent e) {}
	public void windowIconified(WindowEvent e) {}
	public void windowDeiconified(WindowEvent e) {}
	public void windowActivated(WindowEvent e) {}
	public void windowDeactivated(WindowEvent e) {}
}
