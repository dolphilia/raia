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
//#include "include/core/SkDrawLooper.h"
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
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkPicture.h"
#include "include/core/SkPixelRef.h"
#include "include/core/SkRect.h"
#include "include/core/SkShader.h"
#include "include/core/SkStream.h"
#include "include/core/SkSurface.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkVertices.h"
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
#include "include/gpu/graphite/Recorder.h"

#include <map>
#include <utility>

//
// static
//

// struct
static std::map<std::string, SkRect> static_sk_rect;

// class
static std::map<std::string, SkSpan<const SkMesh::ChildPtr>> static_sk_mesh_child_ptr;
static std::map<std::string, sk_sp<const SkCapabilities>> static_sk_capabilities;
static std::map<std::string, sk_sp<const SkData>> static_const_sk_data;
static std::map<std::string, sk_sp<SkBlender>> static_sk_blender;
static std::map<std::string, sk_sp<SkColorFilter>> static_sk_color_filter;
static std::map<std::string, sk_sp<SkColorSpace>> static_sk_color_space;
static std::map<std::string, sk_sp<SkColorTable>> static_sk_color_table;
static std::map<std::string, sk_sp<SkContourMeasure>> static_sk_contour_measure;
static std::map<std::string, sk_sp<SkData>> static_sk_data;
static std::map<std::string, sk_sp<SkDataTable>> static_sk_data_table;
static std::map<std::string, sk_sp<SkDrawable>> static_sk_drawable;
static std::map<std::string, sk_sp<SkFlattenable>> static_sk_flattenable;
static std::map<std::string, sk_sp<SkFontMgr>> static_sk_font_mgr;
static std::map<std::string, sk_sp<SkFontStyleSet>> static_sk_font_style_set;
static std::map<std::string, sk_sp<SkImage>> static_sk_image;
static std::map<std::string, sk_sp<SkImageFilter>> static_sk_image_filter;
static std::map<std::string, sk_sp<SkMaskFilter>> static_sk_mask_filter;
static std::map<std::string, sk_sp<SkMesh::IndexBuffer>> static_sk_mesh_index_buffer;
static std::map<std::string, sk_sp<SkMesh::VertexBuffer>> static_sk_mesh_vertex_buffer;
static std::map<std::string, sk_sp<SkMeshSpecification>> static_sk_mesh_specification;
static std::map<std::string, sk_sp<SkPathEffect>> static_sk_path_effect;
static std::map<std::string, sk_sp<SkPicture>> static_sk_picture;
static std::map<std::string, sk_sp<SkPixelRef>> static_sk_pixel_ref;
static std::map<std::string, sk_sp<SkShader>> static_sk_shader;
static std::map<std::string, sk_sp<SkSurface>> static_sk_surface;
static std::map<std::string, sk_sp<SkTextBlob>> static_sk_text_blob;
static std::map<std::string, sk_sp<SkTypeface>> static_sk_typeface;
static std::map<std::string, sk_sp<SkVertices>> static_sk_vertices;
static std::map<std::string, std::unique_ptr<SkCanvas>> static_sk_canvas;
static std::map<std::string, std::unique_ptr<SkDrawable::GpuDrawHandler>> static_gpu_draw_handler;
static std::map<std::string, std::unique_ptr<SkExecutor>> static_sk_executor;
static std::map<std::string, std::unique_ptr<SkFILEStream>> static_sk_file_stream;
static std::map<std::string, std::unique_ptr<SkImageGenerator>> static_sk_image_generator;
static std::map<std::string, std::unique_ptr<SkMemoryStream>> static_sk_memory_stream;
static std::map<std::string, std::unique_ptr<SkStream>> static_sk_stream;
static std::map<std::string, std::unique_ptr<SkStreamAsset>> static_sk_stream_asset;

