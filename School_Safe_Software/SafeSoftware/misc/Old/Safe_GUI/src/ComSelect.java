import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

import javax.swing.*;
import skin.Button;

public class ComSelect extends JPanel {
	private static final long serialVersionUID = -9072277077974829291L;

	private ArrayList<String> ports;
	private JComboBox<String> cbPorts;
	private Button btnConnect;
	ComSelect(Serial serial) {
		System.out.println("Fetching ports...");
		ports = serial.getPorts();
		System.out.println("Fetched");
		cbPorts = new JComboBox<String>();
		for (String port:ports) {
			cbPorts.addItem(port);
		}
		JLabel lblMessage = new JLabel("Select a port:");
		btnConnect = new Button("Connect");
		setLayout(new BorderLayout());
		JPanel pnlMessage = new JPanel();		
		pnlMessage.add(lblMessage);
		add(pnlMessage, BorderLayout.NORTH);
		JPanel pnlComSelect = new JPanel();
		pnlComSelect.add(cbPorts);
		pnlComSelect.add(btnConnect);
		add(pnlComSelect, BorderLayout.CENTER);		
	}
	public String getSelectedPort() {
		if (cbPorts.getSelectedItem()==null) {return "";}
		return cbPorts.getSelectedItem().toString();
	}
	public void addConnectListener(ActionListener ev) {
		btnConnect.addActionListener(ev);
	}
}
