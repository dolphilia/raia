import Cocoa

class AppDelegate: NSObject, NSApplicationDelegate {
    var window: NSWindow!

    func applicationDidFinishLaunching(_ notification: Notification) {
        // ウィンドウの設定
        let screenSize = NSScreen.main?.frame.size ?? CGSize(width: 800, height: 600)
        window = NSWindow(
            contentRect: NSRect(x: screenSize.width / 4, y: screenSize.height / 4, width: 400, height: 300),
            styleMask: [.titled, .closable, .resizable],
            backing: .buffered,
            defer: false
        )
        window.title = "Swift macOS App"
        window.makeKeyAndOrderFront(nil)

        // ボタンの作成
        let button = NSButton(frame: NSRect(x: 150, y: 100, width: 100, height: 40))
        button.title = "クリック"
        button.target = self
        button.action = #selector(buttonClicked)

        // ウィンドウにボタンを追加
        window.contentView?.addSubview(button)
    }

    @objc func buttonClicked() {
        // モーダルダイアログの表示
        let alert = NSAlert()
        alert.messageText = "確認"
        alert.informativeText = "アプリケーションを終了しますか？"
        alert.alertStyle = .warning
        alert.addButton(withTitle: "はい")
        alert.addButton(withTitle: "いいえ")

        // ダイアログの結果を処理
        let response = alert.runModal()
        if response == .alertFirstButtonReturn { // "はい" ボタン
            NSApplication.shared.terminate(self)
        }
    }
}

// メイン関数
let app = NSApplication.shared
let delegate = AppDelegate()
app.delegate = delegate
app.run()