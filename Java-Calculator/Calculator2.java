import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class Calculator2 extends JFrame
{
	private JPanel panel;
	
	char[] buttonContent = 
	{
		'1','2','3','/',
		'4','5','6','*',
		'7','8','9','-',
		'C','0','.','+',
		' ',' ',' ','=',
	};
	private JTextArea output = new JTextArea(1,15);
	ArrayList<JButton> buttons = new ArrayList();
	
	private String inputString = "";
	private int result = 0;
	private String operator = "";
	
	public Calculator2()
	{
		GridLayout mainWindow = new GridLayout(2,1);
		
		panel = new JPanel(new GridLayout(5,4));
		//create handlers.
		buttonhandler handler = new buttonhandler();
		TextFieldListener tfListener = new TextFieldListener();
		
		//add textoutput to panel.
		//panel.add(output);
		//create buttons.
		for(int i = 0;i<buttonContent.length;i++)
		{
			buttons.add(i, new JButton(buttonContent[i]+""));
		}
		//for every button add it to panel,
		//add it to actionlistener and bind it to handler.
		//if button has text " " don't show it but still place it.
		for(JButton button: buttons)
		{
			//add button to panel.
			panel.add(button);
			//apply size to all buttons.
			button.setSize(5,5);
			//if the button has no text, make it invisible.
			//and don't add it to action listener.
			if(button.getText().equals(" "))
			{
				button.setBorderPainted(false);
				button.setOpaque(false);
				button.setContentAreaFilled(false);
				button.setEnabled(false);
			}
			else
			{
				button.addActionListener(handler);
			}
		}
		//shows content on panel?
		setContentPane(panel);
		
	}
	
	public static void main(String args[])
	{
		JFrame frame = new Calculator2();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setTitle("Calc" );
		frame.setSize(210,230);
		//frame.setResizable(false);
		frame.setVisible(true);
	}
	
	class TextFieldListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
		}
	}
	
	class buttonhandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			String action = event.getActionCommand();
		}
		public void printPressed(String action)
		{
			System.out.println(action+" pressed");
			output.setText(output.getText()+" "+action);
		}
	}
	/*
	class Calculate
	{
		public double calculate(String operator, double value)
		{
			case 
		}
		public double add(double value1, double value2)
		{
			
		}
		public double subtract(double value1, double value2)
		{
			
		}
		public double divide(double value1, double value2)
		{
			
		}
		public double multiply(double value1, double value2)
		{
			
		}
	}*/
}
