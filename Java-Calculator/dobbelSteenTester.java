import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
import java.util.Random;
import java.util.ArrayList;

class dobbelSteenTester extends JFrame
{
	private JPanel mainPanel;
	private JPanel buttonPanel;
	private JPanel controle;
	private JPanel view;
	private Model model;
	
	private Timer timer;
	
	public dobbelSteenTester()
	{
		timer = new Timer(20, new TimerHandler());
		timer.start();
		
		mainPanel = new JPanel(new GridLayout(1,2));
		buttonPanel = new JPanel(new GridLayout(2,1));
	}
	class TimerHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			model.throwDice();
		}
	}
	
	public static void main(String args[])
	{
		dobbelSteenTester dobbelsteen = new dobbelSteenTester();
		dobbelsteen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		dobbelsteen.setSize(500,500);
		dobbelsteen.setVisible(true);
	}
}

class View extends JPanel
{
}

class Model
{
	private int thrownNumber = 0;
	private Random randomGenerator = new Random();
	private ArrayList<Integer> numbers; 
	public Model()
	{
		numbers = new ArrayList<Integer>();
	}
	public void throwDice()
	{
		addNumber(randomGenerator.nextInt(8));
	}
	public void addNumber(int num)
	{
		//numbers.add(num);
	}
	public void average()
	{
		for(Integer number:numbers)
		{
			//System.out.println(number);
		}
	}
}

class Control extends JPanel
{
	
}
