local ffi = require("ffi")
local gl = require("modules/bindings/gles")
local glfw = require("modules/bindings/glfw")
local skia = require("modules/bindings/skia")
local prim = require("modules/primitive")
local System = require("modules/raia/system")

--

if glfw.init() == 0 then
    error("Failed to initialize GLFW")
end

glfw.windowHint(glfw.CLIENT_API, glfw.OPENGL_ES_API)
glfw.windowHint(glfw.CONTEXT_VERSION_MAJOR, 3)
glfw.windowHint(glfw.CONTEXT_VERSION_MINOR, 0)
glfw.windowHint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)
glfw.windowHint(glfw.CONTEXT_CREATION_API, glfw.EGL_CONTEXT_API)
glfw.windowHint(glfw.VISIBLE, glfw.FALSE)

--

local Raia = {}
Raia.audio = {}
Raia.data = {}
Raia.event = {}
Raia.filesystem = {}
Raia.font = {}
Raia.graphics = {}
Raia.image = {}
Raia.joystick = {}
Raia.keyboard = {}
Raia.math = {}
Raia.mouse = {}
Raia.physics = {}
Raia.sound = {}
Raia.system = {}
Raia.thread = {}
Raia.timer = {}
Raia.touch = {}
Raia.video = {}
Raia.window = {}
Raia.window.id = glfw.createWindow(500, 500, "Untitled")
Raia.window.width = 500
Raia.window.height = 500
Raia.window.title = "Untitled"
Raia.window.visible = false

-- Raia.audio

--- 現在有効なエフェクト名のリストを取得します。
function Raia.audio.getActiveEffects()
end
--- 現在同時再生中の Source の本数を取得します。
function Raia.audio.getActiveSourceCount()
end
--- 減衰距離モデルを返します。
function Raia.audio.getDistanceModel()
end
--- ドップラー効果に対する大域基準化係数を取得します。
function Raia.audio.getDopplerScale()
end
--- エフェクト関連の設定を取得します。
function Raia.audio.getEffect()
end
--- システムで対応しているエフェクトの最大使用可能数を取得します。
function Raia.audio.getMaxSceneEffects()
end
--- Source ごとに使用可能な最大エフェクト数を取得します。
function Raia.audio.getMaxSourceEffects()
end
--- （廃止）現在同時再生中の Source の本数を取得します。
function Raia.audio.getNumSources()
end
--- リスナーの方向を返します。
function Raia.audio.getOrientation()
end
--- リスナーの座標を返します。
function Raia.audio.getPosition()
end
--- システムに接続されている録音機器のリストを取得します。
function Raia.audio.getRecordingDevices()
end
--- （非推奨）現在同時再生中の Source の本数を取得します。
function Raia.audio.getSourceCount()
end
--- リスナーの速度を返します。
function Raia.audio.getVelocity()
end
--- 主音量を取得します。
function Raia.audio.getVolume()
end
--- システムにおける音声エフェクトの対応の有無を取得します。
function Raia.audio.isEffectsSupported()
end
--- Source:queue でのリアルタイム生成音声の再生用に Source を新規作成します。
function Raia.audio.newQueueableSource()
end
--- ファイルパス, File, Decoder または SoundData から Source を新規作成します。	
function Raia.audio.newSource()
end
--- 指定、または全ての Source の再生を一時停止します。
function Raia.audio.pause()
end
--- 指定された Source を再生します。
function Raia.audio.play()
end
--- （廃止）音声の再生を全て再開します。
function Raia.audio.resume()
end
--- （廃止）再生中の音声を全てを巻き戻します。
function Raia.audio.rewind()
end
--- 減衰距離モデルを設定します。
function Raia.audio.setDistanceModel()
end
--- ドップラー効果に対する大域基準化係数を設定します。
function Raia.audio.setDopplerScale()
end
--- Source で使うエフェクトを定義します。
function Raia.audio.setEffect()
end
--- システムのオーディと音声をミキシングするかどうかシステムを設定します。
function Raia.audio.setMixWithSystem()
end
--- リスナーの方向を設定します。
function Raia.audio.setOrientation()
end
--- リスナーの座標を設定します。
function Raia.audio.setPosition()
end
--- リスナーの速度を設定します。
function Raia.audio.setVelocity()
end
--- 主音量を設定します。
function Raia.audio.setVolume()
end
--- 現在再生中の Source を停止します。
function Raia.audio.stop()
end

