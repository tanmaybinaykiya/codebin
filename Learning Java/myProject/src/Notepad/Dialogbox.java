package Notepad;
import java.awt.Button;
import java.awt.Dialog;
import java.awt.Label;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

class Dialogbox extends Dialog implements ActionListener
	{
		private static final long serialVersionUID = 1L;
		Label l1;
		Button b1,b2;
		
		public Dialogbox(NotepadLooks parent,String title, boolean modal,int a, int b) 
		{
			super(parent,title,modal);
			setSize(a,b);
			NotepadLooks n1=parent;
			l1=new Label();
			
			b1=new Button("OK");
			b1.addActionListener(new Actions(n1));
			addWindowListener(new WindowAd());
			setVisible(true);
		}
		
		public void actionPerformed(ActionEvent e) 
		{
			
		}
		class WindowAd extends WindowAdapter
		{
			public void windowClosing(WindowEvent e) 
			{
				dispose();	
			}
		}
	}