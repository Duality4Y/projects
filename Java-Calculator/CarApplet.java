import java.awt.Color;
import java.awt.*;
import javax.swing.*;
import javax.swing.Timer;
import java.awt.event.*;
import java.util.*;

class CarApplet extends JFrame
{
	JPanel mainPanel;
	public CarApplet()
	{
		mainPanel = new DrawingPanel();
		setContentPane(mainPanel);
	}
	public static void main(String args[])
	{
		CarApplet applet = new CarApplet();
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
		car = new Car(20,150,80,30);
	}
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		setBackground(Color.WHITE);
		car.draw(g);
	}
}

class Car
{
	private ArrayList<Part> partsList;
	
	private int xPosition = 0;
	private int left = 0;
	private int under = 0;
	private int width = 0;
	private int height = 0;
	private int wheelsize = 0;
	
	public Car(int left, int under, int width, int height)
	{
		partsList = new ArrayList<Part>();
		this.left = left;
		this.under = under;
		this.width = width;
		this.height = height;
		this.wheelsize = 20;
		int chassisUnder = under - wheelsize/2;
		
		//chassis
		partsList.add( new RectAngle(Color.BLUE, left, under-10, width, height));
		
		//cabine
		partsList.add( new RectAngle(Color.CYAN, left, under-10-height, 4*width/5, 4*height/5));
		
		//hind wheel
		partsList.add( new Circle(Color.YELLOW, left+5, under, wheelsize));
		
		//front wheel
		partsList.add( new Circle(Color.YELLOW, left+width-30, under, wheelsize));
		
		//the window		
		partsList.add(new TriAngle(Color.RED, left, under));
	}
	
	public void draw(Graphics g)
	{
		for(Part part : partsList)
		{
			part.draw(g);
		}
	}
}

interface Part
{
	public void draw(Graphics g);
}

abstract class AbstractPart implements Part
{
	//make static to associate variables with this class.
	//and not with the class calling super() and using similair
	//named variables.
	protected int left,under; 
	protected Color color;
	
	protected AbstractPart()
	{
		color = Color.black;
		left = under = 0;
	}
	
	protected AbstractPart(Color color, int left, int under)
	{
		this.color = color;
		this.left = left;
		this.under = under;
	}
	
	public abstract void draw(Graphics g);
	
	public Color getColor()
	{
		return this.color;
	}
	
	public void setColor(Color color)
	{
		this.color = color;
	}
	
}

class Circle extends AbstractPart implements Part
{
	private int cross_section;
	
	public Circle(Color color, int left, int under, int cross_section)
	{
		super(color, left, under);
		this.cross_section = cross_section;
	}
	
	public void draw(Graphics g)
	{
		g.setColor(this.color);
		g.fillOval(left, under-cross_section, cross_section, cross_section);
		g.setColor(Color.black);
		g.drawOval(left, under-cross_section, cross_section, cross_section);
	}
}

class RectAngle extends AbstractPart implements Part
{
	private int width,height;
	
	public RectAngle(Color color, int left, int under, int width, int height)
	{
		super(color, left, under);
		this.width = width;
		this.height = height;
	}
	
	public void draw(Graphics g)
	{
		g.setColor(this.color);
		g.fillRect(left, under-height, width, height);
		g.setColor(Color.black);
		g.drawRect(left, under-height, width, height);
	}
}

class TriAngle extends AbstractPart implements Part
{
	private int[] xpoints = {85,85,100};
	private int[] ypoints = {85,110,110};
	
	public TriAngle(Color color, int left, int under)
	{
		super(color,left,under);
		
		//determine where to place the triangle;
		xpoints[0] = left+65;
		ypoints[0] = under-40;
		
		xpoints[1] = left+65;
		ypoints[1] = under-60;
		
		xpoints[2] = left+75;
		ypoints[2] = under-40;
	}
	
	public void draw(Graphics g)
	{
		if(xpoints.length == ypoints.length)
		{
			g.setColor(color);
			g.fillPolygon(xpoints, ypoints, xpoints.length);
			g.setColor(Color.black);
			g.drawPolygon(xpoints, ypoints, xpoints.length);
		}
	}
}
