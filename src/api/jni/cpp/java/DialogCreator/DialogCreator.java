// DialogCreator.java
import javax.swing.*;

public class DialogCreator {

    public static void showAlert() {
        java.awt.EventQueue.invokeLater(() -> {
            JOptionPane.showMessageDialog(null, "This is a warning message", "Warning", JOptionPane.WARNING_MESSAGE);
        });
    }

    // public static void main(String[] args) {
    //     showAlert();
    // }
}