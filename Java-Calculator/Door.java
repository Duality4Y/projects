import java.util.*;
import javax.swing.*;
import java.awt.*;
public class Door extends JFrame
{
    Panel mainPanel;
    public Door()
    {
        mainPanel = new Panel();
        mainPanel.setLayout(null);
        mainPanel.setBackground(Color.WHITE);

        setContentPane(mainPanel);
    }
    
    public static void main( String args[] ) { 
        Door frame = new Door(); 
        frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE ); 
        frame.setSize( 700, 1200 ); 
        frame.setTitle( "Door" ); 
        frame.setVisible( true ); 
    }
}
