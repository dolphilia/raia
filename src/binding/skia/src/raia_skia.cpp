#include "raia_skia.h"

// Skiaヘッダのインクルード
#include "include/codec/SkPngDecoder.h"
#include "include/core/SkAnnotation.h"
#include "include/core/SkBBHFactory.h"
#include "include/core/SkBitmap.h"
#include "include/core/SkBlender.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkCapabilities.h"
#include "include/core/SkColorFilter.h"
#include "include/core/SkColorPriv.h"
#include "include/core/SkColorTable.h"
#include "include/core/SkContourMeasure.h"
#include "include/core/SkCubicMap.h"
#include "include/core/SkData.h"
#include "include/core/SkDataTable.h"
#include "include/core/SkDocument.h"
#include "include/core/SkDrawable.h"
#include "include/core/SkExecutor.h"
#include "include/core/SkFlattenable.h"
#include "include/core/SkFont.h"
#include "include/core/SkFontArguments.h"
#include "include/core/SkFontMetrics.h"
#include "include/core/SkFontMgr.h"
#include "include/core/SkFontStyle.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkPathEffect.h"
#include "include/core/SkImage.h"
#include "include/core/SkImageGenerator.h"
#include "include/core/SkMaskFilter.h"
#include "include/core/SkMesh.h"
#include "include/core/SkOpenTypeSVGDecoder.h"
#include "include/core/SkOverdrawCanvas.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkPathBuilder.h"
#include "include/core/SkPathMeasure.h"
#include "include/core/SkPicture.h"
#include "include/core/SkPictureRecorder.h"
#include "include/core/SkPixelRef.h"
#include "include/core/SkPoint3.h"
#include "include/core/SkRect.h"
#include "include/core/SkRefCnt.h"
#include "include/core/SkRegion.h"
#include "include/core/SkRRect.h"
#include "include/core/SkRSXform.h"
#include "include/core/SkSamplingOptions.h"
#include "include/core/SkShader.h"
#include "include/core/SkStream.h"
#include "include/core/SkStrokeRec.h"
#include "include/core/SkSurface.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkTraceMemoryDump.h"
#include "include/core/SkUnPreMultiply.h"
#include "include/core/SkVertices.h"
#include "include/effects/Sk1DPathEffect.h"
#include "include/effects/Sk2DPathEffect.h"
#include "include/effects/SkBlenders.h"
#include "include/effects/SkColorMatrix.h"
#include "include/effects/SkColorMatrixFilter.h"
#include "include/effects/SkCornerPathEffect.h"
#include "include/effects/SkDashPathEffect.h"
#include "include/effects/SkDiscretePathEffect.h"
#include "include/effects/SkGradientShader.h"
#include "include/effects/SkHighContrastFilter.h"
#include "include/effects/SkImageFilters.h"
//#include "include/effects/SkLayerDrawLooper.h"
#include "include/effects/SkLumaColorFilter.h"
#include "include/effects/SkOverdrawColorFilter.h"
#include "include/effects/SkImageFilters.h"
#include "include/effects/SkShaderMaskFilter.h"
#include "include/effects/SkTableMaskFilter.h"
#include "include/effects/SkTrimPathEffect.h"
#include "include/gpu/graphite/Recorder.h"
#include "include/pathops/SkPathOps.h"
#include "modules/skshaper/include/SkShaper.h"
#include "binding/sk_canvas.h"
#include "binding/sk_data.h"
#include "binding/sk_paint.h"
#include "binding/sk_path.h"
#include "binding/sk_rect.h"
#include "binding/sk_stream.h"

#include <utility>

