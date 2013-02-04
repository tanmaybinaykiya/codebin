package Calculator;
import java.awt.*;
import java.awt.event.*;
public class Calculator extends Frame implements ActionListener,KeyListener
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	Panel p[]=new Panel[5];
	Scrollbar scroll1;
	ScrollPane scrlpan;
	TextField textbox; 
	Button[] no=new Button[10];
	Label lab; 
	Button equals,add,multiply,subtract,divide,AC,backspace,decimal;
	double prev=0,curr=0,ctr=0,dec_ctr=0,decc=0;
	
	public Calculator()
	{
		scrlpan=new ScrollPane();
		scroll1=new Scrollbar();
		
		setSize(500,500);
		setLayout(new BorderLayout());
		for(int i=0;i<5;i++ )
			p[i]= new Panel();
		
		add(scroll1,"East");
		add(scrlpan);
		textbox = new TextField();
		add(textbox,"North");
//-----------------------------------p[0]------------------
		p[0].setLayout(new GridLayout( 4,3));
		
	/*	lab = new Label("Label");
		p[0].add(lab);
		
		AC =new Button("AC");
		AC.addActionListener(this);
		p[0].add(AC);
		
		backspace =new Button("<--");
		backspace.addActionListener(this);
		p[0].add(backspace);                    */
		
		for(int i=1;i<10;i++)
		{
			no[i]=new Button(""+i);
			no[i].addActionListener(this);
			p[0].add(no[i]);
		}
		
		decimal=new Button(" . ");
		decimal.addActionListener(this);
		p[0].add(decimal);
		
		no[0]=new Button("0");
		no[0].addActionListener(this);
		p[0].add(no[0]);
		
		equals =new Button("=");
		equals.addActionListener(this);
		p[0].add(equals);
//---------------------------------------p0 ends		
//---------------------------------------p1 starts		
		p[1].setLayout(new GridLayout(4,1));
	
		multiply =new Button("x");
		multiply.addActionListener(this);
		p[1].add(multiply);
		
		divide =new Button("/");
		divide.addActionListener(this);
		p[1].add(divide);
		
		add =new Button("+");
		add.addActionListener(this);
		p[1].add(add);
		
		subtract =new Button("-");
		subtract.addActionListener(this);
		p[1].add(subtract);
//--------------------------------------------------p[1]ends
//--------------------------------------------------p[2]starts
	
		p[2].add(p[0]);
		p[2].add(p[1]);
//-------------------------------------------------p[2]ends
//--------------------------------------------------p[3]starts		
	
		
		AC =new Button("AC");
		AC.addActionListener(this);
		p[3].add(AC);
		
		backspace =new Button("<--");
		backspace.addActionListener(this);
		p[3].add(backspace);   
//------------------------------------------------p3 ends		
		p[4].setLayout(new BorderLayout());
		p[4].add(p[3],"North");
		p[4].add(p[2]);
		add(p[4]);
		
		addWindowListener(new Windows());
		setVisible(true);
	}
	class Windows extends WindowAdapter
	{
		public void windowClosing(WindowEvent arg0) 
	{
		System.exit(0);
		
	}
	}
	
	public void actionPerformed(ActionEvent e) 
	{
		if(e.getActionCommand()==("x"))
		{
			prev=curr;
			ctr=1;
			curr=0;
			textbox.setText(""+curr);
			
		}
		else if(e.getActionCommand()==("/"))
		{
			prev=curr;
			ctr=2;
			curr=0;
			textbox.setText(""+curr);
			
		}else if(e.getActionCommand()==("AC"))
		{
			prev=curr=0;
			ctr=0;
			textbox.setText(""+curr);
			
		}else if(e.getActionCommand()==("<--"))
		{
			curr=((curr/10)-((curr%10)/10));
			textbox.setText(""+curr);
			
		}
		else if(e.getActionCommand()==("+"))
		{
			prev=curr;
			ctr=3;
			curr=0;
			textbox.setText(""+curr);
			
		}
		else if(e.getActionCommand()==("-"))
		{
			prev=curr;
			ctr=4;
			curr=0;
			textbox.setText(""+curr);
			
		}
		else if(e.getActionCommand()==(" . "))
		{
			dec_ctr=0;
			prev=curr;
			ctr=4;
			curr=0;
			textbox.setText(""+curr);
			
		}
		else if(e.getActionCommand()==("="))
		{
			if(ctr==0)
			{
				prev=0;
			}
			else if(ctr == 1)
			{
				curr=prev*curr;
			}
			else if(ctr == 2)
			{
				curr=prev/curr;
			}
			else if(ctr == 3)
			{
				curr=prev+curr;
			}
			else if(ctr == 4)
			{
				curr=prev-curr;
			}
			textbox.setText(""+curr);
		}
		else if(e.getActionCommand()==("AC"))
		{
			curr=prev=ctr=0;
			textbox.setText(""+curr);
		}
		else 
		{
			int i=Integer.parseInt(e.getActionCommand());
					curr=curr*10+i;
					textbox.setText(""+curr);
			
		}
		
	}
	
	public void keyTyped(KeyEvent e)
	{
	
		
	}
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
}
