package skin;
import java.awt.*;

import javax.swing.*;

public class Button extends JButton {

	/**
	 * 
	 */
	private static final long serialVersionUID = -7196363953902143443L;

	boolean makeDarker = false;
	public Button(String text){
        super(text);
        setContentAreaFilled(false);
        setFocusPainted(false); // disable painting focus :)
    }
	
	public Button(String text, boolean dark){
        super(text);
        makeDarker = true;
        setContentAreaFilled(false);
        setFocusPainted(false); // disable painting focus :)
    }

    @Override
    protected void paintComponent(Graphics g){
        Graphics2D g2 = (Graphics2D)g.create();
        if (makeDarker) {
	        g2.setPaint(new GradientPaint(
	                new Point(0, 0), 
	                new Color(229,229, 229), 
	                new Point(0, getHeight()), 
	                new Color(219,219, 219)));
        } else {
	        g2.setPaint(new GradientPaint(
	                new Point(0, 0), 
	                new Color(239,239, 239), 
	                new Point(0, getHeight()), 
	                new Color(229,229, 229)));
        }
        g2.fillRect(0, 0, getWidth(), getHeight());
        g2.dispose();

        super.paintComponent(g);
    }
}
