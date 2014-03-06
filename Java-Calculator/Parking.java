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
		invoerPanel.add(output);
		
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
		}
	}
	//handler voor buttons. maar 5 buttons.
	class buttonhandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			String action = event.getActionCommand();
			switch(action)
			{
				case "a":
				break;
				default:
				printPressed(action);
				break;
			}
		}
		public void printPressed(String action)
		{
			System.out.println(action+" pressed");
		}
	}
}
