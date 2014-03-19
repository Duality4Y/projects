import gnu.io.SerialPortEventListener;

import java.awt.*;
import java.awt.event.*;
import java.util.Random;

import javax.swing.*;


public class View extends JFrame {
	private static final long serialVersionUID = 7002428971413959811L;
	public final static int COMSELECT = 0;
	public final static int ENTERPIN = 1;
	public final static int MAIN = 2;
	private JPanel mainPanel;
	private MainView mainView;
	private ComSelect comSelect;
	private SelectCom selectCom;
	private EnterPin enterPin;
	private Dimension mainSize = new Dimension(600, 400);
	private Dimension smallSize = new Dimension(300, 140);
	private Serial serial;
	private int mode;
	public View(Serial serial) {
		this.serial = serial;
		
		mainPanel = new JPanel();
		mainPanel.setLayout(new BorderLayout());
		setIconImage(Toolkit.getDefaultToolkit().getImage(getClass().getResource("icon.png")));
		setContentPane(mainPanel);
		setTitle("Safe");
		setResizable(false);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setPreferredSize(new Dimension(300,140));
		pack();
		//Put the JFrame on a random position on the screen
		Random random = new Random();
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		setLocation(random.nextInt(screenSize.width-getPreferredSize().width), random.nextInt(screenSize.height-getPreferredSize().height));
		addComponents();
	}
	void addComponents() {		
		selectCom = new SelectCom(serial);
		comSelect = new ComSelect(serial);
		enterPin  = new EnterPin();
		mainView = new MainView();
		
		//mainPanel.add(mainView, BorderLayout.CENTER);
		//mainPanel.add(enterPin, BorderLayout.CENTER);
		//mainPanel.add(comSelect);
		mainPanel.add(selectCom);
	}
	public void setStatus(boolean isOpen) {
		mainView.setStatus(isOpen);
	}
	public String getStatus() {
		return mainView.getStatus();
	}
	public String getVerifyPin() {
		return enterPin.getPin();
	}
	void addSerialListener(SerialPortEventListener ev) {
		selectCom.addSerialListener(ev);
	}
	void btnOpenCloseActionListener(ActionListener ev) {
		mainView.addOpenCloseListener(ev);
	}
	void btnConnectActionListener(ActionListener ev) {
		comSelect.addConnectListener(ev);
	}
	void btnVerifyActionListener(ActionListener ev) {
		enterPin.addVerifyListener(ev);
	}
	void btnDisconnectActionListener(ActionListener ev) {
		mainView.addDisconnectListener(ev);
	}
	String getSelectedPort() {
		return comSelect.getSelectedPort();
	}
	public void setRotary(int mode) {
		mainView.setRotary(mode);
	}
	public void setNum(int segment, int num) {
		mainView.setNum(segment, num);
	}
	public void setView(int view) {
		mode = view;
		switch(view) {
		case COMSELECT:
			mainPanel.remove(mainView);
			mainPanel.add(selectCom);
			break;
		case ENTERPIN:
			mainPanel.remove(selectCom);
			mainPanel.add(enterPin);
			mainPanel.repaint();
			mainPanel.revalidate();
			break;
		case MAIN:
			mainPanel.remove(enterPin);
			mainPanel.add(mainView);
			break;
		}
		mainPanel.repaint();
		mainPanel.revalidate();
	}
	public int getView() {
		return mode;
	}
	public void resizeToMain() {
		new Thread( new Runnable() {
			@Override
			public void run() {
				if (getSize().width!=mainSize.width && getSize().height!=mainSize.height) {
					try {
						for (int i=0;i<=100;i++) {
							double width = smallSize.getWidth()+((mainSize.getWidth()-smallSize.getWidth())/100)*i;
							double height = smallSize.getHeight()+((mainSize.getHeight()-smallSize.getHeight())/100)*i;
							setSize((int) width, (int)height);
							Thread.sleep(1);
						}
					} catch(Exception ex) {
						ex.printStackTrace();
					}
					setSize(mainSize);
					setView(MAIN);
				}
			}		
		}).start();			
	}
	public void resizeToSmall() {
		new Thread( new Runnable() {
			@Override
			public void run() {
				if (getSize().width!=smallSize.width && getSize().height!=smallSize.height) {
					setView(COMSELECT);
					try {
						for (int i=100;i>=0;i--) {
							double width = smallSize.getWidth()+((mainSize.getWidth()-smallSize.getWidth())/100)*i;
							double height = smallSize.getHeight()+((mainSize.getHeight()-smallSize.getHeight())/100)*i;
							setSize((int) width, (int)height);
							Thread.sleep(1);
						}
					} catch(Exception ex) {
						ex.printStackTrace();
					}
					setSize(smallSize);
				}
			}		
		}).start();		
	}
	public void resizeWindow() {
		new Thread( new Runnable() {
			@Override
			public void run() {
				if (getSize().width==mainSize.width && getSize().height==mainSize.height) {
					setView(COMSELECT);
					try {
						for (int i=100;i>=0;i--) {
							double width = smallSize.getWidth()+((mainSize.getWidth()-smallSize.getWidth())/100)*i;
							double height = smallSize.getHeight()+((mainSize.getHeight()-smallSize.getHeight())/100)*i;
							setSize((int) width, (int)height);
							Thread.sleep(1);
						}
					} catch(Exception ex) {
						ex.printStackTrace();
					}
					setSize(smallSize);
				} else {
					try {
						for (int i=0;i<=100;i++) {
							double width = smallSize.getWidth()+((mainSize.getWidth()-smallSize.getWidth())/100)*i;
							double height = smallSize.getHeight()+((mainSize.getHeight()-smallSize.getHeight())/100)*i;
							setSize((int) width, (int)height);
							Thread.sleep(1);
						}
					} catch(Exception ex) {
						ex.printStackTrace();
					}
					setSize(mainSize);
					setView(MAIN);
				}
			}		
		}).start();
	}
}
