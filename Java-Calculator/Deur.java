import java.util.*;
import javax.swing.*;
import java.awt.*;
public class Deur extends JFrame
{
    Panel mainPanel;
    public Deur()
    {
        mainPanel = new Panel();
        mainPanel.setLayout(null);
        mainPanel.setBackground(Color.WHITE);

        setContentPane(mainPanel);
    }
    
    public static void main( String args[] ) { 
        Deur frame = new Deur(); 
        frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE ); 
        frame.setSize( 700, 1200 ); 
        frame.setTitle( "Deur" ); 
        frame.setVisible( true ); 
    }
}
