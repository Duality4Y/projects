import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;

//import 

class ChannelControler extends JPanel implements DummySerialPort.DummySerialPortEventListener
{
	//class variables
	private Color color;
	private int sensitivity;
	private int channelNumber;
	private boolean selected;
	private boolean isNewData = true;
	private char chanSel = 'A';
	private int value = 1;
	
	private TransientSource source = new TransientSource();
	
	//for getting the data.
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
	
	public void serialEvent(DummySerialPort.DummySerialPortEvent event)
	{
		java.io.InputStream = event.getSource().getInputStream();
		int[]input = new int[4];
		try
		{
			while(inputStream.available() >= 4)
			{
				for(int i =0;i<4;i++)
				{
					input[i] = inputStream.read();
				}
			}
		}catch(IOExeption e){}
	}
	
	public boolean newValues()
	{
		return this.isNewData;
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
		
		DummySerialPort serialPort = new DummySerialPort();
		serialPort.notifyOnDataAvailable(true);
		try
		{
			serialPort.addEventListener(ChannelControler.this);
		}catch(IOException e){}
		//Channel channel2 = new Channel(Color.GRAY, 2, new TransientModel());
		while(channel1.newValues())
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
		values.add((int)source.getValue());
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
	/*
	DummySerialPort = new DummySerialPort();
	serialPort.notifyOnDataAvailable(true);
	try
	{
		serialPort.addEventListener(new eu.elfring.whd.saxion.transientrecorder.control.MeetwaardenInput(model));
	}catch	{}
	* */
}
