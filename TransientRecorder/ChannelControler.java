import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
//import 

class ChannelControler extends JPanel implements DummySerialPortEventListener
{
	//class variables
	private Color color;
	private int sensitivity;
	private int channelNumber;
	private boolean selected;
	private boolean isNewData = true;
	private char chanSel = 'A';
	private int value = 1;
	
	//for getting the data.
	private DummySerialPort port;
	private InputStream input;
	private boolean channel;
	private ArrayList<Integer> values;
	
	//buttons for selecting amplitude and turning it on or off.
	private JButton selectButton;
	private JButton amplitudeSelect;
	//alink to model.
	private TransientModel model;
	
	public ChannelControler(Color color, int channelNumber, TransientModel model)
	{
		this.color = color;
		this.channelNumber = channelNumber;
		this.selected = false;
		this.sensitivity = 1;
		
		values = new ArrayList<Integer>();
		
		this.port = new DummySerialPort(1);
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
	public boolean newValues()
	{
		return this.isNewData;
	}
	public void serialEvent(DummySerialPortEvent event)
	{
		isNewData = true;
		if ( event.getEventType() == DummySerialPortEvent.DATA_AVAILABLE ) {
			try {
				// read data
				channel = true;
				if(input.available() > 0) {
					values.add((int)input.read());
				} 
			} catch (IOException e) {
			}
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
		while(channel1.newValues() && channel2.newValues())
		{
			//channel1.readValues();
			//channel2.readValues();
			//System.out.println("Channel A"+channel1.readValues());
			//System.out.println("Channel B"+channel2.readValues());
		}
	}
	public ArrayList<Integer> readValues()
	{
		return getValues();
	}
	public ArrayList<Integer> getValues()
	{
		return values;
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