-- Raia.data

--- 指定の圧縮アルゴリズムで文字列またはデータを圧縮します。
function Raia.data.compress()
end
--- EncodeFormat 形式の Data または文字列から Data または文字列をデコードします。
function Raia.data.decode()
end
--- CompressedData または以前に圧縮した文字列か Dataオブジェクトを展開します。
function Raia.data.decompress()
end
--- EncodeFormat 形式の Data または文字列から Data または文字列をエンコードします。
function Raia.data.encode()
end
--- Raia.data.pack で指定された形式が使用しているデータの大きさをバイト単位で取得します。
function Raia.data.getPackedSize()	
end
--- 指定されたハッシュアルゴリズムでメッセージダイジェスト文字列を算出します。
function Raia.data.hash()
end
--- 任意長のバイトから構成される Data オブジェクトを新規作成します。
function Raia.data.newByteData()
end
--- 既存 Data オブジェクトのサブセクションを参照する新規 Data を作成します。
function Raia.data.newDataView()
end
--- Lua 値をパック (シリアライズ) します。
function Raia.data.pack()
end
--- バイト文字列、または Data にある Lua 値をアンパック (デシリアライズ) します。
function Raia.data.unpack()
end

-- Raia.event

--- イベントキューを消去します。
function Raia.event.clear()
end
--- イベントキューにあるメッセージに対してイテレーターを返します。
function Raia.event.poll()
end
--- イベントキューへイベントを汲み出します。
function Raia.event.pump()
end
--- イベントキューへイベントを追加します。
function Raia.event.push()
end
-- Raiaプログラムを終了、または再起動します。
function Raia.event.quit()
end
--- Raia.event.poll() と似ていますが、イベントキューにイベントがあるまで阻止します。
function Raia.event.wait()
end 

-- Raia.filesystem

--- 既存ファイルへデータを追記します。
function Raia.filesystem.append(name, data, size)
    local file, err = io.open(filename, "a")
    if not file then
        return false, err
    end
    file:write(data)
    file:close()
    return true
end
--- Raia.filesystem がシンボリック・リンクを辿るかどうかを取得します。
function Raia.filesystem.areSymlinksEnabled()
end
--- ディレクトリを再帰的に作成します。
function Raia.filesystem.createDirectory()
end
--- （廃止）ディレクトリにある全てのファイルおよびサブディレクトリを返します。
function Raia.filesystem.enumerate()
end
--- （非推奨）ファイルまたはディレクトリの存在を確認します。
function Raia.filesystem.exists()
end
--- アプリケーションのデータディレクトリを返します (getUserDirectory と同じ場合があります)
function Raia.filesystem.getAppdataDirectory()
end
--- require が呼び出されたときに C ライブラリを検索するためのファイルシステムのパスを取得します。
function Raia.filesystem.getCRequirePath()
end
--- ディレクトリにある全てのファイルおよびサブディレクトリを返します。
function Raia.filesystem.getDirectoryItems()
end
--- ゲームの書き込み先のディレクトリ名を取得します。
function Raia.filesystem.getIdentity()
end
--- 指定されたファイル、またはディレクトリに関する情報を取得します。
function Raia.filesystem.getInfo()
end
--- （非推奨）ファイルの最終更新時刻を取得します。
function Raia.filesystem.getLastModified()
end
--- ファイルパスがあるディレクトリの絶対パスを取得します。
function Raia.filesystem.getRealDirectory()
end
--- require が呼ばれた時に検索されるファイルシステムのパスを取得します。
function Raia.filesystem.getRequirePath()
end
--- 明示されたセーブ・ディレクトリのフルパスを取得します。
function Raia.filesystem.getSaveDirectory()
end
--- （非推奨）ファイルの大きさをバイトで取得します。
function Raia.filesystem.getSize()
end
--- .love ファイルのあるディレクトリのフルパスを返します。
function Raia.filesystem.getSourceBaseDirectory() 
end
--- 利用者のディレクトリのパスを返します。	
function Raia.filesystem.getUserDirectory()	
end
--- 現在の作業ディレクトリを取得します。
function Raia.filesystem.getWorkingDirectory()
end
--- Raia.filesystem を初期化しますが、これはシステム内部で呼ばれるものであるため、明示的に使用しないでください。	
function Raia.filesystem.init()	
end
--- （非推奨）対象がディレクトリかどうか確認します。
function Raia.filesystem.isDirectory()
end
--- （非推奨）対象がファイルかどうか確認します。
function Raia.filesystem.isFile()
end
--- 結合型実行形式で動作しているゲームであるかどうかを取得します。
function Raia.filesystem.isFused()	
end
--- （非推奨）ファイルパスが本当にシンボリック・リンクであるかどうかを取得します。
function Raia.filesystem.isSymlink()
end
--- ファイルの最終行までイテレート(反復)します。
function Raia.filesystem.lines()		
end
--- lua ファイルを読み込みます (が実行はしません)。	
function Raia.filesystem.load()	
end
--- （廃止）再帰的にディレクトリを作成します。
function Raia.filesystem.mkdir()
end
--- ゲームのセーブ・ディレクトリで読み取るために zip ファイルまたはフォルダをマウント（装着）します。
function Raia.filesystem.mount()
end
--- File オブジェクトを新規作成します。
function Raia.filesystem.newFile()
end
--- FileData オブジェクトを新規作成します。
function Raia.filesystem.newFileData()
end
--- ファイルの内容を読み込みます。
function Raia.filesystem.read()
end
--- ファイルを削除します (またはディレクトリ)。	
function Raia.filesystem.remove()	
end
--- require が呼び出されたときに C ライブラリを検索するためのファイルシステムのパスを設定します。
function Raia.filesystem.setCRequirePath()
end
--- ゲームの書き込み先ディレクトリを設定します。
function Raia.filesystem.setIdentity()
end
--- require が呼ばれた時に検索されるファイルシステムのパスを設定します。
function Raia.filesystem.setRequirePath()
end
--- ゲームのソースとして、どこにコードが存在するのかを設定します。	
function Raia.filesystem.setSource()	
end
--- Raia.filesystem がシンボリック・リンクを辿るように設定します。
function Raia.filesystem.setSymlinksEnabled()
end
--- 以前に Raia.filesystem.mount で読み取るためにマウントした zip ファイルまたはフォルダをアンマウント(脱着)します。
function Raia.filesystem.unmount()
end
--- ファイルへデータを書き込みます。
function Raia.filesystem.write()
end

