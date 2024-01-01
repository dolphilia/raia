//
// SkRasterHandleAllocator
//
~SkRasterHandleAllocator()
bool allocHandle(const SkImageInfo &, Rec *)
void updateHandle(Handle, const SkMatrix &, const SkIRect &)
// static
std::unique_ptr<SkCanvas> MakeCanvas(std::unique_ptr<SkRasterHandleAllocator>, const SkImageInfo &, const Rec *rec, const SkSurfaceProps *props)
//
// SkRect Struct
//
bool isEmpty()
bool isSorted()
bool isFinite()
float x()
float y()
float left()
float top()
float right()
float bottom()
float width()
float height()
float centerX()
float centerY()
SkPoint center()
void toQuad(SkPoint quad[4])
void setEmpty()
void set(const SkIRect &src)
void setLTRB(float left, float top, float right, float bottom)
void setBounds(const SkPoint pts[], int count)
bool setBoundsCheck(const SkPoint pts[], int count)
void setBoundsNoCheck(const SkPoint pts[], int count)
void set(const SkPoint &p0, const SkPoint &p1)
void setXYWH(float x, float y, float width, float height)
void setWH(float width, float height)
void setIWH(int32_t width, int32_t height)
SkRect makeOffset(float dx, float dy)
SkRect makeOffset(SkVector v)
SkRect makeInset(float dx, float dy)
SkRect makeOutset(float dx, float dy)
void offset(float dx, float dy)
void offset(const SkPoint &delta)
void offsetTo(float newX, float newY)
void inset(float dx, float dy)
void outset(float dx, float dy)
bool intersect(const SkRect &r)
bool intersect(const SkRect &a, const SkRect &b)
bool intersects(const SkRect &r)
void join(const SkRect &r)
void joinNonEmptyArg(const SkRect &r)
void joinPossiblyEmptyRect(const SkRect &r)
bool contains(float x, float y)
bool contains(const SkRect &r)
bool contains(const SkIRect &r)
void round(SkIRect *dst)
void roundOut(SkIRect *dst)
void roundOut(SkRect *dst)
void roundIn(SkIRect *dst)
SkIRect round()
SkIRect roundOut()
SkIRect roundIn()
void sort()
SkRect makeSorted()
const float * asScalars()
void dump(bool asHex)
void dump()
void dumpHex()
// static
SkRect MakeEmpty()
SkRect MakeWH(float w, float h)
SkRect MakeIWH(int w, int h)
SkRect MakeSize(const SkSize &size)
SkRect MakeLTRB(float l, float t, float r, float b)
SkRect MakeXYWH(float x, float y, float w, float h)
SkRect Make(const SkISize &size)
SkRect Make(const SkIRect &irect)
bool Intersects(const SkRect &a, const SkRect &b)
//
// SkRefCnt
//
bool unique()
void ref()
void unref()
//
// SkRefCntBase
//
SkRefCntBase()
~SkRefCntBase()
bool unique()
void ref()
void unref()
//
// SkRegion
//
SkRegion()
SkRegion(const SkRegion &region)
SkRegion(const SkIRect &rect)
~SkRegion()
SkRegion & operator=(const SkRegion &region)
bool operator==(const SkRegion &other)
bool operator!=(const SkRegion &other)
bool set(const SkRegion &src)
void swap(SkRegion &other)
bool isEmpty()
bool isRect()
bool isComplex()
const SkIRect & getBounds()
int computeRegionComplexity()
bool getBoundaryPath(SkPath *path)
bool setEmpty()
bool setRect(const SkIRect &rect)
bool setRects(const SkIRect rects[], int count)
bool setRegion(const SkRegion &region)
bool setPath(const SkPath &path, const SkRegion &clip)
bool intersects(const SkIRect &rect)
bool intersects(const SkRegion &other)
bool contains(int32_t x, int32_t y)
bool contains(const SkIRect &other)
bool contains(const SkRegion &other)
bool quickContains(const SkIRect &r)
bool quickReject(const SkIRect &rect)
bool quickReject(const SkRegion &rgn)
void translate(int dx, int dy)
void translate(int dx, int dy, SkRegion *dst)
bool op(const SkIRect &rect, Op op)
bool op(const SkRegion &rgn, Op op)
bool op(const SkIRect &rect, const SkRegion &rgn, Op op)
bool op(const SkRegion &rgn, const SkIRect &rect, Op op)
bool op(const SkRegion &rgna, const SkRegion &rgnb, Op op)
size_t writeToMemory(void *buffer)
size_t readFromMemory(const void *buffer, size_t length)
//
// SkRGBA4f<kAT> Struct Template
//
const float * vec()
float * vec()
std::array<float, 4> array()
float operator[](int index)
float & operator[](int index)
bool isOpaque()
bool fitsInBytes()
SkColor toSkColor()
SkRGBA4f<kPremul_SkAlphaType> premul()
SkRGBA4f<kUnpremul_SkAlphaType> unpremul()
uint32_t toBytes_RGBA()
SkRGBA4f makeOpaque()
// static
SkRGBA4f FromColor(SkColor color)
SkRGBA4f FromPMColor(SkPMColor)
SkRGBA4f FromBytes_RGBA(uint32_t color)
//
// SkRRect
//
SkRRect()
SkRRect(const SkRRect &rrect)
SkRRect & operator=(const SkRRect &rrect)
Type getType()
Type type()
bool isEmpty()
bool isRect()
bool isOval()
bool isSimple()
bool isNinePatch()
bool isComplex()
SkScalar width()
SkScalar height()
SkVector getSimpleRadii()
void setEmpty()
void setRect(const SkRect &rect)
void setOval(const SkRect &oval)
void setRectXY(const SkRect &rect, SkScalar xRad, SkScalar yRad)
void setNinePatch(const SkRect &rect, SkScalar leftRad, SkScalar topRad, SkScalar rightRad, SkScalar bottomRad)
void setRectRadii(const SkRect &rect, const SkVector radii[4])
const SkRect & rect()
SkVector radii(Corner corner)
const SkRect & getBounds()
void inset(SkScalar dx, SkScalar dy, SkRRect *dst)
void inset(SkScalar dx, SkScalar dy)
void outset(SkScalar dx, SkScalar dy, SkRRect *dst)
void outset(SkScalar dx, SkScalar dy)
void offset(SkScalar dx, SkScalar dy)
SkRRect makeOffset(SkScalar dx, SkScalar dy)
bool contains(const SkRect &rect)
bool isValid()
size_t writeToMemory(void *buffer)
size_t readFromMemory(const void *buffer, size_t length)
bool transform(const SkMatrix &matrix, SkRRect *dst)
void dump(bool asHex)
SkString dumpToString(bool asHex)
void dump()
void dumpHex()
// static
SkRRect MakeEmpty()
SkRRect MakeRect(const SkRect &r)
SkRRect MakeOval(const SkRect &oval)
SkRRect MakeRectXY(const SkRect &rect, SkScalar xRad, SkScalar yRad)
//
// SkRSXform
//
bool rectStaysRect()
void setIdentity()
void set(SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty)
void toQuad(SkScalar width, SkScalar height, SkPoint quad[4])
void toQuad(const SkSize &size, SkPoint quad[4])
void toTriStrip(SkScalar width, SkScalar height, SkPoint strip[4])
// static
SkRSXform Make(SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty)
SkRSXform MakeFromRadians(SkScalar scale, SkScalar radians, SkScalar tx, SkScalar ty, SkScalar ax, SkScalar ay)
//
// SkRTreeFactory
//
sk_sp<SkBBoxHierarchy> operator()() const override
//
// SkRuntimeBlendBuilder
//
SkRuntimeBlendBuilder(sk_sp<SkRuntimeEffect>)
~SkRuntimeBlendBuilder()
SkRuntimeBlendBuilder(const SkRuntimeBlendBuilder &)=delete
SkRuntimeBlendBuilder & operator=(const SkRuntimeBlendBuilder &)=delete
sk_sp<SkBlender> makeBlender()
const SkRuntimeEffect * effect()
BuilderUniform uniform(std::string_view name)
BuilderChild child(std::string_view name)
sk_sp<const SkData> uniforms()
SkSpan<const SkRuntimeEffect::ChildPtr> children()
//
// SkRuntimeColorFilterBuilder
//
SkRuntimeColorFilterBuilder(sk_sp<SkRuntimeEffect>)
~SkRuntimeColorFilterBuilder()
SkRuntimeColorFilterBuilder(const SkRuntimeColorFilterBuilder &)=delete
SkRuntimeColorFilterBuilder & operator=(const SkRuntimeColorFilterBuilder &)=delete
sk_sp<SkColorFilter> makeColorFilter()
const SkRuntimeEffect * effect()
BuilderUniform uniform(std::string_view name)
BuilderChild child(std::string_view name)
sk_sp<const SkData> uniforms()
SkSpan<const SkRuntimeEffect::ChildPtr> children()
//
// SkRuntimeEffect
//
sk_sp<SkShader> makeShader(sk_sp<const SkData> uniforms, sk_sp<SkShader> children[], size_t childCount, const SkMatrix *localMatrix)
sk_sp<SkShader> makeShader(sk_sp<const SkData> uniforms, SkSpan<const ChildPtr> children, const SkMatrix *localMatrix)
sk_sp<SkColorFilter> makeColorFilter(sk_sp<const SkData> uniforms)
sk_sp<SkColorFilter> makeColorFilter(sk_sp<const SkData> uniforms, sk_sp<SkColorFilter> children[], size_t childCount)
sk_sp<SkColorFilter> makeColorFilter(sk_sp<const SkData> uniforms, SkSpan<const ChildPtr> children)
sk_sp<SkBlender> makeBlender(sk_sp<const SkData> uniforms, SkSpan<const ChildPtr> children)
const std::string & source()
size_t uniformSize()
SkSpan<const Uniform> uniforms()
SkSpan<const Child> children()
const Uniform * findUniform(std::string_view name)
const Child * findChild(std::string_view name)
bool allowShader()
bool allowColorFilter()
bool allowBlender()
~SkRuntimeEffect() override
bool unique()
void ref()
void unref()
// static
Result MakeForColorFilter(SkString sksl, const Options &)
Result MakeForColorFilter(SkString sksl)
Result MakeForShader(SkString sksl, const Options &)
Result MakeForShader(SkString sksl)
Result MakeForBlender(SkString sksl, const Options &)
Result MakeForBlender(SkString sksl)
TracedShader MakeTraced(sk_sp<SkShader> shader, const SkIPoint &traceCoord)
void RegisterFlattenables()
//
// SkRuntimeEffectBuilder
//
const SkRuntimeEffect * effect()
BuilderUniform uniform(std::string_view name)
BuilderChild child(std::string_view name)
sk_sp<const SkData> uniforms()
SkSpan<const SkRuntimeEffect::ChildPtr> children()
// static
SkRuntimeEffectBuilder()=delete
SkRuntimeEffectBuilder(sk_sp<SkRuntimeEffect> effect)
SkRuntimeEffectBuilder(sk_sp<SkRuntimeEffect> effect, sk_sp<SkData> uniforms)
SkRuntimeEffectBuilder(SkRuntimeEffectBuilder &&)
SkRuntimeEffectBuilder(const SkRuntimeEffectBuilder &)
SkRuntimeEffectBuilder & operator=(SkRuntimeEffectBuilder &&)=delete
SkRuntimeEffectBuilder & operator=(const SkRuntimeEffectBuilder &)=delete
//
// SkRuntimeShaderBuilder
//
SkRuntimeShaderBuilder(sk_sp<SkRuntimeEffect>)
SkRuntimeShaderBuilder(const SkRuntimeShaderBuilder &)
~SkRuntimeShaderBuilder()
sk_sp<SkShader> makeShader(const SkMatrix *localMatrix)
const SkRuntimeEffect * effect()
BuilderUniform uniform(std::string_view name)
BuilderChild child(std::string_view name)
sk_sp<const SkData> uniforms()
SkSpan<const SkRuntimeEffect::ChildPtr> children()
//
// SkSamplingOptions
//
SkSamplingOptions()
SkSamplingOptions(const SkSamplingOptions &)
SkSamplingOptions & operator=(const SkSamplingOptions &that)
SkSamplingOptions(SkFilterMode fm, SkMipmapMode mm)
SkSamplingOptions(SkFilterMode fm)
SkSamplingOptions(const SkCubicResampler &c)
bool operator==(const SkSamplingOptions &other)
bool operator!=(const SkSamplingOptions &other)
bool isAniso()
// static
SkSamplingOptions Aniso(int maxAniso)
//
// SkShader
//
bool isOpaque()
SkImage * isAImage(SkMatrix *localMatrix, SkTileMode xy[2])
bool isAImage()
sk_sp<SkShader> makeWithLocalMatrix(const SkMatrix &)
sk_sp<SkShader> makeWithColorFilter(sk_sp<SkColorFilter>)
sk_sp<SkShader> makeWithWorkingColorSpace(sk_sp<SkColorSpace>)
Factory getFactory()
const char * getTypeName()
void flatten(SkWriteBuffer &)
Type getFlattenableType()
sk_sp<SkData> serialize(const SkSerialProcs *)
size_t serialize(void *memory, size_t memory_size, const SkSerialProcs *)
bool unique()
void ref()
void unref()
// static
Factory NameToFactory(const char name[])
const char * FactoryToName(Factory)
void Register(const char name[], Factory)
sk_sp<SkFlattenable> Deserialize(Type, const void *data, size_t length, const SkDeserialProcs *procs)
//
// SkShaderMaskFilter
//
// static
sk_sp<SkMaskFilter> Make(sk_sp<SkShader> shader)
//
// SkShaper
//
SkShaper()
~SkShaper()
void shape(const char *utf8, size_t utf8Bytes, const SkFont &srcFont, bool leftToRight, SkScalar width, RunHandler *)
void shape(const char *utf8, size_t utf8Bytes, FontRunIterator &, BiDiRunIterator &, ScriptRunIterator &, LanguageRunIterator &, SkScalar width, RunHandler *)
void shape(const char *utf8, size_t utf8Bytes, FontRunIterator &, BiDiRunIterator &, ScriptRunIterator &, LanguageRunIterator &, const Feature *features, size_t featuresSize, SkScalar width, RunHandler *)
// static
std::unique_ptr<SkShaper> MakePrimitive()
std::unique_ptr<SkShaper> Make(sk_sp<SkFontMgr>)
void PurgeCaches()
std::unique_ptr<FontRunIterator> MakeFontMgrRunIterator(const char *utf8, size_t utf8Bytes, const SkFont &font, sk_sp<SkFontMgr> fallback)
std::unique_ptr<SkShaper::FontRunIterator> MakeFontMgrRunIterator(const char *utf8, size_t utf8Bytes, const SkFont &font, sk_sp<SkFontMgr> fallback, const char *requestName, SkFontStyle requestStyle, const SkShaper::LanguageRunIterator *)
std::unique_ptr<BiDiRunIterator> MakeBiDiRunIterator(const char *utf8, size_t utf8Bytes, uint8_t bidiLevel)
std::unique_ptr<ScriptRunIterator> MakeScriptRunIterator(const char *utf8, size_t utf8Bytes, SkFourByteTag script)
std::unique_ptr<LanguageRunIterator> MakeStdLanguageRunIterator(const char *utf8, size_t utf8Bytes)
//
// SkSize Struct
//
void set(SkScalar w, SkScalar h)
bool isZero()
bool isEmpty()
void setEmpty()
SkScalar width()
SkScalar height()
bool equals(SkScalar w, SkScalar h)
SkISize toRound()
SkISize toCeil()
SkISize toFloor()
// static
SkSize Make(SkScalar w, SkScalar h)
SkSize Make(const SkISize &src)
SkSize MakeEmpty()
//
// SkStream
//
~SkStream()
SkStream()
size_t read(void *buffer, size_t size)
size_t skip(size_t size)
size_t peek(void *, size_t)
bool isAtEnd()
bool readS8(int8_t *)
bool readS16(int16_t *)
bool readS32(int32_t *)
bool readU8(uint8_t *i)
bool readU16(uint16_t *i)
bool readU32(uint32_t *i)
bool readBool(bool *b)
bool readScalar(SkScalar *)
bool readPackedUInt(size_t *)
bool rewind()
std::unique_ptr<SkStream> duplicate()
std::unique_ptr<SkStream> fork()
bool hasPosition()
size_t getPosition()
bool seek(size_t)
bool move(long)
bool hasLength()
size_t getLength()
const void * getMemoryBase()
// static
std::unique_ptr<SkStreamAsset> MakeFromFile(const char path[])
//
// SkStreamAsset
//
bool hasLength() const override
size_t getLength() const override
std::unique_ptr<SkStreamAsset> duplicate()
std::unique_ptr<SkStreamAsset> fork()
bool hasPosition() const override
size_t getPosition() const override
bool seek(size_t position) override
bool move(long offset) override
bool rewind() override
size_t read(void *buffer, size_t size)
size_t skip(size_t size)
size_t peek(void *, size_t)
bool isAtEnd()
bool readS8(int8_t *)
bool readS16(int16_t *)
bool readS32(int32_t *)
bool readU8(uint8_t *i)
bool readU16(uint16_t *i)
bool readU32(uint32_t *i)
bool readBool(bool *b)
bool readScalar(SkScalar *)
bool readPackedUInt(size_t *)
const void * getMemoryBase()
// static
std::unique_ptr<SkStreamAsset> MakeFromFile(const char path[])
//
// SkStreamMemory
//
const void * getMemoryBase() override
std::unique_ptr<SkStreamMemory> duplicate()
std::unique_ptr<SkStreamMemory> fork()
bool hasLength() const override
size_t getLength() const override
bool hasPosition() const override
size_t getPosition() const override
bool seek(size_t position) override
bool move(long offset) override
bool rewind() override
size_t read(void *buffer, size_t size)
size_t skip(size_t size)
size_t peek(void *, size_t)
bool isAtEnd()
bool readS8(int8_t *)
bool readS16(int16_t *)
bool readS32(int32_t *)
bool readU8(uint8_t *i)
bool readU16(uint16_t *i)
bool readU32(uint32_t *i)
bool readBool(bool *b)
bool readScalar(SkScalar *)
bool readPackedUInt(size_t *)
// static
std::unique_ptr<SkStreamAsset> MakeFromFile(const char path[])
//
// SkStreamRewindable
//
bool rewind() override
std::unique_ptr<SkStreamRewindable> duplicate()
size_t read(void *buffer, size_t size)
size_t skip(size_t size)
size_t peek(void *, size_t)
bool isAtEnd()
bool readS8(int8_t *)
bool readS16(int16_t *)
bool readS32(int32_t *)
bool readU8(uint8_t *i)
bool readU16(uint16_t *i)
bool readU32(uint32_t *i)
bool readBool(bool *b)
bool readScalar(SkScalar *)
bool readPackedUInt(size_t *)
std::unique_ptr<SkStream> fork()
bool hasPosition()
size_t getPosition()
bool seek(size_t)
bool move(long)
bool hasLength()
size_t getLength()
const void * getMemoryBase()
// static
std::unique_ptr<SkStreamAsset> MakeFromFile(const char path[])
//
// SkStreamSeekable
//
std::unique_ptr<SkStreamSeekable> duplicate()
bool hasPosition() const override
size_t getPosition() const override
bool seek(size_t position) override
bool move(long offset) override
std::unique_ptr<SkStreamSeekable> fork()
bool rewind() override
size_t read(void *buffer, size_t size)
size_t skip(size_t size)
size_t peek(void *, size_t)
bool isAtEnd()
bool readS8(int8_t *)
bool readS16(int16_t *)
bool readS32(int32_t *)
bool readU8(uint8_t *i)
bool readU16(uint16_t *i)
bool readU32(uint32_t *i)
bool readBool(bool *b)
bool readScalar(SkScalar *)
bool readPackedUInt(size_t *)
bool hasLength()
size_t getLength()
const void * getMemoryBase()
// static
std::unique_ptr<SkStreamAsset> MakeFromFile(const char path[])
//
// SkString
//
SkString()
SkString(size_t len)
SkString(const char text[])
SkString(const char text[], size_t len)
SkString(const SkString &)
SkString(SkString &&)
SkString(const std::string &)
SkString(std::string_view)
~SkString()
bool isEmpty()
size_t size()
const char * data()
const char * c_str()
char operator[](size_t n)
bool equals(const SkString &)
bool equals(const char text[])
bool equals(const char text[], size_t len)
bool startsWith(const char prefixStr[])
bool startsWith(const char prefixChar)
bool endsWith(const char suffixStr[])
bool endsWith(const char suffixChar)
bool contains(const char substring[])
bool contains(const char subchar)
int find(const char substring[])
int findLastOf(const char subchar)
SkString & operator=(const SkString &)
SkString & operator=(SkString &&)
SkString & operator=(const char text[])
char * data()
char & operator[](size_t n)
void reset()
void resize(size_t len)
void set(const SkString &src)
void set(const char text[])
void set(const char text[], size_t len)
void set(std::string_view str)
void insert(size_t offset, const char text[])
void insert(size_t offset, const char text[], size_t len)
void insert(size_t offset, const SkString &str)
void insert(size_t offset, std::string_view str)
void insertUnichar(size_t offset, SkUnichar)
void insertS32(size_t offset, int32_t value)
void insertS64(size_t offset, int64_t value, int minDigits)
void insertU32(size_t offset, uint32_t value)
void insertU64(size_t offset, uint64_t value, int minDigits)
void insertHex(size_t offset, uint32_t value, int minDigits)
void insertScalar(size_t offset, SkScalar)
void append(const char text[])
void append(const char text[], size_t len)
void append(const SkString &str)
void append(std::string_view str)
void appendUnichar(SkUnichar uni)
void appendS32(int32_t value)
void appendS64(int64_t value, int minDigits)
void appendU32(uint32_t value)
void appendU64(uint64_t value, int minDigits)
void appendHex(uint32_t value, int minDigits)
void appendScalar(SkScalar value)
void prepend(const char text[])
void prepend(const char text[], size_t len)
void prepend(const SkString &str)
void prepend(std::string_view str)
void prependUnichar(SkUnichar uni)
void prependS32(int32_t value)
void prependS64(int32_t value, int minDigits)
void prependHex(uint32_t value, int minDigits)
void prependScalar(SkScalar value)
void printf(const char format[],...) SK_PRINTF_LIKE(2
void void printVAList(const char format[], va_list) SK_PRINTF_LIKE(2
void void void appendf(const char format[],...) SK_PRINTF_LIKE(2
void void void void appendVAList(const char format[], va_list) SK_PRINTF_LIKE(2
void void void void void prependf(const char format[],...) SK_PRINTF_LIKE(2
void void void void void void prependVAList(const char format[], va_list) SK_PRINTF_LIKE(2
void void void void void void void remove(size_t offset, size_t length)
SkString & operator+=(const SkString &s)
SkString & operator+=(const char text[])
SkString & operator+=(const char c)
void swap(SkString &other)
//
// SkStrokeRec
//
SkStrokeRec(InitStyle style)
SkStrokeRec(const SkPaint &, SkPaint::Style, SkScalar resScale)
SkStrokeRec(const SkPaint &, SkScalar resScale)
Style getStyle()
SkScalar getWidth()
SkScalar getMiter()
SkPaint::Cap getCap()
SkPaint::Join getJoin()
bool isHairlineStyle()
bool isFillStyle()
void setFillStyle()
void setHairlineStyle()
void setStrokeStyle(SkScalar width, bool strokeAndFill=false)
void setStrokeParams(SkPaint::Cap cap, SkPaint::Join join, SkScalar miterLimit)
SkScalar getResScale()
void setResScale(SkScalar rs)
bool needToApply()
bool applyToPath(SkPath *dst, const SkPath &src)
void applyToPaint(SkPaint *paint)
SkScalar getInflationRadius()
bool hasEqualEffect(const SkStrokeRec &other)
// static
SkScalar GetInflationRadius(const SkPaint &, SkPaint::Style)
SkScalar GetInflationRadius(SkPaint::Join, SkScalar miterLimit, SkPaint::Cap, SkScalar strokeWidth)
//
// SkSurface
//
bool isCompatible(const GrSurfaceCharacterization &characterization)
int width()
int height()
SkImageInfo imageInfo()
uint32_t generationID()
void notifyContentWillChange(ContentChangeMode mode)
GrRecordingContext * recordingContext()
skgpu::graphite::Recorder * recorder()
bool replaceBackendTexture(const GrBackendTexture &backendTexture, GrSurfaceOrigin origin, ContentChangeMode mode=kRetain_ContentChangeMode, TextureReleaseProc, ReleaseContext)
SkCanvas * getCanvas()
sk_sp<const SkCapabilities> capabilities()
sk_sp<SkSurface> makeSurface(const SkImageInfo &imageInfo)
sk_sp<SkSurface> makeSurface(int width, int height)
sk_sp<SkImage> makeImageSnapshot()
sk_sp<SkImage> makeImageSnapshot(const SkIRect &bounds)
void draw(SkCanvas *canvas, SkScalar x, SkScalar y, const SkSamplingOptions &sampling, const SkPaint *paint)
void draw(SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint)
bool peekPixels(SkPixmap *pixmap)
bool readPixels(const SkPixmap &dst, int srcX, int srcY)
bool readPixels(const SkImageInfo &dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY)
bool readPixels(const SkBitmap &dst, int srcX, int srcY)
void asyncRescaleAndReadPixels(const SkImageInfo &info, const SkIRect &srcRect, RescaleGamma rescaleGamma, RescaleMode rescaleMode, ReadPixelsCallback callback, ReadPixelsContext context)
void asyncRescaleAndReadPixelsYUV420(SkYUVColorSpace yuvColorSpace, sk_sp<SkColorSpace> dstColorSpace, const SkIRect &srcRect, const SkISize &dstSize, RescaleGamma rescaleGamma, RescaleMode rescaleMode, ReadPixelsCallback callback, ReadPixelsContext context)
void asyncRescaleAndReadPixelsYUVA420(SkYUVColorSpace yuvColorSpace, sk_sp<SkColorSpace> dstColorSpace, const SkIRect &srcRect, const SkISize &dstSize, RescaleGamma rescaleGamma, RescaleMode rescaleMode, ReadPixelsCallback callback, ReadPixelsContext context)
void writePixels(const SkPixmap &src, int dstX, int dstY)
void writePixels(const SkBitmap &src, int dstX, int dstY)
const SkSurfaceProps & props()
bool wait(int numSemaphores, const GrBackendSemaphore *waitSemaphores, bool deleteSemaphoresAfterWait=true)
bool characterize(GrSurfaceCharacterization *characterization)
bool unique()
void ref()
void unref()
// static
BackendHandleAccess kFlushRead_BackendHandleAccess
BackendHandleAccess kFlushWrite_BackendHandleAccess
BackendHandleAccess kDiscardWrite_BackendHandleAccess
//
// SkSurfaceProps
//
SkSurfaceProps()
SkSurfaceProps(uint32_t flags, SkPixelGeometry)
SkSurfaceProps(const SkSurfaceProps &)
SkSurfaceProps & operator=(const SkSurfaceProps &)
SkSurfaceProps cloneWithPixelGeometry(SkPixelGeometry newPixelGeometry)
uint32_t flags()
SkPixelGeometry pixelGeometry()
bool isUseDeviceIndependentFonts()
bool isAlwaysDither()
bool operator==(const SkSurfaceProps &that)
bool operator!=(const SkSurfaceProps &that)
//
// SVG ...
//
//
// SkTableMaskFilter
//
SkTableMaskFilter()=delete
// static
void MakeGammaTable(uint8_t table[256], SkScalar gamma)
void MakeClipTable(uint8_t table[256], uint8_t min, uint8_t max)
SkMaskFilter * Create(const uint8_t table[256])
SkMaskFilter * CreateGamma(SkScalar gamma)
SkMaskFilter * CreateClip(uint8_t min, uint8_t max)
//
// SkTextBlob
//
const SkRect & bounds()
uint32_t uniqueID()
int getIntercepts(const SkScalar bounds[2], SkScalar intervals[], const SkPaint *paint)
size_t serialize(const SkSerialProcs &procs, void *memory, size_t memory_size)
sk_sp<SkData> serialize(const SkSerialProcs &procs)
bool unique()
void ref()
void unref()
void deref()
bool refCntGreaterThan(int32_t threadIsolatedTestCnt)
// static
sk_sp<SkTextBlob> MakeFromText(const void *text, size_t byteLength, const SkFont &font, SkTextEncoding encoding=SkTextEncoding::kUTF8)
sk_sp<SkTextBlob> MakeFromString(const char *string, const SkFont &font, SkTextEncoding encoding=SkTextEncoding::kUTF8)
sk_sp<SkTextBlob> MakeFromPosTextH(const void *text, size_t byteLength, const SkScalar xpos[], SkScalar constY, const SkFont &font, SkTextEncoding encoding=SkTextEncoding::kUTF8)
sk_sp<SkTextBlob> MakeFromPosText(const void *text, size_t byteLength, const SkPoint pos[], const SkFont &font, SkTextEncoding encoding=SkTextEncoding::kUTF8)
sk_sp<SkTextBlob> MakeFromRSXform(const void *text, size_t byteLength, const SkRSXform xform[], const SkFont &font, SkTextEncoding encoding=SkTextEncoding::kUTF8)
sk_sp<SkTextBlob> Deserialize(const void *data, size_t size, const SkDeserialProcs &procs)
//
// SkTextBlobBuilder
//
SkTextBlobBuilder()
~SkTextBlobBuilder()
sk_sp<SkTextBlob> make()
const RunBuffer & allocRun(const SkFont &font, int count, SkScalar x, SkScalar y, const SkRect *bounds)
const RunBuffer & allocRunPosH(const SkFont &font, int count, SkScalar y, const SkRect *bounds)
const RunBuffer & allocRunPos(const SkFont &font, int count, const SkRect *bounds)
const RunBuffer & allocRunRSXform(const SkFont &font, int count)
const RunBuffer & allocRunText(const SkFont &font, int count, SkScalar x, SkScalar y, int textByteCount, const SkRect *bounds)
const RunBuffer & allocRunTextPosH(const SkFont &font, int count, SkScalar y, int textByteCount, const SkRect *bounds)
const RunBuffer & allocRunTextPos(const SkFont &font, int count, int textByteCount, const SkRect *bounds)
const RunBuffer & allocRunTextRSXform(const SkFont &font, int count, int textByteCount, const SkRect *bounds)
//
// SkTextBlobBuilderRunHandler
//
SkTextBlobBuilderRunHandler(const char *utf8Text, SkPoint offset)
sk_sp<SkTextBlob> makeBlob()
SkPoint endPoint()
void beginLine() override
void runInfo(const RunInfo &) override
void commitRunInfo() override
Buffer runBuffer(const RunInfo &) override
void commitRunBuffer(const RunInfo &) override
void commitLine() override
//
// SkTraceMemoryDump
//
void dumpNumericValue(const char *dumpName, const char *valueName, const char *units, uint64_t value)
void dumpStringValue(const char *, const char *, const char *)
void setMemoryBacking(const char *dumpName, const char *backingType, const char *backingObjectId)
void setDiscardableMemoryBacking(const char *dumpName, const SkDiscardableMemory &discardableMemoryObject)
LevelOfDetail getRequestedDetails()
bool shouldDumpWrappedObjects()
void dumpWrappedState(const char *, bool)
bool shouldDumpUnbudgetedObjects()
void dumpBudgetedState(const char *, bool)
//
// SkTrimPathEffect
//
sk_sp<SkPathEffect> Make(SkScalar startT, SkScalar stopT, Mode=Mode::kNormal)
//
// SkTypeface
//
SkFontStyle fontStyle()
bool isBold()
bool isItalic()
bool isFixedPitch()
int getVariationDesignPosition(SkFontArguments::VariationPosition::Coordinate coordinates[], int coordinateCount)
int getVariationDesignParameters(SkFontParameters::Variation::Axis parameters[], int parameterCount)
SkTypefaceID uniqueID()
sk_sp<SkTypeface> makeClone(const SkFontArguments &)
void serialize(SkWStream *, SerializeBehavior=SerializeBehavior::kIncludeDataIfLocal)
sk_sp<SkData> serialize(SerializeBehavior=SerializeBehavior::kIncludeDataIfLocal)
void unicharsToGlyphs(const SkUnichar uni[], int count, SkGlyphID glyphs[])
int textToGlyphs(const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount)
SkGlyphID unicharToGlyph(SkUnichar unichar)
int countGlyphs()
int countTables()
int getTableTags(SkFontTableTag tags[])
size_t getTableSize(SkFontTableTag)
size_t getTableData(SkFontTableTag tag, size_t offset, size_t length, void *data)
sk_sp<SkData> copyTableData(SkFontTableTag tag)
int getUnitsPerEm()
bool getKerningPairAdjustments(const SkGlyphID glyphs[], int count, int32_t adjustments[])
LocalizedStrings * createFamilyNameIterator()
void getFamilyName(SkString *name)
bool getPostScriptName(SkString *name)
std::unique_ptr<SkStreamAsset> openStream(int *ttcIndex)
std::unique_ptr<SkStreamAsset> openExistingStream(int *ttcIndex)
std::unique_ptr<SkScalerContext> createScalerContext(const SkScalerContextEffects &, const SkDescriptor *)
SkRect getBounds()
void filterRec(SkScalerContextRec *rec)
void getFontDescriptor(SkFontDescriptor *desc, bool *isLocal)
void * internal_private_getCTFontRef()
// static
bool Equal(const SkTypeface *facea, const SkTypeface *faceb)
sk_sp<SkTypeface> MakeDefault()
sk_sp<SkTypeface> MakeEmpty()
sk_sp<SkTypeface> MakeFromName(const char familyName[], SkFontStyle fontStyle)
sk_sp<SkTypeface> MakeFromFile(const char path[], int index)
sk_sp<SkTypeface> MakeFromStream(std::unique_ptr<SkStreamAsset> stream, int index)
sk_sp<SkTypeface> MakeFromData(sk_sp<SkData>, int index)
sk_sp<SkTypeface> MakeDeserialize(SkStream *)
sk_sp<SkTypeface> MakeDeserialize(SkStream *, sk_sp<SkFontMgr> lastResortMgr)
void Register(FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &))
//
// SkUnPreMultiply
//
// static
const Scale * GetScaleTable()
Scale GetScale(U8CPU alpha)
U8CPU ApplyScale(Scale scale, U8CPU component)
SkColor PMColorToColor(SkPMColor c)
//
// SkV2 Struct
//
bool operator==(const SkV2 v)
bool operator!=(const SkV2 v)
SkV2 operator-()
SkV2 operator+(SkV2 v)
SkV2 operator-(SkV2 v)
SkV2 operator*(SkV2 v)
void operator+=(SkV2 v)
void operator-=(SkV2 v)
void operator*=(SkV2 v)
void operator*=(SkScalar s)
void operator/=(SkScalar s)
SkScalar lengthSquared()
SkScalar length()
SkScalar dot(SkV2 v)
SkScalar cross(SkV2 v)
SkV2 normalize()
const float * ptr()
float * ptr()
// static
SkScalar Dot(SkV2 a, SkV2 b)
SkScalar Cross(SkV2 a, SkV2 b)
SkV2 Normalize(SkV2 v)
//
// SkV3 Struct
//
bool operator==(const SkV3 &v)
bool operator!=(const SkV3 &v)
SkV3 operator-()
SkV3 operator+(const SkV3 &v)
SkV3 operator-(const SkV3 &v)
SkV3 operator*(const SkV3 &v)
void operator+=(SkV3 v)
void operator-=(SkV3 v)
void operator*=(SkV3 v)
void operator*=(SkScalar s)
SkScalar lengthSquared()
SkScalar length()
SkScalar dot(const SkV3 &v)
SkV3 cross(const SkV3 &v)
SkV3 normalize()
const float * ptr()
float * ptr()
// static
SkScalar Dot(const SkV3 &a, const SkV3 &b)
SkV3 Cross(const SkV3 &a, const SkV3 &b)
SkV3 Normalize(const SkV3 &v)
//
// SkV4 Struct
//
bool operator==(const SkV4 &v)
bool operator!=(const SkV4 &v)
SkV4 operator-()
SkV4 operator+(const SkV4 &v)
SkV4 operator-(const SkV4 &v)
SkV4 operator*(const SkV4 &v)
SkScalar lengthSquared()
SkScalar length()
SkScalar dot(const SkV4 &v)
SkV4 normalize()
const float * ptr()
float * ptr()
float operator[](int i)
float & operator[](int i)
// static
SkScalar Dot(const SkV4 &a, const SkV4 &b)
SkV4 Normalize(const SkV4 &v)
//
// SkVertices
//
uint32_t uniqueID()
const SkRect & bounds()
size_t approximateSize()
SkVerticesPriv priv()
const SkVerticesPriv priv()
bool unique()
void ref()
void unref()
void deref()
bool refCntGreaterThan(int32_t threadIsolatedTestCnt)
// static
sk_sp<SkVertices> MakeCopy(VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[], int indexCount, const uint16_t indices[])
sk_sp<SkVertices> MakeCopy(VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[])
//
// SkWStream
//
~SkWStream()
SkWStream()
bool write(const void *buffer, size_t size)
void flush()
size_t bytesWritten()
bool write8(U8CPU value)
bool write16(U16CPU value)
bool write32(uint32_t v)
bool writeText(const char text[])
bool newline()
bool writeDecAsText(int32_t)
bool writeBigDecAsText(int64_t, int minDigits)
bool writeHexAsText(uint32_t, int minDigits)
bool writeScalarAsText(SkScalar)
bool writeBool(bool v)
bool writeScalar(SkScalar)
bool writePackedUInt(size_t)
bool writeStream(SkStream *input, size_t length)
// static
int SizeOfPackedUInt(size_t value)
//
// SkYUVAInfo
//
SkYUVAInfo()
SkYUVAInfo(const SkYUVAInfo &)
SkYUVAInfo(SkISize dimensions, PlaneConfig, Subsampling, SkYUVColorSpace, SkEncodedOrigin origin=kTopLeft_SkEncodedOrigin, Siting sitingX=Siting::kCentered, Siting sitingY=Siting::kCentered)
SkYUVAInfo & operator=(const SkYUVAInfo &that)
PlaneConfig planeConfig()
Subsampling subsampling()
std::tuple<int, int> planeSubsamplingFactors(int planeIdx)
SkISize dimensions()
int width()
int height()
SkYUVColorSpace yuvColorSpace()
Siting sitingX()
Siting sitingY()
SkEncodedOrigin origin()
SkMatrix originMatrix()
bool hasAlpha()
int planeDimensions(SkISize planeDimensions[kMaxPlanes])
size_t computeTotalBytes(const size_t rowBytes[kMaxPlanes], size_t planeSizes[kMaxPlanes])
int numPlanes()
int numChannelsInPlane(int i)
YUVALocations toYUVALocations(const uint32_t *channelFlags)
SkYUVAInfo makeSubsampling(SkYUVAInfo::Subsampling)
SkYUVAInfo makeDimensions(SkISize)
bool operator==(const SkYUVAInfo &that)
bool operator!=(const SkYUVAInfo &that)
bool isValid()
// static
std::tuple<int, int> SubsamplingFactors(Subsampling)
std::tuple<int, int> PlaneSubsamplingFactors(PlaneConfig, Subsampling, int planeIdx)
int PlaneDimensions(SkISize imageDimensions, PlaneConfig, Subsampling, SkEncodedOrigin, SkISize planeDimensions[kMaxPlanes])
int NumPlanes(PlaneConfig)
int NumChannelsInPlane(PlaneConfig, int i)
YUVALocations GetYUVALocations(PlaneConfig, const uint32_t *planeChannelFlags)
bool HasAlpha(PlaneConfig)
//
// SkYUVAPixmapInfo
//
SkYUVAPixmapInfo()
SkYUVAPixmapInfo(const SkYUVAInfo &, const SkColorType[kMaxPlanes], const size_t rowBytes[kMaxPlanes])
SkYUVAPixmapInfo(const SkYUVAInfo &, DataType, const size_t rowBytes[kMaxPlanes])
SkYUVAPixmapInfo(const SkYUVAPixmapInfo &)
SkYUVAPixmapInfo & operator=(const SkYUVAPixmapInfo &)
bool operator==(const SkYUVAPixmapInfo &)
bool operator!=(const SkYUVAPixmapInfo &that)
const SkYUVAInfo & yuvaInfo()
SkYUVColorSpace yuvColorSpace()
int numPlanes()
DataType dataType()
size_t rowBytes(int i)
const SkImageInfo & planeInfo(int i)
size_t computeTotalBytes(size_t planeSizes[kMaxPlanes])
bool initPixmapsFromSingleAllocation(void *memory, SkPixmap pixmaps[kMaxPlanes])
bool isValid()
bool isSupported(const SupportedDataTypes &)
// static
SkColorType DefaultColorTypeForDataType(DataType dataType, int numChannels)
std::tuple<int, DataType> NumChannelsAndDataType(SkColorType)
//
// SkYUVAPixmaps
//
SkYUVAPixmaps()
~SkYUVAPixmaps()
SkYUVAPixmaps(SkYUVAPixmaps &&that)
SkYUVAPixmaps & operator=(SkYUVAPixmaps &&that)
SkYUVAPixmaps(const SkYUVAPixmaps &)
SkYUVAPixmaps & operator=(const SkYUVAPixmaps &that)
bool isValid()
const SkYUVAInfo & yuvaInfo()
DataType dataType()
SkYUVAPixmapInfo pixmapsInfo()
int numPlanes()
const std::array<SkPixmap, kMaxPlanes> & planes()
const SkPixmap & plane(int i)
SkYUVAInfo::YUVALocations toYUVALocations()
bool ownsStorage()
// static
SkColorType RecommendedRGBAColorType(DataType)
SkYUVAPixmaps Allocate(const SkYUVAPixmapInfo &yuvaPixmapInfo)
SkYUVAPixmaps FromData(const SkYUVAPixmapInfo &, sk_sp<SkData>)
SkYUVAPixmaps MakeCopy(const SkYUVAPixmaps &src)
SkYUVAPixmaps FromExternalMemory(const SkYUVAPixmapInfo &, void *memory)
SkYUVAPixmaps FromExternalPixmaps(const SkYUVAInfo &, const SkPixmap[kMaxPlanes])