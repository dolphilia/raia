import java.awt.Frame;

public class WindowCreator {
    public static void main(String[] args) {
        createWindow();
    }

    public static void createWindow() {
        java.awt.EventQueue.invokeLater(() -> {
            Frame frame = new Frame("AWT Window");
            frame.setSize(300, 300);
            frame.setVisible(true);
        });
    }
}