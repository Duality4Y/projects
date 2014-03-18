import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

import java.awt.BorderLayout;
import java.awt.Toolkit;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.*;

import skin.Button;


public class SelectCom extends JPanel{
	private static final long serialVersionUID = -2326848835200678248L;
	private Serial serial;
	private ArrayList<String> ports;
	private JComboBox<String> cbPorts;
	private Button btnConnect;
	private SerialPortEventListener serialListener;
	SelectCom(Serial serial) {
		this.serial = serial;
		addComponents();
	}
	void addSerialListener(SerialPortEventListener ev) {
		serialListener = ev;
	}
	private void addComponents() {		
        Icon icon = new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("loader.gif")));
		JLabel lblLoader = new JLabel(icon);
		lblLoader.setText("Searching for safe...");

		setLayout(new BorderLayout());
		add(lblLoader, BorderLayout.NORTH);
		

		System.out.println("Fetching ports...");
		ports = serial.getPorts();
		System.out.println("Fetched");
		cbPorts = new JComboBox<String>();
		for (String port:ports) {
			cbPorts.addItem(port);
		}
		JLabel lblMessage = new JLabel("Select a port:");
		btnConnect = new Button("Connect");
		
		JPanel pnlPorts = new JPanel();
		pnlPorts.setLayout(new BorderLayout());
		JPanel pnlMessage = new JPanel();
		pnlMessage.add(lblMessage);
		
		pnlPorts.add(pnlMessage, BorderLayout.NORTH);
		JPanel pnlComSelect = new JPanel();
		pnlComSelect.add(cbPorts);
		pnlComSelect.add(btnConnect);
		
		pnlPorts.add(pnlComSelect, BorderLayout.CENTER);	
		//add(pnlPorts);
		search();
	}
	private void search() {
		new Thread(new Runnable() {

			@Override
			public void run() {
				ArrayList<String> safes = new ArrayList<String>();
				ArrayList<String> ports = serial.getPorts();
				for (String port:ports) {
					System.out.println("Connecting to: "+port);

					boolean connect = serial.Connect(port);
					if (connect) {
						serial.addEventListener(new SerialListener());
						serial.write("BT");			

						int wait = 400;
						int i=0;
						while (i<=wait){
							if (serial.getVerified()) {
								safes.add(port);
								serial.close();
								serial.setVerified(false);
								break;
							} else {			
								try {
									Thread.sleep(10);
								} catch (InterruptedException e) {
									// TODO Auto-generated catch block
									e.printStackTrace();
								}
							}
							i++;
						}
					} else {
						System.out.println("Failed to connect!");
					}
				}
				if (safes.isEmpty()) {
					System.out.println("No Port found!");
				} else if (safes.size()==1) {
					System.out.println("Connecting to safe: "+safes.get(0));
					boolean connect = serial.Connect(safes.get(0));
					if (connect) {
						serial.addEventListener(serialListener);
						serial.write("BT");			
					}
				} else {
					for (String port:safes) {
						System.out.println(port);
					}
				}
			}
			
		}).start();
	}
	public String getSelectedPort() {
		if (cbPorts.getSelectedItem()==null) {return "";}
		return cbPorts.getSelectedItem().toString();
	}
	public void addConnectListener(ActionListener ev) {
		btnConnect.addActionListener(ev);
	}

    class SerialListener implements SerialPortEventListener {
		@Override
		public void serialEvent(SerialPortEvent ev) {
			if (ev.getEventType() == SerialPortEvent.DATA_AVAILABLE) {
				try {
					String readLine = serial.read();
					if (readLine.equals("BTOK")) {
						System.out.println("SAFE FOUND!");
						serial.setVerified(true);
					}					
				} catch (Exception ex) {
					
				}
			}
		}
    }
}
