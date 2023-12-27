

//
// SkMemoryStream
//

SkMemoryStream *SkMemoryStream_new()
SkMemoryStream *SkMemoryStream_new_2(size_t length)
SkMemoryStream *SkMemoryStream_new_3(const void *data, size_t length, bool copyData)
SkMemoryStream *SkMemoryStream_new_4(sk_sp<SkData> data)
void setMemory(const void *data, size_t length, bool copyData)
void setMemoryOwned(const void *data, size_t length)
sk_sp<SkData> asData()
void setData(sk_sp<SkData> data)
void skipToAlign4()
const void * getAtPos()
size_t read(void *buffer, size_t size)
bool isAtEnd()
size_t peek(void *buffer, size_t size)
bool rewind()
std::unique_ptr<SkMemoryStream> duplicate()
size_t getPosition()
bool seek(size_t position)
bool move(long offset)
std::unique_ptr<SkMemoryStream> fork()
size_t getLength()
const void * getMemoryBase()
bool hasLength()
bool hasPosition()
size_t skip(size_t size)
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

std::unique_ptr<SkMemoryStream> MakeCopy(const void *data, size_t length)
std::unique_ptr<SkMemoryStream> MakeDirect(const void *data, size_t length)
std::unique_ptr<SkMemoryStream> Make(sk_sp<SkData> data)
std::unique_ptr<SkStreamAsset> MakeFromFile(const char path[])

