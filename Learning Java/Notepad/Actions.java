package Notepad;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;



public class Actions implements ActionListener,ItemListener {

	NotepadLooks n1;
	String temp,fn,fp;
	int i=0;
	public Actions(NotepadLooks n1) 
	{
		this.n1=n1;
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand()=="Exit")
		{
			System.exit(0);
		}
		else if(e.getActionCommand()=="Save")
		{
			try
			{
				FileWriter fstream = new FileWriter("file.txt");
				BufferedWriter out = new BufferedWriter(fstream);
				out.write("" + n1.Text.getText()+ "");
				out.close();
			}
			catch(Exception exception)
			{
				exception.printStackTrace();
			}
		}
		else if(e.getActionCommand()=="Open")
		{
			JFileChooser filechooser = new JFileChooser();
			int rVal = filechooser.showOpenDialog(n1);
			if (rVal == JFileChooser.APPROVE_OPTION) 
			{
				n1.filename=(filechooser.getSelectedFile().getName());
				n1.filepath=(filechooser.getCurrentDirectory().toString());
			}
			try
			{
				FileInputStream fstream = new FileInputStream(n1.filepath+"\\"+n1.filename);
				BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
				String str,str2="";
				n1.Text.setText(str2);
				while (true)   
				{
					str=br.readLine();
					if(str != null)
					{
						str2="\n";
						str=str.concat(str2);
						n1.Text.append(str);
					}
					else
					{
						break;  
					}
				}
				fstream.close();
			}  
			catch(Exception exception)
			{
				exception.printStackTrace();
			}
		}
		else if(e.getActionCommand()=="View Help")
		{
			n1.dial=new Dialogbox(n1,"Help" ,true,400,200);
			n1.dial.l1.setText("This version of Notepad has been developed by Tanmay using Java in the Eclipse IDE");
			n1.dial.add(n1.dial.l1);
			n1.dial.setVisible(true);
			n1.setVisible(true);
		}
	}
	public void itemStateChanged(ItemEvent e) 
	{
		Label lab=n1.l;

		if (i==0)
		{
			System.out.println("IN IF");
			n1.add(lab,BorderLayout.SOUTH);
			lab.setVisible(true);
			n1.setVisible(true);
			i=1;
		}
		else 
		{
			System.out.println("IN ELSE");
			lab.setVisible(false);
			n1.setVisible(true);
			i=0;
		}
	}
}
