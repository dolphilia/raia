local ffi = require("ffi")
local gl = require("modules/bindings/gles")
local glfw = require("modules/bindings/glfw")
local skia = require("modules/bindings/skia")
--local prim = require("modules/primitive")
local System = require("modules/utils/system")

--[[
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
Raia.window.id = nil
Raia.window.x = 0
Raia.window.y = 0
Raia.window.width = 500
Raia.window.height = 500
Raia.window.title = "Untitled"
Raia.window.visible = false
Raia.shader = {}
Raia.shader.program = nil
Raia.shader.vao = nil
Raia.shader.texture = nil
Raia.shader.pixels = nil
Raia.surface = {}
Raia.surface[0] = {}
Raia.surface[0].bitmap = nil
Raia.surface[0].canvas = nil
Raia.surface[0].paint = nil
Raia.surface[0].pixels = nil

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

]]


--[[
-- Raia.touch

--- ピクセル単位にて、指定されたタッチ打鍵の現在位置を取得する
function Raia.touch.getPosition()
end

--- 指定されたタッチ打鍵における現在の筆圧を取得する
function Raia.touch.getPressure()
end

--- 全ての有効なタッチ打鍵 ID 値の一覧を取得する
function Raia.touch.getTouches()
end

-- Raia.video

--- VideoStream を新規作成する
function Raia.video.newVideoStream()
end


-- Raia.window

--- 数値をピクセルから密度非依存単位へ変換する
function Raia.window.fromPixels()
end

--- ウィンドウに関連づけられた DPI 縮尺係数を取得する
function Raia.window.getDPIScale()
end

--- 接続されているモニターの台数を取得する
function Raia.window.getDisplayCount()
end

--- ディスプレイの名称を取得する
function Raia.window.getDisplayName()
end

--- 現在のデバイスにおけるディスプレイの表示方向を取得する
function Raia.window.getDisplayOrientation()
end

--- ウィンドウがフルスクリーン化されているか取得する
function Raia.window.getFullscreen()
end

--- 対応しているフルスクリーンモードの一覧を取得する
function Raia.window.getFullscreenModes()
end

--- ウィンドウのアイコンを取得する
function Raia.window.getIcon()
end

--- ディスプレイ・モードとウィンドウのプロパティを取得する
function Raia.window.getMode()
end

--- （廃止）ウィンドウに関連づけられた DPI 縮尺係数を取得する
function Raia.window.getPixelScale()
end

--- ノッチなどで隠されないウィンドウ領域範囲を取得する
function Raia.window.getSafeArea()
end

--- 現在の垂直同期方法 (vsync) を取得する
function Raia.window.getVSync()
end

--- ゲームのウィンドウにキーボードのフォーカスがあるか確認する
function Raia.window.hasFocus()
end

--- ゲームのウィンドウにマウスのフォーカスがあるか確認する
function Raia.window.hasMouseFocus()
end

--- ウィンドウが作成されているか確認する
function Raia.window.isCreated()
end

--- プログラム実行中に画面の休止を有効にするかどうかを取得する
function Raia.window.isDisplaySleepEnabled()
end

--- 現在のウィンドウが最大化されているかどうかを取得する
function Raia.window.isMaximized()
end

--- 現在のウィンドウが最小化されているかどうかを取得する
function Raia.window.isMinimized()
end

--- ウィンドウを可能な限り最大化する
function Raia.window.maximize()
end

--- ウィンドウをシステムのタスクバー / ドックへ最小化する
function Raia.window.minimize()
end

--- ウィンドウがフォアグラウンドではない場合に利用者へ注意を促す
function Raia.window.requestAttention()
end

--- ウィンドウが最小化、または最大化状態ならば、ウィンドウの大きさと位置を元の状態に戻す	
function Raia.window.restore()
end

--- プログラム実行中に画面の休止を有効にするかどうかを設定する
function Raia.window.setDisplaySleepEnabled()
end

--- ウィンドウのアイコンを設定する
function Raia.window.setIcon()
end

--- ディスプレイ・モードとウィンドウのプロパティを設定する
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

--- 現在の垂直同期方法 (vsync) を設定する
function Raia.window.setVSync()
end

--- ウィンドウに重ねてメッセージボックスを表示する
function Raia.window.showMessageBox()
end

--- 数値を密度非依存単位からピクセルへ変換する
function Raia.window.toPixels()
end

--- 未指定のプロパティを変更せずにディスプレイモードとウィンドウのを設定する
function Raia.window.updateMode()
end

]]

