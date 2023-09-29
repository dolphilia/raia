import javax.swing.*;
import java.lang.reflect.InvocationTargetException;

public class SwingWindow {

    public static void createWindow() {
        System.out.println("createWindow method called");
        //try {
            SwingUtilities.invokeLater(new Runnable() {
                public void run() {
                    JFrame frame = new JFrame("Swing Window");
                    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    frame.setSize(300, 200);
                    frame.setVisible(true);
                }
            });
        //} catch (InterruptedException | InvocationTargetException e) {
        //    e.printStackTrace();
        //}
    }

    // public static void main(String[] args) {
    //     createWindow();
    // }
}



