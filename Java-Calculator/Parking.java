import java.awt.*;
import java.awt.Dimension.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class Parking extends JFrame
{
	private ParkeerAutomaat parkeerAutomaat = new ParkeerAutomaat();
	
	//window information
	private JPanel mainPanel,buttonPanel;
	/*
	 * twee tekst velden,
	 * een invoer veld
	 * en een prijs veld
	 * */
	private JPanel invoerPanel,outputPanel;
	private JTextArea output;
	private JTextArea input;
	/*
	 * 5 knoppen
	 * 
	 * 20cent knop
	 * euro knop
	 * terug knop
	 * geef knop
	 * kaart knop
	 * */
	
	String[] buttonContent = 
	{
		"0.20€", "1€", "Back", "Give", "Chart"
	};
	
	//contains all the buttons.
	ArrayList<JButton> buttons = new ArrayList();
	
	private boolean kaartIsIngeworpen = false;
	private double teBetalenBedrag = 12.00;
	public Parking()
	{
		JTextArea output = new JTextArea(1,15);
		JTextArea input = new JTextArea(1,15);
		
		mainPanel = new JPanel(new GridLayout(3,1));
		
		invoerPanel = new JPanel(new GridLayout(1,1));
		outputPanel = new JPanel(new GridLayout(1,1));
		
		buttonPanel = new JPanel(new GridLayout(1,5));
		
		//create handlers.
		buttonhandler handler = new buttonhandler();
		TextFieldListener tfListener = new TextFieldListener();
		
		mainPanel.add(invoerPanel);
		mainPanel.add(outputPanel);
		mainPanel.add(buttonPanel);
		
		invoerPanel.add(input);
		input.setEditable(true);//we can enter things.
		outputPanel.add(output);
		output.setEditable(false);//we can only show things.
		
		//set listeners for input and output field.
		//input.addActionListener(tfListener);
		//output.addActionListener(tfListener);
		//create buttons
		for(int i = 0;i<buttonContent.length;i++)
		{
			buttons.add(i, new JButton(buttonContent[i]));
		}
		//add all the buttons to the button panel
		for(JButton button: buttons)
		{
			//add button to panel
			buttonPanel.add(button);
			button.addActionListener(handler);
		}
		setContentPane(mainPanel);
	}
	public static void main(String args[])
	{
		int window_height = 220;
		int window_width = 420;
		
		JFrame frame = new Parking();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setTitle("Parking ");
		frame.pack();
		frame.setSize(window_width, window_height);
		frame.setVisible(true);
	}
	
	class TextFieldListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			String action = event.getActionCommand();
			printPressed(action);
		}
		public void printPressed(String action)
		{
			System.out.println(action+" pressed");
		}

	}
	//handler voor buttons. maar 5 buttons.
	class buttonhandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			/*
			 * "0.20€", "1€", "Back", "Give", "Chart"
			 * */
			String action = event.getActionCommand();
			if(action.equals("0.20€"))
			{
			}
			else if(action.equals("1€"))
			{
			}
			else if(action.equals("Back"))
			{
			}
			else if(action.equals("Give"))
			{
			}
			else if(action.equals("Chart"))
			{
				if(kaartIsIngeworpen)
				{
					kaartIsIngeworpen = false;
				}
				else
				{
					kaartIsIngeworpen = true; //kaart ingworpen
					parkeerAutomaat.setPrijs(teBetalenBedrag);//set het te betalen bedrag
					//output.setText("thing");//display what to pay.
					for(JButton button:buttons)
					{
						if(button.getText().equals("Chart"))
						{
							button.setEnabled(false);
						}
					}
				}
			}
			this.printPressed(action);
		}
		public void printPressed(String action)
		{
			System.out.println(action+" pressed");
		}
	}
}
