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
		view = new View(model);
		
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
	public View(Model model)
	{
		
	}
}

class Model
{
	public static boolean BARGRAPH = true;
	public static boolean TABLE = false;
	
	private int thrownNumber = 0;
	private int throwCount = 0;
	
	private boolean isThrowing = false;
	private boolean selectedGraph = false;
	
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
		if(isThrowing())
		{
			addNumber(randomGenerator.nextInt(8));
			throwCount++;
			System.out.println(getTotalNumThrown(2));
		}
	}
	
	public boolean isThrowing()
	{
		return this.isThrowing;
	}
	public void setThrowing(boolean throwing)
	{
		this.isThrowing = throwing;
	}
	public void selectGraph(boolean graph)
	{
		this.selectedGraph = graph;
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
	public int getTotalNumThrown(int num)
	{
		int total = 1;
		for(Integer number:numbers)
		{
			if(number == num)
			{
				total+=1;
			}
		}
		return throwCount/total;
	}
}

class Control extends JPanel
{
	private JButton stopStartbutton;
	private JButton graphSwitchbutton;
	private Model model;
	public Control(Model model)
	{
		super();
		this.model = model;
		
		stopStartbutton = new JButton("stop");
		stopStartbutton.addActionListener(new stopStartbuttonHandler());
		graphSwitchbutton = new JButton("graph");
		graphSwitchbutton.addActionListener(new graphSwitchbuttonHandler());
		add(stopStartbutton);
		add(graphSwitchbutton);
	}
	class stopStartbuttonHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			if(model.isThrowing())
			{
				model.setThrowing(false);
				stopStartbutton.setText("stop");
			}
			else
			{
				model.setThrowing(true);
				stopStartbutton.setText("start");
			}
		}
	}
	class graphSwitchbuttonHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			//model.stopThrowing();
		}
	}
}
