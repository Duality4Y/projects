import java.awt.event.*;
import javax.swing.Timer;
import javax.swing.*;
import java.awt.*;

class dobbelSteenTester
{
	private Timer timer;
	public dobbelSteenTester()
	{
		this.timer = new Timer(20, new TimerHandler());
	}
	class TimerHandler
	{
		public void actionPerformed(ActionEvent e)
		{
			model.throwDice();
		}
	}
}

class view
{}
class model
{
	private int thrownNumber = 0;
	public model()
	{
	}
	public void 
}
class control{}
