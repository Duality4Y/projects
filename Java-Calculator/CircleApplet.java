import java.awt.Color;
import java.awt.*;
import java.awt.event.*;
import javax.swing.Timer;
import javax.swing.*;
import java.math.*;

class CircleApplet extends JFrame
{
	JPanel mainPanel;
	
	public CircleApplet()
	{
		mainPanel = new DrawingPanel();
		setContentPane(mainPanel);
	}
	
	public static void main(String args[])
	{
		CircleApplet applet = new CircleApplet();
		applet.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		applet.setSize(500,500);
		applet.setVisible(true);
	}
}

class DrawingPanel extends JPanel
{
	public Circle circle;
	
	private Timer timer;
	
	public DrawingPanel()
	{
		circle = new Circle();
		timer = new Timer(1000, new TimerHandler());
		timer.start();
	}
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		circle.drawCircle(g);
		repaint();
	}
	class TimerHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			repaint();
		}
	}
}


class Circle 
{
	private int x,y;
	private int length = 59;
	private double angle = 0.0;
	private double angle_stepsize = 0.1;
	
	public Circle(){}
	
	public void drawCircle(Graphics g)
	{
		g.setColor(Color.BLACK);
		while(angle < 2*Math.PI)
		{
			x = (int)(length*Math.cos(angle));
			y = (int)(length*Math.sin(angle));
			g.drawOval(Math.abs(x),Math.abs(y),1,1);
			angle+=angle_stepsize;
			System.out.println(""+angle+" "+x+" "+y+" ");
		}
	}
}
