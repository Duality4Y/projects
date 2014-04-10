import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
import java.util.Random;
import java.util.ArrayList;

class dobbelSteenTester extends JFrame
{
	private JPanel mainPanel;
	private JPanel control;
	private JPanel view;
	private Model model;
	
	public dobbelSteenTester()
	{		
		mainPanel = new JPanel(new BorderLayout());
		//create a instance of model
		model = new Model();
		//create a instance of control and give it a reference to model.
		control = new Control(model);
		//create a instance of view.
		view = new View();
		
		mainPanel.add(view);
		mainPanel.add(control, BorderLayout.PAGE_END);
		setContentPane(mainPanel);
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
	private int throwCount = 0;
	private Random randomGenerator = new Random();
	private ArrayList<Integer> numbers;
	private Timer timer;
	public Model()
	{
		numbers = new ArrayList<Integer>();
		
		timer = new Timer(20, new TimerHandler());
		timer.start();
	}
	class TimerHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			throwDice();
		}
	}
	public void throwDice()
	{
		addNumber(randomGenerator.nextInt(8));
		throwCount++;
		System.out.println(getAverage(2));
	}
	public void addNumber(int num)
	{
		numbers.add(num);
	}
	public void startThrowing()
	{
		timer.start();
	}
	public void stopThrowing()
	{
		timer.stop();
	}
	public int getAverage(int num)
	{
		int total = 0;
		for(Integer number:numbers)
		{
			if(number == num)
			{
				total+=number;
			}
		}
		return (int)total/throwCount;
	}
}

class Control extends JPanel
{
	private JButton startbutton;
	private JButton stopbutton;
	private Model model;
	public Control(Model model)
	{
		super();
		this.model = model;
		
		startbutton = new JButton("start");
		startbutton.addActionListener(new startbuttonHandler());
		stopbutton = new JButton("stop");
		stopbutton.addActionListener(new stopbuttonHandler());
		add(startbutton);
		add(stopbutton);
	}
	class startbuttonHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			model.startThrowing();
		}
	}
	class stopbuttonHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			model.stopThrowing();
		}
	}
}
