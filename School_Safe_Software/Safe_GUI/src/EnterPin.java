import java.awt.BorderLayout;
import java.awt.event.ActionListener;

import javax.swing.*;

import skin.Button;


public class EnterPin extends JPanel{

	/**
	 * 
	 */
	private static final long serialVersionUID = 8147142734240553813L;
	private JTextField tfPin;
	private Button btnVerify;
	EnterPin() {
		JLabel lblMessage = new JLabel("Enter PIN:");
		btnVerify = new Button("Verify");
		tfPin = new JTextField(10);
		setLayout(new BorderLayout());
		JPanel pnlMessage = new JPanel();		
		pnlMessage.add(lblMessage);
		add(pnlMessage, BorderLayout.NORTH);
		JPanel pnlComSelect = new JPanel();
		pnlComSelect.add(tfPin);
		pnlComSelect.add(btnVerify);
		add(pnlComSelect, BorderLayout.CENTER);		
	}
	public String getPin() {
		return tfPin.getText();
	}
	public void addVerifyListener(ActionListener ev) {
		btnVerify.addActionListener(ev);
	}
}
