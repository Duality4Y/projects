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
		buttonhandler handler = new buttonhandler();
		TextFieldListener tfListener = new TextFieldListener();
		
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
				parkeerAutomaat.voegToeAanBetaald(20);
			}
			else if(action.equals("1€"))
			{
				parkeerAutomaat.voegToeAanBetaald(100);
			}
			else if(action.equals("Back"))
			{
				parkeerAutomaat.setBetaald(0);
			}
			else if(action.equals("Give"))
			{
				if(parkeerAutomaat.voldoendeBetaald() && kaartIsIngeworpen == true)
				{
					kaartIsIngeworpen = false;
					for(JButton button:buttons)
					{
						if(button.getText().equals("Chart"))
						{
							button.setEnabled(true);
						}
					}
				}
			}
			else if(action.equals("Chart"))
			{
				if(kaartIsIngeworpen == false)
				{
					kaartIsIngeworpen = true; //kaart ingworpen
					parkeerAutomaat.setPrijs(teBetalenBedrag);//set het te betalen bedrag
					parkeerAutomaat.setBetaald(0); //altijd vanaf nul beginnen met betalen.
					for(JButton button:buttons)
					{
						if(button.getText().equals("Chart"))
						{
							button.setEnabled(false); //disable de button.
						}
					}
				}
			}
			output.setText("te betalen: "+parkeerAutomaat.getPrijs()+" betaald: "+parkeerAutomaat.getBetaald());
			this.printPressed(action);
		}
		public void printPressed(String action)
		{
			System.out.println(action+" pressed");
		}
	}
}
