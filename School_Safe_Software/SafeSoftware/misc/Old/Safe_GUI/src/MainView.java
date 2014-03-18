import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import skin.Button;


public class MainView extends JPanel{
	private static final long serialVersionUID = -1111147139303829760L;
	private SevenSegmentDisplay[] segments = {new SevenSegmentDisplay(),new SevenSegmentDisplay(), new SevenSegmentDisplay(), new SevenSegmentDisplay()};
	private Button btnDisconnect;
	private RotaryView pnlRotary;
	private JTextField tfPinOld, tfPinNew, tfPinConfirm;
	private Button btnPinApply;
	private JLabel lblStatus;
	private Button btnOpenClose;
	public MainView() {
		JPanel pnlSegment = new JPanel();
		pnlSegment.setLayout(new GridLayout(1, 4));
		pnlSegment.add(segments[0]);
		pnlSegment.add(segments[1]);
		pnlSegment.add(segments[2]);
		pnlSegment.add(segments[3]);
				
		pnlRotary = new RotaryView();
		btnDisconnect = new Button("Disconnect");
		
		setLayout(new BorderLayout());
		JPanel trPanel = new JPanel();
		trPanel.setLayout(new BorderLayout());
		trPanel.add(btnDisconnect, BorderLayout.NORTH);
		trPanel.add(pnlRotary, BorderLayout.CENTER);
		JPanel topPanel = new JPanel();
		topPanel.setLayout(new BorderLayout());
		topPanel.add(pnlSegment, BorderLayout.CENTER);
		topPanel.add(trPanel, BorderLayout.EAST);
		add(topPanel, BorderLayout.NORTH);
		//End top Panel

		JPanel pnlStatus = new JPanel();
		pnlStatus.setBorder(BorderFactory.createTitledBorder("Status"));
		JLabel lblStat = new JLabel("Status: ");
		lblStatus = new JLabel("closed");
		lblStatus.setForeground(Color.RED);
		btnOpenClose = new Button("Open");
		pnlStatus.setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		c.fill = GridBagConstraints.BOTH;
		c.insets = new Insets(2, 2, 2, 2);
		pnlStatus.add(lblStat, c);
		pnlStatus.add(lblStatus, c);
		c.gridy = 1;
		c.gridwidth = 2;
		pnlStatus.add(btnOpenClose, c);
		
		JPanel pnlPin = new JPanel();
		pnlPin.setBorder(BorderFactory.createTitledBorder("Change PIN"));
		pnlPin.setLayout(new GridBagLayout());
		GridBagConstraints gbcPin = new GridBagConstraints();
		gbcPin.fill = GridBagConstraints.BOTH;
		gbcPin.insets = new Insets(2, 2, 2, 2);
		JLabel lblPinOld = new JLabel("Old PIN: ");
		tfPinOld = new JTextField(10);
		JLabel lblPinNew = new JLabel("New PIN: ");
		tfPinNew = new JTextField(10);
		JLabel lblPinConfirm = new JLabel("Confirm PIN: ");
		tfPinConfirm = new JTextField(10);
		btnPinApply = new Button("Apply");

		pnlPin.add(lblPinOld, gbcPin);
		pnlPin.add(tfPinOld, gbcPin);
		gbcPin.gridy = 1;
		pnlPin.add(lblPinNew, gbcPin);
		pnlPin.add(tfPinNew, gbcPin);
		gbcPin.gridy = 2;
		pnlPin.add(lblPinConfirm, gbcPin);
		pnlPin.add(tfPinConfirm, gbcPin);
		gbcPin.gridy = 3;
		gbcPin.gridwidth = 2;
		pnlPin.add(btnPinApply, gbcPin);
		
		JPanel middlePanel = new JPanel();
		middlePanel.setLayout(new GridLayout(1, 2));
		middlePanel.add(pnlStatus);
		middlePanel.add(pnlPin);
		add(middlePanel);
		
	}
	void setStatus(boolean isOpen) {
		if (isOpen) {
			lblStatus.setText("open");
			lblStatus.setForeground(Color.GREEN);
			btnOpenClose.setText("Close");
		} else {
			lblStatus.setText("closed");
			lblStatus.setForeground(Color.RED);
			btnOpenClose.setText("Open");			
		}
	}
	String getStatus() {
		return lblStatus.getText();
	}
	public void setRotary(int mode) {
		pnlRotary.setRotary(mode);
	}
	public void setNum(int segment, int num) {
		segments[segment].setNum(num);
	}
	public void addDisconnectListener(ActionListener ev) {
		btnDisconnect.addActionListener(ev);
	}
	void addOpenCloseListener(ActionListener ev) {
		btnOpenClose.addActionListener(ev);
	}
}
