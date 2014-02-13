import java.awt.*;
import java.awt.Dimension.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class Calculator2 extends JFrame
{
	private int window_width = 210;
	private int window_height = 220;
	private JPanel buttonPanel,outputPanel,mainPanel;
	private JTextArea output = new JTextArea(1,15);
	
	char[] buttonContent = 
	{
		'1','2','3','/',
		'4','5','6','*',
		'7','8','9','-',
		'C','0','.','+',
		' ',' ',' ','=',
	};
	ArrayList<JButton> buttons = new ArrayList();
	
	private String inputString = "";
	private String operator = "";
	private double result = 0;
	private Calculate cal = new Calculate();
	
	public Calculator2()
	{
		
		buttonPanel = new JPanel(new GridLayout(5,4));
		outputPanel = new JPanel(new GridLayout(1,1));
		mainPanel = new JPanel(new GridLayout(2,1));
		
		//create handlers.
		buttonhandler handler = new buttonhandler();
		TextFieldListener tfListener = new TextFieldListener();
		
		//add buttonpanel and outputpanel to panels.
		mainPanel.add(outputPanel);
		mainPanel.add(buttonPanel);
		outputPanel.add(output);
		//set the button panel to a certain size.
		buttonPanel.setPreferredSize(new Dimension(window_width, 200));
		outputPanel.setPreferredSize(new Dimension(window_width, 20));
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
			buttonPanel.add(button);
			//apply size to all buttons.
			button.setSize(5,5);
			
			if(button.getText().equals(" "))
			{
				//if the button has no text, make it invisible.
				//and don't add it to action listener.
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
		setContentPane(mainPanel);
		
	}
	
	public static void main(String args[])
	{
		JFrame frame = new Calculator2();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setTitle("Calc" );
		frame.pack();
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
			switch(action)
			{
				case "+":
					operator = "+";
					result = Integer.parseInt(inputString);
					inputString = "";
					break;
				case "-":
					break;
				case "/":
					break;
				case "*":
					break;
				case "C":
					result = 0.0;
					break;
				case "=":
					result = cal.calculate(operator, result, Integer.parseInt(inputString));
					System.out.println("result: "+result);
					operator = "";
					inputString = "";
					break;
				default:
					inputString+=action;
					break;
					
			}
			System.out.println(inputString);
		}
		public void printPressed(String action)
		{
			System.out.println(action+" pressed");
			output.setText(output.getText()+" "+action);
		}
	}
	
	class Calculate
	{
		public double calculate(String operator, double Lvalue, double Rvalue)
		{
			switch(operator)
			{
				case "+":
					break;
				case "-":
					break;
				case "/":
					break;
				case "*":
					break;
				default:
					System.out.println("Unknow");
			};
		}
		public double add(double value1, double value2)
		{
			return 0.0;
		}
		public double subtract(double value1, double value2)
		{
			return 0.0;
		}
		public double divide(double value1, double value2)
		{
			return 0.0;
		}
		public double multiply(double value1, double value2)
		{
			return 0.0;
		}
	}
}
