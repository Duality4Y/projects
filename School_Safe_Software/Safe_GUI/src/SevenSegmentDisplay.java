import java.awt.*;

import javax.swing.*;
import javax.swing.border.EmptyBorder;


public class SevenSegmentDisplay extends JPanel{
	private static final long serialVersionUID = 6390935633488407379L;
	private int number;
	private Panel segA, segB, segC, segD, segE, segF, segG;
	public SevenSegmentDisplay() {
		segA = new Panel(new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("segA.png"))).getImage());
		segB = new Panel(new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("segB.png"))).getImage());
		segC = new Panel(new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("segC.png"))).getImage());
		segD = new Panel(new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("segD.png"))).getImage());
		segE = new Panel(new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("segE.png"))).getImage());
		segF = new Panel(new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("segF.png"))).getImage());
		segG = new Panel(new ImageIcon(Toolkit.getDefaultToolkit().getImage(getClass().getResource("segG.png"))).getImage());
		setLayout(new GridBagLayout());
		setNum(0);
		GridBagConstraints c = new GridBagConstraints();
		
		add(new JPanel());
		add(segA);
		add(new JPanel());		
		c.gridy = 1;
		add(segF, c);
		add(new JPanel(), c);
		add(segB, c);
		c.gridy = 2;
		add(new JPanel(), c);
		add(segG, c);
		add(new JPanel(), c);
		c.gridy = 3;
		add(segE, c);
		add(new JPanel(), c);
		add(segC, c);
		c.gridy = 4;
		add(new JPanel(), c);
		add(segD,c);
		add(new JPanel(), c);
	}
	int getNum() {
		return number;
	}
	void setNum(int num) {
		number = num;
		switch(num) {
		case 0:
			repaintSegment(true, true, true, true, true, true, false);
			break;
		case 1:
			repaintSegment(false, true, true, false, false, false, false);
			break;
		case 2:
			repaintSegment(true, true, false, true, true, false, true);
			break;
		case 3:
			repaintSegment(true, true, true, true, false, false, true);
			break;
		case 4:
			repaintSegment(false, true, true, false, false, true, true);
			break;
		case 5:
			repaintSegment(true, false, true, true, false, true, true);
			break;
		case 6:
			repaintSegment(true, false, true, true, true, true, true);
			break;
		case 7:
			repaintSegment(true, true, true, false, false, false, false);
			break;
		case 8:
			repaintSegment(true, true, true, true, true, true, true);
			break;
		case 9:
			repaintSegment(true, true, true, true, false, true, true);
			break;
		}
	}
	void repaintSegment(boolean segA, boolean segB, boolean segC, boolean segD, boolean segE, boolean segF, boolean segG) {
		this.segA.clear(!segA);
		this.segA.repaint();
		this.segB.clear(!segB);
		this.segB.repaint();
		this.segC.clear(!segC);
		this.segC.repaint();
		this.segD.clear(!segD);
		this.segD.repaint();
		this.segE.clear(!segE);
		this.segE.repaint();
		this.segF.clear(!segF);
		this.segF.repaint();
		this.segG.clear(!segG);
		this.segG.repaint();
	}
	class Panel extends JPanel {
		private Image img;
		private boolean erasePaint;
		public Panel(Image img) {
			this.img = img;
		    Dimension size = new Dimension(img.getWidth(null), img.getHeight(null));
		    setPreferredSize(size);
		    setMinimumSize(size);
		    setMaximumSize(size);
		    setSize(size);
		    setLayout(new BorderLayout());
		    setBorder(new EmptyBorder(12, 10, 10, 10) );
		}
		public void clear(boolean doClear) {
			erasePaint = doClear;
		}
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			if (!erasePaint) {
			    g.drawImage(img, 0, 0, null);				
			}
		}
	}
}