extern "C" {

//



//
// SkBBHFactory - abstract
//

//
// SkDrawLooper
//

/*
SkDrawLooper::Context * SkDrawLooper_makeContext(SkDrawLooper *draw_looper, SkArenaAlloc *arena_alloc) {
    return draw_looper->makeContext(arena_alloc);
}

bool SkDrawLooper_canComputeFastBounds(SkDrawLooper *draw_looper, const SkPaint *paint) {
    return draw_looper->canComputeFastBounds(*paint);
}

void SkDrawLooper_computeFastBounds(SkDrawLooper *draw_looper, const SkPaint *paint, const SkRect *src, SkRect *dst) {
    draw_looper->computeFastBounds(*paint, *src, dst);
}

bool SkDrawLooper_asABlurShadow(SkDrawLooper *draw_looper, SkDrawLooper::BlurShadowRec *blur_shadow_rec) {
    return draw_looper->asABlurShadow(blur_shadow_rec);
}

SkFlattenable::Type SkDrawLooper_getFlattenableType(SkDrawLooper *draw_looper) {
    return draw_looper->getFlattenableType();
}

void SkDrawLooper_apply(SkDrawLooper *draw_looper, SkCanvas *canvas, const SkPaint *paint, std::function< void(SkCanvas *, const SkPaint &)> fn) { // @TODO
    draw_looper->apply(canvas, *paint, std::move(fn));
}

SkDrawLooper::Factory SkDrawLooper_getFactory(SkDrawLooper *draw_looper) {
    return draw_looper->getFactory();
}

const char * SkDrawLooper_getTypeName(SkDrawLooper *draw_looper) {
    return draw_looper->getTypeName();
}

void SkDrawLooper_flatten(SkDrawLooper *draw_looper, SkWriteBuffer *write_buffer) {
    draw_looper->flatten(*write_buffer);
}

void SkDrawLooper_serialize(const char *sk_data_key_out, SkDrawLooper *draw_looper, const SkSerialProcs *serial_procs) {
    static_sk_data[sk_data_key_out] = draw_looper->serialize(serial_procs);
}

size_t SkDrawLooper_serialize_2(SkDrawLooper *draw_looper, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) {
    return draw_looper->serialize(memory, memory_size, serial_procs);
}

bool SkDrawLooper_unique(SkDrawLooper *draw_looper) {
    return draw_looper->unique();
}

void SkDrawLooper_ref(SkDrawLooper *draw_looper) {
    draw_looper->ref();
}

void SkDrawLooper_unref(SkDrawLooper *draw_looper) {
    draw_looper->unref();
}

// static

SkFlattenable::Type SkDrawLooper_GetFlattenableType() {
    return SkDrawLooper::GetFlattenableType();
}

void SkDrawLooper_Deserialize(const char *sk_draw_looper_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_draw_looper[sk_draw_looper_key_out] = SkDrawLooper::Deserialize(data, size, procs);
}

SkDrawLooper::Factory SkDrawLooper_NameToFactory(const char name[]) {
    SkDrawLooper::NameToFactory(name);
}

const char * SkDrawLooper_FactoryToName(SkDrawLooper::Factory factory) {
    return SkDrawLooper::FactoryToName(factory);
}

void SkDrawLooper_Register(const char name[], SkDrawLooper::Factory factory) {
    SkDrawLooper::Register(name, factory);
}

*/

//
// SkLayerDrawLooper
//

/*
void SkLayerDrawLooper_delete(SkLayerDrawLooper *layer_draw_looper) {}
SkDrawLooper::Context * SkLayerDrawLooper_makeContext(SkLayerDrawLooper *layer_draw_looper, SkArenaAlloc *arena_alloc) {}
bool SkLayerDrawLooper_asABlurShadow(SkLayerDrawLooper *layer_draw_looper, SkLayerDrawLooper::BlurShadowRec *rec) {}
bool canComputeFastBounds(const SkPaint &paint)
void computeFastBounds(const SkPaint &paint, const SkRect &src, SkRect *dst)
SkFlattenable::Type getFlattenableType() const override
void apply(SkCanvas *canvas, const SkPaint &paint, std::function<void(SkCanvas *, const SkPaint &)>)
Factory getFactory()
const char * getTypeName()
sk_sp<SkData> serialize(const SkSerialProcs *)
size_t serialize(void *memory, size_t memory_size, const SkSerialProcs *)
bool unique()
void ref()
void unref()

// static

SkFlattenable::Type GetFlattenableType()
sk_sp<SkDrawLooper> Deserialize(const void *data, size_t size, const SkDeserialProcs *procs)
sk_sp<SkFlattenable> Deserialize(Type, const void *data, size_t length, const SkDeserialProcs *procs)
Factory NameToFactory(const char name[])
const char * FactoryToName(Factory)
void Register(const char name[], Factory)

*/

//
// SkMesh
//

// SkMesh & operator=(const SkMesh &)
// SkMesh & operator=(SkMesh &&)

/*
SkMesh *SkMesh_new() {
    return new SkMesh();
}

SkMesh *SkMesh_new_2(const SkMesh *mesh) {
    return new SkMesh(*mesh);
}

SkMesh *SkMesh_new_3(SkMesh &&mesh) { //@TODO
    return new SkMesh(mesh);
}

void SkMesh_delete(SkMesh *mesh) {
    delete mesh;
}

void SkMesh_refSpec(const char *sk_mesh_specification_key_out, SkMesh *mesh) {
    static_sk_mesh_specification[sk_mesh_specification_key_out] = mesh->refSpec();
}

SkMeshSpecification * SkMesh_spec(SkMesh *mesh) {
    return mesh->spec();
}

SkMesh::Mode SkMesh_mode(SkMesh *mesh) {
    return mesh->mode();
}

void SkMesh_refVertexBuffer(const char *sk_mesh_vertex_buffer_key_out, SkMesh *mesh) {
    static_sk_mesh_vertex_buffer[sk_mesh_vertex_buffer_key_out] = mesh->refVertexBuffer();
}

SkMesh::VertexBuffer * SkMesh_vertexBuffer(SkMesh *mesh) {
    return mesh->vertexBuffer();
}

size_t SkMesh_vertexOffset(SkMesh *mesh) {
    return mesh->vertexOffset();
}

size_t SkMesh_vertexCount(SkMesh *mesh) {
    return mesh->vertexCount();
}

void SkMesh_refIndexBuffer(const char *sk_mesh_index_buffer_key_out, SkMesh *mesh) {
    static_sk_mesh_index_buffer[sk_mesh_index_buffer_key_out] = mesh->refIndexBuffer();
}

SkMesh::IndexBuffer * SkMesh_indexBuffer(SkMesh *mesh) {
    return mesh->indexBuffer();
}

size_t SkMesh_indexOffset(SkMesh *mesh) {
    return mesh->indexOffset();
}

size_t SkMesh_indexCount(SkMesh *mesh) {
    return mesh->indexCount();
}

void SkMesh_refUniforms(const char *sk_data_key_out, SkMesh *mesh) {
    static_const_sk_data[sk_data_key_out] = mesh->refUniforms();
}

const SkData * SkMesh_uniforms(SkMesh *mesh) {
    return mesh->uniforms();
}

void SkMesh_children(const char *sk_mesh_child_ptr_key_out, SkMesh *mesh) {
    static_const_sk_mesh_child_ptr[sk_mesh_child_ptr_key_out] = mesh->children();
}

SkRect SkMesh_bounds(SkMesh *mesh) {
    return mesh->bounds();
}

bool SkMesh_isValid(SkMesh *mesh) {
    return mesh->isValid();
}

SkMesh::Result SkMesh_Make(const char *sk_mesh_specification_key_in, const char *sk_mesh_vertex_buffer_key_in, const char *sk_data_key_in, const char *sk_mesh_child_ptr_key_in, SkMesh::Mode mode, size_t vertexCount, size_t vertexOffset, const SkRect *bounds) {
    return SkMesh::Make(static_sk_mesh_specification[sk_mesh_specification_key_in], mode, static_sk_mesh_vertex_buffer[sk_mesh_vertex_buffer_key_in], vertexCount, vertexOffset, static_const_sk_data[sk_data_key_in], static_sk_mesh_child_ptr[sk_mesh_child_ptr_key_in], *bounds);
}

SkMesh::Result SkMesh_MakeIndexed(const char *sk_mesh_specification_key_in, const char *sk_mesh_vertex_buffer_key_in, const char *sk_mesh_index_buffer_key_in, const char *sk_data_key_in, const char *sk_mesh_child_ptr_key_in, SkMesh::Mode mode, size_t vertexCount, size_t vertexOffset, size_t indexCount, size_t indexOffset, const SkRect *bounds) {
    return SkMesh::MakeIndexed(static_sk_mesh_specification[sk_mesh_specification_key_in], mode, static_sk_mesh_vertex_buffer[sk_mesh_vertex_buffer_key_in], vertexCount, vertexOffset, static_sk_mesh_index_buffer[sk_mesh_index_buffer_key_in], indexCount, indexOffset, static_const_sk_data[sk_data_key_in], static_sk_mesh_child_ptr[sk_mesh_child_ptr_key_in], *bounds);
}
*/

//
// SkMeshSpecification
//

/*
void SkMeshSpecification_delete(SkMeshSpecification *mesh_specification) {
    delete mesh_specification;
}

SkSpan<const SkMeshSpecification::Attribute> SkMeshSpecification_attributes(SkMeshSpecification *mesh_specification) {
    return mesh_specification->attributes();
}

size_t SkMeshSpecification_uniformSize(SkMeshSpecification *mesh_specification) {
    return mesh_specification->uniformSize();
}

SkSpan<const SkMeshSpecification::Uniform> SkMeshSpecification_uniforms(SkMeshSpecification *mesh_specification) {
    return mesh_specification->uniforms();
}

SkSpan<const SkMeshSpecification::Child> SkMeshSpecification_children(SkMeshSpecification *mesh_specification) {
    return mesh_specification->children();
}

const SkMeshSpecification::Child * SkMeshSpecification_findChild(SkMeshSpecification *mesh_specification, std::string_view name) {
    return mesh_specification->findChild(name);
}

const SkMeshSpecification::Uniform * SkMeshSpecification_findUniform(SkMeshSpecification *mesh_specification, std::string_view name) {
    return mesh_specification->findUniform(name);
}

const SkMeshSpecification::Attribute * SkMeshSpecification_findAttribute(SkMeshSpecification *mesh_specification, std::string_view name) {
    return mesh_specification->findAttribute(name);
}

const SkMeshSpecification::Varying * SkMeshSpecification_findVarying(SkMeshSpecification *mesh_specification, std::string_view name) {
    return mesh_specification->findVarying(name);
}

size_t SkMeshSpecification_stride(SkMeshSpecification *mesh_specification) {
    return mesh_specification->stride();
}

bool SkMeshSpecification_unique(SkMeshSpecification *mesh_specification) {
    return mesh_specification->unique();
}

void SkMeshSpecification_ref(SkMeshSpecification *mesh_specification) {
    mesh_specification->ref();
}

void SkMeshSpecification_unref(SkMeshSpecification *mesh_specification) {
    mesh_specification->unref();
}

void SkMeshSpecification_deref(SkMeshSpecification *mesh_specification) {
    mesh_specification->deref();
}

bool SkMeshSpecification_refCntGreaterThan(SkMeshSpecification *mesh_specification, int32_t threadIsolatedTestCnt) {
    return mesh_specification->refCntGreaterThan(threadIsolatedTestCnt);
}

// static

SkMeshSpecification::Result SkMeshSpecification_Make(SkSpan<const SkMeshSpecification::Attribute> attributes, size_t vertexStride, SkSpan<const SkMeshSpecification::Varying> varyings, const SkString &vs, const SkString &fs) {
    return SkMeshSpecification::Make(attributes, vertexStride, varyings, vs, fs);
}

SkMeshSpecification::Result SkMeshSpecification_Make_2(SkSpan<const SkMeshSpecification::Attribute> attributes, size_t vertexStride, SkSpan<const SkMeshSpecification::Varying> varyings, const SkString &vs, const SkString &fs, sk_sp<SkColorSpace> cs) {
    return SkMeshSpecification::Make(attributes, vertexStride, varyings, vs, fs, cs);
}

SkMeshSpecification::Result SkMeshSpecification_Make_3(SkSpan<const SkMeshSpecification::Attribute> attributes, size_t vertexStride, SkSpan<const SkMeshSpecification::Varying> varyings, const SkString &vs, const SkString &fs, sk_sp<SkColorSpace> cs, SkAlphaType at) {
    return SkMeshSpecification::Make(attributes, vertexStride, varyings, vs, fs, cs, at);
}
*/

//
// SkNullWStream
//


/*
SkNullWStream *SkNullWStream_new(SkNullWStream *null_w_stream) {
    return new SkNullWStream();
}

void SkNullWStream_delete(SkNullWStream *null_w_stream) {
    delete null_w_stream;
}

bool SkNullWStream_write(SkNullWStream *null_w_stream, const void *v, size_t n) {
    return null_w_stream->write(v, n);
}

void SkNullWStream_flush(SkNullWStream *null_w_stream) {
    null_w_stream->flush();
}

size_t SkNullWStream_bytesWritten(SkNullWStream *null_w_stream) {
    return null_w_stream->bytesWritten();
}

bool SkNullWStream_write8(SkNullWStream *null_w_stream, U8CPU value) {
    return null_w_stream->write8(value);
}

bool SkNullWStream_write16(SkNullWStream *null_w_stream, U16CPU value) {
    return null_w_stream->write16(value);
}

bool SkNullWStream_write32(SkNullWStream *null_w_stream, uint32_t v) {
    return null_w_stream->write32(v);
}

bool SkNullWStream_writeText(SkNullWStream *null_w_stream, const char text[]) {
    return null_w_stream->writeText(text);
}

bool SkNullWStream_newline(SkNullWStream *null_w_stream) {
    return null_w_stream->newline();
}

bool SkNullWStream_writeDecAsText(SkNullWStream *null_w_stream, int32_t v) {
    return null_w_stream->writeDecAsText(v);
}

bool SkNullWStream_writeBigDecAsText(SkNullWStream *null_w_stream, int64_t v, int minDigits) {
    return null_w_stream->writeBigDecAsText(v, minDigits);
}

bool SkNullWStream_writeHexAsText(SkNullWStream *null_w_stream, uint32_t v, int minDigits) {
    return null_w_stream->writeHexAsText(v, minDigits);
}

bool SkNullWStream_writeScalarAsText(SkNullWStream *null_w_stream, SkScalar v) {
    return null_w_stream->writeScalarAsText(v);
}

bool SkNullWStream_writeBool(SkNullWStream *null_w_stream, bool v) {
    return null_w_stream->writeBool(v);
}

bool SkNullWStream_writeScalar(SkNullWStream *null_w_stream, SkScalar v) {
    return null_w_stream->writeScalar(v);
}

bool SkNullWStream_writePackedUInt(SkNullWStream *null_w_stream, size_t v) {
    return null_w_stream->writePackedUInt(v);
}

bool SkNullWStream_writeStream(SkNullWStream *null_w_stream, SkStream *input, size_t length) {
    return null_w_stream->writeStream(input, length);
}

// static

int SkNullWStream_SizeOfPackedUInt(size_t value) {
    return SkNullWStream::SizeOfPackedUInt(value);
}
*/

//
// SkNVRefCnt<Derived>
//

/*
SkNVRefCnt *SkNVRefCnt_new(SkNVRefCnt *nv_ref_cnt) {
    return new SkNVRefCnt();
}

void SkNVRefCnt_delete(SkNVRefCnt *nv_ref_cnt) {
    delete nv_ref_cnt;
}

bool unique(SkNVRefCnt *nv_ref_cnt) {
    return nv_ref_cnt->
}

void ref(SkNVRefCnt *nv_ref_cnt) {
    nv_ref_cnt->
}

void unref(SkNVRefCnt *nv_ref_cnt) {
    nv_ref_cnt->
}

void deref(SkNVRefCnt *nv_ref_cnt) {
    nv_ref_cnt->
}

bool refCntGreaterThan(SkNVRefCnt *nv_ref_cnt, int32_t threadIsolatedTestCnt) {
    return nv_ref_cnt->
}
*/

//
// SkRGBA4f<kAT> Struct Template
//

/*
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
*/

//
// SkRTreeFactory
//

//sk_sp<SkBBoxHierarchy> operator()() const override

//
// SVG ...
//

}