-- Raia.font

--- BMFont のラスタライザを新規作成します。
function Raia.font.newBMFontRasterizer()
end
--- （廃止）FontData の新規作成。
function Raia.font.newFontData()
end
--- GlyphData の新規作成。
function Raia.font.newGlyphData()
end
--- Rasterizer の新規作成。
function Raia.font.newRasterizer()
end
--- TrueType ラスタライザの新規作成。
function Raia.font.newTrueTypeRasterizer()
end

-- Raia.graphics

--- 円弧を描画します。
function Raia.graphics.arc()
end
--- 円を描画します。
function Raia.graphics.circle()
end
--- 画面または有効な Canvas を指定色で消去します。
function Raia.graphics.clear()		
end
--- 画面または有効な Canvas の内容を廃棄 (破壊) します。
function Raia.graphics.discard()
end
--- オブジェクトを画面へ描画します。
function Raia.graphics.draw()	
end
--- アレイ・テクスチャをレイヤに描画します。
function Raia.graphics.drawLayer()
end
--- （廃止）指定された画像を使って Quad を画面へ描画します。
function Raia.graphics.drawq()
end
--- 楕円を描画します。
function Raia.graphics.ellipse()
end
--- 自動バッチ描画が行われたときにレンダリング処理を即時実行します。
function Raia.graphics.flushBatch()
end
--- 線分を描画します。
function Raia.graphics.line()
end
--- （廃止）点を描画します。
function Raia.graphics.point()
end
--- 一つ以上の点を描画します。
function Raia.graphics.points()
end
--- 多角形を描画します。
function Raia.graphics.polygon()
end
--- 画面への描画操作結果を表示します。
function Raia.graphics.present()
end
--- 画面へテキストを描画します。 Font を設定していない場合、必要ならば(一括で)作成と設定をしてください。	
function Raia.graphics.print()
end
--- 語句の折り返しと整列を行い、整形したテキストを描画します。
function Raia.graphics.printf()
end
--- （廃止）四辺形の形状を描きます。
function Raia.graphics.quad()
end
--- 長方形を描画します。
function Raia.graphics.rectangle()
end
--- ステンシルとして幾何学的形状を描きます。
function Raia.graphics.stencil()
end
--- （廃止）三角形の描画。
function Raia.graphics.triangle()
end

