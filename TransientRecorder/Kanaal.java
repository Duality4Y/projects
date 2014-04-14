import javax.swing.*;
import java.awt.*;
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
	private int valueA;
	private int valueB;
	
	public Channel(Color color, int channelNumber, TransientModel model)
	{
		this.color = color;
		this.channelNumber = channelNumber;
		this.selected = false;
		this.sensitivity = 1;
		
		this.port = new DummySerialPort(100);
		try
		{
			port.addEventListener(this);
		}catch(TooManyListenersException e){}
		port.notifyOnDataAvailable(true);
		input = port.getInputStream();
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
					if(isForThisChannel == true)
					{
						this.valueA = (int)input.read();
					}
					else
					{
						this.valueB = (int)input.read();
					}
					isForThisChannel = !isForThisChannel;
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
	public int getValue()
	{
		if(this.channelNumber == 1)
		{
			
		}
		else if(this.channelNumber == 2)
		{
			
		}
		return -1;
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
