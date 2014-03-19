
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.TooManyListenersException;

import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

public class Serial{

	SerialPort serialPort;
    /** The port we're normally going to use. */
	/**
* A BufferedReader which will be fed by a InputStreamReader 
* converting the bytes into characters 
* making the displayed results codepage independent
*/
private BufferedReader input;
/** The output stream to the port */
private OutputStream output;
/** Milliseconds to block while waiting for port open */
private static final int TIME_OUT = 5000;
/** Default bits per second for COM port. */
private static final int DATA_RATE = 38400;
private boolean verify;
	public Serial() {	
	}
	
	@SuppressWarnings("rawtypes")
	public boolean Connect(String portName) {
		CommPortIdentifier portId = null;
		Enumeration portEnum = CommPortIdentifier.getPortIdentifiers();

		//First, Find an instance of serial port as set in PORT_NAMES.
		while (portEnum.hasMoreElements()) {
			CommPortIdentifier currPortId = (CommPortIdentifier) portEnum.nextElement();
			if (portName.equals(currPortId.getName())) {
				portId = currPortId;
				break;
			}
		}
		if (portId == null) {
			System.out.println("Could not find COM port.");
			return false;
		}

		try {
			// open serial port, and use class name for the appName.
			serialPort = (SerialPort) portId.open(this.getClass().getName(),
					TIME_OUT);

			// set port parameters
			serialPort.setSerialPortParams(DATA_RATE, SerialPort.DATABITS_8, SerialPort.STOPBITS_1,	SerialPort.PARITY_NONE);
			serialPort.enableReceiveTimeout(1000);
			serialPort.enableReceiveThreshold(0);
			// open the streams
			input = new BufferedReader(new InputStreamReader(serialPort.getInputStream()));
			output = serialPort.getOutputStream();

			// add event listeners
			serialPort.notifyOnDataAvailable(true);
			return true;
		} catch (Exception e) {
			if (e.getClass().toString().equals("class gnu.io.PortInUseException" )) {
				System.out.println("PORT IS IN USE");
			} else {
				System.err.println(e.toString());			
			}
		}
		return false;
	}
	public void close() {
		serialPort.close();getClass();
		try {
			input.close();
			output.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	public void setVerified(boolean verify) {
		this.verify = verify;
	}
	public boolean getVerified() {
		return verify;
	}
	public static void main(String[] args) {
		Serial main = new Serial();
		//main.initialize();
		Thread t=new Thread() {
			public void run() {
				//the following line will keep this app alive for 1000 seconds,
				//waiting for events to occur and responding to them (printing incoming messages to console).
				try {Thread.sleep(1000000);} catch (InterruptedException ie) {}
			}
		};
		t.start();
		System.out.println("Started");
	}
	
	public String read() {
		try {
			return input.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			//e.printStackTrace();
		}
		return "";
	}
	public void write(String message) {
		try {
			output.write(message.getBytes());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	int mode = 1;
	public void addEventListener(SerialPortEventListener ev) {
		try {
			serialPort.addEventListener(ev);
		} catch (TooManyListenersException e) {
			e.printStackTrace();
		}
	}
	public ArrayList<String> getPorts() {
		ArrayList<String> ports = new ArrayList<String>();
		Enumeration portEnum = CommPortIdentifier.getPortIdentifiers();

		//First, Find an instance of serial port as set in PORT_NAMES.
		while (portEnum.hasMoreElements()) {
			CommPortIdentifier currPortId = (CommPortIdentifier) portEnum.nextElement();
			ports.add(currPortId.getName());
		}
		return ports;
	}
}
