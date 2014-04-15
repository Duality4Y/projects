import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
//import 

class Channel extends JPanel implements DummySerialPortEventListener
{
	//class variables
	private Color color;
	private int sensitivity;
	private int channelNumber;
	private boolean selected;
	
	//for getting the data.
	private DummySerialPort port;
	private InputStream input;
	private boolean isForThisChannel;
	private ArrayList<Integer> A_values;
	private ArrayList<Integer> B_values;
	
	//buttons for selecting amplitude and turning it on or off.
	private JButton selectButton;
	private JButton amplitudeSelect;
	//alink to model.
	private TransientModel model;
	
	public Channel(Color color, int channelNumber, TransientModel model)
	{
		this.color = color;
		this.channelNumber = channelNumber;
		this.selected = false;
		this.sensitivity = 1;
		
		A_values = new ArrayList<Integer>();
		B_values = new ArrayList<Integer>();
		
		this.port = new DummySerialPort(100);
		try
		{
			port.addEventListener(this);
		}catch(TooManyListenersException e){}
		port.notifyOnDataAvailable(true);
		input = port.getInputStream();
		
		//handlers and buttons and model link
		this.model = model;
		this.selectButton = new JButton("select channel");
		this.amplitudeSelect = new JButton("v/div");
		this.selectButton.addActionListener(new SelectButtonHandler());
		this.amplitudeSelect.addActionListener(new SensitivityHandler());
		add(selectButton);
		add(amplitudeSelect);
	}
	class SelectButtonHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			selected = !selected;
		}
	}
	class SensitivityHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			sensitivity += 5;
		}
	}
	public int stillValues()
	{
		try{
			return input.available();
		}catch(IOException e){return -1;}
	}
	public void serialEvent(DummySerialPortEvent event)
	{
		if(event.getEventType() == DummySerialPortEvent.DATA_AVAILABLE)
		{
			try
			{
				isForThisChannel = true;
				if(input.available() > 0)
				{
					
					char channel =  'A';
					int value = 	0;
					if(isForThisChannel)
						channel =  (char)input.read();
					else
						value = (int)input.read();
					if(channel == 'A')
					{
						A_values.add(value);
					}
					else if(channel == 'B')
					{
						B_values.add(value);
					}
					/*
					if(isForThisChannel == true)
					{
						A_values.add((int)input.read()/sensitivity);
					}
					else
					{
						B_values.add((int)input.read()/sensitivity);
					}
					isForThisChannel = !isForThisChannel;
					* */
				}
			}catch(IOException e){}
		}
	}
	
	/*
	 * Setters and Getters down here.
	 * */
	public void setColor(Color color)
	{
		this.color = color;
	}
	
	public Color getColor()
	{
		return this.color;
	}
	public static void main(String[] args)
	{
		Channel channel1 = new Channel(Color.GRAY, 1, new TransientModel());
		Channel channel2 = new Channel(Color.GRAY, 2, new TransientModel());
		while(channel1.stillValues() > 0 && channel2.stillValues() > 0)
		{
			System.out.println("Channel A"+channel1.getValues(1));
			System.out.println("Channel B"+channel2.getValues(2));
		}
	}
	public ArrayList<Integer> getValues(int channelnumber)
	{
		if(this.channelNumber == channelnumber)
		{
			return A_values;
		}
		else if(this.channelNumber == channelnumber)
		{
			return B_values;
		}
		return null;
	}
	public void setSensitivity(int sensitivity)
	{
		this.sensitivity = sensitivity;
	}
	public int getSensitivity()
	{
		return this.sensitivity;
	}
	
	public void setChannelNumber(int channelNumber)
	{
		this.channelNumber = channelNumber;
	}
	
	public int getChannelNumber()
	{
		return this.channelNumber;
	}
	
	public void selectChannel(boolean selected)
	{
		this.selected = selected;
	}
	
	public boolean isSelected()
	{
		return (selected);
	}
}
