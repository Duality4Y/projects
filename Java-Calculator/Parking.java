import java.awt.*;
import java.awt.Dimension.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class Parking extends JFrame
{
	//handlers.
	muntInwerpen Inwerpen;
	geefTerug Terug;
    geef Geef;
	kaart Kaart;
	
	private ParkeerAutomaat parkeerAutomaat = new ParkeerAutomaat();
	
	//window information
	private JPanel mainPanel,buttonPanel;
	/*
	 * 1 tekst velden,
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
		muntInwerpen Inwerpen = new muntInwerpen(); //voor het inwerpen van munten
		geefTerug Terug = new geefTerug(); //voor het terug geven van munten
		geef Geef = new geef(); //voor het geven van het geld.
		kaart Kaart = new kaart(); //word aangeroepen als kaart ingeworpen word.
		
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
			buttonPanel.add(button);
			if(button.getText().equals("0.20€"))
			{
				button.addActionListener(Inwerpen);
			}
			if(button.getText().equals("1€"))
			{
				button.addActionListener(Inwerpen);
			}
			if(button.getText().equals("Back"))
			{
				button.addActionListener(Terug);
			}
			if(button.getText().equals("Give"))
			{
				button.addActionListener(Geef);
				button.setEnabled(false);
			}
			if(button.getText().equals("Chart"))
			{
				button.addActionListener(Kaart);
			}
		}
		setContentPane(mainPanel);
		/*
		buttonhandler muntInwerpen = new buttonhandler(); //voor het inwerpen van munten
		buttonhandler geefTerug = new buttonhandler(); //voor het terug geven van munten
		buttonhandler geef = new buttonhandler(); //voor het geven van het geld.
		buttonhandler kaart = new buttonhandler(); //word aangeroepen als kaart ingeworpen word.
		* */
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
	public void displayCurrent()
	{
		output.setText("te betalen: "+parkeerAutomaat.getPrijs()+" Cent. betaald: "+parkeerAutomaat.getBetaald()+" Cent.");
		//this.printPressed(action);
	}
	class muntInwerpen implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			String action = e.getActionCommand();
			if(action.equals("0.20€"))
			{
				parkeerAutomaat.voegToeAanBetaald(20);
			}
			else if(action.equals("1€"))
			{
				parkeerAutomaat.voegToeAanBetaald(100);
			}
			displayCurrent();
			for(JButton button:buttons)
			{
				if(button.getText().equals("Give"))
				{
					button.setEnabled(parkeerAutomaat.voldoendeBetaald());
				}
			}
		}
	}
	class geef implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
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
			if(parkeerAutomaat.getBetaald() >= parkeerAutomaat.getPrijs())
			{
				parkeerAutomaat.haalAfVanBetaald(parkeerAutomaat.getPrijs());
			}
			displayCurrent();
			for(JButton button:buttons)
			{
				if(button.getText().equals("Give"))
				{
					button.setEnabled(parkeerAutomaat.voldoendeBetaald());
				}
			}
		}
	}
	class geefTerug implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			parkeerAutomaat.setBetaald(0);
			displayCurrent();
		}
	}
	class kaart implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			if(kaartIsIngeworpen == false)
			{
				kaartIsIngeworpen = true; //kaart ingworpen
				parkeerAutomaat.setPrijs();//set het te betalen bedrag
				for(JButton button:buttons)
				{
					if(button.getText().equals("Chart"))
					{
						button.setEnabled(false); //disable de button.
					}
				}
			}
			for(JButton button:buttons)
			{
				if(button.getText().equals("Give"))
				{
					button.setEnabled(parkeerAutomaat.voldoendeBetaald());
				}
			}
			displayCurrent();
		}
	}
}