-- Raia.image

--- CompressedImageData としてファイルを読み込むことができるかどうか決定します。
function Raia.image.isCompressed()
end
--- 圧縮された画像ファイルから CompressedImageData オブジェクトを新規作成します。
function Raia.image.newCompressedData()
end
--- ImageData をエンコードします。
function Raia.image.newEncodedImageData()
end
--- ImageData オブジェクトを新規作成します。
function Raia.image.newImageData()
end

-- Raia.joystick

--- （廃止）ジョイスティックを閉じます。
function Raia.joystick.close()
end
--- （廃止）各軸の方向を返します。
function Raia.joystick.getAxes()
end
--- （廃止）軸の方向を返します。
function Raia.joystick.getAxis()
end
--- （廃止）ボールの座標変更を返します。
function Raia.joystick.getBall()
end
--- 指定された GUID を有する Joystick (ジョイスティック) に関するゲームパッドのマッピング文字列を完全取得します。 nil の場合は指定の GUID でゲームパッドは認識されていません。
function Raia.joystick.getGamepadMappingString()
end
--- （廃止）ハットの方向を返します。
function Raia.joystick.getHat()
end
--- 接続されているジョイスティックの台数を取得します。
function Raia.joystick.getJoystickCount()
end
--- 接続されているジョイスティックの一覧を取得します。
function Raia.joystick.getJoysticks()
end
--- （廃止）ジョイスティックの機器名を取得します。
function Raia.joystick.getName()
end
--- （廃止）ジョイスティックに実装されている軸の個数を取得します。
function Raia.joystick.getNumAxes()
end
--- （廃止）ジョイスティックに実装されているボタンの個数を取得します。
function Raia.joystick.getNumButtons()
end
--- （廃止）ジョイスティックに実装されているハットの個数を返します。
function Raia.joystick.getNumHats()
end
--- （廃止）利用可能なジョイスティックの台数を返します。
function Raia.joystick.getNumJoysticks()
end
--- （廃止）ジョイスティックのボタンが押されているか確認します。
function Raia.joystick.isDown()
end
--- （廃止）ジョイスティックの使用状況を確認します。
function Raia.joystick.isOpen()
end
--- ゲームパッド・マッピングを読み込みます。
function Raia.joystick.loadGamepadMappings()
end
--- （廃止）ジョイスティックを使用開始します。
function Raia.joystick.open()
end
--- 仮想ゲームパッド・マッピングを保存します。
function Raia.joystick.saveGamepadMappings()
end
--- ボタン、軸またはハットを仮想ゲームパッドの入力へ割り当てます。
function Raia.joystick.setGamepadMapping()
end

-- Raia.keyboard

--- 指定されたハードウェア・スキャンコードに対してキーを対応させます。
function Raia.keyboard.getKeyFromScancode()
end
--- （廃止）キーリピートにおける遅延と間隔の値を返します。
function Raia.keyboard.getKeyRepeat()
end
--- 指定されたキーに対してハードウェア・スキャンコードを対応させます。
function Raia.keyboard.getScancodeFromKey()
end
--- キーリピートが有効であるかどうか取得します。
function Raia.keyboard.hasKeyRepeat()
end
--- スクリーンキーボードの対応状況を取得します。
function Raia.keyboard.hasScreenKeyboard()
end
--- テキスト入力イベントが有効であるかどうか取得します。
function Raia.keyboard.hasTextInput()
end
--- 特定のキーが押されたかどうか検出します。	
function Raia.keyboard.isDown()	
end
--- 指定されたスキャンコードが押されたかどうか確認します。
function Raia.keyboard.isScancodeDown()
end
--- Rave.keypressed に対するキーリピートを有効または無効にします。デフォルト値では無効です。	
function Raia.keyboard.setKeyRepeat()	
end
--- テキスト入力イベントを有効または無効にします。
function Raia.keyboard.setTextInput()
end

-- Raia.math

