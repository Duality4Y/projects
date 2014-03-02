import java.awt.event.*;
import javax.swing.*;

class Calculator1 extends JFrame
{
	private JPanel panel;
	private JLabel label;
	private JButton button;
	
	public Calculator1()
	{
		panel = new JPanel();
		label = new JLabel("Hartelijk Welkom!");
		button = new JButton("klik");
		
		buttonhandler handler = new buttonhandler();
		button.addActionListener(handler);
		
		panel.add(label);
		panel.add(button);
		
		setContentPane(panel);
		
		//this.main();
	}
	
	public static void main(String args[])
	{
		JFrame frame = new Calculator1();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(400,200);
		frame.setTitle("this Title" );
		frame.setVisible(true);
	}
	
	class buttonhandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			label.setText("Bedankt!");
		}
	}
}
