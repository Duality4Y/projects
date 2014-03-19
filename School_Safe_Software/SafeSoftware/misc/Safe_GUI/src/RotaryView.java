import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;

import javax.swing.*;
import javax.swing.border.EmptyBorder;


public class RotaryView extends JPanel{
	/**
	 * 
	 */
	private static final long serialVersionUID = -6327311837795109961L;
	public final static int NORMAL = 0;
	public final static int LEFT = 1;
	public final static int RIGHT = 2;
	
	private Image imgRot, imgRotLeft, imgRotRight;
	private int mode;

	public RotaryView() {
		imgRot = new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("Rotary/rot.png"))).getImage();
		imgRotLeft = new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("Rotary/rotLeft.png"))).getImage();
		imgRotRight = new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("Rotary/rotRight.png"))).getImage();
	    Dimension size = new Dimension(imgRot.getWidth(null), imgRot.getHeight(null));
	    setPreferredSize(size);
	    setMinimumSize(size);
	    setMaximumSize(size);
	    setSize(size);
	    setLayout(new BorderLayout());
	    setBorder(new EmptyBorder(12, 10, 10, 10) );
	}
	public void setRotary(int mode) {
		this.mode = mode;
		repaint();
	}
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		if (mode==NORMAL) {
			g.drawImage(imgRot,0,0,null);
		} else if (mode==LEFT) {
			g.drawImage(imgRotLeft,0,0,null);			
		} else if (mode==RIGHT) {
			g.drawImage(imgRotRight,0,0,null);			
		}
	}
}
