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
	private JPanel outputPanel;
	private JTextField output = new JTextField(15);
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
	private int teBetalenBedrag = 1200;
	public Parking()
	{
		
		mainPanel = new JPanel(new GridLayout(2,1));
		
		outputPanel = new JPanel(new GridLayout(1,1));
		
		buttonPanel = new JPanel(new GridLayout(1,5));
		
		//create handlers.
		buttonhandler muntInwerpen = new buttonhandler(); //voor het inwerpen van munten
		buttonhandler geefTerug = new buttonhandler(); //voor het terug geven van munten
		buttonhandler geef = new buttonhandler(); //voor het geven van het geld.
		buttonhandler kaart = new buttonhandler(); //word aangeroepen als kaart ingeworpen word.
		
		mainPanel.add(outputPanel);
		mainPanel.add(buttonPanel);
		
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
			if(button.getText().equals("0.20€")){}
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
	class muntInwerpen implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			
		}
	}
}