extern "C" {

//
// SkMemoryStream
//

SkMemoryStream *SkMemoryStream_new() {
    return new SkMemoryStream();
}

SkMemoryStream *SkMemoryStream_new_2(size_t length) {
    return new SkMemoryStream(length);
}

SkMemoryStream *SkMemoryStream_new_3(const void *data, size_t length, bool copyData) {
    return new SkMemoryStream(data, length, copyData);
}

SkMemoryStream *SkMemoryStream_new_4(const char *sk_data_key_in) {
    return new SkMemoryStream(static_sk_data[sk_data_key_in]);
}


void SkMemoryStream_setMemory(SkMemoryStream *memory_stream, const void *data, size_t length, bool copyData) {
    memory_stream->setMemory(data, length, copyData);
}

void SkMemoryStream_setMemoryOwned(SkMemoryStream *memory_stream, const void *data, size_t length) {
    memory_stream->setMemoryOwned(data, length);
}

void SkMemoryStream_asData(const char *sk_data_key_out, SkMemoryStream *memory_stream) {
    static_sk_data[sk_data_key_out] = memory_stream->asData();
}

void SkMemoryStream_setData(const char *sk_data_key_in, SkMemoryStream *memory_stream) {
    memory_stream->setData(static_sk_data[sk_data_key_in]);
}

void SkMemoryStream_skipToAlign4(SkMemoryStream *memory_stream) {
    memory_stream->skipToAlign4();
}

const void * SkMemoryStream_getAtPos(SkMemoryStream *memory_stream) {
    return memory_stream->getAtPos();
}

size_t SkMemoryStream_read(SkMemoryStream *memory_stream, void *buffer, size_t size) {
    return memory_stream->read(buffer, size);
}

bool SkMemoryStream_isAtEnd(SkMemoryStream *memory_stream) {
    return memory_stream->isAtEnd();
}

size_t SkMemoryStream_peek(SkMemoryStream *memory_stream, void *buffer, size_t size) {
    return memory_stream->peek(buffer, size);
}

bool SkMemoryStream_rewind(SkMemoryStream *memory_stream) {
    return memory_stream->rewind();
}

void SkMemoryStream_duplicate(const char *sk_memory_stream_key_out, SkMemoryStream *memory_stream) {
    static_sk_memory_stream[sk_memory_stream_key_out] = memory_stream->duplicate();
}

size_t SkMemoryStream_getPosition(SkMemoryStream *memory_stream) {
    return memory_stream->getPosition();
}

bool SkMemoryStream_seek(SkMemoryStream *memory_stream, size_t position) {
    return memory_stream->seek(position);
}

bool SkMemoryStream_move(SkMemoryStream *memory_stream, long offset) {
    return memory_stream->move(offset);
}

void SkMemoryStream_fork(const char *sk_memory_stream_key_out, SkMemoryStream *memory_stream) {
    static_sk_memory_stream[sk_memory_stream_key_out] = memory_stream->fork();
}

size_t SkMemoryStream_getLength(SkMemoryStream *memory_stream) {
    return memory_stream->getLength();
}

const void * SkMemoryStream_getMemoryBase(SkMemoryStream *memory_stream) {
    return memory_stream->getMemoryBase();
}

bool SkMemoryStream_hasLength(SkMemoryStream *memory_stream) {
    return memory_stream->hasLength();
}

bool SkMemoryStream_hasPosition(SkMemoryStream *memory_stream) {
    return memory_stream->hasPosition();
}

size_t SkMemoryStream_skip(SkMemoryStream *memory_stream, size_t size) {
    return memory_stream->skip(size);
}

bool SkMemoryStream_readS8(SkMemoryStream *memory_stream, int8_t *i) {
    return memory_stream->readS8(i);
}

bool SkMemoryStream_readS16(SkMemoryStream *memory_stream, int16_t *i) {
    return memory_stream->readS16(i);
}

bool SkMemoryStream_readS32(SkMemoryStream *memory_stream, int32_t *i) {
    return memory_stream->readS32(i);
}

bool SkMemoryStream_readU8(SkMemoryStream *memory_stream, uint8_t *i) {
    return memory_stream->readU8(i);
}

bool SkMemoryStream_readU16(SkMemoryStream *memory_stream, uint16_t *i) {
    return memory_stream->readU16(i);
}

bool SkMemoryStream_readU32(SkMemoryStream *memory_stream, uint32_t *i) {
    return memory_stream->readU32(i);
}

bool SkMemoryStream_readBool(SkMemoryStream *memory_stream, bool *b) {
    return memory_stream->readBool(b);
}

bool SkMemoryStream_readScalar(SkMemoryStream *memory_stream, SkScalar *v) {
    return memory_stream->readScalar(v);
}

bool SkMemoryStream_readPackedUInt(SkMemoryStream *memory_stream, size_t *size) {
    return memory_stream->readPackedUInt(size);
}


// static

void SkMemoryStream_MakeCopy(const char *sk_memory_stream_key_out, const void *data, size_t length) {
    static_sk_memory_stream[sk_memory_stream_key_out] = SkMemoryStream::MakeCopy(data, length);
}

void SkMemoryStream_MakeDirect(const char *sk_memory_stream_key_out, const void *data, size_t length) {
    static_sk_memory_stream[sk_memory_stream_key_out] = SkMemoryStream::MakeDirect(data, length);
}

void SkMemoryStream_Make(const char *sk_memory_stream_key_out, const char *sk_data_key_in) {
    static_sk_memory_stream[sk_memory_stream_key_out] = SkMemoryStream::Make(static_sk_data[sk_data_key_in]);
}

//
// SkMesh
//

// SkMesh & operator=(const SkMesh &)
// SkMesh & operator=(SkMesh &&)

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
    static_sk_mesh_child_ptr[sk_mesh_child_ptr_key_out] = mesh->children();
}

