import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.awt.Color;
import java.awt.Graphics;

public class appletinput extends Applet implements ActionListener {
    Image picture;
    TextField t1 = new TextField(20);
    TextField t2 = new TextField(20);
    TextField t3 = new TextField(20);
    TextField t4 = new TextField(20);
    Label heading = new Label("Foam Loss Calculator");
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
        setLayout(new GridLayout(0, 2, 500, 150));
        Panel centeringPanel = new Panel(new FlowLayout(FlowLayout.CENTER));
        heading.setFont(new Font("Arial", Font.BOLD, 35)); 
        heading.setForeground(Color.BLUE);
        heading.setAlignment(Label.CENTER); 
        centeringPanel.add(heading);
        add(centeringPanel);
        add(new Label("")); 
        l1.setFont(new Font("Helvetica", Font.BOLD, 24)); 
        l1.setForeground(Color.BLACK);
        l1.setAlignment(Label.CENTER);
        centeringPanel.add(l1);
        add(centeringPanel);

        l2.setFont(new Font("Helvetica", Font.BOLD, 24)); 
        l2.setForeground(Color.BLACK);
        l2.setAlignment(Label.CENTER);
        centeringPanel.add(l2);
        add(centeringPanel);

        l3.setFont(new Font("Helvetica", Font.BOLD, 24)); 
        l3.setForeground(Color.BLACK);
        l3.setAlignment(Label.CENTER);
        centeringPanel.add(l3);
        add(centeringPanel);

        l4.setFont(new Font("Helvetica", Font.BOLD, 24)); 
        l4.setForeground(Color.BLACK);
        l4.setAlignment(Label.CENTER);
        centeringPanel.add(l4);
        add(centeringPanel);
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
    }
    public void paint(Graphics g) {  
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
<applet code="appletinput" width=300 height=100>
</applet>
*/