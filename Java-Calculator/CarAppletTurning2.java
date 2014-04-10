import java.awt.Color;
import java.awt.*;
import javax.swing.*;
import javax.swing.Timer;
import java.awt.event.*;
import java.util.*;
import java.awt.geom.*;

class CarAppletTurning2 extends JFrame
{
	JPanel mainPanel;
	public CarAppletTurning2()
	{
		mainPanel = new DrawingPanel();
		setContentPane(mainPanel);
	}
	public static void main(String args[])
	{
		CarAppletTurning2 applet = new CarAppletTurning2();
		applet.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		applet.setSize(500,500);
		applet.setVisible(true);
	}
}

class DrawingPanel extends JPanel
{
	private Car car;
	private Timer timer;
	public DrawingPanel()
	{
		car = new Car(20,20,100,80);
		timer = new Timer(50, new TimerHandler());
		timer.start();
	}
	
	class TimerHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			car.ride();
		}
	}
	
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		setBackground(Color.WHITE);
		car.draw(g);
		repaint();
	}
}

class Car
{
	private int x,y,width,height;
	private int wheelSize = 30;
	private int roofWidth,roofHeight;
	private int windowWidth, windowHeight;
	private int chassisWidth, chassisHeight;
	public Car(int x, int y, int width, int height)
	{
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		
		this.roofWidth = this.width-(this.width/4);
		this.roofHeight = this.height/3;
		this.chassisHeight = roofHeight;
		this.chassisWidth = this.width;
		this.windowWidth = chassisWidth-roofWidth;
		this.windowHeight = roofHeight;
		
		
	}
	public void draw(Graphics g)
	{
		//draw roof
		g.setColor(Color.BLUE);
		g.fillRect(this.x,this.y,roofWidth,this.roofHeight);
		
		//draw chassis
		g.setColor(Color.GREEN);
		g.fillRect(x,y+roofHeight,chassisWidth,chassisHeight);
		
		//draw window
		int[] xpoints = {x+roofWidth,x+roofWidth,x+roofWidth+windowWidth};
		int[] ypoints = {y,y+roofHeight,y+roofHeight};
		g.setColor(Color.RED);
		g.fillPolygon(xpoints, ypoints, xpoints.length);
		
		//front wheel
		g.setColor(Color.GRAY);
		g.fillOval(this.x+chassisWidth/6,(this.y+chassisHeight+roofHeight)-(wheelSize/2), wheelSize,wheelSize);
		//hind wheel
		g.setColor(Color.GRAY);
		g.fillOval(this.x+chassisWidth-(2*chassisWidth/6), (this.y+chassisHeight+roofHeight)-(wheelSize/2), wheelSize, wheelSize);
		
		//turning points on wheel
		//hind wheel rotating.
		int wheelx = this.x+chassisWidth-(2*chassisWidth/6);
		int wheely = (this.y+chassisHeight+roofHeight)-(wheelSize/2);
		int dotSize = wheelSize/4;
		wheelx = wheelx+(int)(dotSize*Math.cos(this.x))+wheelSize/4+dotSize/2;
		wheely = wheely+(int)(dotSize*Math.sin(this.x))+wheelSize/4+dotSize/2;
		g.setColor(Color.WHITE);
		g.fillOval(wheelx,wheely , dotSize, dotSize);
		//front wheel rotating
		wheelx = this.x+chassisWidth/6;
		wheely = (this.y+chassisHeight+roofHeight)-(wheelSize/2);
		wheelx = wheelx+(int)(dotSize*Math.cos(this.x))+wheelSize/4+dotSize/2;
		wheely = wheely+(int)(dotSize*Math.sin(this.x))+wheelSize/4+dotSize/2;
		g.fillOval(wheelx,wheely, dotSize, dotSize);
	}
	public void ride()
	{
		this.x+=1;
	}
}