/*
void used() {
    SkPath *path = SkPath_new();
    SkPoint *p = nullptr;
    p->fX = 0.0;
    p->fY = 0.0;
    SkPath_moveTo_2(path, *p);
}
 */

int main(int argc, char* argv[]) {
    // GLFWを初期化する
    {
        if (glfwInit() != GL_TRUE) {
            fprintf(stderr, "Initialization of GLFW failed.\n");
            exit(EXIT_FAILURE);
        }
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    int width = 1920;
    int height = 1080;
    GLFWwindow *window;
    {
        window = glfwCreateWindow(width, height, "RaiaEngine", NULL, NULL);
        if (!window) {
            fprintf(stderr, "Window creation failed.\n");
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
    }

    // 頂点データを作成する
    GLuint vertex_array_object;
    GLuint vertex_buffer_object;
    GLuint element_buffer_object;
    {
        float vertices[] = {
                -1.0f, 1.0f, 0.0f,  // Position 0
                0.0f, 0.0f,         // TexCoord 0
                -1.0f, -1.0f, 0.0f,  // Position 1
                0.0f, 1.0f,         // TexCoord 1
                1.0f, -1.0f, 0.0f,  // Position 2
                1.0f, 1.0f,         // TexCoord 2
                1.0f, 1.0f, 0.0f,  // Position 3
                1.0f, 0.0f          // TexCoord 3
        };
        unsigned int indices[] = {
                0, 1, 2, 0, 2, 3
        };
        glGenVertexArrays(1, &vertex_array_object);
        glGenBuffers(1, &vertex_buffer_object);
        glGenBuffers(1, &element_buffer_object);
        glBindVertexArray(vertex_array_object);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_object);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glBindVertexArray(0);
    }

    // シェーダーを作成する
    GLuint shader_program;
    {
        const char *vertex_shader_source =
                "attribute vec4 a_position;"
                "attribute vec2 a_texCoord;"
                "varying vec2 v_texCoord;"
                "void main() {"
                "    gl_Position = a_position;"
                "    v_texCoord = a_texCoord;"
                "}";
        const char *fragment_shader_source =
                "precision mediump float;"
                "varying vec2 v_texCoord;"
                "uniform sampler2D s_texture;"
                "void main() {"
                "    gl_FragColor = texture2D(s_texture, v_texCoord);"
                "}";
        GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        shader_program = glCreateProgram();
        glAttachShader(shader_program, vertex_shader);
        glAttachShader(shader_program, fragment_shader);
        glLinkProgram(shader_program);
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
    }

    // ウィンドウのピクセルデータを初期化する
    GLubyte *image_pixels;
    int image_width = 800;
    int image_height = 600;
    int image_channels = 0;
    GLuint window_texture;
    {
        image_pixels = stbi_load("adv_sample_image2.png", &image_width, &image_height, &image_channels, 0);
        glGenTextures(1, &window_texture);
    }


    // SkBitmapとSkCanvasを初期化する
    SkBitmap* skBitmap = SkBitmap_new();
    {
        SkBitmap_allocN32Pixels(skBitmap, image_width, image_height, false);
        SkCanvas *canvas = SkCanvas_new_3(skBitmap);

        {
            // PNG画像を読み込む
            SkStream_MakeFromFile("image_file", "adv_sample_image2.png");
            SkData_MakeFromStream("image_data", static_sk_stream_get("image_file"), SkStream_getLength(static_sk_stream_get("image_file")));
            SkImages_DeferredFromEncodedData("sample_image", "image_data");
        }

        {
            // 画像をキャンバスに描画
            SkCanvas_drawImage_4(canvas, static_sk_image_get("sample_image"), 0, 0);
        }

        {
            // 図形を描画する
            SkPaint *paint = SkPaint_new();
            SkPaint_setBlendMode(paint, SkBlendMode::kOverlay);
            SkPaint_setColor(paint, SK_ColorBLUE); // 赤色を選択
            SkRect_MakeXYWH("rect", 20, 20, 400, 600 - 40); // 四角形の位置とサイズ
            //SkCanvas_drawRect("rect", canvas, paint); // 四角形を描画
            static_sk_rect_delete("rect");
        }

        {
            // パスを描画する
            const SkScalar scale = 256.0f;
            const SkScalar R = 0.45f * scale;
            const SkScalar TAU = 6.2831853f;
            SkPath *path = SkPath_new();
            SkPath_moveTo(path, R, 0.0f);
            for (int i = 1; i < 7; ++i) {
                SkScalar theta = (float)(3 * i) * TAU / 7;
                SkPath_lineTo(path,R * cos(theta), R * sin(theta));
            }
            SkPath_close(path);
            SkPaint *paint = SkPaint_new();
            SkPaint_setARGB(paint, 255, 255, 0, 0);
            SkPaint_setAntiAlias(paint, true);
            //SkCanvas_drawPath(canvas, path, paint);
        }

        // ピクセルデータを書き込む
        //skBitmap.setPixels(image_pixels);

        // スマートポインタを明示的に解放する
        static_sk_data_delete("image_data");
        static_sk_stream_delete("image_file");
        static_sk_image_delete("sample_image");
    }
    // Skiaのビットマップからピクセルデータを取得
    GLubyte* skia_pixels = (GLubyte*)SkBitmap_getPixels(skBitmap);;



    // メインループ
    while (!glfwWindowShouldClose(window)) {
        glBindTexture(GL_TEXTURE_2D, window_texture);
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width, image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_pixels);
        // Skiaで描画したピクセルデータをOpenGLテクスチャにコピー
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        //glBindTexture(GL_TEXTURE_2D, window_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, skia_pixels);

        glUseProgram(shader_program);
        glBindVertexArray(vertex_array_object);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindTexture(GL_TEXTURE_2D, 2);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 不要なオブジェクトを解放する
    glDeleteVertexArrays(1, &vertex_array_object);
    glDeleteBuffers(1, &vertex_buffer_object);
    glDeleteBuffers(1, &element_buffer_object);
    glDeleteTextures(1, &window_texture);
    free(image_pixels);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;

}
