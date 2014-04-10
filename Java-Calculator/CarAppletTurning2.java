import java.awt.Color;
import java.awt.*;
import javax.swing.*;
import javax.swing.Timer;
import java.awt.event.*;
import java.util.*;

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
	public DrawingPanel()
	{
		car = new Car(20,20,80,30);
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
	private int x,y,width,height;
	private int wheelSize = 20;
	private int roofWidth,roofHeight;
	private int windowWidth, windowHeight;
	private int chassisWidth, chassisHeight;
	public Car(int x, int y, int width, int height)
	{
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		
		int chassisHeight = ;
		int chassisWidth = ;
		
		int windowWidth = ;
		int windowHeight = ;
		
		int roofWidth = ;
		int roofHeight = ;
	}
	public void draw(Graphics g)
	{
		//draw roof
		//g.setColor(Color.BLUE);
		//g.fillRect(this.x,this.y,this.width-windowWidth,this.height-chassisHeight);
		
		//draw window
		int[] xpoints = {roofWidth,roofWidth,roofWidth+windowWidth};
		int[] ypoints = {y, windowHeight, windowHeight};
		g.setColor(Color.RED);
		g.drawPolygon(xpoints, ypoints, 3);
	}
}
