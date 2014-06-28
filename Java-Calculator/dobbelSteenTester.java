import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
import java.util.Random;
import java.util.ArrayList;
import java.util.Observable;
import java.util.Observer;

class dobbelSteenTester extends JFrame
{
	private JPanel mainPanel;
	private Control control;
	private View view;
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
		
		model.addObserver(view);
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

class View extends JPanel implements Observer
{
	private Model model;
	public View(Model model)
	{
		this.model = model;
	}
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		int collomWidth = 50;
		int offset = 5;
		int leftOffset = 100;
		if(model.getGraph() == model.TABLE)
		{
			//g.fillRect(
			for(int i = 1;i<7;i++)
			{
				g.setColor(Color.BLACK);
				g.drawString(""+i, 100+(i*collomWidth), 370);
				g.drawString(""+model.getNumThrown(i), 100+(i*collomWidth), 400);
			}
		}
		//else if(model.getGraph() == model.BARGRAPH)
		else
		{
			for(int i = 1;i<7;i++)
			{
				g.setColor(Color.BLACK);
				/*drawRect(int x, int y, int width, int height)*/
				g.drawRect(i*40+leftOffset+offset*i, 340-(model.getTotalNumThrown(i)*10), 10, (model.getTotalNumThrown(i)*10));
				//g.drawRect(i*10+leftOffset+offset*i,340,10,(340-model.getNumThrown(i)*10));
				//g.setColor(Color.BLUE);
			}
		}
	}
	//update view here.
	public void update(Observable obs, Object obj)
	{
		repaint();
		System.out.println("got here");
	}
}

class Model extends Observable
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
			//addNumber(randomGenerator.nextInt(8));
			addNumber((int)(Math.random()*6.0)+1);
			throwCount++;
			System.out.println(getTotalNumThrown(2));
		}
		setChanged();
		notifyObservers();
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
	public boolean getGraph()
	{
		return this.selectedGraph;
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
	public int getNumThrown(int num)
	{
		int total = 0;
		for(Integer number:numbers)
		{
			if(number == num)
			{
				total++;
			}
		}
		return total;
	}
	//gives average
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
		
		stopStartbutton = new JButton("start");
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
				stopStartbutton.setText("start");
			}
			else
			{
				model.setThrowing(true);
				stopStartbutton.setText("stop");
			}
		}
	}
	class graphSwitchbuttonHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			if(model.getGraph() == model.BARGRAPH)
			{
				model.selectGraph(model.TABLE);
				graphSwitchbutton.setText("graph");
			}
			else
			{
				model.selectGraph(model.BARGRAPH);
				graphSwitchbutton.setText("Table");
			}
		}
	}
}
