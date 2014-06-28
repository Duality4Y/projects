//package DummySerialPort;

//import gnu.io.*;
import java.io.*;
import java.util.*;

/**
 * Demo for using the DummySerialPort classes ( DummySerialPort, DummySerialPortEventListener, DummySerialPPortEvent)
 * When upgrading to using real Serial port, make sure you have the gnu/io pachage installed and change this source
 * You can get this at http://rxtx.org/
 * 
 * This demo inits DummySerialport, adds itself as a listener for it and asks to get an event on data available.
 * On the appearance of an even, the inputstream from the dummyserialport is read until no more chars are available;
 * 
 * @author Eelco Jannink for Saxion-CII
 */
public class Tester implements DummySerialPortEventListener {
	private DummySerialPort port;
	private InputStream input;
	
	public Tester() {
		port = new DummySerialPort(100);
		try {
			port.addEventListener( this );
		} catch ( TooManyListenersException e ) {}
		port.notifyOnDataAvailable( true );
		input = port.getInputStream();
				
	}
	
	/**
	 * event handling, according to DummySerialPortEventListener.
	 */
	public void serialEvent( DummySerialPortEvent event ) {		
		if ( event.getEventType() == DummySerialPortEvent.DATA_AVAILABLE ) {
			try {
				// read data
				boolean channel = true;
				while (input.available() > 0) {
					if(channel)
						System.out.print((char) input.read());
					else
						System.out.println((int) input.read());
					
					channel = !channel;
				} 
			} catch (IOException e) {
			}
		}
	}
	
	/**
	 * method for test purposes to monitor the stream in console for 10 seconds, should not be needed in a gui
	 */
	public void monitor( int time ) {
		try {
			Thread.sleep( time );
		} catch( Exception e ) {
			System.out.println( "Error: "+e );
		}
		port.stop(); // stop the thread bij getting out of the loop !
	}
	/**
	 * does a simple test... read the port for 10 seconds
	 */
	public static void main( String[] args ) {
		System.out.println("Starting");
		Tester tester = new Tester();
		tester.monitor( 10000 ); // see what happens during 10 secs
		System.out.println("Done");
		
	}
}

