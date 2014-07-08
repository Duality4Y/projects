import java.awt.*;

import javax.swing.*;
import java.awt.event.*;
public class Panel extends JPanel
{
    private Timer timer;
    private int xPoints[] = {310,390,390,310};
    private int yPoints[] = {600,600,440,440};
    private boolean gaatOpen = true;
    public Panel()
    {
        timer = new Timer(20, new TimerHandler());
        timer.start();
    }

    public void paintComponent(Graphics g) {
        tekenMuur(g);
    }

    class TimerHandler implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            if(gaatOpen == true) {
                xPoints[0]++;
                xPoints[3]++;
                yPoints[0]++;
                yPoints[3]++;
                repaint();
                if(xPoints[0]==410) {
                    gaatOpen = false;
                }
            }
            if(gaatOpen == false) {
                xPoints[0]--;
                xPoints[3]--;
                yPoints[0]--;
                yPoints[3]--;
                repaint();
                if(xPoints[0]==310) {
                    gaatOpen = true;
                }
            }
        }
    }

    public void tekenMuur(Graphics g) {
        g.setColor(Color.WHITE);
        g.fillRect(0,0,900,900); // de achtergrond
        g.setColor(Color.RED);
        g.fillRect(150,200,400,400); //het huis
        g.setColor(Color.YELLOW);
        g.fillRect(310,440,80,160); //de deuropening
        g.setColor(Color.BLACK);
        g.drawRect(310,440,80,160); //zwarte lijn om de deuropening
        g.drawRect(150,200,400,400); // zwarte lijn om het huis
        g.setColor(Color.LIGHT_GRAY);
        g.fillPolygon(xPoints,yPoints,4);
        g.setColor(Color.BLACK);
        g.drawPolygon(xPoints,yPoints,4);
        
    }
}