--- os.exitをオーバーライド
local original_exit = os.exit
os.exit = function(...)
    glfw.terminate()
    original_exit(...)
end

-- Initialize
-- local Raia = {
--     currentWindow = 0,
--     currentWindowIndex = 0,
--     Window = {
--         id = nil,
--         x = nil,
--         y = nil,
--         width = 500,
--         height = 500,
--         title = "Untitled",
--         visible = false,
--         pixels = nil,
--         isFullscreen = false,
--     },
--     Shader = {
--         program = nil,
--         vao = nil,
--         texture = nil,
--     },
--     -- Surface = {
--     --     {
--     --         bitmap = nil,
--     --         canvas = nil,
--     --         paint = nil,
--     --         pixels = nil,
--     --     }
--     -- }
-- }

-- クラス定義

if Raia == nil then -- 初めて読み込んだとき
    Raia = {}
    if glfw.init() == 0 then
        error("Failed to initialize GLFW")
        os.exit()
    end
end

-- Raia.system

Raia.System = {}
Raia.System.__index = Raia.System

function Raia.System:new()
    local self = setmetatable({}, Raia.System)
    return self
end

--- クリップボードからテキストを取得します。
function Raia.System:getClipboardText(windowID)
    return glfw.getClipboardString(windowID)
end

--- 現在のオペレーティングシステムを取得します。
function Raia.System:getOS()
    return System.getOS()
end

--- システムの電源供給についての情報を取得します。
function Raia.System:getPowerInfo()
    return System.getPowerInfo()
end

--- システムに搭載されている論理プロセッサ数を取得します。
function Raia.System:getProcessorCount()
    return System.getProcessorCount()
end

--- ほかのアプリケーションがシステムで音楽をバックグラウンド再生しているかどうかを取得します。
function Raia.System:hasBackgroundMusic()
    return false
end

--- 利用者のウェブまたはファイルブラウザで URL を開きます。
function Raia.System:openURL(url)
    return System.openURL(url)
end

--- クリップボードへテキストを出力します。
function Raia.System:setClipboardText(windowID, string)
    glfw.setClipboardString(windowID, string)
end

--- 利用可能であれば、デバイスを振動させます。
function Raia.System:vibrate()
end

function Raia.System:printMemoryUsage()
    System.printMemoryUsage()
end

function Raia.System:getMemoryUsage()
    return System.getMemoryUsage()
end

-- Raia.timer

Raia.Timer = {}
Raia.Timer.__index = Raia.Timer

function Raia.Timer:new()
    local self = setmetatable({}, Raia.Timer)
    --
    self.frameTimes = {}
    self.frameTimeIndex = 1
    self.maxFrameSamples = 100
    self.lastTime = glfw.getTime()  -- 最初の時間を設定
    self.startTime = glfw.getTime() -- アプリケーションの開始時刻を取得
    return self
end

--- 最近の秒間における平均デルタ時間を返す
function Raia.Timer:getAverageDelta()
    local currentTime = glfw.getTime()
    local frameTime = currentTime - self.lastTime

    self.frameTimes[self.frameTimeIndex] = frameTime
    self.frameTimeIndex = (self.frameTimeIndex % self.maxFrameSamples) + 1

    local sum = 0
    for _, time in ipairs(self.frameTimes) do
        sum = sum + time
    end
    self.lastTime = currentTime  -- 最後の時間を更新

    return #self.frameTimes > 0 and (sum / #self.frameTimes) or 0
