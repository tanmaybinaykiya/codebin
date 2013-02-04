package Notepad;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class NotepadLooks extends JFrame implements ActionListener
{
	private static final long serialVersionUID = 1L;
	JTextArea Text = new JTextArea("Start Typing Here...."); 
	
	JMenuBar bar = new JMenuBar();
	JMenu File =new JMenu("File");
	JMenu Edit =new JMenu("Edit");
	JMenu Format =new JMenu("Format");
	JMenu View =new JMenu("View");
	JMenu Help =new JMenu("Help");
	JLabel statusBar =new JLabel("Status..."); 
	JMenuItem Items[]=new JMenuItem[21];
	Label l=new Label("Status");
	JCheckBoxMenuItem status;
	String filename,filepath;
	Dialogbox dial;
	
	public NotepadLooks()
	{
		setTitle("T Notepad");
		setSize(1024, 700);
		setLayout(new BorderLayout());
		Items[0]=new JMenuItem("New") ; 
		Items[1]=new JMenuItem ("Open") ; 
		Items[2]=new JMenuItem ("Save") ; 
		Items[3]=new JMenuItem ("Save As") ; 
		Items[4]=new JMenuItem ("Print") ; 
		Items[5]=new JMenuItem ("Print Setup") ; 
		Items[6]=new JMenuItem ("Exit") ; 

		for (int i=0 ;i<7;i++)
		{
			Items[i].addActionListener(new Actions(this));
			File.add(Items[i]);
			if((i==3)||(i==5))
				File.addSeparator();
		}
		bar.add(File);
		
		Items[7]=new JMenuItem ("Undo") ; 
		Items[8]=new JMenuItem ("Cut") ; 
		Items[9]=new JMenuItem ("Copy") ; 
		Items[10]=new JMenuItem ("Paste") ; 
		Items[11]=new JMenuItem ("Find") ; 
		Items[12]=new JMenuItem ("Find Next") ; 
		Items[13]=new JMenuItem ("Replace") ; 
		Items[14]=new JMenuItem ("Go To") ; 
		Items[15]=new JMenuItem ("Select All") ; 
		Items[16]=new JMenuItem (" Date / Time ") ; 
		for (int i=7 ;i<17;i++)
		{
			Items[i].addActionListener(new Actions(this));
			Edit.add(Items[i]);
			if((i==7)||(i==11)||(i==15))
				Edit.addSeparator();
		}
		bar.add(Edit);
		
		
		Items[17]=new JMenuItem ("Word Wrap") ;
		Items[17].addActionListener(new Actions(this));
		Items[18]=new JMenuItem ("Font") ;
		Items[18].addActionListener(new Actions(this));
		Format.add(Items[17]);
		Format.add(Items[18]);
		bar.add(Format);
		
		status=new JCheckBoxMenuItem("Status Bar");
		status.addItemListener(new Actions(this));	
		
		View.add(status);
		bar.add(View);
		
		Items[19]=new JMenuItem ("View Help") ;
		Items[19].addActionListener(new Actions(this));
		Items[20]=new JMenuItem ("About Notepad") ;
		Items[20].addActionListener(new Actions(this));
		Help.add(Items[19]);
		Help.addSeparator();
		Help.add(Items[20]);
		bar.add(Help);
		
		setJMenuBar(bar);
		add(Text);
		setVisible(true);
		addWindowListener(new WindowAd());
		
	}	
	class WindowAd extends WindowAdapter
	{
		public void windowClosing(WindowEvent arg0) 
		{
			System.exit(0);
			
		}
	}
	@Override
	public void actionPerformed(ActionEvent e) 
	{
		// TODO Auto-generated method stub
		
	}
	
}