--- 色の範囲を 0..1 から 0..255 へ変換します。
function Raia.math.colorFromBytes()
end
--- 色の範囲を 0..1 から 0..255 へ変換します。
function Raia.math.colorToBytes()
end
--- （非推奨）指定の圧縮アルゴリズムで文字列またはデータを圧縮します。
function Raia.math.compress()
end
--- （非推奨）CompressedData または以前に圧縮された文字列あるいは Data オブジェクトを展開します。
function Raia.math.decompress()
end
--- ガンマ空間 (sRGB) から線形空間 (RGB) へ色変換します。
function Raia.math.gammaToLinear()
end
--- 乱数生成器の種を取得します。
function Raia.math.getRandomSeed()
end
--- 乱数生成器における現在の状態を取得します。
function Raia.math.getRandomStat()
end
--- 凸面の多角形かどうか確認します。
function Raia.math.isConvex()
end
--- 線形空間 (RGB) からガンマ空間 (sRGB) へ色変換します。
function Raia.math.linearToGamma()
end
--- BezierCurve オブジェクトの新規作成。
function Raia.math.newBezierCurve()
end
--- RandomGenerator オブジェクトの新規作成。
function Raia.math.newRandomGenerator()
end
--- Transform オブジェクトの新規作成。
function Raia.math.newTransform()
end
--- １～４次元によるシンプレックスまたはパーリンノイズの値を生成します。	
function Raia.math.noise()
end
--- 一様分布による疑似乱数の整数を取得します。
function Raia.math.random()
end
--- 正規分布による疑似乱数を取得します。
function Raia.math.randomNormal()
end
--- 乱数生成器の種を設定します。
function Raia.math.setRandomSeed()
end
--- 乱数生成器における現在の状態を設定します。
function Raia.math.setRandomState()
end
--- 単一の多角形を三角形へ分解します。
function Raia.math.triangulate()
end

-- Raia.mouse

--- 現在のカーソルを取得します。
function Raia.mouse.getCursor()
end
--- マウスの現在座標を返します。
function Raia.mouse.getPosition()
    return glfw.getCursorPos(Raia.window.id)
end
--- マウスに対する相対方式が有効かどうかを取得します。
function Raia.mouse.getRelativeMode()
end
--- システムで提供されているハードウェアカーソルを Cursor オブジェクトとして取得します。
function Raia.mouse.getSystemCursor()
end
--- マウスの現在の X 位置を返します。
function Raia.mouse.getX()
    local mouse_x, mouse_y = glfw.getCursorPos(Raia.window.id)
    return mouse_x
end
--- マウスの現在の Y 位置を返します。
function Raia.mouse.getY()
    local mouse_x, mouse_y = glfw.getCursorPos(Raia.window.id)
    return mouse_y
end
--- （廃止）カーソルの機能性に対応しているかどうかを取得します。
function Raia.mouse.hasCursor()
end
--- カーソルの機能に関する対応状況を取得します。
function Raia.mouse.isCursorSupported()
end
--- 特定のマウスボタンが押されたかどうか検出します。	
function Raia.mouse.isDown()
end
--- マウスが捕獲されているか確認します。	
function Raia.mouse.isGrabbed()
end
--- カーソルが表示されているか確認します。		
function Raia.mouse.isVisible()
end
--- ハードウェア Cursor オブジェクトを画像から作成します。
function Raia.mouse.newCursor()
end
--- 現在のマウスカーソルを設定します。
function Raia.mouse.setCursor()
end
--- （廃止）マウスを捕獲してからウィンドウ内に閉じこめて移動制限をします。
function Raia.mouse.setGrab()
end
--- マウスを捕獲してからウィンドウ内に閉じこめて移動制限をします。
function Raia.mouse.setGrabbed()
end
--- マウスの現在位置を設定します。
function Raia.mouse.setPosition(x, y)
    glfw.setCursorPos(Raia.window.id, x, y)
end
--- マウスの相対方式を有効にするかどうかを設定します。
function Raia.mouse.setRelativeMode()
end
--- 現在のカーソルにおける可視性を設定します。
function Raia.mouse.setVisible()
end
--- マウスの現在の X 位置を設定します。
function Raia.mouse.setX(x)
    local mouse_x, mouse_y = glfw.getCursorPos(Raia.window.id)
    glfw.setCursorPos(Raia.window.id, x, mouse_y)
end
--- マウスの現在の Y 位置を設定します。
function Raia.mouse.setY(y)
    local mouse_x, mouse_y = glfw.getCursorPos(Raia.window.id)
    glfw.setCursorPos(Raia.window.id, mouse_x, y)
end

-- Raia.physics

