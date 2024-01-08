import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.awt.Color;
import java.awt.Graphics;

public class appletinput1 extends Applet implements ActionListener {
    Image picture;  
    TextField t1 = new TextField(20);
    TextField t2 = new TextField(20);
    TextField t3 = new TextField(20);
    TextField t4 = new TextField(20);
    Label l1 = new Label("Enter the percentage of foam loss per day");
    Label l2 = new Label("Enter threshold percentage");
    Label l3 = new Label("Weeks");
    Label l4 = new Label("Remaining days");
    Button b = new Button("Calculate");

    int weeks;
    int remainingDays;

    public void init() {
	 picture = getImage(getDocumentBase(),"java.png"); 
	 setSize(picture.getWidth(this), picture.getHeight(this));
        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(l3);
        add(t3);
        add(l4);
        add(t4);
        add(b);
        b.addActionListener(this);
    }	  public void paint(Graphics g) {  
    g.drawImage(picture,0,0,getWidth(),getHeight(),this);  
  }  

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b) {
            double d1 = Double.parseDouble(t1.getText());
            double d2 = Double.parseDouble(t2.getText());
            double foamRemaining = 100.0;
            int days = 0;

            while (foamRemaining > d2) {
                foamRemaining -= foamRemaining * (d1 / 100);
                days++;
            }

            weeks = days / 7;
            remainingDays = days % 7;
            t3.setText(Integer.toString(weeks));
            t4.setText(Integer.toString(remainingDays));
            repaint();
        }
    }
}

/*
<applet code="appletinput1" width=300 height=100>
</applet>
*/