end

--- 最近の２フレーム間における時間を返します。
function Raia.Timer:getDelta()
    local currentTime = glfw.getTime()
    local deltaTime = currentTime - self.lastTime
    self.lastTime = currentTime  -- 現在の時間を記録
    return deltaTime
end

--- 毎秒ごとに現在のフレーム数を返します。	
function Raia.Timer:getFPS()
    local currentTime = glfw.getTime()
    self.frameTimes[#self.frameTimes + 1] = currentTime
    -- 過去1秒間にどれだけフレームがあったかカウント
    local count = 0
    for i = #self.frameTimes, 1, -1 do
        if currentTime - self.frameTimes[i] > 1.0 then
            table.remove(self.frameTimes, i)  -- 1秒以上前のフレームタイムはリストから削除
        else
            count = count + 1
        end
    end
    return count
end

--- （廃止）タイマーの値を精密マイクロ秒で返します。
function Raia.Timer:getMicroTime()
end

--- 過去の無指定による開始時間からの経過時間を返します。
function Raia.Timer:getTime() -- getTimeSinceStart()
    local currentTime = glfw.getTime()
    return currentTime - self.startTime
end

--- 指定された時間になるまで現在のスレッドを一時停止します。
function Raia.Timer:sleep(seconds) -- wait()
    local startTime = glfw.getTime()
    while glfw.getTime() - startTime < seconds do
        glfw.pollEvents() -- 応答性を保持するためにイベントをポーリング
    end
end

--- ２フレームの間にある時間を計測する
function Raia.Timer:step()
    local currentTime = glfw.getTime()
    local deltaTime = currentTime - self.lastTime
    self.lastTime = currentTime  -- 現在の時間を最後のフレーム時間として更新
    return deltaTime
end


-- Window

Raia.Window = {}
Raia.Window.__index = Raia.Window

-- コンストラクタ
function Raia.Window:new(title, width, height)
    title = title or "Untitled"
    width = width or 500
    height = height or 500

    local getter = function(t, key)
        if key == "title" then
            return rawget(t, "_title")
        elseif key == "position" then
            return {rawget(t, "_pos_x"), rawget(t, "_pos_y")}
        elseif key == "size" then
            return {rawget(t, "_width"), rawget(t, "_height")}
        else
            return Raia.Window[key]
        end
    end

    local setter = function(t, key, value)
        if key == "title" then
            t:setTitle(value)
        elseif key == "position" then
            if raia.lua.type(value) == "table" and #value == 2 then
                t:setPosition(value[1], value[2])
            else
                error("Position must be a table with at least two numeric values")
            end
        elseif key == "size" then
            if raia.lua.type(value) == "table" and #value == 2 then
                t:setSize(value[1], value[2])
            else
                error("Position must be a table with at least two numeric values")
            end
        else
            rawset(t, key, value)
        end
    end

    local instance = {}
    setmetatable(instance, {
        __index = getter,
        __newindex = setter
    })

    -- destructor
    local gc_proxy = ffi.new("struct {}")  -- 空の構造体
    local destructor_callback = function()
        if instance.destructor then
            instance:destructor()
        end
    end
    ffi.gc(gc_proxy, destructor_callback)
    instance._gc_proxy = gc_proxy

    -- GLFW の初期化とウィンドウの作成
    glfw.windowHint(glfw.CLIENT_API, glfw.OPENGL_ES_API)
    glfw.windowHint(glfw.CONTEXT_VERSION_MAJOR, 3)
    glfw.windowHint(glfw.CONTEXT_VERSION_MINOR, 0)
    glfw.windowHint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)
    glfw.windowHint(glfw.CONTEXT_CREATION_API, glfw.EGL_CONTEXT_API)
    local windowID = glfw.createWindow(width, height, title)
    if windowID == nil then
        glfw.terminate()
        error("Failed to create GLFW window")
    end
    glfw.makeContextCurrent(windowID)
    glfw.swapInterval(1)

    -- GLFW コールバックの設定
    glfw.setErrorCallbackAlt()
    glfw.setJoystickCallbackAlt()
    glfw.setMonitorCallbackAlt()
    glfw.setWindowPosCallbackAlt(windowID)
    glfw.setWindowSizeCallbackAlt(windowID)
    glfw.setWindowCloseCallbackAlt(windowID)
    glfw.setWindowRefreshCallbackAlt(windowID)
    glfw.setWindowFocusCallbackAlt(windowID)
    glfw.setWindowIconifyCallbackAlt(windowID)
    glfw.setFramebufferSizeCallbackAlt(windowID)
    glfw.setKeyCallbackAlt(windowID)

    -- ffi.cdef[[
    --     typedef struct GLFWwindow GLFWwindow;
    --     typedef void (* GLFWcursorposfun)(GLFWwindow* window, double xpos, double ypos);
    -- ]]

    -- local count = 0
    -- local cb = ffi.cast("GLFWcursorposfun", function(window, xpos, ypos)
    --     count = count + 1
    --     --print(xpos)
    --     return window
    -- end)

    -- glfw.setCursorPosCallback(windowID, cb)

    glfw.setCursorPosCallbackAlt(windowID)
    glfw.setMouseButtonCallbackAlt(windowID)
    glfw.setCharCallbackAlt(windowID)
    glfw.setCharModsCallbackAlt(windowID)
    glfw.setCursorEnterCallbackAlt(windowID)
    glfw.setScrollCallbackAlt(windowID)
    glfw.setDropCallbackAlt(windowID)
    glfw.setWindowMaximizeCallbackAlt(windowID)
    glfw.setWindowContentScaleCallbackAlt(windowID)

    -- OpenGL の初期化
    local vertices = ffi.new("float[32]", {
        -1.0,  1.0, 0.0,  0.0, 0.0,  -- Position 0, TexCoord 0
        -1.0, -1.0, 0.0,  0.0, 1.0,  -- Position 1, TexCoord 1
         1.0, -1.0, 0.0,  1.0, 1.0,  -- Position 2, TexCoord 2
         1.0,  1.0, 0.0,  1.0, 0.0   -- Position 3, TexCoord 3
    })
    local indices = ffi.new("unsigned int[6]", {0, 1, 2, 0, 2, 3})
    local vao = ffi.new("GLuint[1]")
    local vbo = ffi.new("GLuint[1]")
    local ebo = ffi.new("GLuint[1]")
    gl.genVertexArrays(1, vao)
    gl.genBuffers(1, vbo)
    gl.genBuffers(1, ebo)
    gl.bindVertexArray(vao[0])
    gl.bindBuffer(gl.ARRAY_BUFFER, vbo[0])
    gl.bufferData(gl.ARRAY_BUFFER, ffi.sizeof(vertices), vertices, gl.STATIC_DRAW)
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, ebo[0])
    gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, ffi.sizeof(indices), indices, gl.STATIC_DRAW)
    gl.vertexAttribPointer(0, 3, gl.FLOAT, gl.FALSE, 5 * ffi.sizeof("float"), ffi.cast("void*", 0))
    gl.enableVertexAttribArray(0)
    gl.vertexAttribPointer(1, 2, gl.FLOAT, gl.FALSE, 5 * ffi.sizeof("float"), ffi.cast("void*", 3 * ffi.sizeof("float")))
    gl.enableVertexAttribArray(1)
    gl.bindVertexArray(0)

    -- シェーダーのコンパイルとプログラムの作成
    local vertexShaderSource = [[
        attribute vec4 a_position;
        attribute vec2 a_texCoord;
        varying vec2 v_texCoord;
        void main() {
            gl_Position = a_position;
            v_texCoord = a_texCoord;
        }
    ]]
    local fragmentShaderSource = [[
        precision mediump float;
        varying vec2 v_texCoord;
        uniform sampler2D s_texture;
        void main() {
            gl_FragColor = texture2D(s_texture, v_texCoord);
        }
    ]]
    local vertex_shader = gl.createShader(gl.VERTEX_SHADER)
    gl.shaderSource(vertex_shader, 1, ffi.new("const char*[1]", {vertexShaderSource}), nil)
    gl.compileShader(vertex_shader)
    local fragment_shader = gl.createShader(gl.FRAGMENT_SHADER)
    gl.shaderSource(fragment_shader, 1, ffi.new("const char*[1]", {fragmentShaderSource}), nil)
    gl.compileShader(fragment_shader)
    local program = gl.createProgram()
    gl.attachShader(program, vertex_shader)
    gl.attachShader(program, fragment_shader)
    gl.linkProgram(program)
    gl.deleteShader(vertex_shader)
    gl.deleteShader(fragment_shader)

    -- テクスチャの作成
    local pixels = ffi.new("GLubyte[?]", width * height * 4)
    local texture = ffi.new("GLuint[1]")
    gl.genTextures(1, texture)
    gl.bindTexture(gl.TEXTURE_2D, texture[0])
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, width, height, 0, gl.RGBA, gl.UNSIGNED_BYTE, pixels)
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST)
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST)

    -- インスタンスのプロパティを設定
    rawset(instance, "id", windowID)
    rawset(instance, "_title", title)
    rawset(instance, "_width", width)
    rawset(instance, "_height", height)
    rawset(instance, "_pos_x", 0)
    rawset(instance, "_pos_y", 0)
    rawset(instance, "_visible", true)
    rawset(instance, "vao", vao)
    rawset(instance, "program", program)
    rawset(instance, "pixels", pixels)
    rawset(instance, "texture", texture)

    return instance
