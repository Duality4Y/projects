import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class TellerApplet extends JFrame
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
		telleraplet.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		telleraplet.setSize(500,500);
		telleraplet.setVisible(true);
	}
}

class TimerPanel extends JPanel
{
	private Timer timer;
	private int timing;
	
	public TimerPanel()
	{
		timing = 0;
		timer = new Timer(1000,new TimerHandler());
		timer.start();
	}
	
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		g.setColor(Color.BLUE);
		g.setFont(new Font("SandsSerif", Font.BOLD, 14));
		g.drawString("teller = "+ timing, 130, 80);
		
	}
	
	class TimerHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			timing++;
			repaint();
		}
	}
}