--- 二つの取付具およびそれらの距離間で最も近接している二つの地点を返します。
function Raia.physics.getDistance()
end
--- メートル尺度係数を返します。
function Raia.physics.getMeter()
end
--- 物体の新規作成を行います。
function Raia.physics.newBody()
end
--- ChainShape の新規作成。
function Raia.physics.newChainShape()
end
--- CircleShape の新規作成。
function Raia.physics.newCircleShape()
end
--- 二つの物体間に対して DistanceJoint を作成します。
function Raia.physics.newDistanceJoint()
end
--- EdgeShape の新規作成を行います。
function Raia.physics.newEdgeShape()
end
--- 物体へ Fixture を作成して取り付けます。
function Raia.physics.newFixture()
end
--- FrictionJoint は物体に摩擦を適用します。
function Raia.physics.newFrictionJoint()
end
--- 二つの関節を接続するために GearJoint を作成します。
function Raia.physics.newGearJoint()
end
--- 相対運動を制御するために二つの物体間に関節を作成します。
function Raia.physics.newMotorJoint()
end
--- 物体およびマウス間の関節を作成します。
function Raia.physics.newMouseJoint()
end
--- PolygonShape の新規作成。
function Raia.physics.newPolygonShape()
end
--- 二つの物体間に対して PrismaticJoint を作成します。
function Raia.physics.newPrismaticJoint()
end
--- 基礎と二つの物体を互いに接続するために PulleyJoint を作成します。
function Raia.physics.newPulleyJoint()
end
--- 長方形の PolygonShape を作成するための速記法です。
function Raia.physics.newRectangleShape()
end
--- 二つの物体間で車軸関節を作成します。
function Raia.physics.newRevoluteJoint()
end
--- 二つの物体間における関節を作成します。
function Raia.physics.newRopeJoint()
end
--- WeldJoint は二つの物体を接着します。
function Raia.physics.newWeldJoint()
end
--- 車輪関節を作成します。
function Raia.physics.newWheelJoint()
end
--- 世界の新規作成。
function Raia.physics.newWorld()
end
--- メートル尺度係数を設定します。
function Raia.physics.setMeter()
end

-- Raia.sound

-- 指定されたファイルにある符号化済み音声データで用いる復号方法を検出します。
function Raia.sound.newDecoder()
end
-- SoundData を新規作成します。
function Raia.sound.newSoundData()
end

-- Raia.system

--- クリップボードからテキストを取得します。
function Raia.system.getClipboardText()
    return glfw.getClipboardString(Raia.window.id)
end

--- 現在のオペレーティングシステムを取得します。
function Raia.system.getOS()
    return System.getOS()
end

--- システムの電源供給についての情報を取得します。
function Raia.system.getPowerInfo()
    return System.getPowerInfo()
end

--- システムに搭載されている論理プロセッサ数を取得します。
function Raia.system.getProcessorCount()
    return System.getProcessorCount()
end

--- ほかのアプリケーションがシステムで音楽をバックグラウンド再生しているかどうかを取得します。
function Raia.system.hasBackgroundMusic()
    return false
end

--- 利用者のウェブまたはファイルブラウザで URL を開きます。
function Raia.system.openURL(url)
    return System.openURL(url)
end

--- クリップボードへテキストを出力します。
function Raia.system.setClipboardText(string)
    glfw.setClipboardString(Raia.window.id, string)
end

--- 利用可能であれば、デバイスを振動させます。
function Raia.system.vibrate()
end

-- Raia.thread

--- 名前ありスレッドのチャンネルを作成または検索します。
function Raia.thread.getChannel()
end
--- （廃止）スレッドを検索してオブジェクトを取得します。
function Raia.thread.getThread()
end
--- （廃止）全てのスレッドを取得します。
function Raia.thread.getThreads()
end
--- 名前なしスレッドのチャンネルを新規作成します。
function Raia.thread.newChannel()
end
--- ファイル名、文字列または Lua コードのある FileData オブジェクトからスレッドを新規作成します。
function Raia.thread.newThread()
end

-- Raia.timer

Raia.timer.frameTimes = {}
Raia.timer.frameTimeIndex = 1
Raia.timer.maxFrameSamples = 100
Raia.timer.lastTime = glfw.getTime()  -- 最初の時間を設定
Raia.timer.startTime = glfw.getTime() -- アプリケーションの開始時刻を取得

