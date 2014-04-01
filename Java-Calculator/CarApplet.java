import javax.swing.JFrame;
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import java.awt.BorderLayout;

class CarApplet extends JFrame
{
	JPanel mainPanel;
	public CarApplet()
	{
		mainPanel = new JPanel();
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

class DrawingPanel
{
}

class Car
{
}

abstract class Part
{
}

class RectAngle extends Part
{
}

class Circle extends Part
{
}

class TriAngle extends Part
{
}
