/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package atob;

import java.awt.BorderLayout;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

/**
 *
 * @author Andreas
 */
public class MainFrame extends JFrame{
    WindowAdapter myWA = new WindowAdapter() {
            @Override
            public void windowClosing ( WindowEvent e ) { 
                System.exit( 0 );
            }
        };
    {
        setSize( 250, 150 );
        addWindowListener(myWA);
    }    
    AtoBFrame atob = new AtoBFrame();{
        atob.setVisible(true);
        atob.setSize(500, 500);
        atob.addWindowListener(myWA);
        
        atob.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                atob.p[firstSecond.isSelected() ? 0 : 1].set(e.getX(), e.getY());
                atob.repaint();
            }
        });
    }
    JSlider slider0 = new JSlider(0,360,0);{
        slider0.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                atob.p[0].angle = Math.toRadians(slider0.getValue());
                atob.repaint();
            }
        });
    }
    JSlider slider1 = new JSlider(0,360,0);{
        slider1.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                atob.p[1].angle = Math.toRadians(slider1.getValue());
                atob.repaint();
            }
        });
    }
    JCheckBox firstSecond = new JCheckBox("first / second");
    JPanel mainPanel = new JPanel();{
        getContentPane().add(mainPanel);
        mainPanel.add(slider0);
        mainPanel.add(slider1);
        mainPanel.add(firstSecond);
    }
    public MainFrame(){
        Point p = atob.getLocation();
        p.move(atob.getWidth(), 0);
        setLocation(p);
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        new MainFrame().setVisible(true);
    }
}
