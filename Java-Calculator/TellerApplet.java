import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class TellerApplet extends JApplet
{
	public TellerApplet()
	{
		init();
	}
	public void init()
	{
		setContentPane(new TimerPanel());
	}
	public static void main(String args[])
	{
		TellerApplet telleraplet = new TellerApplet();
	}
}

class TimerPanel
{
	private Timer timer;
}