end

-- デストラクタの定義
function Raia.Window:destructor()
    gl.deleteVertexArrays(1, self.VAO)
    gl.deleteTextures(1, self.texture)
    glfw.destroyWindow(self.window)
    glfw.terminate()
end

--- (拡張) 再描画する
function Raia.Window:redraw(isSwap, isPollEvents)
    local width = self._width
    local height = self._height
    local windowID = self.id
    local pixels = self.pixels
    local texture = self.texture[0]
    local program = self.program
    local vao = self.vao[0]
    gl.viewport(0, 0, width, height)
    gl.clearColor(1.0, 1.0, 1.0, 1.0)
    gl.clear(gl.COLOR_BUFFER_BIT)
    gl.bindTexture(gl.TEXTURE_2D, texture)
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, width, height, 0, gl.RGBA, gl.UNSIGNED_BYTE, pixels)
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST)
    gl.useProgram(program)
    gl.bindVertexArray(vao)
    gl.activeTexture(gl.TEXTURE0)
    gl.drawElements(gl.TRIANGLES, 6, gl.UNSIGNED_INT, nil)
    if isSwap == true then
        glfw.swapBuffers(windowID)
    end
    if isPollEvents == true then
        glfw.pollEvents()
    end
end

-- イベントをプールする
function Raia.Window:pollEvents()
    glfw.pollEvents()
