
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class FileChooserTest extends JFrame {
  private JTextField filename, dir;

  private JButton open,save;

  public FileChooserTest() {
	  
	  JPanel p = new JPanel();
		  open = new JButton("Open");
			  open.addActionListener(new OpenL());
			  p.add(open);
		
		  save = new JButton("Save"); 
			  save.addActionListener(new SaveL());
			  p.add(save);
		  
	  add(p, BorderLayout.SOUTH);
    
	  p = new JPanel();
	  
	  p.setLayout(new GridLayout(2, 1));
		  
	  	  filename = new JTextField();
		  	filename.setEditable(false);
		  	p.add(filename);
		  
		  dir= new JTextField();
		  	dir.setEditable(false);
		  	p.add(dir);
	  
	  add(p, BorderLayout.NORTH);
  }

  class OpenL implements ActionListener {
    public void actionPerformed(ActionEvent e) {
      JFileChooser c = new JFileChooser();
      // Demonstrate "Open" dialog:
      int rVal = c.showOpenDialog(FileChooserTest.this);
      if (rVal == JFileChooser.APPROVE_OPTION) {
        filename.setText(c.getSelectedFile().getName());
        dir.setText(c.getCurrentDirectory().toString());
      }
      if (rVal == JFileChooser.CANCEL_OPTION) {
        filename.setText("You pressed cancel");
        dir.setText("");
      }
    }
  }

  class SaveL implements ActionListener {
    public void actionPerformed(ActionEvent e) {
      JFileChooser c = new JFileChooser();
      // Demonstrate "Save" dialog:
      int rVal = c.showSaveDialog(FileChooserTest.this);
      if (rVal == JFileChooser.APPROVE_OPTION) {
        filename.setText(c.getSelectedFile().getName());
        dir.setText(c.getCurrentDirectory().toString());
      }
      if (rVal == JFileChooser.CANCEL_OPTION) {
        filename.setText("You pressed cancel");
        dir.setText("");
      }
    }
  }

  public static void main(String[] args) {
    run(new FileChooserTest(), 250, 110);
  }

  public static void run(JFrame frame, int width, int height) {
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(width, height);
    frame.setVisible(true);
  }
} ///:~



           
         