--- 最近の秒間における平均デルタ時間を返します。
function Raia.timer.getAverageDelta()
    local currentTime = glfw.getTime()
    local frameTime = currentTime - Raia.timer.lastTime
    Raia.timer.frameTimes[Raia.timer.frameTimeIndex] = frameTime
    Raia.timer.frameTimeIndex = (Raia.timer.frameTimeIndex % Raia.timer.maxFrameSamples) + 1

    local sum = 0
    for _, time in ipairs(Raia.timer.frameTimes) do
        sum = sum + time
    end
    Raia.timer.lastTime = currentTime  -- 最後の時間を更新

    return #Raia.timer.frameTimes > 0 and (sum / #Raia.timer.frameTimes) or 0
end

--- 最近の２フレーム間における時間を返します。
function Raia.timer.getDelta()
    local currentTime = glfw.getTime()
    local deltaTime = currentTime - Raia.timer.lastTime
    Raia.timer.lastTime = currentTime  -- 現在の時間を記録
    return deltaTime
end

--- 毎秒ごとに現在のフレーム数を返します。	
function Raia.timer.getFPS()
    local currentTime = glfw.getTime()
    Raia.timer.frameTimes[#Raia.timer.frameTimes + 1] = currentTime
    -- 過去1秒間にどれだけフレームがあったかカウント
    local count = 0
    for i = #Raia.timer.frameTimes, 1, -1 do
        if currentTime - Raia.timer.frameTimes[i] > 1.0 then
            table.remove(Raia.timer.frameTimes, i)  -- 1秒以上前のフレームタイムはリストから削除
        else
            count = count + 1
        end
    end
    return count
end

--- （廃止）タイマーの値を精密マイクロ秒で返します。
function Raia.timer.getMicroTime()
end

--- 過去の無指定による開始時間からの経過時間を返します。
function Raia.timer.getTime() -- getTimeSinceStart()
    local currentTime = glfw.getTime()
    return currentTime - Raia.timer.startTime
end

--- 指定された時間になるまで現在のスレッドを一時停止します。
function Raia.timer.sleep(seconds) -- wait()
    local startTime = glfw.getTime()
    while glfw.getTime() - startTime < seconds do
        glfw.pollEvents() -- 応答性を保持するためにイベントをポーリング
    end
end

--- ２フレームの間にある時間を計測します。
function Raia.timer.step()
    local currentTime = glfw.getTime()
    local deltaTime = currentTime - Raia.timer.lastTime
    Raia.timer.lastTime = currentTime  -- 現在の時間を最後のフレーム時間として更新
    return deltaTime
end

-- Raia.touch

--- ピクセル単位にて、指定されたタッチ打鍵の現在位置を取得します。
function Raia.touch.getPosition()
end
--- 指定されたタッチ打鍵における現在の筆圧を取得します。
function Raia.touch.getPressure()
end
--- 全ての有効なタッチ打鍵 ID 値の一覧を取得します。
function Raia.touch.getTouches()
end

-- Raia.video

--- VideoStream を新規作成します。
function Raia.video.newVideoStream()
end


-- Raia.window

--- ウィンドウを閉じます。
function Raia.window.close()
    glfw.destroyWindow(Raia.window.id)
end

--- 数値をピクセルから密度非依存単位へ変換します。
function Raia.window.fromPixels()
end

--- ウィンドウに関連づけられた DPI 縮尺係数を取得します。
function Raia.window.getDPIScale()
end

--- デスクトップの幅と高さを取得します。
function Raia.window.getDesktopDimensions()
    local primaryMonitor = glfw.getPrimaryMonitor()
    if not primaryMonitor then
        error("Failed to get primary monitor")
    end
    local mode = glfw.getVideoMode(primaryMonitor)
    if not mode then
        error("Failed to get video mode")
    end
    return mode
end

--- （廃止）ウィンドウの幅と高さを取得します。
function Raia.window.getDimensions()
end

--- 接続されているモニターの台数を取得します。
function Raia.window.getDisplayCount()
end

--- ディスプレイの名称を取得します。
function Raia.window.getDisplayName()
end

--- 現在のデバイスにおけるディスプレイの表示方向を取得します。
function Raia.window.getDisplayOrientation()
end

--- ウィンドウがフルスクリーン化されているか取得します。
function Raia.window.getFullscreen()
end

--- 対応しているフルスクリーンモードの一覧を取得します。
function Raia.window.getFullscreenModes()
end

--- （廃止）ウィンドウの高さを取得します。
function Raia.window.getHeight()
end

--- ウィンドウのアイコンを取得します。
function Raia.window.getIcon()
end

--- ディスプレイ・モードとウィンドウのプロパティを取得します。
function Raia.window.getMode()
end

--- （廃止）ウィンドウに関連づけられた DPI 縮尺係数を取得します。
function Raia.window.getPixelScale()
end

--- 画面上にあるウィンドウの位置を取得します。
function Raia.window.getPosition()
end

--- ノッチなどで隠されないウィンドウ領域範囲を取得します。
function Raia.window.getSafeArea()
end

--- ウィンドウのタイトルを取得します。
function Raia.window.getTitle()
    return Raia.window.title
end

--- 現在の垂直同期方法 (vsync) を取得します。
function Raia.window.getVSync()
end

--- （廃止）ウィンドウの幅を取得します。
function Raia.window.getWidth()
end

--- ゲームのウィンドウにキーボードのフォーカスがあるか確認します。
function Raia.window.hasFocus()
end

--- ゲームのウィンドウにマウスのフォーカスがあるか確認します。
function Raia.window.hasMouseFocus()
end

--- ウィンドウが作成されているか確認します。
function Raia.window.isCreated()
end

--- プログラム実行中に画面の休止を有効にするかどうかを取得します。
function Raia.window.isDisplaySleepEnabled()
end

--- 現在のウィンドウが最大化されているかどうかを取得します。
function Raia.window.isMaximized()
end

--- 現在のウィンドウが最小化されているかどうかを取得します。
function Raia.window.isMinimized()
end

--- ゲームのウィンドウが表示されているか確認します。
function Raia.window.isVisible()
end

--- ウィンドウを可能な限り最大化します。
function Raia.window.maximize()
end

--- ウィンドウをシステムのタスクバー / ドックへ最小化します。
function Raia.window.minimize()
end

--- ウィンドウがフォアグラウンドではない場合に利用者へ注意を促します。
function Raia.window.requestAttention()
end

--- ウィンドウが最小化、または最大化状態ならば、ウィンドウの大きさと位置を元の状態に戻します。	
function Raia.window.restore()
end

--- プログラム実行中に画面の休止を有効にするかどうかを設定します。
function Raia.window.setDisplaySleepEnabled()
end

--- フルスクリーンへ入るか出ます。
function Raia.window.setFullscreen()
end

--- ウィンドウのアイコンを設定します。
function Raia.window.setIcon()
end

--- ディスプレイ・モードとウィンドウのプロパティを設定します。
function Raia.window.setMode(width, height, flags)
    width = width or Raia.window.width
    height = height or Raia.window.height
    flags = flags or {}
    flags.fullscreen = flags.fullscreen or false
    flags.fullscreentype = flags.fullscreentype or "desktop"
    flags.vsync = flags.vsync or true
    flags.msaa = flags.mesaa or 0
    flags.stencil = flags.stencil or true
    flags.depth = flags.depth or 0
    flags.resizable = flags.resizable or false
    flags.borderless = flags.borderless or false
    flags.centered = flags.centered or true
    flags.display = flags.display or 1
    flags.minwidth = flags.minwidth or 1
    flags.minheight = flags.minheight or 1
    flags.highdpi = flags.highdpi or false
    flags.x = flags.x or nil
    flags.y = flags.y or nil
    flags.usedpiscale = flags.usedpiscale or true
    --
    glfw.setWindowSize(Raia.window.id, width, height)
    Raia.window.width = width
    Raia.window.height = height
end

--- 画面上にあるウィンドウの位置を設定します。
function Raia.window.setPosition()
end

--- ウィンドウのタイトルを設定します。
function Raia.window.setTitle(title)
    glfw.setWindowTitle(Raia.window.id, title)
    Raia.window.title = title
end

--- 現在の垂直同期方法 (vsync) を設定します。
function Raia.window.setVSync()
end

--- LÖVE ウィンドウに重ねてメッセージボックスを表示します。
function Raia.window.showMessageBox()
end

--- 数値を密度非依存単位からピクセルへ変換します。
function Raia.window.toPixels()
end

--- 未指定のプロパティを変更せずにディスプレイモードとウィンドウのを設定します。
function Raia.window.updateMode()
end

--- （拡張）ウィンドウを表示する。
function Raia.window.show()
    glfw.showWindow(Raia.window.id)
    Raia.window.visible = true
end

--- （拡張）ウィンドウを非表示にする。
function Raia.window.hide()
    glfw.hideWindow(Raia.window.id)
    Raia.window.visible = false
end

return Raia