end

-- バッファをスワップする
function Raia.Window:swapBuffers(windowID)
    windowID = windowID or self.id
    glfw.swapBuffers(windowID)
end

-- 現在のコンテキストを取得する
function Raia.Window:getCurrentContext()
    return glfw.getCurrentContext()
end

-- 現在のコンテキストを設定する
function Raia.Window:makeContextCurrent(window)
    glfw.makeContextCurrent(window)
end

--- （拡張）ウィンドウを中央に配置する
function Raia.Window:center(width, height)
    width = width or self._width
    height = height or self._height
    local windowID = self.id
    local monitor = glfw.getPrimaryMonitor()
    local mode = glfw.getVideoMode(monitor)
    if not mode then
        error("Failed to get video mode.")
    end
    local x = (mode.width - width) / 2
    local y = (mode.height - height) / 2
    glfw.setWindowPos(windowID, x, y)
    rawset(self, "_x", x)
    rawset(self, "_y", y)
end

--- （拡張）ウィンドウを非表示状態にする
function Raia.Window:hide()
    local windowID = self.id
    glfw.hideWindow(windowID)
    rawset(self, "_visible", false)
end

--- （拡張）ウィンドウを表示状態にする
function Raia.Window:show()
    local windowID = self.id
    glfw.showWindow(windowID)
    rawset(self, "_visible", true)