//
// SkMesh
//
SkMesh()
~SkMesh()
SkMesh(const SkMesh &)
SkMesh(SkMesh &&)
SkMesh & operator=(const SkMesh &)
SkMesh & operator=(SkMesh &&)
sk_sp<SkMeshSpecification> refSpec()
SkMeshSpecification * spec()
Mode mode()
sk_sp<VertexBuffer> refVertexBuffer()
VertexBuffer * vertexBuffer()
size_t vertexOffset()
size_t vertexCount()
sk_sp<IndexBuffer> refIndexBuffer()
IndexBuffer * indexBuffer()
size_t indexOffset()
size_t indexCount()
sk_sp<const SkData> refUniforms()
const SkData * uniforms()
SkSpan<const ChildPtr> children()
SkRect bounds()
bool isValid()
// static
Result Make(sk_sp<SkMeshSpecification>, Mode, sk_sp<VertexBuffer>, size_t vertexCount, size_t vertexOffset, sk_sp<const SkData> uniforms, SkSpan<ChildPtr> children, const SkRect &bounds)
Result MakeIndexed(sk_sp<SkMeshSpecification>, Mode, sk_sp<VertexBuffer>, size_t vertexCount, size_t vertexOffset, sk_sp<IndexBuffer>, size_t indexCount, size_t indexOffset, sk_sp<const SkData> uniforms, SkSpan<ChildPtr> children, const SkRect &bounds)
//
// SkMeshSpecification
//
~SkMeshSpecification()
SkSpan<const Attribute> attributes()
size_t uniformSize()
SkSpan<const Uniform> uniforms()
SkSpan<const Child> children()
const Child * findChild(std::string_view name)
const Uniform * findUniform(std::string_view name)
const Attribute * findAttribute(std::string_view name)
const Varying * findVarying(std::string_view name)
size_t stride()
bool unique()
void ref()
void unref()
void deref()
bool refCntGreaterThan(int32_t threadIsolatedTestCnt)
// static
Result Make(SkSpan<const Attribute> attributes, size_t vertexStride, SkSpan<const Varying> varyings, const SkString &vs, const SkString &fs)
Result Make(SkSpan<const Attribute> attributes, size_t vertexStride, SkSpan<const Varying> varyings, const SkString &vs, const SkString &fs, sk_sp<SkColorSpace> cs)
Result Make(SkSpan<const Attribute> attributes, size_t vertexStride, SkSpan<const Varying> varyings, const SkString &vs, const SkString &fs, sk_sp<SkColorSpace> cs, SkAlphaType at)
//
// SkNullWStream
//
SkNullWStream()
bool write(const void *, size_t n) override
void flush() override
size_t bytesWritten() const override
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
// SkNVRefCnt<Derived>
//
SkNVRefCnt()
~SkNVRefCnt()
bool unique()
void ref()
void unref()
void deref()
bool refCntGreaterThan(int32_t threadIsolatedTestCnt)
//
// SkOpBuilder
//
void add(const SkPath &path, SkPathOp _operator)
bool resolve(SkPath *result)
//
// SkOpenTypeSVGDecoder
//
size_t approximateSize()
bool render(SkCanvas &, int upem, SkGlyphID glyphId, SkColor foregroundColor, SkSpan<SkColor> palette)
~SkOpenTypeSVGDecoder()
//
// SkOverdrawCanvas
//
SkOverdrawCanvas(SkCanvas *)
void onDrawTextBlob(const SkTextBlob *, SkScalar, SkScalar, const SkPaint &) override
void onDrawGlyphRunList(const sktext::GlyphRunList &glyphRunList, const SkPaint &paint) override
void onDrawPatch(const SkPoint[12], const SkColor[4], const SkPoint[4], SkBlendMode, const SkPaint &) override
void onDrawPaint(const SkPaint &) override
void onDrawBehind(const SkPaint &paint) override
void onDrawRect(const SkRect &, const SkPaint &) override
void onDrawRegion(const SkRegion &, const SkPaint &) override
void onDrawOval(const SkRect &, const SkPaint &) override
void onDrawArc(const SkRect &, SkScalar, SkScalar, bool, const SkPaint &) override
void onDrawDRRect(const SkRRect &, const SkRRect &, const SkPaint &) override
void onDrawRRect(const SkRRect &, const SkPaint &) override
void onDrawPoints(PointMode, size_t, const SkPoint[], const SkPaint &) override
void onDrawVerticesObject(const SkVertices *, SkBlendMode, const SkPaint &) override
void onDrawPath(const SkPath &, const SkPaint &) override
void onDrawImage2(const SkImage *, SkScalar, SkScalar, const SkSamplingOptions &, const SkPaint *) override
void onDrawImageRect2(const SkImage *, const SkRect &, const SkRect &, const SkSamplingOptions &, const SkPaint *, SrcRectConstraint) override
void onDrawImageLattice2(const SkImage *, const Lattice &, const SkRect &, SkFilterMode, const SkPaint *) override
void onDrawAtlas2(const SkImage *, const SkRSXform[], const SkRect[], const SkColor[], int, SkBlendMode, const SkSamplingOptions &, const SkRect *, const SkPaint *) override
void onDrawDrawable(SkDrawable *, const SkMatrix *) override
void onDrawPicture(const SkPicture *, const SkMatrix *, const SkPaint *) override
void onDrawAnnotation(const SkRect &, const char key[], SkData *value) override
void onDrawShadowRec(const SkPath &, const SkDrawShadowRec &) override
void onDrawEdgeAAQuad(const SkRect &, const SkPoint[4], SkCanvas::QuadAAFlags, const SkColor4f &, SkBlendMode) override
void onDrawEdgeAAImageSet2(const ImageSetEntry[], int count, const SkPoint[], const SkMatrix[], const SkSamplingOptions &, const SkPaint *, SrcRectConstraint) override
//
// SkOverdrawColorFilter
//
// static
sk_sp<SkColorFilter> MakeWithSkColors(const SkColor[kNumColors])
//
// SkPaint
//
SkPaint()
SkPaint(const SkColor4f &color, SkColorSpace *colorSpace)
SkPaint(const SkPaint &paint)
SkPaint(SkPaint &&paint)
~SkPaint()
SkPaint & operator=(const SkPaint &paint)
SkPaint & operator=(SkPaint &&paint)
void reset()
bool isAntiAlias()
void setAntiAlias(bool aa)
bool isDither()
void setDither(bool dither)
Style getStyle()
void setStyle(Style style)
void setStroke(bool)
SkColor getColor()
SkColor4f getColor4f()
void setColor(SkColor color)
void setColor(const SkColor4f &color, SkColorSpace *colorSpace)
void setColor4f(const SkColor4f &color, SkColorSpace *colorSpace)
float getAlphaf()
uint8_t getAlpha()
void setAlphaf(float a)
void setAlpha(U8CPU a)
void setARGB(U8CPU a, U8CPU r, U8CPU g, U8CPU b)
SkScalar getStrokeWidth()
void setStrokeWidth(SkScalar width)
SkScalar getStrokeMiter()
void setStrokeMiter(SkScalar miter)
Cap getStrokeCap()
void setStrokeCap(Cap cap)
Join getStrokeJoin()
void setStrokeJoin(Join join)
SkShader * getShader()
sk_sp<SkShader> refShader()
void setShader(sk_sp<SkShader> shader)
SkColorFilter * getColorFilter()
sk_sp<SkColorFilter> refColorFilter()
void setColorFilter(sk_sp<SkColorFilter> colorFilter)
std::optional<SkBlendMode> asBlendMode()
SkBlendMode getBlendMode_or(SkBlendMode defaultMode)
bool isSrcOver()
void setBlendMode(SkBlendMode mode)
SkBlender * getBlender()
sk_sp<SkBlender> refBlender()
void setBlender(sk_sp<SkBlender> blender)
SkPathEffect * getPathEffect()
sk_sp<SkPathEffect> refPathEffect()
void setPathEffect(sk_sp<SkPathEffect> pathEffect)
SkMaskFilter * getMaskFilter()
sk_sp<SkMaskFilter> refMaskFilter()
void setMaskFilter(sk_sp<SkMaskFilter> maskFilter)
SkImageFilter * getImageFilter()
sk_sp<SkImageFilter> refImageFilter()
void setImageFilter(sk_sp<SkImageFilter> imageFilter)
bool nothingToDraw()
bool canComputeFastBounds()
const SkRect & computeFastBounds(const SkRect &orig, SkRect *storage)
const SkRect & computeFastStrokeBounds(const SkRect &orig, SkRect *storage)
const SkRect & doComputeFastBounds(const SkRect &orig, SkRect *storage, Style style)
// static
int kStyleCount = kStrokeAndFill_Style + 1
int kCapCount = kLast_Cap + 1
int kJoinCount = kLast_Join + 1
//
// SkPath
//
SkPath()
SkPath(const SkPath &path)
~SkPath()
SkPath & operator=(const SkPath &path)
bool isInterpolatable(const SkPath &compare)
bool interpolate(const SkPath &ending, SkScalar weight, SkPath *out)
SkPathFillType getFillType()
void setFillType(SkPathFillType ft)
bool isInverseFillType()
void toggleInverseFillType()
bool isConvex()
bool isOval(SkRect *bounds)
bool isRRect(SkRRect *rrect)
SkPath & reset()
SkPath & rewind()
bool isEmpty()
bool isLastContourClosed()
bool isFinite()
bool isVolatile()
SkPath & setIsVolatile(bool isVolatile)
bool isLine(SkPoint line[2])
int countPoints()
SkPoint getPoint(int index)
int getPoints(SkPoint points[], int max)
int countVerbs()
int getVerbs(uint8_t verbs[], int max)
size_t approximateBytesUsed()
void swap(SkPath &other)
const SkRect & getBounds()
void updateBoundsCache()
SkRect computeTightBounds()
bool conservativelyContainsRect(const SkRect &rect)
void incReserve(int extraPtCount)
SkPath & moveTo(SkScalar x, SkScalar y)
SkPath & moveTo(const SkPoint &p)
SkPath & rMoveTo(SkScalar dx, SkScalar dy)
SkPath & lineTo(SkScalar x, SkScalar y)
SkPath & lineTo(const SkPoint &p)
SkPath & rLineTo(SkScalar dx, SkScalar dy)
SkPath & quadTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2)
SkPath & quadTo(const SkPoint &p1, const SkPoint &p2)
SkPath & rQuadTo(SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2)
SkPath & conicTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w)
SkPath & conicTo(const SkPoint &p1, const SkPoint &p2, SkScalar w)
SkPath & rConicTo(SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar w)
SkPath & cubicTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3)
SkPath & cubicTo(const SkPoint &p1, const SkPoint &p2, const SkPoint &p3)
SkPath & rCubicTo(SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar dx3, SkScalar dy3)
SkPath & arcTo(const SkRect &oval, SkScalar startAngle, SkScalar sweepAngle, bool forceMoveTo)
SkPath & arcTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar radius)
SkPath & arcTo(const SkPoint p1, const SkPoint p2, SkScalar radius)
SkPath & arcTo(SkScalar rx, SkScalar ry, SkScalar xAxisRotate, ArcSize largeArc, SkPathDirection sweep, SkScalar x, SkScalar y)
SkPath & arcTo(const SkPoint r, SkScalar xAxisRotate, ArcSize largeArc, SkPathDirection sweep, const SkPoint xy)
SkPath & rArcTo(SkScalar rx, SkScalar ry, SkScalar xAxisRotate, ArcSize largeArc, SkPathDirection sweep, SkScalar dx, SkScalar dy)
SkPath & close()
bool isRect(SkRect *rect, bool *isClosed, SkPathDirection *direction)
SkPath & addRect(const SkRect &rect, SkPathDirection dir, unsigned start)
SkPath & addRect(const SkRect &rect, SkPathDirection dir=SkPathDirection::kCW)
SkPath & addRect(SkScalar left, SkScalar top, SkScalar right, SkScalar bottom, SkPathDirection dir=SkPathDirection::kCW)
SkPath & addOval(const SkRect &oval, SkPathDirection dir=SkPathDirection::kCW)
SkPath & addOval(const SkRect &oval, SkPathDirection dir, unsigned start)
SkPath & addCircle(SkScalar x, SkScalar y, SkScalar radius, SkPathDirection dir=SkPathDirection::kCW)
SkPath & addArc(const SkRect &oval, SkScalar startAngle, SkScalar sweepAngle)
SkPath & addRoundRect(const SkRect &rect, SkScalar rx, SkScalar ry, SkPathDirection dir=SkPathDirection::kCW)
SkPath & addRoundRect(const SkRect &rect, const SkScalar radii[], SkPathDirection dir=SkPathDirection::kCW)
SkPath & addRRect(const SkRRect &rrect, SkPathDirection dir=SkPathDirection::kCW)
SkPath & addRRect(const SkRRect &rrect, SkPathDirection dir, unsigned start)
SkPath & addPoly(const SkPoint pts[], int count, bool close)
SkPath & addPoly(const std::initializer_list<SkPoint> &list, bool close)
SkPath & addPath(const SkPath &src, SkScalar dx, SkScalar dy, AddPathMode mode=kAppend_AddPathMode)
SkPath & addPath(const SkPath &src, AddPathMode mode=kAppend_AddPathMode)
SkPath & addPath(const SkPath &src, const SkMatrix &matrix, AddPathMode mode=kAppend_AddPathMode)
SkPath & reverseAddPath(const SkPath &src)
void offset(SkScalar dx, SkScalar dy, SkPath *dst)
void offset(SkScalar dx, SkScalar dy)
void transform(const SkMatrix &matrix, SkPath *dst, SkApplyPerspectiveClip pc=SkApplyPerspectiveClip::kYes)
void transform(const SkMatrix &matrix, SkApplyPerspectiveClip pc=SkApplyPerspectiveClip::kYes)
SkPath makeTransform(const SkMatrix &m, SkApplyPerspectiveClip pc=SkApplyPerspectiveClip::kYes)
SkPath makeScale(SkScalar sx, SkScalar sy)
bool getLastPt(SkPoint *lastPt)
void setLastPt(SkScalar x, SkScalar y)
void setLastPt(const SkPoint &p)
uint32_t getSegmentMasks()
bool contains(SkScalar x, SkScalar y)
void dump(SkWStream *stream, bool dumpAsHex)
void dump()
void dumpHex()
void dumpArrays(SkWStream *stream, bool dumpAsHex)
void dumpArrays()
size_t writeToMemory(void *buffer)
sk_sp<SkData> serialize()
size_t readFromMemory(const void *buffer, size_t length)
uint32_t getGenerationID()
bool isValid()
// static
SkPath Make(const SkPoint[], int pointCount, const uint8_t[], int verbCount, const SkScalar[], int conicWeightCount, SkPathFillType, bool isVolatile=false)
SkPath Rect(const SkRect &, SkPathDirection=SkPathDirection::kCW, unsigned startIndex)
SkPath Oval(const SkRect &, SkPathDirection=SkPathDirection::kCW)
SkPath Oval(const SkRect &, SkPathDirection, unsigned startIndex)
SkPath Circle(SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir=SkPathDirection::kCW)
SkPath RRect(const SkRRect &, SkPathDirection dir=SkPathDirection::kCW)
SkPath RRect(const SkRRect &, SkPathDirection, unsigned startIndex)
SkPath RRect(const SkRect &bounds, SkScalar rx, SkScalar ry, SkPathDirection dir=SkPathDirection::kCW)
SkPath Polygon(const SkPoint pts[], int count, bool isClosed, SkPathFillType=SkPathFillType::kWinding, bool isVolatile=false)
SkPath Polygon(const std::initializer_list<SkPoint> &list, bool isClosed, SkPathFillType fillType=SkPathFillType::kWinding, bool isVolatile=false)
SkPath Line(const SkPoint a, const SkPoint b)
bool IsLineDegenerate(const SkPoint &p1, const SkPoint &p2, bool exact)
bool IsQuadDegenerate(const SkPoint &p1, const SkPoint &p2, const SkPoint &p3, bool exact)
bool IsCubicDegenerate(const SkPoint &p1, const SkPoint &p2, const SkPoint &p3, const SkPoint &p4, bool exact)
int ConvertConicToQuads(const SkPoint &p0, const SkPoint &p1, const SkPoint &p2, SkScalar w, SkPoint pts[], int pow2)
//
// SkPath1DPathEffect
//
// static
sk_sp<SkPathEffect> Make(const SkPath &path, SkScalar advance, SkScalar phase, Style)
void RegisterFlattenables()
//
// SkPath2DPathEffect
//
// static
sk_sp<SkPathEffect> Make(const SkMatrix &matrix, const SkPath &path)
void RegisterFlattenables()
//
// SkPathBuilder
//
SkPathBuilder()
SkPathBuilder(SkPathFillType)
SkPathBuilder(const SkPath &)
SkPathBuilder(const SkPathBuilder &)
~SkPathBuilder()
SkPathBuilder & operator=(const SkPath &)
SkPathBuilder & operator=(const SkPathBuilder &)
SkPathFillType fillType()
SkRect computeBounds()
SkPath snapshot()
SkPath detach()
SkPathBuilder & setFillType(SkPathFillType ft)
SkPathBuilder & setIsVolatile(bool isVolatile)
SkPathBuilder & reset()
SkPathBuilder & moveTo(SkPoint pt)
SkPathBuilder & moveTo(SkScalar x, SkScalar y)
SkPathBuilder & lineTo(SkPoint pt)
SkPathBuilder & lineTo(SkScalar x, SkScalar y)
SkPathBuilder & quadTo(SkPoint pt1, SkPoint pt2)
SkPathBuilder & quadTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2)
SkPathBuilder & quadTo(const SkPoint pts[2])
SkPathBuilder & conicTo(SkPoint pt1, SkPoint pt2, SkScalar w)
SkPathBuilder & conicTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w)
SkPathBuilder & conicTo(const SkPoint pts[2], SkScalar w)
SkPathBuilder & cubicTo(SkPoint pt1, SkPoint pt2, SkPoint pt3)
SkPathBuilder & cubicTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3)
SkPathBuilder & cubicTo(const SkPoint pts[3])
SkPathBuilder & close()
SkPathBuilder & polylineTo(const SkPoint pts[], int count)
SkPathBuilder & polylineTo(const std::initializer_list<SkPoint> &list)
SkPathBuilder & rLineTo(SkPoint pt)
SkPathBuilder & rLineTo(SkScalar x, SkScalar y)
SkPathBuilder & rQuadTo(SkPoint pt1, SkPoint pt2)
SkPathBuilder & rQuadTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2)
SkPathBuilder & rConicTo(SkPoint p1, SkPoint p2, SkScalar w)
SkPathBuilder & rConicTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w)
SkPathBuilder & rCubicTo(SkPoint pt1, SkPoint pt2, SkPoint pt3)
SkPathBuilder & rCubicTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3)
SkPathBuilder & arcTo(const SkRect &oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg, bool forceMoveTo)
SkPathBuilder & arcTo(SkPoint p1, SkPoint p2, SkScalar radius)
SkPathBuilder & arcTo(SkPoint r, SkScalar xAxisRotate, ArcSize largeArc, SkPathDirection sweep, SkPoint xy)
SkPathBuilder & addArc(const SkRect &oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg)
SkPathBuilder & addRect(const SkRect &, SkPathDirection, unsigned startIndex)
SkPathBuilder & addOval(const SkRect &, SkPathDirection, unsigned startIndex)
SkPathBuilder & addRRect(const SkRRect &, SkPathDirection, unsigned startIndex)
SkPathBuilder & addRect(const SkRect &rect, SkPathDirection dir=SkPathDirection::kCW)
SkPathBuilder & addOval(const SkRect &rect, SkPathDirection dir=SkPathDirection::kCW)
SkPathBuilder & addRRect(const SkRRect &rrect, SkPathDirection dir=SkPathDirection::kCW)
SkPathBuilder & addCircle(SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir=SkPathDirection::kCW)
SkPathBuilder & addPolygon(const SkPoint pts[], int count, bool isClosed)
SkPathBuilder & addPolygon(const std::initializer_list<SkPoint> &list, bool isClosed)
SkPathBuilder & addPath(const SkPath &)
void incReserve(int extraPtCount, int extraVerbCount)
void incReserve(int extraPtCount)
SkPathBuilder & offset(SkScalar dx, SkScalar dy)
SkPathBuilder & toggleInverseFillType()
//
// SkPathEffect
//
DashType asADash(DashInfo *info)
bool filterPath(SkPath *dst, const SkPath &src, SkStrokeRec *, const SkRect *cullR)
bool filterPath(SkPath *dst, const SkPath &src, SkStrokeRec *, const SkRect *cullR, const SkMatrix &ctm)
bool needsCTM()
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
sk_sp<SkPathEffect> MakeSum(sk_sp<SkPathEffect> first, sk_sp<SkPathEffect> second)
sk_sp<SkPathEffect> MakeCompose(sk_sp<SkPathEffect> outer, sk_sp<SkPathEffect> inner)
SkFlattenable::Type GetFlattenableType()
sk_sp<SkPathEffect> Deserialize(const void *data, size_t size, const SkDeserialProcs *procs)
Factory NameToFactory(const char name[])
const char * FactoryToName(Factory)
void Register(const char name[], Factory)
sk_sp<SkFlattenable> Deserialize(Type, const void *data, size_t length, const SkDeserialProcs *procs)
//
// SkPathMeasure
//
SkPathMeasure()
SkPathMeasure(const SkPath &path, bool forceClosed, SkScalar resScale)
~SkPathMeasure()
SkPathMeasure(SkPathMeasure &&)
SkPathMeasure & operator=(SkPathMeasure &&)
void setPath(const SkPath *, bool forceClosed)
SkScalar getLength()
bool getPosTan(SkScalar distance, SkPoint *position, SkVector *tangent)
bool getMatrix(SkScalar distance, SkMatrix *matrix, MatrixFlags flags=kGetPosAndTan_MatrixFlag)
bool getSegment(SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo)
bool isClosed()
bool nextContour()
//
// SkPicture
//
~SkPicture() override
void playback(SkCanvas *canvas, AbortCallback *callback)
SkRect cullRect()
uint32_t uniqueID()
sk_sp<SkData> serialize(const SkSerialProcs *procs)
void serialize(SkWStream *stream, const SkSerialProcs *procs)
int approximateOpCount(bool nested=false)
size_t approximateBytesUsed()
sk_sp<SkShader> makeShader(SkTileMode tmx, SkTileMode tmy, SkFilterMode mode, const SkMatrix *localMatrix, const SkRect *tileRect)
sk_sp<SkShader> makeShader(SkTileMode tmx, SkTileMode tmy, SkFilterMode mode)
bool unique()
void ref()
void unref()
// static
sk_sp<SkPicture> MakeFromStream(SkStream *stream, const SkDeserialProcs *procs)
sk_sp<SkPicture> MakeFromData(const SkData *data, const SkDeserialProcs *procs)
sk_sp<SkPicture> MakeFromData(const void *data, size_t size, const SkDeserialProcs *procs)
sk_sp<SkPicture> MakePlaceholder(SkRect cull)
//
// SkPictureRecorder
//
SkPictureRecorder()
~SkPictureRecorder()
SkCanvas * beginRecording(const SkRect &bounds, sk_sp<SkBBoxHierarchy> bbh)
SkCanvas * beginRecording(const SkRect &bounds, SkBBHFactory *bbhFactory)
SkCanvas * beginRecording(SkScalar width, SkScalar height, SkBBHFactory *bbhFactory)
SkCanvas * getRecordingCanvas()
sk_sp<SkPicture> finishRecordingAsPicture()
sk_sp<SkPicture> finishRecordingAsPictureWithCull(const SkRect &cullRect)
sk_sp<SkDrawable> finishRecordingAsDrawable()
//
// SkPixelRef
//
SkPixelRef(int width, int height, void *addr, size_t rowBytes)
~SkPixelRef() override
SkISize dimensions()
int width()
int height()
void * pixels()
size_t rowBytes()
uint32_t getGenerationID()
void notifyPixelsChanged()
bool isImmutable()
void setImmutable()
void addGenIDChangeListener(sk_sp<SkIDChangeListener> listener)
void notifyAddedToCache()
SkDiscardableMemory * diagnostic_only_getDiscardable()
bool unique()
void ref()
void unref()
//
// SkPixmap
//
SkPixmap()
SkPixmap(const SkImageInfo &info, const void *addr, size_t rowBytes)
void reset()
void reset(const SkImageInfo &info, const void *addr, size_t rowBytes)
void setColorSpace(sk_sp<SkColorSpace> colorSpace)
bool reset(const SkMask &mask)
bool extractSubset(SkPixmap *subset, const SkIRect &area)
const SkImageInfo & info()
size_t rowBytes()
const void * addr()
int width()
int height()
SkISize dimensions()
SkColorType colorType()
SkAlphaType alphaType()
SkColorSpace * colorSpace()
sk_sp<SkColorSpace> refColorSpace()
bool isOpaque()
SkIRect bounds()
int rowBytesAsPixels()
int shiftPerPixel()
size_t computeByteSize()
bool computeIsOpaque()
SkColor getColor(int x, int y)
SkColor4f getColor4f(int x, int y)
float getAlphaf(int x, int y)
const void * addr(int x, int y)
const uint8_t * addr8()
const uint16_t * addr16()
const uint32_t * addr32()
const uint64_t * addr64()
const uint16_t * addrF16()
const uint8_t * addr8(int x, int y)
const uint16_t * addr16(int x, int y)
const uint32_t * addr32(int x, int y)
const uint64_t * addr64(int x, int y)
const uint16_t * addrF16(int x, int y)
void * writable_addr()
void * writable_addr(int x, int y)
uint8_t * writable_addr8(int x, int y)
uint16_t * writable_addr16(int x, int y)
uint32_t * writable_addr32(int x, int y)
uint64_t * writable_addr64(int x, int y)
uint16_t * writable_addrF16(int x, int y)
bool readPixels(const SkImageInfo &dstInfo, void *dstPixels, size_t dstRowBytes)
bool readPixels(const SkImageInfo &dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY)
bool readPixels(const SkPixmap &dst, int srcX, int srcY)
bool readPixels(const SkPixmap &dst)
bool scalePixels(const SkPixmap &dst, const SkSamplingOptions &)
bool erase(SkColor color, const SkIRect &subset)
bool erase(SkColor color)
bool erase(const SkColor4f &color, const SkIRect *subset)
//
// SkPoint3
//
SkScalar x()
SkScalar y()
SkScalar z()
void set(SkScalar x, SkScalar y, SkScalar z)
SkScalar length()
bool normalize()
SkPoint3 makeScale(SkScalar scale)
void scale(SkScalar value)
SkPoint3 operator-()
void operator+=(const SkPoint3 &v)
void operator-=(const SkPoint3 &v)
bool isFinite()
SkScalar dot(const SkPoint3 &vec)
SkPoint3 cross(const SkPoint3 &vec)
// static
SkPoint3 Make(SkScalar x, SkScalar y, SkScalar z)
SkScalar Length(SkScalar x, SkScalar y, SkScalar z)
SkScalar DotProduct(const SkPoint3 &a, const SkPoint3 &b)
SkPoint3 CrossProduct(const SkPoint3 &a, const SkPoint3 &b)
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