SkRect SkMesh_bounds(SkMesh *mesh) {
    return mesh->bounds();
}

bool SkMesh_isValid(SkMesh *mesh) {
    return mesh->isValid();
}

// static @TODO

//SkMesh::Result SkMesh_Make(sk_sp<SkMeshSpecification> *mesh_specification, SkMesh::Mode mode, sk_sp<SkMesh::VertexBuffer> *vertex_buffer, size_t vertexCount, size_t vertexOffset, sk_sp<const SkData> *uniforms, SkSpan<SkMesh::ChildPtr> children, const SkRect *bounds) {
//    return SkMesh::Make(*mesh_specification, mode, *vertex_buffer, vertexCount, vertexOffset, *uniforms, children, *bounds);
//}

//SkMesh::Result SkMesh_MakeIndexed(sk_sp<SkMeshSpecification> *mesh_specification, SkMesh::Mode mode, sk_sp<SkMesh::VertexBuffer> *vertex_buffer, size_t vertexCount, size_t vertexOffset, sk_sp<SkMesh::IndexBuffer> *index_buffer, size_t indexCount, size_t indexOffset, sk_sp<const SkData> *uniforms, SkSpan<SkMesh::ChildPtr> children, const SkRect *bounds) {
//    return SkMesh::MakeIndexed(*mesh_specification, mode, *vertex_buffer, vertexCount, vertexOffset, *index_buffer, indexCount, indexOffset, *uniforms, children, *bounds);
//}



}

void used() {
    /*
    SkPath *path = SkPath_new();
    SkPoint *p = nullptr;
    p->fX = 0.0;
    p->fY = 0.0;
    SkPath_moveTo(path, p);
     */
}

int main(int argc, char* argv[]) {
    /*
    //used();

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
    int width = 800;
    int height = 600;
    GLFWwindow *window;
    {
        window = glfwCreateWindow(width, height, "GUI", NULL, NULL);
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
        image_pixels = stbi_load("adv_sample_image.png", &image_width, &image_height, &image_channels, 0);
        glGenTextures(1, &window_texture);
    }


    // SkBitmapとSkCanvasを初期化する
    SkBitmap* skBitmap = SkBitmap_new();
    {
        SkBitmap_allocN32Pixels(skBitmap, image_width, image_height, false);
        SkCanvas *canvas = SkCanvas_new_4(skBitmap);

        {
            // PNG画像を読み込む
            SkStream_MakeFromFile("image_file", "adv_sample_image.png");
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
            SkPaint_setColor_2(paint, SK_ColorBLUE); // 赤色を選択
            SkRect_MakeXYWH("rect", 20, 20, 400, 600 - 40); // 四角形の位置とサイズ
            SkCanvas_drawRect("rect", canvas, paint); // 四角形を描画
            static_sk_rect_delete("rect");
        }

        {
            // パスを描画する
            const SkScalar scale = 256.0f;
            const SkScalar R = 0.45f * scale;
            const SkScalar TAU = 6.2831853f;
            SkPath *path = SkPath_new();
            SkPath_moveTo_2(path, R, 0.0f);
            for (int i = 1; i < 7; ++i) {
                SkScalar theta = (float)(3 * i) * TAU / 7;
                SkPath_lineTo_2(path,R * cos(theta), R * sin(theta));
            }
            SkPath_close(path);
            SkPaint *paint = SkPaint_new();
            SkPaint_setARGB(paint, 255, 255, 0, 0);
            SkPaint_setAntiAlias(paint, true);
            //canvas->clear(SK_ColorWHITE);
            //canvas.translate(0.5f * scale, 0.5f * scale);
            SkCanvas_drawPath(canvas, path, paint);
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
     */
    return 0;
}
