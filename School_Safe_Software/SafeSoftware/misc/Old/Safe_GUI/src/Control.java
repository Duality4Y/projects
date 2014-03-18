import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;

import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

public class Control {
	private View view;
	private Serial serial;
	public Control(View view, Serial serial) {
		this.view = view;
		this.serial = serial;
		view.addSerialListener(new SerialListener());
		view.btnConnectActionListener(new BtnListener());
		view.btnVerifyActionListener(new VerifyListener());
		view.btnDisconnectActionListener(new DisconnectListener());
		view.btnOpenCloseActionListener(new OpenCloseListener());
	}
	public Control(View view) {
		this.view = view;
		
		//serial.addEventListener(new SerialListener());
	}
    class SerialListener implements SerialPortEventListener {
		@Override
		public void serialEvent(SerialPortEvent ev) {
			if (ev.getEventType() == SerialPortEvent.DATA_AVAILABLE) {
				String readLine = serial.read();
				if (readLine.equals("BTOK")) {
					//serial.setVerified(true);
					view.setView(View.ENTERPIN);
				} else if (readLine.indexOf("num0")!=-1) {
					readLine = readLine.replace("num0 ", "");
					try {
						view.setNum(0, Integer.parseInt(readLine));			
					} catch (Exception ex) {						
					}					
				} else if (readLine.indexOf("num1")!=-1) {
					readLine = readLine.replace("num1 ", "");
					try {
						view.setNum(1, Integer.parseInt(readLine));			
					} catch (Exception ex) {						
					}					
				} else if (readLine.indexOf("num2")!=-1) {
					readLine = readLine.replace("num2 ", "");
					try {
						view.setNum(2, Integer.parseInt(readLine));			
					} catch (Exception ex) {						
					}					
				} else if (readLine.indexOf("num3")!=-1) {
					readLine = readLine.replace("num3 ", "");
					try {
						view.setNum(3, Integer.parseInt(readLine));				
					} catch (Exception ex) {						
					}									
				} else if(readLine.indexOf("rot")!=-1) {
					readLine = readLine.replace("rot ", "");
					try {
						view.setRotary(Integer.parseInt(readLine));						
					} catch (Exception ex) {						
					}					
				} else if (readLine.equals("SDENIED")) {
			        JOptionPane.showMessageDialog(view, "WRONG PIN!");					
				} else if (readLine.equals("SACCES")) {
					view.resizeToMain();		
					serial.write("close");
				} else if (readLine.equals("locked")) {
					view.setNum(0, 0);
					view.setNum(1, 0);
					view.setNum(2, 0);
					view.setNum(3, 0);	
					if (view.getStatus().equals("open")) {
						view.setStatus(false);
					}
				} else if (readLine.equals("open")) {
					view.setNum(0, 0);
					view.setNum(1, 0);
					view.setNum(2, 0);
					view.setNum(3, 0);
					if (view.getStatus().equals("closed")) {
						view.setStatus(true);
					}
				} else if (readLine.equals("close")) {
					view.resizeToSmall();					
				}
				System.out.println(readLine);		
			}			
		}
    
    }
    class OpenCloseListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			if (view.getStatus().equals("open")) {
				serial.write("close");
				view.setStatus(false);
			} else {
				serial.write("open");
				view.setStatus(true);
			}
		}
    	
    }
    class BtnListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			if (view.getSelectedPort().equals("")) {
				JOptionPane.showMessageDialog(view, "No port was found! :(");
			} else {
				boolean connect = serial.Connect(view.getSelectedPort());
				if (connect) {
					serial.addEventListener(new SerialListener());
					serial.write("BT");
				//	view.setView(View.ENTERPIN );				
				} else {
					System.out.println("Failed to connect!");
				}
			}
		}
    	
    }
    class VerifyListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			serial.write("login "+view.getVerifyPin());
		}
    	
    }
    class DisconnectListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			serial.write("logout");
			serial.close();
			view.resizeWindow();
		}
    	
    }
}
