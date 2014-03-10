public class Main {

	public static void main(String[] args) {
		Serial serial = new Serial();
		View view = new View(serial);
		Control control = new Control(view, serial);
		view.setVisible(true);
		
	}

}
