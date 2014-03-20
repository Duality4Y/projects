
class Channel
{
	private int color;
	private int sensitivity;
	private int time;
	private int channelNumber;
	private String name;
	private boolean selected;
	
	public Channel()
	{
		
	}
	/*
	 * Setters and Getters down here.
	 * */
	public void setColor(int color)
	{
		this.color = color;
	}
	public int getColor()
	{
		return this.color;
	}
	
	public void setSensitivity(int sensitivity)
	{
		this.sensitivity = sensitivity;
	}
	public int getSensitivity()
	{
		return this.sensitivity;
	}
	
	public void setTime(int time)
	{
		this.time = time;
	}
	public int getTime()
	{
		return this.time;
	}
	
	public void setChannelNumber(int channelNumber)
	{
		this.channelNumber = channelNumber;
	}
	public int getChannelNumber()
	{
		return this.ChannelNumber;
	}
	
	public void setName(String name)
	{
		this.name = name;
	}
	public String getName()
	{
		return this.name;
	}
	
	public void selectChannel(boolean selected)
	{
		this.selected = selected;
	}
	public boolean isSelected()
	{
		return (selected != 0);
	}
}
