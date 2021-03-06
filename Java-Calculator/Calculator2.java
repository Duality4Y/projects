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
	private String allInput = "";
	private String operator = "";
	private double result = 0;
	private boolean deciamalPointUsed = false;
	private Calculate cal = new Calculate();
	
	public Calculator2()
	{
		
		buttonPanel = new JPanel(new GridLayout(5,4));
		outputPanel = new JPanel(new GridLayout(1,1));
		mainPanel = new JPanel(new GridLayout(2,1));
		
		//create handlers.
		buttonhandler handler = new buttonhandler();
		TextFieldListener tfListener = new TextFieldListener();
		//set the button panel to a certain size.
		outputPanel.setSize(window_width, window_height-20);
		//add buttonpanel and outputpanel to panels.
		mainPanel.add(outputPanel);
		mainPanel.add(buttonPanel);
		outputPanel.add(output);
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
	/*
	 * apparte handler maken voor buttons met nummers en 
	 * voor buttons met operators.
	 * de operators doen steeds het zelfde kan in 1 functie
	 * */
	class buttonhandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			String action = event.getActionCommand();
			allInput+=action;
			switch(action)
			{
				case "+":
					result = Double.parseDouble(inputString);
					operator = action;
					inputString = "";
					printAll();
					break;
				case "-":
					result = Double.parseDouble(inputString);
					operator = action;
					inputString = "";
					printAll();
					break;
				case "/":
					result = Double.parseDouble(inputString);
					operator = action;
					inputString = "";
					printAll();
					break;
				case "*":
					result = Double.parseDouble(inputString);
					operator = action;
					inputString = "";
					printAll();
					break;
				case "C":
					result = 0.0;
					inputString = "";
					operator = "";
					allInput = "";
					output.setText("");
					break;
				case "=":
					result = cal.calculate(operator, result, Double.parseDouble(inputString));
					//int length = String.valueOf(result).length();
					/*
					if( ((10)%result) != 0)
					{
						allInput += result;
					}
					else
					{
						allInput += (int)result;
					}*/
					if((int)result == result)
					{
						allInput += (int)result;
					}
					else
					{
						allInput += result;
					}
					operator = "";
					inputString = "";
					printAll();
					allInput = "";
					break;
				default:
					inputString+=action;
					printAll();
					break;
					
			}
			System.out.println(inputString);
			System.out.println(event);
		}
		public void printAll()
		{
			output.setText(allInput);
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
					return add(Lvalue,Rvalue);
				case "-":
					return subtract(Lvalue, Rvalue);
				case "/":
					return divide(Lvalue, Rvalue);
				case "*":
					return multiply(Lvalue, Rvalue);
				default:
					System.out.println("Unknow");
					return 0.0;
			}
		}
		public double add(double value1, double value2)
		{
			return value1+value2;
		}
		public double subtract(double value1, double value2)
		{
			return value1-value2;
		}
		public double divide(double value1, double value2)
		{
			return value1/value2;
		}
		public double multiply(double value1, double value2)
		{
			return value1*value2;
		}
	}
}