end

--- ウィンドウを閉じる
function Raia.Window:close()
    local windowID = self.id
    glfw.destroyWindow(windowID)
end

-- ## Get

--- ウィンドウのタイトルを取得する
function Raia.Window:getTitle()
    return self._title
end

--- デスクトップの幅と高さを取得する
function Raia.Window:getDesktopDimensions()
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

--- ウィンドウの位置を取得する
function Raia.Window:getPosition()
    local windowID = self.id
    local x, y = glfw.getWindowPos(windowID)
    return x, y
end

--- （廃止）ウィンドウの幅と高さを取得する
function Raia.Window:getDimensions()
    return self._width, self._height
end

--- （廃止）ウィンドウの幅を取得する
function Raia.Window:getWidth()
    return self._width
end

--- （廃止）ウィンドウの高さを取得する
function Raia.Window:getHeight()
    return self._height
end

-- ## Set

--- ウィンドウのタイトルを設定する
function Raia.Window:setTitle(title)
    local windowID = self.id
    glfw.setWindowTitle(windowID, title)
    rawset(self, "_title", title)
end

--- 画面上にあるウィンドウの位置を設定する
function Raia.Window:setPosition(x, y)
    local windowID = self.id
    glfw.setWindowPos(windowID, x, y)
    rawset(self, "_pos_x", x)
    rawset(self, "_pos_y", y)
end

function Raia.Window:setPositionX(x)
    local windowID = self.id
    local y = self._y
    glfw.setWindowPos(windowID, x, y)
    rawset(self, "_pos_x", x)
end

function Raia.Window:setPositionY(y)
    local windowID = self.id
    local x = self._x
    glfw.setWindowPos(windowID, x, y)
    rawset(self, "_pos_y", y)
end

--- 画面上にあるウィンドウのサイズを設定する
function Raia.Window:setSize(width, height)
    local windowID = self.id
    glfw.setWindowSize(windowID, width, height)
    rawset(self, "_width", width)
    rawset(self, "_height", height)
end

--- フルスクリーンの設定をする
function Raia.Window:setFullscreen(fullscreen, monitor)
    monitor = monitor or glfw.getPrimaryMonitor()
    local windowID = self.id
    local x = self._x
    local y = self._y
    local width = self.width
    local height = self.height
    if fullscreen then
        local mode = glfw.getVideoMode(monitor) -- 現在のモニターの解像度を取得
        glfw.setWindowMonitor(windowID, monitor, 0, 0, mode.width, mode.height, mode.refreshRate)
    else
        glfw.setWindowMonitor(windowID, nil, x, y, width, height, glfw.DONT_CARE) -- ウィンドウモードに戻す
    end
    rawset(self, "isFullscreen", fullscreen)
end

--- （拡張）ピクセルデータを設定する
function Raia.Window:setPixels(pixels)
    rawset(self, "pixels", pixels)
end

-- ## is

--- ウィンドウが表示されているか
function Raia.Window:isVisibled()
    return seif._visible
 end

--- （拡張）ウィンドウを閉じるボタンが押されたか
function Raia.Window:shouldClose()
    local windowID = self.id
    return glfw.windowShouldClose(windowID) ~= 0  -- CのAPIは通常0以外をtrueとして扱う
end

return Raia