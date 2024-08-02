local ffi = require("ffi")

ffi.cdef[[
    // ヘルパーマクロ
    void raia_imgui_assert(bool expr);
    bool raia_imgui_check_version();

    // コンテキストの作成とアクセス
    void *raia_imgui_create_context(void *shared_font_atlas);
    void raia_imgui_destroy_context(void *ctx);
    void *raia_imgui_get_current_context();
    void raia_imgui_set_current_context(void *ctx);

    // メイン
    void *raia_imgui_getio();
    void *raia_imgui_getstyle();
    void raia_imgui_new_frame();
    void raia_imgui_end_frame();
    void raia_imgui_render();
    void *raia_imgui_get_draw_data();

    // デモ・デバッグ・情報
    void raia_imgui_show_demo_window(bool *p_open);
    void raia_imgui_show_metrics_window(bool* p_open /* = NULL */);
    void raia_imgui_show_debug_log_window(bool* p_open /* = NULL */);
    void raia_imgui_show_stack_tool_window(bool* p_open /* = NULL */);
    void raia_imgui_show_about_window(bool* p_open /* = NULL */);
    void raia_imgui_show_style_editor(void* ref /* = NULL */);
    bool raia_imgui_show_style_selector(const char* label);
    void raia_imgui_show_font_selector(const char* label);
    void raia_imgui_show_user_guide();
    const char* raia_imgui_get_version();

    // スタイル
    void raia_imgui_style_colors_dark(void *dst);
    void raia_imgui_style_colors_light(void *dst);
    void raia_imgui_style_colors_classic(void *dst);

    // ウィンドウ
    bool raia_imgui_begin(const char* name, bool* p_open, int flags);
    void raia_imgui_end();

    // 子ウィンドウ
    bool raia_imgui_begin_child(const char* str_id, float size_x, float size_y, bool border, int flags);
    bool raia_imgui_begin_child_2(int id, float size_x, float size_y, bool border, int flags);
    void raia_imgui_end_child();

    // ウィンドウ・ユーティリティ
    bool raia_imgui_is_window_appearing();
    bool raia_imgui_is_window_collapsed();
    bool raia_imgui_is_window_focused(int flags /* = 0 */);
    bool raia_imgui_is_window_hovered(int flags /* = 0 */);
    void* raia_imgui_get_window_draw_list();
    float raia_imgui_get_window_pos_x();
    float raia_imgui_get_window_pos_y();
    float raia_imgui_get_window_width();
    float raia_imgui_get_window_height();

    // ウィンドウ操作
    void raia_imgui_set_next_window_pos(float pos_x, float pos_y, int cond, float pivot_x, float pivot_y);
    void raia_imgui_set_next_window_size(float size_x, float size_y, int cond /* = 0 */);
    void raia_imgui_set_next_window_size_constraints(float size_min_x, float size_min_y, float size_max_x, float size_max_y, void* custom_callback /* = NULL*/, void* custom_callback_data /* = NULL*/);
    void raia_imgui_set_next_window_content_size(float size_x, float size_y);
    void raia_imgui_set_next_window_collapsed(bool collapsed, int cond /*= 0*/);
    void raia_imgui_set_next_window_focus();
    void raia_imgui_set_next_window_scroll(float scroll_x, float scroll_y);
    void raia_imgui_set_next_window_bg_alpha(float alpha);
    void raia_imgui_set_next_window_viewport(void* viewport);
    void raia_imgui_set_next_window_viewport_2(unsigned int viewport_id);
    void raia_imgui_set_window_pos(float pos_x, float pos_y, int cond /* = 0*/);
    void raia_imgui_set_window_size(float size_x, float size_y, int cond /* = 0 */);
    void raia_imgui_set_window_collapsed(bool collapsed, int cond /* = 0*/);
    void raia_imgui_set_window_focus();
    void raia_imgui_set_window_font_scale(float scale);
    void raia_imgui_set_window_pos_2(const char* name, float pos_x, float pos_y, int cond /*= 0*/);
    void raia_imgui_set_window_size_2(const char* name, float size_x, float size_y, int cond /*= 0*/);
    void raia_imgui_set_window_collapsed_2(const char* name, bool collapsed, int cond /*= 0*/);
    void raia_imgui_set_window_focus_2(const char* name);

    // コンテンツ領域
    float raia_imgui_get_content_region_avail_x();
    float raia_imgui_get_content_region_avail_y();
    float raia_imgui_get_content_region_max_x();
    float raia_imgui_get_content_region_max_y();
    float raia_imgui_get_window_content_region_min_x();
    float raia_imgui_get_window_content_region_min_y();
    float raia_imgui_get_window_content_region_max_x();
    float raia_imgui_get_window_content_region_max_y();
    
    // ウィンドウ・スクロール
    float raia_imgui_get_scroll_x();
    float raia_imgui_get_scroll_y();
    void raia_imgui_set_scroll_x(float scroll_x);
    void raia_imgui_set_scroll_y(float scroll_y);
    float raia_imgui_get_scroll_max_x();
    float raia_imgui_get_scroll_max_y();
    void raia_imgui_set_scroll_here_x(float center_x_ratio /* = 0.5f*/);
    void raia_imgui_set_scroll_here_y(float center_y_ratio /* = 0.5f*/);
    void raia_imgui_set_scroll_from_pos_x(float local_x, float center_x_ratio /* = 0.5f*/);
    void raia_imgui_set_scroll_from_pos_y(float local_y, float center_y_ratio /* = 0.5f*/);
    
    // パラメータ・スタック（共有）
    void raia_imgui_push_font(void* font);
    void raia_imgui_pop_font();
    void raia_imgui_push_style_color(int idx, unsigned int col);
    void raia_imgui_push_style_color_2(int idx, float col_x, float col_y, float col_z, float col_w);
    void raia_imgui_pop_style_color_3(int count /* = 1*/);
    void raia_imgui_push_style_var(int idx, float val);
    void raia_imgui_push_style_var_2(int idx, float val_x, float val_y);
    void raia_imgui_pop_style_var_3(int count /* = 1*/);
    void raia_imgui_push_tab_stop(bool tab_stop);
    void raia_imgui_pop_tab_stop();
    void raia_imgui_push_button_repeat(bool repeat);
    void raia_imgui_pop_button_repeat();
        
    // パラメータ・スタック（現在のウィンドウ）
    void raia_imgui_push_item_width(float item_width);
    void raia_imgui_pop_item_width();
    void raia_imgui_set_next_item_width(float item_width);
    float raia_imgui_calc_item_width();
    void raia_imgui_push_text_wrap_pos(float wrap_local_pos_x /* = 0.0f*/);
    void raia_imgui_pop_text_wrap_pos();
    
    // スタイルの読み込みとアクセス
    void* raia_imgui_get_font();
    float raia_imgui_get_font_size();
    float raia_imgui_get_font_tex_uv_white_pixel_x();
    float raia_imgui_get_font_tex_uv_white_pixel_y();
    unsigned int raia_imgui_get_color_u32(int idx, float alpha_mul /* = 1.0f*/);
    unsigned int raia_imgui_get_color_u32_2(float col_x, float col_y, float col_z, float col_w);
    unsigned int raia_imgui_get_color_u32_3(unsigned int col);
    float raia_imgui_get_style_color_vec4_x(int idx);
    float raia_imgui_get_style_color_vec4_y(int idx);
    float raia_imgui_get_style_color_vec4_z(int idx);
    float raia_imgui_get_style_color_vec4_w(int idx);

    // カーソル / レイアウト
    void raia_imgui_separator();
    void raia_imgui_same_line();
    void raia_imgui_new_line();
    void raia_imgui_spacing();
    void raia_imgui_dummy(float size_x, float size_y);
    void raia_imgui_indent(float indent_w /* = 0.0f*/);
    void raia_imgui_unindent(float indent_w /* = 0.0f*/);
    void raia_imgui_begin_group();
    void raia_imgui_end_group();
    float raia_imgui_get_cursor_pos_x();
    float raia_imgui_get_cursor_pos_y();
    void raia_imgui_set_cursor_pos(float local_pos_x, float local_pos_y);
    void raia_imgui_set_cursor_pos_x(float local_x);
    void raia_imgui_set_cursor_pos_y(float local_y);
    float raia_imgui_get_cursor_start_pos_x();
    float raia_imgui_get_cursor_start_pos_y();
    float raia_imgui_get_cursor_screen_pos_x();
    float raia_imgui_get_cursor_screen_pos_y();
    void raia_imgui_set_cursor_screen_pos(float pos_x, float pos_y);
    void raia_imgui_align_text_to_frame_padding();
    float raia_imgui_get_text_line_height();
    float raia_imgui_get_text_line_height_with_spacing();
    float raia_imgui_get_frame_height();
    float raia_imgui_get_frame_height_with_spacing();
    
    // IDスタック / スコープ
    void raia_imgui_push_id(const char* str_id);
    void raia_imgui_push_id_2(const char* str_id_begin, const char* str_id_end);
    void raia_imgui_push_id_3(const void* ptr_id);
    void raia_imgui_push_id_4(int int_id);
    void raia_imgui_pop_id();
    unsigned int raia_imgui_get_id(const char* str_id);
    unsigned int raia_imgui_get_id_2(const char* str_id_begin, const char* str_id_end);
    unsigned int raia_imgui_get_id_3(const void* ptr_id);
    
    // ウィジェット: テキスト
    void raia_imgui_text_unformatted(const char* text, const char* text_end /* = NULL */);
    void raia_imgui_text(const char *text);
    void raia_imgui_text_colored(float col_x, float col_y, float col_z, float col_w, const char* text);
    void raia_imgui_text_disabled(const char* text);
    void raia_imgui_text_wrapped(const char* text);
    void raia_imgui_label_text(const char* label, const char* text);
    void raia_imgui_bullet_text(const char* text);
    void raia_imgui_separator_text(const char* label);
    
    // ウィジェット: メイン
    bool raia_imgui_button(const char *label, float width, float height);
    bool raia_imgui_small_button(const char* label);
    bool raia_imgui_invisible_button(const char* str_id, float size_x, float size_y, int flags /* = 0*/);
    bool raia_imgui_arrow_button(const char* str_id, int dir);
    bool raia_imgui_checkbox(const char *label, bool *v);
    bool raia_imgui_checkbox_flags(const char* label, int* flags, int flags_value);
    bool raia_imgui_checkbox_flags_2(const char* label, unsigned int* flags, unsigned int flags_value);
    bool raia_imgui_radio_button(const char* label, bool active);
    bool raia_imgui_radio_button_2(const char* label, int* v, int v_button);
    void raia_imgui_progress_bar(float fraction, float size_arg_x /*= -FLT_MIN*/, float size_arg_y /*= 0*/, const char* overlay /* = NULL*/);
    void raia_imgui_bullet();
    
    // ウィジェット: 画像
    void raia_imgui_image(void *texture_id, float width, float height);
    bool raia_imgui_image_button(const char* str_id, void* user_texture_id, float size_x, float size_y,
                             float uv0_x /* = 0 */, float uv0_y /* = 0 */,
                             float uv1_x /* = 1 */, float uv1_y /* = 1 */,
                             float bg_col_x /* = 0 */, float bg_col_y /* = 0 */, float bg_col_z /* = 0 */, float bg_col_w /* = 0 */,
                             float tint_col_x /* = 1 */, float tint_col_y /* = 1 */, float tint_col_z /* = 1 */, float tint_col_w /* = 1 */);

    // ウィジェット: コンボボックス（ドロップダウン）
    bool raia_imgui_begin_combo(const char* label, const char* preview_value, int flags /* = 0 */);
    void raia_imgui_end_combo();
    bool raia_imgui_combo(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items /* = -1 */);
    bool raia_imgui_combo_2(const char* label, int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items /* = -1 */);
    bool raia_imgui_combo_3(const char* label, int* current_item, void* items_getter, void* data, int items_count, int popup_max_height_in_items /* = -1 */);

    // ウィジェット: ドラッグスライダー
    bool raia_imgui_drag_float(const char* label, float* v, float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_drag_float2(const char* label, float v[2], float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_drag_float3(const char* label, float v[3], float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_drag_float4(const char* label, float v[4], float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_drag_float_range2(const char* label, float* v_current_min, float* v_current_max, float v_speed /* = 1.0f */, float v_min /* = 0.0f */, float v_max /* = 0.0f */, const char* format /* = "%.3f" */, const char* format_max /* = NULL */, int flags /* = 0 */);
    bool raia_imgui_drag_int(const char* label, int* v, float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, int flags /* = 0 */) ;
    bool raia_imgui_drag_int2(const char* label, int v[2], float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, int flags /* = 0 */);
    bool raia_imgui_drag_int3(const char* label, int v[3], float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, int flags /* = 0 */);
    bool raia_imgui_drag_int4(const char* label, int v[4], float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, int flags /* = 0 */);
    bool raia_imgui_drag_int_range2(const char* label, int* v_current_min, int* v_current_max, float v_speed /* = 1.0f */, int v_min /* = 0 */, int v_max /* = 0 */, const char* format /* = "%d" */, const char* format_max /* = NULL */, int flags /* = 0 */);
    bool raia_imgui_drag_scalar(const char* label, int data_type, void* p_data, float v_speed /* = 1.0f */, const void* p_min /* = NULL */, const void* p_max /* = NULL */, const char* format /* = NULL */, int flags /* = 0 */);
    bool raia_imgui_drag_scalar_n(const char* label, int data_type, void* p_data, int components, float v_speed /* = 1.0f */, const void* p_min /* = NULL */, const void* p_max /* = NULL */, const char* format /* = NULL */, int flags /* = 0 */);

    // ウィジェット: レギュラー・スライダー
    float raia_imgui_slider_float(const char *label, float *v, float v_min, float v_max, const char* format /* = "%.3f"*/, int flags /* = 0 */);
    bool raia_imgui_slider_float2(const char* label, float v[2], float v_min, float v_max, const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_slider_float3(const char* label, float v[3], float v_min, float v_max, const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_slider_float4(const char* label, float v[4], float v_min, float v_max, const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_slider_angle(const char* label, float* v_rad, float v_degrees_min /* = -360.0f */, float v_degrees_max /* = +360.0f */, const char* format /* = "%.0f deg" */, int flags /* = 0 */);
    bool raia_imgui_slider_int(const char* label, int* v, int v_min, int v_max, const char* format /* = "%d" */, int flags /* = 0 */);
    bool raia_imgui_slider_int2(const char* label, int v[2], int v_min, int v_max, const char* format /* = "%d" */, int flags /* = 0 */);
    bool raia_imgui_slider_int3(const char* label, int v[3], int v_min, int v_max, const char* format /* = "%d" */, int flags /* = 0 */);
    bool raia_imgui_slider_int4(const char* label, int v[4], int v_min, int v_max, const char* format /* = "%d" */, int flags /* = 0 */);
    bool raia_imgui_slider_scalar(const char* label, int data_type, void* p_data, const void* p_min, const void* p_max, const char* format /* = NULL */, int flags /* = 0 */);
    bool raia_imgui_slider_scalar_n(const char* label, int data_type, void* p_data, int components, const void* p_min, const void* p_max, const char* format /* = NULL */, int flags /* = 0 */);
    bool raia_imgui_v_slider_float(const char* label, float size_x, float size_y, float* v, float v_min, float v_max, const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_v_slider_int(const char* label, float size_x, float size_y, int* v, int v_min, int v_max, const char* format /* = "%d" */, int flags /* = 0 */);
    bool raia_imgui_v_slider_scalar(const char* label, float size_x, float size_y, int data_type, void* p_data, const void* p_min, const void* p_max, const char* format /* = NULL */, int flags /* = 0 */);

    // ウィジェット: キーボード入力
    bool raia_imgui_input_text(const char* label, char* buf, size_t buf_size, int flags /* = 0 */, void* callback /* = NULL */, void* user_data /* = NULL */);
    bool raia_imgui_input_text_multiline(const char* label, char* buf, size_t buf_size, float size_x /* = 0 */, float size_y /* = 0 */, int flags /* = 0 */, void* callback /* = NULL */, void* user_data /* = NULL */);
    bool raia_imgui_input_text_with_hint(const char* label, const char* hint, char* buf, size_t buf_size, int flags /* = 0 */, void* callback /* = NULL */, void* user_data /* = NULL */);
    bool raia_imgui_input_float(const char* label, float* v, float step /* = 0.0f */, float step_fast /* = 0.0f */, const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_input_float2(const char* label, float v[2], const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_input_float3(const char* label, float v[3], const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_input_float4(const char* label, float v[4], const char* format /* = "%.3f" */, int flags /* = 0 */);
    bool raia_imgui_input_int(const char* label, int* v, int step /* = 1 */, int step_fast /* = 100 */, int flags /* = 0 */);
    bool raia_imgui_input_int2(const char* label, int v[2], int flags /* = 0 */);
    bool raia_imgui_input_int3(const char* label, int v[3], int flags /* = 0 */);
    bool raia_imgui_input_int4(const char* label, int v[4], int flags /* = 0 */);
    bool raia_imgui_input_double(const char* label, double* v, double step /* = 0.0 */, double step_fast /* = 0.0 */, const char* format /* = "%.6f" */, int flags /* = 0 */);
    bool raia_imgui_input_scalar(const char* label, int data_type, void* p_data, const void* p_step /* = NULL */, const void* p_step_fast /* = NULL */, const char* format /* = NULL */, int flags /* = 0 */);
    bool raia_imgui_input_scalar_n(const char* label, int data_type, void* p_data, int components, const void* p_step /* = NULL */, const void* p_step_fast /* = NULL */, const char* format /* = NULL */, int flags /* = 0 */);

    // ウィジェット: カラーエディター/ピッカー
    bool raia_imgui_color_edit3(const char *label, float *col, int flags);
    bool raia_imgui_color_edit4(const char* label, float col[4], int flags /* = 0 */);
    bool raia_imgui_color_picker3(const char* label, float col[3], int flags /* = 0 */);
    bool raia_imgui_color_picker4(const char* label, float col[4], int flags /* = 0 */, const float* ref_col /* = NULL */);
    bool raia_imgui_color_button(const char* desc_id, float col_x, float col_y, float col_z, float col_w, int flags /* = 0 */, float size_x /* = 0 */, float size_y /* = 0 */);
    void raia_imgui_set_color_edit_options(int flags);

    // ウィジェット: ツリー
    bool raia_imgui_tree_node(const char* label);
    bool raia_imgui_tree_node_2(const char* str_id, const char* text);
    bool raia_imgui_tree_node_3(const void* ptr_id, const char* text);
    bool raia_imgui_tree_node_ex(const char* label, int flags /* = 0 */);
    bool raia_imgui_tree_node_ex_2(const char* str_id, int flags, const char* text);
    bool raia_imgui_tree_node_ex_3(const void* ptr_id, int flags, const char* text);
    void raia_imgui_tree_push(const char* str_id);
    void raia_imgui_tree_push_2(const void* ptr_id);
    void raia_imgui_tree_pop();
    float raia_imgui_get_tree_node_to_label_spacing();
    bool raia_imgui_collapsing_header(const char* label, int flags /* = 0 */);
    bool raia_imgui_collapsing_header_2(const char* label, bool* p_visible, int flags /* = 0 */);
    void raia_imgui_set_next_item_open(bool is_open, int cond /* = 0 */);
    
    // ウィジェット: セレクタブル
    bool raia_imgui_selectable(const char* label, bool selected /* = false */, int flags /* = 0 */, float size_x /* = 0*/, float size_y /* = 0*/);
    bool raia_imgui_selectable_2(const char* label, bool* p_selected, int flags /* = 0 */,  float size_x /* = 0*/, float size_y /* = 0*/);
    
    // ウィジェット: リストボックス
    bool raia_imgui_begin_list_box(const char* label, float size_x /* = 0*/, float size_y /* = 0*/);
    void raia_imgui_end_list_box();
    bool raia_imgui_list_box(const char* label, int* current_item, const char* const items[], int items_count, int height_in_items /* = -1 */);
    bool raia_imgui_list_box_2(const char* label, int* current_item, bool (*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int height_in_items /* = -1 */);

    // ウィジェット: データプロット
    void raia_imgui_plot_lines(const char* label, const float* values, int values_count,
                           int values_offset /* = 0 */, const char* overlay_text /* = NULL */,
                           float scale_min /* = FLT_MAX */, float scale_max /* = FLT_MAX */,
                           float graph_size_x /* = 0*/, float graph_size_y /* = 0 */, int stride /* = sizeof(float) */);
    void raia_imgui_plot_lines_2(const char* label, float(*values_getter)(void* data, int idx),
                                void* data, int values_count, int values_offset /* = 0 */, const char* overlay_text /* = NULL */,
                                float scale_min /* = FLT_MAX */, float scale_max /* = FLT_MAX */,
                                float graph_size_x /* = 0*/, float graph_size_y /* = 0 */);
    void raia_imgui_plot_histogram(const char* label, const float* values, int values_count, int values_offset /* = 0 */,
                                const char* overlay_text /* = NULL */, float scale_min /* = FLT_MAX */, float scale_max /* = FLT_MAX */,
                                float graph_size_x /* = 0*/, float graph_size_y /* = 0 */, int stride /* = sizeof(float) */);
    void raia_imgui_plot_histogram_2(const char* label, float(*values_getter)(void* data, int idx), void* data, int values_count,
                                    int values_offset /* = 0 */, const char* overlay_text /* = NULL */,
                                    float scale_min /* = FLT_MAX */, float scale_max /* = FLT_MAX */,
                                    float graph_size_x /* = 0*/, float graph_size_y /* = 0 */);

    // ウィジェット: Value() ヘルパー
    void raia_imgui_value(const char* prefix, bool b);
    void raia_imgui_value_2(const char* prefix, int v);
    void raia_imgui_value_3(const char* prefix, unsigned int v);
    void raia_imgui_value_4(const char* prefix, float v, const char* float_format /* = NULL */);

    // ウィジェット: メニュー
    bool raia_imgui_begin_menu_bar();
    void raia_imgui_end_menu_bar();
    bool raia_imgui_begin_main_menu_bar();
    void raia_imgui_end_main_menu_bar();
    bool raia_imgui_begin_menu(const char* label, bool enabled /* = true */);
    void raia_imgui_end_menu();
    bool raia_imgui_menu_item(const char* label, const char* shortcut /* = NULL */, bool selected /* = false */, bool enabled /* = true */);
    bool raia_imgui_menu_item_2(const char* label, const char* shortcut, bool* p_selected, bool enabled /* = true */);

    // ツールチップ
    bool raia_imgui_begin_tooltip();
    void raia_imgui_end_tooltip();
    void raia_imgui_set_tooltip(const char* text);
    bool raia_imgui_begin_item_tooltip();
    void raia_imgui_set_item_tooltip(const char* text);
    
    // ポップアップ・モーダル
    bool raia_imgui_begin_popup(const char* str_id, int flags /* = 0 */);
    bool raia_imgui_begin_popup_modal(const char* name, bool* p_open /* = NULL */, int flags /* = 0 */);
    void raia_imgui_end_popup();
    void raia_imgui_open_popup(const char* str_id, int popup_flags /* = 0 */);
    void raia_imgui_open_popup_2(unsigned int id, int popup_flags /* = 0 */);
    void raia_imgui_open_popup_on_item_click(const char* str_id /* = NULL */, int popup_flags /* = 1 */);
    void raia_imgui_close_current_popup();
    bool raia_imgui_begin_popup_context_item(const char* str_id /* = NULL */, int popup_flags /* = 1 */);
    bool raia_imgui_begin_popup_context_window(const char* str_id /* = NULL */, int popup_flags /* = 1 */);
    bool raia_imgui_begin_popup_context_void(const char* str_id /* = NULL */, int popup_flags /* = 1 */);
    bool raia_imgui_is_popup_open(const char* str_id, int flags /* = 0 */);

    // テーブル
    bool raia_imgui_begin_table(const char* str_id, int column, int flags /* = 0 */, float outer_size_x /* = 0 */, float outer_size_y /* = 0 */, float inner_width /* = 0.0f */);
    void raia_imgui_end_table();
    void raia_imgui_table_next_row(int row_flags /* = 0 */, float min_row_height /* = 0.0f */);
    bool raia_imgui_table_next_column();
    bool raia_imgui_table_set_column_index(int column_n);
    void raia_imgui_table_setup_column(const char* label, int flags /* = 0 */, float init_width_or_weight /* = 0.0f */, unsigned int user_id /* = 0 */);
    void raia_imgui_table_setup_scroll_freeze(int cols, int rows);
    void raia_imgui_table_headers_row();
    void raia_imgui_table_header(const char* label);
    void* raia_imgui_table_get_sort_specs();
    int raia_imgui_table_get_column_count();
    int raia_imgui_table_get_column_index();
    int raia_imgui_table_get_row_index();
    const char* raia_imgui_table_get_column_name(int column_n /* = -1 */);
    int raia_imgui_table_get_column_flags(int column_n /* = -1 */);
    void raia_imgui_table_set_column_enabled(int column_n, bool v);
    void raia_imgui_table_set_bg_color(int target, unsigned int color, int column_n /* = -1 */);
    void raia_imgui_columns(int count /* = 1 */, const char* id /* = NULL */, bool border /* = true */); // ここからレガシーなテーブルAPI
    void raia_imgui_next_column();
    int raia_imgui_get_column_index();
    float raia_imgui_get_column_width(int column_index /* = -1 */);
    void raia_imgui_set_column_width(int column_index, float width);
    float raia_imgui_get_column_offset(int column_index /* = -1 */);
    void raia_imgui_set_column_offset(int column_index, float offset_x);
    int raia_imgui_get_columns_count();

    // タブバー、タブ
    bool raia_imgui_begin_tab_bar(const char* str_id, int flags /* = 0 */);
    void raia_imgui_end_tab_bar();
    bool raia_imgui_begin_tab_item(const char* label, bool* p_open /* = NULL */, int flags /* = 0 */);
    void raia_imgui_end_tab_item();
    bool raia_imgui_tab_item_button(const char* label, int flags /* = 0 */);
    void raia_imgui_set_tab_item_closed(const char* tab_or_docked_window_label);
    
    // ロギング/キャプチャ
    void raia_imgui_log_to_tty(int auto_open_depth /* = -1 */);
    void raia_imgui_log_to_file(int auto_open_depth /* = -1 */, const char* filename /* = NULL */);
    void raia_imgui_log_to_clipboard(int auto_open_depth /* = -1 */);
    void raia_imgui_log_finish();
    void raia_imgui_log_buttons();
    void raia_imgui_log_text(const char* text);
    
    // 無効化 [BETA API]
    void raia_imgui_begin_disabled(bool disabled /* = true */);
    void raia_imgui_end_disabled();
    
    // クリッピング
    void raia_imgui_push_clip_rect(float clip_rect_min_x, float clip_rect_min_y, float clip_rect_max_x, float clip_rect_max_y, bool intersect_with_current_clip_rect);
    void raia_imgui_pop_clip_rect();
    
    // フォーカス, アクティブ化
    void raia_imgui_set_item_default_focus();
    void raia_imgui_set_keyboard_focus_here(int offset /* = 0 */);
    
    // オーバーラッピング・モード
    void raia_imgui_set_next_item_allow_overlap();
    
    // アイテム/ウィジェット ユーティリティとクエリ関数
    bool raia_imgui_is_item_hovered(int flags /* = 0 */);
    bool raia_imgui_is_item_active();
    bool raia_imgui_is_item_focused();
    bool raia_imgui_is_item_clicked(int mouse_button /* = 0 */);
    bool raia_imgui_is_item_visible();
    bool raia_imgui_is_item_edited();
    bool raia_imgui_is_item_activated();
    bool raia_imgui_is_item_deactivated();
    bool raia_imgui_is_item_deactivated_after_edit();
    bool raia_imgui_is_item_toggled_open();
    bool raia_imgui_is_any_item_hovered();
    bool raia_imgui_is_any_item_active();
    bool raia_imgui_is_any_item_focused();
    unsigned int raia_imgui_get_item_id();
    float raia_imgui_get_item_rect_min_x();
    float raia_imgui_get_item_rect_min_y();
    float raia_imgui_get_item_rect_max_x();
    float raia_imgui_get_item_rect_max_y();
    float raia_imgui_get_item_rect_size_x();
    float raia_imgui_get_item_rect_size_y();
    
    // ビューポート
    void* raia_imgui_get_main_viewport();
    
    // 背景／前景ドローリスト
    void* raia_imgui_get_background_draw_list();
    void* raia_imgui_get_foreground_draw_list();
    
    // その他ユーティリティ
    bool raia_imgui_is_rect_visible(float size_x, float size_y);
    bool raia_imgui_is_rect_visible_2(float rect_min_x, float rect_min_y, float rect_max_x, float rect_max_y);
    double raia_imgui_get_time();
    int raia_imgui_get_frame_count();
    void* raia_imgui_get_draw_list_shared_data();
    const char* raia_imgui_get_style_color_name(int idx);
    void raia_imgui_set_state_storage(void* storage);
    void* raia_imgui_get_state_storage();
    bool raia_imgui_begin_child_frame(unsigned int id, float size_x, float size_y, int flags /* = 0 */);
    void raia_imgui_end_child_frame();
    
    // テキスト・ユーティリティ
    float raia_imgui_calc_text_size_x(const char* text, const char* text_end /* = NULL */, bool hide_text_after_double_hash /* = false */, float wrap_width /* = -1.0f */);
    float raia_imgui_calc_text_size_y(const char* text, const char* text_end /* = NULL */, bool hide_text_after_double_hash /* = false */, float wrap_width /* = -1.0f */);
    
    // カラーユーティリティ
    float raia_imgui_color_convert_u32_to_float4_x(unsigned int in);
    float raia_imgui_color_convert_u32_to_float4_y(unsigned int in);
    float raia_imgui_color_convert_u32_to_float4_z(unsigned int in);
    float raia_imgui_color_convert_u32_to_float4_w(unsigned int in);
    unsigned int raia_imgui_color_convert_float4_to_u32(float in_x, float in_y, float in_z, float in_w);
    void raia_imgui_color_convert_rgb_to_hsv(float r, float g, float b, float * out_h, float * out_s, float * out_v);
    void raia_imgui_color_convert_hsv_to_rgb(float h, float s, float v, float * out_r, float * out_g, float * out_b);
    
    // 入力ユーティリティ: キーボード/マウス/ゲームパッド
    bool raia_imgui_is_key_down(int key);
    bool raia_imgui_is_key_pressed(int key, bool repeat /* = true */);
    bool raia_imgui_is_key_released(int key);
    int raia_imgui_get_key_pressed_amount(int key, float repeat_delay, float rate);
    const char* raia_imgui_get_key_name(int key);
    void raia_imgui_set_next_frame_want_capture_keyboard(bool want_capture_keyboard);
    
    // 入力ユーティリティ： マウス専用
    bool raia_imgui_is_mouse_down(int button);
    bool raia_imgui_is_mouse_clicked(int button, bool repeat /* = false */);
    bool raia_imgui_is_mouse_released(int button);
    bool raia_imgui_is_mouse_double_clicked(int button);
    int raia_imgui_get_mouse_clicked_count(int button);
    bool raia_imgui_is_mouse_hovering_rect(float r_min_x, float r_min_y, float r_max_x, float r_max_y, bool clip /* = true */);
    bool raia_imgui_is_mouse_pos_valid(const void* mouse_pos /* = NULL */);
    bool raia_imgui_is_any_mouse_down();
    float raia_imgui_get_mouse_pos_x();
    float raia_imgui_get_mouse_pos_y();
    float raia_imgui_get_mouse_pos_on_opening_current_popup_x();
    float raia_imgui_get_mouse_pos_on_opening_current_popup_y();
    bool raia_imgui_is_mouse_dragging(int button, float lock_threshold /* = -1.0f */);
    float raia_imgui_get_mouse_drag_delta_x(int button /* = 0 */, float lock_threshold /* = -1.0f */);
    float raia_imgui_get_mouse_drag_delta_y(int button /* = 0 */, float lock_threshold /* = -1.0f */);
    void raia_imgui_reset_mouse_drag_delta(int button /* = 0 */);
    int raia_imgui_get_mouse_cursor();
    void raia_imgui_set_mouse_cursor(int cursor_type);
    void raia_imgui_set_next_frame_want_capture_mouse(bool want_capture_mouse);
    
    // クリップボードユーティリティ
    const char* raia_imgui_get_clipboard_text();
    void raia_imgui_set_clipboard_text(const char* text);
    
    // 設定/.Ini ユーティリティ
    void raia_imgui_load_ini_settings_from_disk(const char* ini_filename);
    void raia_imgui_load_ini_settings_from_memory(const char* ini_data, size_t ini_size /* = 0 */);
    void raia_imgui_save_ini_settings_to_disk(const char* ini_filename);
    const char* raia_imgui_save_ini_settings_to_memory(size_t* out_ini_size /* = NULL */);

    // デバッグ・ユーティリティ
    void raia_imgui_debug_text_encoding(const char* text);
    bool raia_imgui_debug_check_version_and_data_layout(const char* version_str, size_t sz_io, size_t sz_style, size_t sz_vec2, size_t sz_vec4, size_t sz_drawvert, size_t sz_drawidx);

    // メモリ・アロケータ
    void raia_imgui_set_allocator_functions(void* alloc_func, void* free_func, void* user_data /* = NULL */);
    void raia_imgui_get_allocator_functions(void** p_alloc_func, void** p_free_func, void** p_user_data);
    void* raia_imgui_mem_alloc(size_t size);
    void raia_imgui_mem_free(void* ptr);

    // -- ここから拡張
    double raia_get_flt_min();
    double raia_get_flt_max();

    // imgui.cpp
    void raia_imgui_update_platform_windows();
    void raia_imgui_render_platform_windows_default();

    // impl GLFW
    bool raia_imgui_impl_glfw_init_for_opengl(void* window, bool install_callbacks);
    void raia_imgui_impl_glfw_new_frame();
    void raia_imgui_impl_glfw_shutdown();
    
    // impl OpenGL3
    bool raia_imgui_impl_opengl3_init(const char *glsl_version);
    void raia_imgui_impl_opengl3_new_frame();
    void raia_imgui_impl_opengl3_render_draw_data(void* draw_data);
    void raia_imgui_impl_opengl3_shutdown();
    
    // GetIO ユーティリティ
    void raia_imgui_io_set_config_flags(int config_flags);
    void raia_imgui_io_set_config_viewports_no_auto_merge(bool flag);
    void raia_imgui_io_set_config_viewports_no_task_bar_icon(bool flag);
    void raia_imgui_io_set_font_global_scale(float num);
    float raia_imgui_io_get_framerate();
    void raia_imgui_io_set_font_default(void *font);
    
    // GetIO.Fonts ユーティリティ
    void* raia_imgui_io_fonts_add_font_default();
    const void *raia_imgui_io_fonts_get_glyph_ranges_japanese();
    void *raia_imgui_io_fonts_add_font_from_file_ttf(const char *filename, float size_pixels, const void *font_cfg, const void *glyph_ranges);
    
    // GetStyle ユーティリティ
    void raia_imgui_style_set_alpha(float n);
    void raia_imgui_style_set_disabled_alpha(float n);
    void raia_imgui_style_set_window_padding(float x, float y);
    void raia_imgui_style_set_window_rounding(float n);
    void raia_imgui_style_set_window_border_size(float n);
    void raia_imgui_style_set_window_min_size(float x, float y);
    void raia_imgui_style_set_window_title_align(float x, float y);
    void raia_imgui_style_set_window_menu_button_position(int n);
    void raia_imgui_style_set_child_rounding(float n);
    void raia_imgui_style_set_child_border_size(float n);
    void raia_imgui_style_set_popup_rounding(float n);
    void raia_imgui_style_set_popup_border_size(float n);
    void raia_imgui_style_set_frame_padding(float x, float y);
    void raia_imgui_style_set_frame_rounding(float n);
    void raia_imgui_style_set_frame_border_size(float n);
    void raia_imgui_style_set_item_spacing(float x, float y);
    void raia_imgui_style_set_item_inner_spacing(float x, float y);
    void raia_imgui_style_set_cell_padding(float x, float y);
    void raia_imgui_style_set_touch_extra_padding(float x, float y);
    void raia_imgui_style_set_indent_spacing(float n);
    void raia_imgui_style_set_columns_min_spacing(float n);
    void raia_imgui_style_set_scrollbar_size(float n);
    void raia_imgui_style_set_scrollbar_rounding(float n);
    void raia_imgui_style_set_grab_min_size(float n);
    void raia_imgui_style_set_grab_rounding(float n);
    void raia_imgui_style_set_log_slider_deadzone(float n);
    void raia_imgui_style_set_tab_rounding(float n);
    void raia_imgui_style_set_tab_border_size(float n);
    void raia_imgui_style_set_tab_min_width_for_close_button(float n);
    void raia_imgui_style_set_bolor_button_position(int n);
    void raia_imgui_style_set_button_text_align(float x, float y);
    void raia_imgui_style_set_selectable_text_align(float x, float y);
    void raia_imgui_style_set_separator_text_border_size(float n);
    void raia_imgui_style_set_separator_text_align(float x, float y);
    void raia_imgui_style_set_separator_text_padding(float x, float y);
    void raia_imgui_style_set_display_window_padding(float x, float y);
    void raia_imgui_style_set_display_safe_area_padding(float x, float y);
    void raia_imgui_style_set_mouse_cursor_scale(float n);
    void raia_imgui_style_set_anti_aliased_lines(bool n);
    void raia_imgui_style_set_anti_aliased_lines_use_tex(bool n);
    void raia_imgui_style_set_anti_aliased_fill(bool n);
    void raia_imgui_style_set_curve_tessellation_tol(float n);
    void raia_imgui_style_set_circle_tessellation_max_error(float n);
    void raia_imgui_style_scale_all_sizes(float n);
    void raia_imgui_style_set_colors(int col, float red, float green, float blue, float alpha);

    // Image ユーティリティ
    void *raia_imgui_int_to_ptr(int value);
]]

local lib = ffi.load("libraia_imgui")
local bit = require("bit")
local ImGui = {}

-- 列挙

ImGui.WindowFlags = {
    None                     = 0,
    NoTitleBar               = bit.lshift(1, 0),
    NoResize                 = bit.lshift(1, 1),
    NoMove                   = bit.lshift(1, 2),
    NoScrollbar              = bit.lshift(1, 3),
    NoScrollWithMouse        = bit.lshift(1, 4),
    NoCollapse               = bit.lshift(1, 5),
    AlwaysAutoResize         = bit.lshift(1, 6),
    NoBackground             = bit.lshift(1, 7),
    NoSavedSettings          = bit.lshift(1, 8),
    NoMouseInputs            = bit.lshift(1, 9),
    MenuBar                  = bit.lshift(1, 10),
    HorizontalScrollbar      = bit.lshift(1, 11),
    NoFocusOnAppearing       = bit.lshift(1, 12),
    NoBringToFrontOnFocus    = bit.lshift(1, 13),
    AlwaysVerticalScrollbar  = bit.lshift(1, 14),
    AlwaysHorizontalScrollbar= bit.lshift(1, 15),
    AlwaysUseWindowPadding   = bit.lshift(1, 16),
    NoNavInputs              = bit.lshift(1, 18),
    NoNavFocus               = bit.lshift(1, 19),
    UnsavedDocument          = bit.lshift(1, 20),
    NoDocking                = bit.lshift(1, 21),
}

ImGui.WindowFlags.NoNav        = bit.bor(ImGui.WindowFlags.NoNavInputs, ImGui.WindowFlags.NoNavFocus)
ImGui.WindowFlags.NoDecoration = bit.bor(ImGui.WindowFlags.NoTitleBar, ImGui.WindowFlags.NoResize, ImGui.WindowFlags.NoScrollbar, ImGui.WindowFlags.NoCollapse)
ImGui.WindowFlags.NoInputs     = bit.bor(ImGui.WindowFlags.NoMouseInputs, ImGui.WindowFlags.NoNavInputs, ImGui.WindowFlags.NoNavFocus)

ImGui.InputTextFlags = {
    None                = 0,
    CharsDecimal        = bit.lshift(1, 0),
    CharsHexadecimal    = bit.lshift(1, 1),
    CharsUppercase      = bit.lshift(1, 2),
    CharsNoBlank        = bit.lshift(1, 3),
    AutoSelectAll       = bit.lshift(1, 4),
    EnterReturnsTrue    = bit.lshift(1, 5),
    CallbackCompletion  = bit.lshift(1, 6),
    CallbackHistory     = bit.lshift(1, 7),
    CallbackAlways      = bit.lshift(1, 8),
    CallbackCharFilter  = bit.lshift(1, 9),
    AllowTabInput       = bit.lshift(1, 10),
    CtrlEnterForNewLine = bit.lshift(1, 11),
    NoHorizontalScroll  = bit.lshift(1, 12),
    AlwaysOverwrite     = bit.lshift(1, 13),
    ReadOnly            = bit.lshift(1, 14),
    Password            = bit.lshift(1, 15),
    NoUndoRedo          = bit.lshift(1, 16),
    CharsScientific     = bit.lshift(1, 17),
    CallbackResize      = bit.lshift(1, 18),
    CallbackEdit        = bit.lshift(1, 19),
    EscapeClearsAll     = bit.lshift(1, 20),
}

ImGui.TreeNodeFlags = {
    None                 = 0,
    Selected             = bit.lshift(1, 0),
    Framed               = bit.lshift(1, 1),
    AllowOverlap         = bit.lshift(1, 2),
    NoTreePushOnOpen     = bit.lshift(1, 3),
    NoAutoOpenOnLog      = bit.lshift(1, 4),
    DefaultOpen          = bit.lshift(1, 5),
    OpenOnDoubleClick    = bit.lshift(1, 6),
    OpenOnArrow          = bit.lshift(1, 7),
    Leaf                 = bit.lshift(1, 8),
    Bullet               = bit.lshift(1, 9),
    FramePadding         = bit.lshift(1, 10),
    SpanAvailWidth       = bit.lshift(1, 11),
    SpanFullWidth        = bit.lshift(1, 12),
    NavLeftJumpsBackHere = bit.lshift(1, 13),
}

ImGui.TreeNodeFlags.CollapsingHeader = bit.bor(ImGui.TreeNodeFlags.Framed, ImGui.TreeNodeFlags.NoTreePushOnOpen, ImGui.TreeNodeFlags.NoAutoOpenOnLog)

ImGui.PopupFlags = {
    None                    = 0,
    MouseButtonLeft         = 0,
    MouseButtonRight        = 1,
    MouseButtonMiddle       = 2,
    MouseButtonMask_        = 0x1F,
    MouseButtonDefault_     = 1,
    NoOpenOverExistingPopup = bit.lshift(1, 5),
    NoOpenOverItems         = bit.lshift(1, 6),
    AnyPopupId              = bit.lshift(1, 7),
    AnyPopupLevel           = bit.lshift(1, 8),
}

ImGui.PopupFlags.AnyPopup = bit.bor(ImGui.PopupFlags.AnyPopupId, ImGui.PopupFlags.AnyPopupLevel)

ImGui.SelectableFlags = {
    None               = 0,
    DontClosePopups    = bit.lshift(1, 0),
    SpanAllColumns     = bit.lshift(1, 1),
    AllowDoubleClick   = bit.lshift(1, 2),
    Disabled           = bit.lshift(1, 3),
    AllowOverlap       = bit.lshift(1, 4),
}

ImGui.ComboFlags = {
    None                    = 0,
    PopupAlignLeft          = bit.lshift(1, 0),
    HeightSmall             = bit.lshift(1, 1),
    HeightRegular           = bit.lshift(1, 2),
    HeightLarge             = bit.lshift(1, 3),
    HeightLargest           = bit.lshift(1, 4),
    NoArrowButton           = bit.lshift(1, 5),
    NoPreview               = bit.lshift(1, 6),
}

ImGui.ComboFlags.HeightMask_ = bit.bor(ImGui.ComboFlags.HeightSmall, ImGui.ComboFlags.HeightRegular, ImGui.ComboFlags.HeightLarge, ImGui.ComboFlags.HeightLargest)

ImGui.TabBarFlags = {
    None                           = 0,
    Reorderable                    = bit.lshift(1, 0),
    AutoSelectNewTabs              = bit.lshift(1, 1),
    TabListPopupButton             = bit.lshift(1, 2),
    NoCloseWithMiddleMouseButton   = bit.lshift(1, 3),
    NoTabListScrollingButtons      = bit.lshift(1, 4),
    NoTooltip                      = bit.lshift(1, 5),
    FittingPolicyResizeDown        = bit.lshift(1, 6),
    FittingPolicyScroll            = bit.lshift(1, 7),
}

ImGui.TabBarFlags.FittingPolicyMask_ = bit.bor(ImGui.TabBarFlags.FittingPolicyResizeDown, ImGui.TabBarFlags.FittingPolicyScroll)
ImGui.TabBarFlags.FittingPolicyDefault_ = bit.bor(ImGui.TabBarFlags.FittingPolicyResizeDown)

ImGui.TabItemFlags = {
    None                          = 0,
    UnsavedDocument               = bit.lshift(1, 0),
    SetSelected                   = bit.lshift(1, 1),
    NoCloseWithMiddleMouseButton  = bit.lshift(1, 2),
    NoPushId                      = bit.lshift(1, 3),
    NoTooltip                     = bit.lshift(1, 4),
    NoReorder                     = bit.lshift(1, 5),
    Leading                       = bit.lshift(1, 6),
    Trailing                      = bit.lshift(1, 7),
}

ImGui.TableFlags = {
    None                       = 0,
    Resizable                  = bit.lshift(1, 0),
    Reorderable                = bit.lshift(1, 1),
    Hideable                   = bit.lshift(1, 2),
    Sortable                   = bit.lshift(1, 3),
    NoSavedSettings            = bit.lshift(1, 4),
    ContextMenuInBody          = bit.lshift(1, 5),
    RowBg                      = bit.lshift(1, 6),
    BordersInnerH              = bit.lshift(1, 7),
    BordersOuterH              = bit.lshift(1, 8),
    BordersInnerV              = bit.lshift(1, 9),
    BordersOuterV              = bit.lshift(1, 10),
    NoBordersInBody            = bit.lshift(1, 11),
    NoBordersInBodyUntilResize = bit.lshift(1, 12),
    SizingFixedFit             = bit.lshift(1, 13),
    SizingFixedSame            = bit.lshift(2, 13),
    SizingStretchProp          = bit.lshift(3, 13),
    SizingStretchSame          = bit.lshift(4, 13),
    NoHostExtendX              = bit.lshift(1, 16),
    NoHostExtendY              = bit.lshift(1, 17),
    NoKeepColumnsVisible       = bit.lshift(1, 18),
    PreciseWidths              = bit.lshift(1, 19),
    NoClip                     = bit.lshift(1, 20),
    PadOuterX                  = bit.lshift(1, 21),
    NoPadOuterX                = bit.lshift(1, 22),
    NoPadInnerX                = bit.lshift(1, 23),
    ScrollX                    = bit.lshift(1, 24),
    ScrollY                    = bit.lshift(1, 25),
    SortMulti                  = bit.lshift(1, 26),
    SortTristate               = bit.lshift(1, 27),
}

ImGui.TableFlags.BordersH     = bit.bor(ImGui.TableFlags.BordersInnerH, ImGui.TableFlags.BordersOuterH)
ImGui.TableFlags.BordersV     = bit.bor(ImGui.TableFlags.BordersInnerV, ImGui.TableFlags.BordersOuterV)
ImGui.TableFlags.BordersInner = bit.bor(ImGui.TableFlags.BordersInnerV, ImGui.TableFlags.BordersInnerH)
ImGui.TableFlags.BordersOuter = bit.bor(ImGui.TableFlags.BordersOuterV, ImGui.TableFlags.BordersOuterH)
ImGui.TableFlags.Borders      = bit.bor(ImGui.TableFlags.BordersInner, ImGui.TableFlags.BordersOuter)
ImGui.TableFlags.SizingMask_  = bit.bor(ImGui.TableFlags.SizingFixedFit, ImGui.TableFlags.SizingFixedSame, ImGui.TableFlags.SizingStretchProp, ImGui.TableFlags.SizingStretchSame)

ImGui.TableColumnFlags = {
    None                  = 0,
    Disabled              = bit.lshift(1, 0),
    DefaultHide           = bit.lshift(1, 1),
    DefaultSort           = bit.lshift(1, 2),
    WidthStretch          = bit.lshift(1, 3),
    WidthFixed            = bit.lshift(1, 4),
    NoResize              = bit.lshift(1, 5),
    NoReorder             = bit.lshift(1, 6),
    NoHide                = bit.lshift(1, 7),
    NoClip                = bit.lshift(1, 8),
    NoSort                = bit.lshift(1, 9),
    NoSortAscending       = bit.lshift(1, 10),
    NoSortDescending      = bit.lshift(1, 11),
    NoHeaderLabel         = bit.lshift(1, 12),
    NoHeaderWidth         = bit.lshift(1, 13),
    PreferSortAscending   = bit.lshift(1, 14),
    PreferSortDescending  = bit.lshift(1, 15),
    IndentEnable          = bit.lshift(1, 16),
    IndentDisable         = bit.lshift(1, 17),
    IsEnabled             = bit.lshift(1, 24),
    IsVisible             = bit.lshift(1, 25),
    IsSorted              = bit.lshift(1, 26),
    IsHovered             = bit.lshift(1, 27),
    NoDirectResize_       = bit.lshift(1, 30),
}

ImGui.TableColumnFlags.WidthMask_      = bit.bor(ImGui.TableColumnFlags.WidthStretch, ImGui.TableColumnFlags.WidthFixed)
ImGui.TableColumnFlags.IndentMask_     = bit.bor(ImGui.TableColumnFlags.IndentEnable, ImGui.TableColumnFlags.IndentDisable)
ImGui.TableColumnFlags.StatusMask_     = bit.bor(ImGui.TableColumnFlags.IsEnabled, ImGui.TableColumnFlags.IsVisible, ImGui.TableColumnFlags.IsSorted, ImGui.TableColumnFlags.IsHovered)

ImGui.TableRowFlags = {
    None    = 0,
    Headers = bit.lshift(1, 0),
}

ImGui.TableBgTarget = {
    None   = 0,
    RowBg0 = 1,
    RowBg1 = 2,
    CellBg = 3,
}

ImGui.FocusedFlags = {
    None             = 0,
    ChildWindows     = bit.lshift(1, 0),
    RootWindow       = bit.lshift(1, 1),
    AnyWindow        = bit.lshift(1, 2),
    NoPopupHierarchy = bit.lshift(1, 3),
}

ImGui.FocusedFlags.RootAndChildWindows = bit.bor(ImGui.FocusedFlags.RootWindow, ImGui.FocusedFlags.ChildWindows)

ImGui.HoveredFlags = {
    None                            = 0,
    ChildWindows                    = bit.lshift(1, 0),
    RootWindow                      = bit.lshift(1, 1),
    AnyWindow                       = bit.lshift(1, 2),
    NoPopupHierarchy                = bit.lshift(1, 3),
--  DockHierarchy                   = bit.lshift(1, 4),
    AllowWhenBlockedByPopup         = bit.lshift(1, 5),
--  AllowWhenBlockedByModal         = bit.lshift(1, 6),
    AllowWhenBlockedByActiveItem    = bit.lshift(1, 7),
    AllowWhenOverlappedByItem       = bit.lshift(1, 8),
    AllowWhenOverlappedByWindow     = bit.lshift(1, 9),
    AllowWhenDisabled               = bit.lshift(1, 10),
    NoNavOverride                   = bit.lshift(1, 11),
    ForTooltip                      = bit.lshift(1, 12),
    Stationary                      = bit.lshift(1, 13),
    DelayNone                       = bit.lshift(1, 14),
    DelayShort                      = bit.lshift(1, 15),
    DelayNormal                     = bit.lshift(1, 16),
    NoSharedDelay                   = bit.lshift(1, 17),
}

ImGui.HoveredFlags.AllowWhenOverlapped = bit.bor(ImGui.HoveredFlags.AllowWhenOverlappedByItem, ImGui.HoveredFlags.AllowWhenOverlappedByWindow)
ImGui.HoveredFlags.RectOnly            = bit.bor(ImGui.HoveredFlags.AllowWhenBlockedByPopup, ImGui.HoveredFlags.AllowWhenBlockedByActiveItem, ImGui.HoveredFlags.AllowWhenOverlapped)
ImGui.HoveredFlags.RootAndChildWindows = bit.bor(ImGui.HoveredFlags.RootWindow, ImGui.HoveredFlags.ChildWindows)

ImGui.DragDropFlags = {
    None                         = 0,
    SourceNoPreviewTooltip       = bit.lshift(1, 0),
    SourceNoDisableHover         = bit.lshift(1, 1),
    SourceNoHoldToOpenOthers     = bit.lshift(1, 2),
    SourceAllowNullID            = bit.lshift(1, 3),
    SourceExtern                 = bit.lshift(1, 4),
    SourceAutoExpirePayload      = bit.lshift(1, 5),
    AcceptBeforeDelivery         = bit.lshift(1, 10),
    AcceptNoDrawDefaultRect      = bit.lshift(1, 11),
    AcceptNoPreviewTooltip       = bit.lshift(1, 12),
}

ImGui.DragDropFlags.AcceptPeekOnly = bit.bor(ImGui.DragDropFlags.AcceptBeforeDelivery, ImGui.DragDropFlags.AcceptNoDrawDefaultRect)

ImGui.DataType = {
    S8     = 0,
    U8     = 1,
    S16    = 2,
    U16    = 3,
    S32    = 4,
    U32    = 5,
    S64    = 6,
    U64    = 7,
    Float  = 8,
    Double = 9,
    COUNT  = 10,
}

ImGui.Dir = {
    None    = -1,
    Left    = 0,
    Right   = 1,
    Up      = 2,
    Down    = 3,
    COUNT   = 4,
}

ImGui.SortDirection = {
    None         = 0,
    Ascending    = 1,
    Descending   = 2
}

ImGui.Key = {
    None                = 0,
    Tab                 = 512, -- == ImGuiKey_NamedKey_BEGIN
    LeftArrow           = 513,
    RightArrow          = 514,
    UpArrow             = 515,
    DownArrow           = 516,
    PageUp              = 517,
    PageDown            = 518,
    Home                = 519,
    End                 = 520,
    Insert              = 521,
    Delete              = 522,
    Backspace           = 523,
    Space               = 524,
    Enter               = 525,
    Escape              = 526,
    LeftCtrl            = 527,
    LeftShift           = 528,
    LeftAlt             = 529,
    LeftSuper           = 530,
    RightCtrl           = 531,
    RightShift          = 532,
    RightAlt            = 533,
    RightSuper          = 534,
    Menu                = 535,
    _0                  = 536,
    _1                  = 537,
    _2                  = 538,
    _3                  = 539,
    _4                  = 540,
    _5                  = 541,
    _6                  = 542,
    _7                  = 543,
    _8                  = 544,
    _9                  = 545,
    A                   = 546,
    B                   = 547,
    C                   = 548,
    D                   = 549,
    E                   = 550,
    F                   = 551,
    G                   = 552,
    H                   = 553,
    I                   = 554,
    J                   = 555,
    K                   = 556,
    L                   = 557,
    M                   = 558,
    N                   = 559,
    O                   = 560,
    P                   = 561,
    Q                   = 562,
    R                   = 563,
    S                   = 564,
    T                   = 565,
    U                   = 566,
    V                   = 567,
    W                   = 568,
    X                   = 569,
    Y                   = 570,
    Z                   = 571,
    F1                  = 572,
    F2                  = 573,
    F3                  = 574,
    F4                  = 575,
    F5                  = 576,
    F6                  = 577,
    F7                  = 578,
    F8                  = 579,
    F9                  = 580,
    F10                 = 581,
    F11                 = 582,
    F12                 = 583,
    Apostrophe          = 584, -- '
    Comma               = 585, -- ,
    Minus               = 586, -- -
    Period              = 587, -- .
    Slash               = 588, -- /
    Semicolon           = 589, -- ;
    Equal               = 590, -- =
    LeftBracket         = 591, -- [
    Backslash           = 592, -- \ (this text inhibit multiline comment caused by backslash)
    RightBracket        = 593, -- ]
    GraveAccent         = 594, -- `
    CapsLock            = 595,
    ScrollLock          = 596,
    NumLock             = 597,
    PrintScreen         = 598,
    Pause               = 599,
    Keypad0             = 600,
    Keypad1             = 601,
    Keypad2             = 602,
    Keypad3             = 603,
    Keypad4             = 604,
    Keypad5             = 605,
    Keypad6             = 606,
    Keypad7             = 607,
    Keypad8             = 608,
    Keypad9             = 609,
    KeypadDecimal       = 610,
    KeypadDivide        = 611,
    KeypadMultiply      = 612,
    KeypadSubtract      = 613,
    KeypadAdd           = 614,
    KeypadEnter         = 615,
    KeypadEqual         = 616,
    GamepadStart        = 617,
    GamepadBack         = 618,
    GamepadFaceLeft     = 619,
    GamepadFaceRight    = 620,
    GamepadFaceUp       = 621,
    GamepadFaceDown     = 622,
    GamepadDpadLeft     = 623,
    GamepadDpadRight    = 624,
    GamepadDpadUp       = 625,
    GamepadDpadDown     = 626,
    GamepadL1           = 627,
    GamepadR1           = 628,
    GamepadL2           = 629,
    GamepadR2           = 630,
    GamepadL3           = 631,
    GamepadR3           = 632,
    GamepadLStickLeft   = 633,
    GamepadLStickRight  = 634,
    GamepadLStickUp     = 635,
    GamepadLStickDown   = 636,
    GamepadRStickLeft   = 637,
    GamepadRStickRight  = 638,
    GamepadRStickUp     = 639,
    GamepadRStickDown   = 640,
    MouseLeft           = 641,
    MouseRight          = 642,
    MouseMiddle         = 643,
    MouseX1             = 644,
    MouseX2             = 645,
    MouseWheelX         = 646,
    MouseWheelY         = 647,
    ReservedForModCtrl  = 648,
    ReservedForModShift = 649,
    ReservedForModAlt   = 650,
    ReservedForModSuper = 651,
    COUNT               = 652,
}

ImGui.Mod = {
    None     = 0,
    Ctrl     = bit.lshift(1, 12),
    Shift    = bit.lshift(1, 13),
    Alt      = bit.lshift(1, 14),
    Super    = bit.lshift(1, 15),
    Shortcut = bit.lshift(1, 11),
    Mask_    = 0xF800,
}

ImGui.ConfigFlags = {
    None                    = 0,
    NavEnableKeyboard       = bit.lshift(1, 0),
    NavEnableGamepad        = bit.lshift(1, 1),
    NavEnableSetMousePos    = bit.lshift(1, 2),
    NavNoCaptureKeyboard    = bit.lshift(1, 3),
    NoMouse                 = bit.lshift(1, 4),
    NoMouseCursorChange     = bit.lshift(1, 5),
    DockingEnable           = bit.lshift(1, 6),
    ViewportsEnable         = bit.lshift(1, 10),
    DpiEnableScaleViewports = bit.lshift(1, 14),
    DpiEnableScaleFonts     = bit.lshift(1, 15),
    IsSRGB                  = bit.lshift(1, 20),
    IsTouchScreen           = bit.lshift(1, 21),
}

ImGui.BackendFlags = {
    None                  = 0,
    HasGamepad            = bit.lshift(1, 0),
    HasMouseCursors       = bit.lshift(1, 1),
    HasSetMousePos        = bit.lshift(1, 2),
    RendererHasVtxOffset  = bit.lshift(1, 3),
}

ImGui.Col = { -- enum
    Text                  = 0,
    TextDisabled          = 1,
    WindowBg              = 2,
    ChildBg               = 3,
    PopupBg               = 4,
    Border                = 5,
    BorderShadow          = 6,
    FrameBg               = 7,
    FrameBgHovered        = 8,
    FrameBgActive         = 9,
    TitleBg               = 10,
    TitleBgActive         = 11,
    TitleBgCollapsed      = 12,
    MenuBarBg             = 13,
    ScrollbarBg           = 14,
    ScrollbarGrab         = 15,
    ScrollbarGrabHovered  = 16,
    ScrollbarGrabActive   = 17,
    CheckMark             = 18,
    SliderGrab            = 19,
    SliderGrabActive      = 20,
    Button                = 21,
    ButtonHovered         = 22,
    ButtonActive          = 23,
    Header                = 24,
    HeaderHovered         = 25,
    HeaderActive          = 26,
    Separator             = 27,
    SeparatorHovered      = 28,
    SeparatorActive       = 29,
    ResizeGrip            = 30,
    ResizeGripHovered     = 31,
    ResizeGripActive      = 32,
    Tab                   = 33,
    TabHovered            = 34,
    TabActive             = 35,
    TabUnfocused          = 36,
    TabUnfocusedActive    = 37,
    DockingPreview        = 38,
    DockingEmptyBg        = 39,
    PlotLines             = 40,
    PlotLinesHovered      = 41,
    PlotHistogram         = 42,
    PlotHistogramHovered  = 43,
    TableHeaderBg         = 44,
    TableBorderStrong     = 45,
    TableBorderLight      = 46,
    TableRowBg            = 47,
    TableRowBgAlt         = 48,
    TextSelectedBg        = 49,
    DragDropTarget        = 40,
    NavHighlight          = 51,
    NavWindowingHighlight = 52,
    NavWindowingDimBg     = 53,
    ModalWindowDimBg      = 54,
    COUNT                 = 55
}

ImGui.StyleVar = {
    -- Enum name -------------    -- Member in ImGuiStyle structure (see ImGuiStyle for descriptions)
    Alpha                   = 0,  -- float     Alpha
    DisabledAlpha           = 1,  -- float     DisabledAlpha
    WindowPadding           = 2,  -- ImVec2    WindowPadding
    WindowRounding          = 3,  -- float     WindowRounding
    WindowBorderSize        = 4,  -- float     WindowBorderSize
    WindowMinSize           = 5,  -- ImVec2    WindowMinSize
    WindowTitleAlign        = 6,  -- ImVec2    WindowTitleAlign
    ChildRounding           = 7,  -- float     ChildRounding
    ChildBorderSize         = 8,  -- float     ChildBorderSize
    PopupRounding           = 9,  -- float     PopupRounding
    PopupBorderSize         = 10, -- float     PopupBorderSize
    FramePadding            = 11, -- ImVec2    FramePadding
    FrameRounding           = 12, -- float     FrameRounding
    FrameBorderSize         = 13, -- float     FrameBorderSize
    ItemSpacing             = 14, -- ImVec2    ItemSpacing
    ItemInnerSpacing        = 15, -- ImVec2    ItemInnerSpacing
    IndentSpacing           = 16, -- float     IndentSpacing
    CellPadding             = 17, -- ImVec2    CellPadding
    ScrollbarSize           = 18, -- float     ScrollbarSize
    ScrollbarRounding       = 19, -- float     ScrollbarRounding
    GrabMinSize             = 20, -- float     GrabMinSize
    GrabRounding            = 21, -- float     GrabRounding
    TabRounding             = 22, -- float     TabRounding
    ButtonTextAlign         = 23, -- ImVec2    ButtonTextAlign
    SelectableTextAlign     = 24, -- ImVec2    SelectableTextAlign
    SeparatorTextBorderSize = 25, -- float     SeparatorTextBorderSize
    SeparatorTextAlign      = 26, -- ImVec2    SeparatorTextAlign
    SeparatorTextPadding    = 27, -- ImVec2    SeparatorTextPadding
    COUNT                   = 28
}

ImGui.ButtonFlags = {
    None              = 0,
    MouseButtonLeft   = bit.lshift(1, 0),
    MouseButtonRight  = bit.lshift(1, 1),
    MouseButtonMiddle = bit.lshift(1, 2),
}

ImGui.ButtonFlags.MouseButtonMask_       = bit.bor(ImGui.ButtonFlags.MouseButtonLeft, ImGui.ButtonFlags.MouseButtonRight, ImGui.ButtonFlags.MouseButtonMiddle)
ImGui.ButtonFlags.MouseButtonDefault_    = bit.bor(ImGui.ButtonFlags.MouseButtonLeft)

ImGui.ColorEditFlags = {
    None             = 0,
    NoAlpha          = bit.lshift(1, 1),
    NoPicker         = bit.lshift(1, 2),
    NoOptions        = bit.lshift(1, 3),
    NoSmallPreview   = bit.lshift(1, 4),
    NoInputs         = bit.lshift(1, 5),
    NoTooltip        = bit.lshift(1, 6),
    NoLabel          = bit.lshift(1, 7),
    NoSidePreview    = bit.lshift(1, 8),
    NoDragDrop       = bit.lshift(1, 9),
    NoBorder         = bit.lshift(1, 10),
    AlphaBar         = bit.lshift(1, 16),
    AlphaPreview     = bit.lshift(1, 17),
    AlphaPreviewHalf = bit.lshift(1, 18),
    HDR              = bit.lshift(1, 19),
    DisplayRGB       = bit.lshift(1, 20),
    DisplayHSV       = bit.lshift(1, 21),
    DisplayHex       = bit.lshift(1, 22),
    Uint8            = bit.lshift(1, 23),
    Float            = bit.lshift(1, 24),
    PickerHueBar     = bit.lshift(1, 25),
    PickerHueWheel   = bit.lshift(1, 26),
    InputRGB         = bit.lshift(1, 27),
    InputHSV         = bit.lshift(1, 28),
}

ImGui.ColorEditFlags.DefaultOptions_ = bit.bor(ImGui.ColorEditFlags.Uint8, ImGui.ColorEditFlags.DisplayRGB, ImGui.ColorEditFlags.InputRGB, ImGui.ColorEditFlags.PickerHueBar)
ImGui.ColorEditFlags.DisplayMask_    = bit.bor(ImGui.ColorEditFlags.DisplayRGB, ImGui.ColorEditFlags.DisplayHSV, ImGui.ColorEditFlags.DisplayHex)
ImGui.ColorEditFlags.DataTypeMask_   = bit.bor(ImGui.ColorEditFlags.Uint8, ImGui.ColorEditFlags.Float)
ImGui.ColorEditFlags.PickerMask_     = bit.bor(ImGui.ColorEditFlags.PickerHueWheel, ImGui.ColorEditFlags.PickerHueBar)
ImGui.ColorEditFlags.InputMask_      = bit.bor(ImGui.ColorEditFlags.InputRGB, ImGui.ColorEditFlags.InputHSV)

ImGui.SliderFlags = {
    None                   = 0,
    AlwaysClamp            = bit.lshift(1, 4),
    Logarithmic            = bit.lshift(1, 5),
    NoRoundToFormat        = bit.lshift(1, 6),
    NoInput                = bit.lshift(1, 7),
    InvalidMask_           = 0x7000000F,
}

ImGui.MouseButton = {
    Left   = 0,
    Right  = 1,
    Middle = 2,
    COUNT  = 5
}

ImGui.MouseCursor = {
    None       = -1,
    Arrow      = 0,
    TextInput  = 1,
    ResizeAll  = 2,
    ResizeNS   = 3,
    ResizeEW   = 4,
    ResizeNESW = 5,
    ResizeNWSE = 6,
    Hand       = 7,
    NotAllowed = 8,
    COUNT      = 9
}

ImGui.MouseSource = {
    Mouse       = 0,
    TouchScreen = 1,
    Pen         = 2,
    COUNT       = 3
}

ImGui.Cond = {
    None          = 0,
    Always        = bit.lshift(1, 0),
    Once          = bit.lshift(1, 1),
    FirstUseEver  = bit.lshift(1, 2),
    Appearing     = bit.lshift(1, 3),
}

-- ヘルパーマクロ

function ImGui.assert(expr)
    lib.raia_imgui_assert(expr)
end

function ImGui.checkVersion()
    return lib.raia_imgui_check_version()
end

-- コンテキストの作成とアクセス

function ImGui.createContext(shared_font_atlas)
    shared_font_atlas = shared_font_atlas or ffi.null
    return lib.raia_imgui_create_context(shared_font_atlas)
end

function ImGui.destroyContext(ctx)
    ctx = ctx or ffi.null
    lib.raia_imgui_destroy_context(ctx)
end

function ImGui.getCurrentContext()
    return lib.raia_imgui_get_current_context()
end

function ImGui.setCurrentContext(ctx)
    lib.raia_imgui_set_current_context(ctx)
end

-- メイン

function ImGui.getIO()
    return lib.raia_imgui_getio()
end

function ImGui.getStyle()
    return lib.raia_imgui_getstyle()
end

function ImGui.newFrame()
    lib.raia_imgui_new_frame()
end

function ImGui.endFramw()
    lib.raia_imgui_end_frame()
end

function ImGui.render()
    lib.raia_imgui_render()
end

function ImGui.getDrawData()
    return lib.raia_imgui_get_draw_data()
end

-- デモ・デバッグ・情報

function ImGui.showDemoWindow(p_open)
    p_open = p_open or ffi.null
    lib.raia_imgui_show_demo_window(p_open)
end

function ImGui.showMetricsWindow(p_open)
    p_open = p_open or ffi.null
    lib.raia_imgui_show_metrics_window(p_open)
end

function ImGui.showDebugLogWindow(p_open)
    p_open = p_open or ffi.null
    lib.raia_imgui_show_debug_log_window(p_open)
end

function ImGui.showStackToolWindow(p_open)
    p_open = p_open or ffi.null
    lib.raia_imgui_show_stack_tool_window(p_open)
end

function ImGui.showAboutWindow(p_open)
    p_open = p_open or ffi.null
    lib.raia_imgui_show_about_window(p_open)
end

function ImGui.showStyleEditor(ref)
    ref = ref or ffi.null
    lib.raia_imgui_show_style_editor(ref)
end

function ImGui.showStyleSelector(label)
    return lib.raia_imgui_show_style_selector(label)
end

function ImGui.showFontSelector(label)
    lib.raia_imgui_show_font_selector(label)
end

function ImGui.showUserGuide()
    lib.raia_imgui_show_user_guide()
end

function ImGui.getVersion()
    lib.raia_imgui_get_version()
end

-- スタイル

function ImGui.styleColorsDark(dst)
    dst = dst or ffi.null
    lib.raia_imgui_style_colors_dark(dst)
end

function ImGui.styleColorsLight(dst)
    dst = dst or ffi.null
    lib.raia_imgui_style_colors_light(dst)
end

function ImGui.styleColorsClassic(dst)
    dst = dst or ffi.null
    lib.raia_imgui_style_colors_classic(dst)
end

-- ウィンドウ

function ImGui.Begin(name, p_open, flags)
    p_open = p_open or ffi.null
    flags = flags or 0
    return lib.raia_imgui_begin(name, p_open, flags)
end

function ImGui.End()
    lib.raia_imgui_end()
end

-- 子ウィンドウ

function ImGui.beginChild(str_id, size_x, size_y, border, flags)
    size_x = size_x or 0
    size_y = size_y or 0
    border = border or false
    flags = flags or 0
    return lib.raia_imgui_begin_child(str_id, size_x, size_y, border, flags)
end

function ImGui.beginChild2(id, size_x, size_y, border, flags)
    size_x = size_x or 0
    size_y = size_y or 0
    border = border or false
    flags = flags or 0
    return lib.raia_imgui_begin_child_2(id, size_x, size_y, border, flags)
end

function ImGui.endChild()
    lib.raia_imgui_end_child()
end

-- ウィンドウ・ユーティリティ

function ImGui.isWindowAppearing()
    return lib.raia_imgui_is_window_appearing()
end

function ImGui.isWindowCollapsed()
    return lib.raia_imgui_is_window_collapsed()
end

function ImGui.isWindowFocused(flag)
    return lib.raia_imgui_is_window_focused(flags)
end

function ImGui.isWindowHovered(flags)
    return lib.raia_imgui_is_window_hovered(flags)
end

function ImGui.getWindowDrawList()
    return lib.raia_imgui_get_window_draw_list()
end

function ImGui.getWindowPosX()
    return lib.raia_imgui_get_window_pos_x()
end

function ImGui.getWindowPosY()
    return lib.raia_imgui_get_window_pos_y()
end

function ImGui.getWindowWidth()
    return lib.raia_imgui_get_window_width()
end

function ImGui.getWindowHeight()
    return lib.raia_imgui_get_window_height()
end


-- ウィンドウ操作

function ImGui.setNextWindowPos(pos_x, pos_y, cond, pivot_x, pivot_y)
    return lib.raia_imgui_set_next_window_pos(pos_x, pos_y, cond, pivot_x, pivot_y)
end

function ImGui.setNextWindowSize(size_x, size_y, cond)
    cond = cond or 0
    lib.raia_imgui_set_next_window_size(size_x, size_y, cond) 
end

function ImGui.setNextWindowSizeConstraints(size_min_x, size_min_y, size_max_x, size_max_y, custom_callback, custom_callback_data)
    custom_callback = custom_callback or ffi.null
    custom_callback_data = custom_callback_data or ffi.null
    lib.raia_imgui_set_next_window_size_constraints(size_min_x, size_min_y, size_max_x, size_max_y, custom_callback, custom_callback_data) 
end

function ImGui.setNextWindowContentSize(size_x, size_y)
    lib.raia_imgui_set_next_window_content_size(size_x, size_y) 
end

function ImGui.setNextWindowCollapsed(collapsed, cond)
    lib.raia_imgui_set_next_window_collapsed(collapsed, cond) 
end

function ImGui.setNextWindowFocus()
    lib.raia_imgui_set_next_window_focus() 
end

function ImGui.setNextWindowScroll(scroll_x, scroll_y)
    lib.raia_imgui_set_next_window_scroll(scroll_x, scroll_y) 
end

function ImGui.setNextWindowBgAlpha(alpha)
    return lib.raia_imgui_set_next_window_bg_alpha(alpha)
end

function ImGui.setNextWindowViewport(viewport)
    return lib.raia_imgui_set_next_window_viewport(viewport)
end

function ImGui.setNextWindowViewport_2(viewport_id)
    lib.raia_imgui_set_next_window_viewport_2(viewport_id)
end

function ImGui.setWindowPos(pos_x, pos_y, cond)
    cond = cond or 0
    lib.raia_imgui_set_window_pos(pos_x, pos_y, cond)
end

function ImGui.setWindowSize(size_x, size_y, cond)
    cond = cond or 0
    lib.raia_imgui_set_window_size(size_x, size_y, cond)
end

function ImGui.setWindowCollapsed(collapsed, cond)
    cond = cond or 0
    lib.raia_imgui_set_window_collapsed(collapsed, cond)
end

function ImGui.setWindowFocus()
    lib.raia_imgui_set_window_focus()
end

function ImGui.setWindowFontScale(scale)
    lib.raia_imgui_set_window_font_scale(scale)
end

function ImGui.setWindowPos_2(name, pos_x, pos_y, cond)
    cond = cond or 0
    lib.raia_imgui_set_window_pos_2(name, pos_x, pos_y, cond)
end

function ImGui.setWindowSize_2(name, size_x, size_y, cond)
    cond = cond or 0
    lib.raia_imgui_set_window_size_2(name, size_x, size_y, cond)
end

function ImGui.setWindowCollapsed_2(name, collapsed, cond)
    cond = cond or 0
    lib.raia_imgui_set_window_collapsed_2(name, collapsed, cond)
end

function ImGui.setWindowFocus_2(name)
    lib.raia_imgui_set_window_focus_2(name)
end

-- コンテンツ領域

function ImGui.getContentRegionAvailX()
    return lib.raia_imgui_get_content_region_avail_x()
end

function ImGui.getContentRegionAvailY()
    return lib.raia_imgui_get_content_region_avail_y()
end

function ImGui.getContentRegionMaxX()
    return lib.raia_imgui_get_content_region_max_x()
end

function ImGui.getContentRegionMaxY()
    return lib.raia_imgui_get_content_region_max_y()
end

function ImGui.getWindowContentRegionMinX()
    return lib.raia_imgui_get_window_content_region_min_x()
end

function ImGui.getWindowContentRegionMinY()
    return lib.raia_imgui_get_window_content_region_min_y()
end

function ImGui.getWindowContentRegionMaxX()
    return lib.raia_imgui_get_window_content_region_max_x()
end

function ImGui.getWindowContentRegionMaxY()
    return lib.raia_imgui_get_window_content_region_max_y()
end

-- ウィンドウ・スクロール

function ImGui.getScrollX()
    return lib.raia_imgui_get_scroll_x()
end

function ImGui.getScrollY()
    return lib.raia_imgui_get_scroll_y()
end

function ImGui.setScrollX(scroll_x)
    lib.raia_imgui_set_scroll_x(scroll_x)
end

function ImGui.setScrollY(scroll_y)
    lib.raia_imgui_set_scroll_y(scroll_y)
end

function ImGui.getScrollMaxX()
    return lib.raia_imgui_get_scroll_max_x()
end

function ImGui.getScrollMaxY()
    return lib.raia_imgui_get_scroll_max_y()
end

function ImGui.setScrollHereX(center_x_ratio)
    center_x_ratio = center_x_ratio or 0.5
    lib.raia_imgui_set_scroll_here_x(center_x_ratio)
end

function ImGui.setScrollHereY(center_y_ratio)
    center_y_ratio = center_y_ratio or 0.5
    lib.raia_imgui_set_scroll_here_y(center_y_ratio)
end

function ImGui.setScrollFromPosX(local_x, center_x_ratio)
    center_x_ratio = center_x_ratio or 0.5
    lib.raia_imgui_set_scroll_from_pos_x(local_x, center_x_ratio)
end

function ImGui.setScrollFromPosY(local_y, center_y_ratio)
    center_y_ratio = center_y_ratio or 0.5
    lib.raia_imgui_set_scroll_from_pos_y(local_y, center_y_ratio)
end

-- パラメータ・スタック（共有）

function ImGui.pushFont(font)
    lib.raia_imgui_push_font(font)
end

function ImGui.popFont()
    lib.raia_imgui_pop_font()
end

function ImGui.pushStyleColor(idx, col)
    lib.raia_imgui_push_style_color(idx, col)
end

function ImGui.pushStyleColor_2(idx, col_x, col_y, col_z, col_w)
    lib.raia_imgui_push_style_color_2(idx, col_x, col_y, col_z, col_w)
end

function ImGui.popStyleColor_3(count)
    count = count or 1
    lib.raia_imgui_pop_style_color_3(count)
end

function ImGui.pushStyleVar(idx, val)
    lib.raia_imgui_push_style_var(idx, val)
end

function ImGui.pushStyleVar_2(idx, val_x, val_y)
    lib.raia_imgui_push_style_var_2(idx, val_x, val_y)
end

function ImGui.popStyleVar_3(count)
    count = count or 1
    lib.raia_imgui_pop_style_var_3(count)
end

function ImGui.pushTabStop(tab_stop)
    lib.raia_imgui_push_tab_stop(tab_stop)
end

function ImGui.popTabStop()
    lib.raia_imgui_pop_tab_stop()
end

function ImGui.pushButtonRepeat(repeat_)
    lib.raia_imgui_push_button_repeat(repeat_)
end

function ImGui.popButtonRepeat()
    lib.raia_imgui_pop_button_repeat()
end

-- パラメータ・スタック（現在のウィンドウ）

function ImGui.pushItemWidth()
    lib.raia_imgui_push_item_width(item_width)
end

function ImGui.popItemWidth()
    lib.raia_imgui_pop_item_width()
end

function ImGui.setNextItemWidth()
    lib.raia_imgui_set_next_item_width(item_width)
end

function ImGui.calcItemWidth()
    return lib.raia_imgui_calc_item_width()
end

function ImGui.pushTextWrapPos()
    wrap_local_pos_x = wrap_local_pos_x or 0.0
    lib.raia_imgui_push_text_wrap_pos(wrap_local_pos_x)
end

function ImGui.popTextWrapPos()
    lib.raia_imgui_pop_text_wrap_pos()
end

-- スタイルの読み込みとアクセス

function ImGui.getFont()
    return lib.raia_imgui_get_font()
end

function ImGui.getFontSize()
    return lib.raia_imgui_get_font_size()
end

function ImGui.getFontTexUVWhitePixelX()
    return lib.raia_imgui_get_font_tex_uv_white_pixel_x()
end

function ImGui.getFontTexUVWhitePixelY()
    return lib.raia_imgui_get_font_tex_uv_white_pixel_y()
end

function ImGui.getColorU32(idx, alpha_mul)
    alpha_mul = alpha_mul or 1.0
    return lib.raia_imgui_get_color_u32(idx, alpha_mul)
end

function ImGui.getColorU32_2(col_x, col_y, col_z, col_w)
    return lib.raia_imgui_get_color_u32_2(col_x, col_y, col_z, col_w)
end

function ImGui.getColorU32_3(col)
    return lib.raia_imgui_get_color_u32_3(col)
end

function ImGui.getStyleColorVec4X(idx)
    return lib.raia_imgui_get_style_color_vec4_x(idx)
end

function ImGui.getStyleColorVec4Y(idx)
    return lib.raia_imgui_get_style_color_vec4_y(idx)
end

function ImGui.getStyleColorVec4Z(idx)
    return lib.raia_imgui_get_style_color_vec4_z(idx)
end

function ImGui.getStyleColorVec4W(idx)
    return lib.raia_imgui_get_style_color_vec4_w(idx)
end


-- カーソル / レイアウト

function ImGui.separator()
    return lib.raia_imgui_separator()
end

function ImGui.sameLine()
    lib.raia_imgui_same_line()
end

function ImGui.newLine()
    lib.raia_imgui_new_line()
end

function ImGui.spspacingacing()
    lib.raia_imgui_spacing()
end

function ImGui.dummy(size_x, size_y)
    lib.raia_imgui_dummy(size_x, size_y)
end

function ImGui.indent(indent_w)
    indent_w = indent_w or 0.0
    lib.raia_imgui_indent(indent_w)
end

function ImGui.unindent(indent_w)
    indent_w = indent_w or 0.0
    lib.raia_imgui_unindent(indent_w)
end

function ImGui.beginGroup()
    lib.raia_imgui_begin_group()
end

function ImGui.endGroup()
    lib.raia_imgui_end_group()
end

function ImGui.getCursorPosX()
    return lib.raia_imgui_get_cursor_pos_x()
end

function ImGui.getCursorPosY()
    return lib.raia_imgui_get_cursor_pos_y()
end

function ImGui.setCursorPos(local_pos_x, local_pos_y)
    lib.raia_imgui_set_cursor_pos(local_pos_x, local_pos_y)
end

function ImGui.setCursorPosX(local_x)
    lib.raia_imgui_set_cursor_pos_x(local_x)
end

function ImGui.setCursorPosY(local_y)
    lib.raia_imgui_set_cursor_pos_y(local_y)
end

function ImGui.getCursorStartPosX()
    return lib.raia_imgui_get_cursor_start_pos_x()
end

function ImGui.getCursorStartPosY()
    return lib.raia_imgui_get_cursor_start_pos_y()
end

function ImGui.getCursorScreenPosX()
    return lib.raia_imgui_get_cursor_screen_pos_x()
end

function ImGui.getCursorScreenPosY()
    return lib.raia_imgui_get_cursor_screen_pos_y()
end

function ImGui.setCursorScreenPos(pos_x, pos_y)
    lib.raia_imgui_set_cursor_screen_pos(pos_x, pos_y)
end

function ImGui.alignTextToFramePadding()
    lib.raia_imgui_align_text_to_frame_padding()
end

function ImGui.getTextLineHeight()
    return lib.raia_imgui_get_text_line_height()
end

function ImGui.getTextLineHeightWithSpacing()
    return lib.raia_imgui_get_text_line_height_with_spacing()
end

function ImGui.getFrameHeight()
    return lib.raia_imgui_get_frame_height()
end

function ImGui.getFrameHeightWithSpacing()
    return lib.raia_imgui_get_frame_height_with_spacing()
end

-- IDスタック / スコープ

function ImGui.pushID(str_id)
    lib.raia_imgui_push_id(str_id)
end

function ImGui.pushID_2(str_id_begin, str_id_end)
    lib.raia_imgui_push_id_2(str_id_begin, str_id_end)
end

function ImGui.pushID_3(ptr_id)
    lib.raia_imgui_push_id_3(ptr_id)
end

function ImGui.pushID_4(int_id)
    lib.raia_imgui_push_id_4(int_id)
end

function ImGui.popID()
    lib.raia_imgui_pop_id()
end

function ImGui.getID(str_id)
    return lib.raia_imgui_get_id(str_id)
end

function ImGui.getID_2(str_id_begin, str_id_end)
    return lib.raia_imgui_get_id_2(str_id_begin, str_id_end)
end

function ImGui.getID_3(ptr_id)
    return lib.raia_imgui_get_id_3(ptr_id)
end

-- ウィジェット: テキスト

function ImGui.textUnformatted(text, text_end)
    text_end = text_end or ffi.null
    lib.raia_imgui_text_unformatted(text, text_end)
end

function ImGui.text(fmt, ...)
    lib.raia_imgui_text(string.format(fmt, ...))
end

function ImGui.textColored(col_x, col_y, col_z, col_w, fmt, ...)
    libraia_imgui_text_colored(col_x, col_y, col_z, col_w, string.format(fmt, ...))
end

function ImGui.textDisabled(fmt, ...)
    lib.raia_imgui_text_disabled(string.format(fmt, ...))
end

function ImGui.textWrapped(fmt, ...)
    lib.raia_imgui_text_wrapped(string.format(fmt, ...))
end

function ImGui.labelText(label, fmt, ...)
    lib.raia_imgui_label_text(label, string.format(fmt, ...))
end

function ImGui.bulletText(fmt, ...)
    lib.raia_imgui_bullet_text(string.format(fmt, ...))
end

function ImGui.separatorText(label)
    lib.raia_imgui_separator_text(label)
end

-- ウィジェット: メイン

function ImGui.button(label, width, height)
    return lib.raia_imgui_button(label, width, height)
end

function ImGui.smallButton(label)
    return lib.raia_imgui_small_button(label)
end

function ImGui.invisibleButton(str_id, size_x, size_y, flags)
    flags = flags or 0
    return lib.raia_imgui_invisible_button(str_id, size_x, size_y, flags)
end

function ImGui.arrowButton(str_id, dir)
    return lib.raia_imgui_arrow_button(str_id, dir)
end

function ImGui.checkbox(label, v)
    return lib.raia_imgui_checkbox(label, v)
end

function ImGui.checkboxFlags(label, flags, flags_value)
    return lib.raia_imgui_checkbox_flags(label, flags, flags_value)
end

function ImGui.checkboxFlags_2(label, flags, flags_value)
    return lib.raia_imgui_checkbox_flags_2(label, flags, flags_value)
end

function ImGui.radioButton(label, active)
    return lib.raia_imgui_radio_button(label, active)
end

function ImGui.radioButton_2(label, v, v_button)
    return lib.raia_imgui_radio_button_2(label, v, v_button)
end

function ImGui.progressBar(fraction, size_arg_x, size_arg_y, overlay)
    size_arg_x = size_arg_x or -lib.raia_get_flt_min()
    size_arg_y = size_arg_y or 0
    overlay = overlay or ffi.null
    lib.raia_imgui_progress_bar(fraction, size_arg_x, size_arg_y, overlay)
end

function ImGui.bullet()
    lib.raia_imgui_bullet()
end

-- ウィジェット: 画像

function ImGui.image(texture_id, width, height)
    lib.raia_imgui_image(texture_id, width, height)
end

function ImGui.imageButton(str_id, user_texture_id, size_x, size_y,
    uv0_x, uv0_y, uv1_x, uv1_y,
    bg_col_x, bg_col_y, bg_col_z, bg_col_w,
    tint_col_x, tint_col_y, tint_col_z, tint_col_w)
    uv0_x = uv0_x or 0
    uv0_y = uv0_y or 0
    uv1_x = uv1_x or 1
    uv1_y = uv1_y or 1
    bg_col_x = bg_col_x or 0
    bg_col_y = bg_col_y or 0
    bg_col_z = bg_col_z or 0
    bg_col_w = bg_col_w or 0
    tint_col_x = tint_col_x or 1
    tint_col_y = tint_col_y or 1
    tint_col_z = tint_col_z or 1
    tint_col_w = tint_col_w or 1
    return lib.raia_imgui_image_button(str_id, user_texture_id, size_x, size_y,
        uv0_x, uv0_y, uv1_x, uv1_y,
        bg_col_x, bg_col_y, bg_col_z, bg_col_w,
        tint_col_x, tint_col_y, tint_col_z, tint_col_w)
end

-- ウィジェット: コンボボックス（ドロップダウン）

function ImGui.beginCombo(label, preview_value, flags)
    flags = flags or 0
    return lib.raia_imgui_begin_combo(label, preview_value, flags)
end

function ImGui.endCombo()
    lib.raia_imgui_end_combo()
end

function ImGui.combo(label, current_item, items, items_count, popup_max_height_in_items)
    popup_max_height_in_items = popup_max_height_in_items or -1
    return lib.raia_imgui_combo(label, current_item, items, items_count, popup_max_height_in_items)
end

function ImGui.combo_2(label, current_item, items_separated_by_zeros, popup_max_height_in_items)
    popup_max_height_in_items = popup_max_height_in_items or -1
    return lib.raia_imgui_combo_2(label, current_item, items_separated_by_zeros, popup_max_height_in_items)
end

function ImGui.combo_3(label, current_item, items_getter, data, items_count, popup_max_height_in_items)
    popup_max_height_in_items = popup_max_height_in_items or -1
    return lib.raia_imgui_combo_3(label, current_item, items_getter, data, items_count, popup_max_height_in_items)
end

-- ウィジェット: ドラッグスライダー

function ImGui.dragFloat(label, v, v_speed, v_min, v_max, format, flags)
    v_speed = v_speed or 1.0
    v_min = v_min or 0.0
    v_max = v_max or 0.0
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_drag_float(label, v, v_speed, v_min, v_max, format, flags)
end

function ImGui.dragFloat2(label, v, v_speed, v_min, v_max, format, flags)
    v_speed = v_speed or 1.0
    v_min = v_min or 0.0
    v_max = v_max or 0.0
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_drag_float2(label, v, v_speed, v_min, v_max, format, flags)
end

function ImGui.dragFloat3(label, v, v_speed, v_min, v_max, format, flags)
    v_speed = v_speed or 1.0
    v_min = v_min or 0.0
    v_max = v_max or 0.0
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_drag_float3(label, v, v_speed, v_min, v_max, format, flags)
end

function ImGui.dragFloat4(label, v, v_speed, v_min, v_max, format, flags)
    v_speed = v_speed or 1.0
    v_min = v_min or 0.0
    v_max = v_max or 0.0
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_drag_float4(label, v, v_speed, v_min, v_max, format, flags)
end

function ImGui.dragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, flags)
    v_speed = v_speed or 1.0
    v_min = v_min or 0.0
    v_max = v_max or 0.0
    format = format or "%.3f"
    format_max = format_max or ffi.null
    flags = flags or 0
    return lib.raia_imgui_drag_float_range2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, flags)
end

function ImGui.dragInt(label, v, v_speed, v_min, v_max, format, flags)
    v_speed = v_speed or 1.0
    v_min = v_min or 0
    v_max = v_max or 0
    format = format or "%d"
    flags = flags or 0
    return lib.raia_imgui_drag_int(label, v, v_speed, v_min, v_max, format, flags) 
end

function ImGui.dragInt2(label, v, v_speed, v_min, v_max, format, flags)
    v_speed = v_speed or 1.0
    v_min = v_min or 0
    v_max = v_max or 0
    format = format or "%d"
    flags = flags or 0
    return lib.raia_imgui_drag_int2(label, v, v_speed, v_min, v_max, format, flags)
end

function ImGui.dragInt3(label, v, v_speed , v_min, v_max, format, flags)
    v_speed = v_speed or 1.0
    v_min = v_min or 0
    v_max = v_max or 0
    format = format or "%d"
    flags = flags or 0
    return lib.raia_imgui_drag_int3(label, v, v_speed , v_min, v_max, format, flags)
end

function ImGui.dragInt4(label, v, v_speed, v_min, v_max, format, flags)
    v_speed = v_speed or 1.0
    v_min = v_min or 0
    v_max = v_max or 0
    format = format or "%d"
    flags = flags or 0
    return lib.raia_imgui_drag_int4(label, v, v_speed, v_min, v_max, format, flags)
end

function ImGui.dragIntRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, flags)
    v_speed = v_speed or 1.0
    v_min = v_min or 0
    v_max = v_max or 0
    format = format or "%d"
    format_max = format_max or ffi.null
    flags = flags or 0
    return lib.raia_imgui_drag_int_range2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, flags)
end

function ImGui.dragScalar(label, data_type, p_data, v_speed , p_min, p_max, format, flags)
    v_speed = v_speed or 1.0
    p_min = p_min or ffi.null
    p_max = p_max or ffi.null
    format = format or ffi.null
    flags = flags or 0
    return lib.raia_imgui_drag_scalar(label, data_type, p_data, v_speed , p_min, p_max, format, flags)
end

function ImGui.dragScalarN(label, data_type, p_data, components, v_speed, p_min, p_max, format, flags)
    v_speed = v_speed or 1.0
    p_min = p_min or ffi.null
    p_max = p_max or ffi.null
    format = format or ffi.null
    flags = flags or 0
    return lib.raia_imgui_drag_scalar_n(label, data_type, p_data, components, v_speed, p_min, p_max, format, flags)
end

-- ウィジェット: レギュラー・スライダー
function ImGui.sliderFloat(label, v, v_min, v_max, format, flags)
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_slider_float(label, v, v_min, v_max)
end

function ImGui.sliderFloat2(label, v, v_min, v_max, format, flags)
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_slider_float2(label, v, v_min, v_max, format, flags)
end

function ImGui.sliderFloat3(label, v, v_min, v_max, format, flags)
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_slider_float3(label, v, v_min, v_max, format, flags)
end

function ImGui.sliderFloat4(label, v, v_min, v_max, format, flags)
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_slider_float4(label, v, v_min, v_max, format, flags)
end

function ImGui.sliderAngle(label, v_rad, v_degrees_min, v_degrees_max, format, flags)
    v_degrees_min = v_degrees_min or -360.0
    v_degrees_max = v_degrees_max or 360.0
    format = format or "%.0f deg"
    flags = flags or 0
    return lib.raia_imgui_slider_angle(label, v_rad, v_degrees_min, v_degrees_max, format, flags)
end

function ImGui.sliderInt(label, v, v_min, v_max, format, flags)
    format = format or "%d"
    flags = flags or 0
    return lib.raia_imgui_slider_int(label, v, v_min, v_max, format, flags)
end

function ImGui.sliderInt2(label, v, v_min, v_max, format, flags)
    format = format or "%d"
    flags = flags or 0
    return lib.raia_imgui_slider_int2(label, v, v_min, v_max, format, flags)
end

function ImGui.sliderInt3(label, v, v_min, v_max, format, flags)
    format = format or "%d"
    flags = flags or 0
    return lib.raia_imgui_slider_int3(label, v, v_min, v_max, format, flags)
end

function ImGui.sliderInt4(label, v, v_min, v_max, format, flags)
    format = format or "%d"
    flags = flags or 0
    return lib.raia_imgui_slider_int4(label, v, v_min, v_max, format, flags)
end

function ImGui.sliderScalar(label, data_type, p_data, p_min, p_max, format, flags)
    format = format or ffi.null
    flags = flags or 0
    return lib.raia_imgui_slider_scalar(label, data_type, p_data, p_min, p_max, format, flags)
end

function ImGui.sliderScalarN(label, data_type, p_data, components, p_min, p_max, format, flags)
    format = format or ffi.null
    flags = flags or 0
    return lib.raia_imgui_slider_scalar_n(label, data_type, p_data, components, p_min, p_max, format, flags)
end

function ImGui.vSliderFloat(label, size_x, size_y, v, v_min, v_max, format, flags)
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_v_slider_float(label, size_x, size_y, v, v_min, v_max, format, flags)
end

function ImGui.vSliderInt(label, size_x, size_y, v, v_min, v_max, format, flags)
    format = format or "%d"
    flags = flags or 0
    return lib.raia_imgui_v_slider_int(label, size_x, size_y, v, v_min, v_max, format, flags)
end

function ImGui.vSliderScalar(label, size_x, size_y, data_type, p_data, p_min, p_max, format, flags)
    format = format or ffi.null
    flags = flags or 0
    return lib.raia_imgui_v_slider_scalar(label, size_x, size_y, data_type, p_data, p_min, p_max, format, flags)
end

-- ウィジェット: キーボード入力

function ImGui.inputText(label, buf, buf_size, flags, callback, user_data)
    flags = flags or 0
    callback = callback or ffi.null
    user_data = user_data or ffi.null
    return lib.raia_imgui_input_text(label, buf, buf_size, flags, callback, user_data)
end

function ImGui.inputTextMultiline(label, buf, buf_size, size_x, size_y, flags, callback, user_data)
    size_x = size_x or 0
    size_y = size_y or 0
    flags = flags or 0
    callback = callback or ffi.null
    user_data = user_data or ffi.null
    return lib.raia_imgui_input_text_multiline(label, buf, buf_size, size_x, size_y, flags, callback, user_data)
end

function ImGui.inputTextWithHint(label, hint, buf, buf_size, flags, callback, user_data)
    flags = flags or 0
    callback = callback or ffi.null
    user_data = user_data or ffi.null
    return lib.raia_imgui_input_text_with_hint(label, hint, buf, buf_size, flags, callback, user_data)
end

function ImGui.inputFloat(label, v, step, step_fast, format, flags)
    step = step or 0.0
    step_fast = step_fast or 0.0
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_input_float(label, v, step, step_fast, format, flags)
end

function ImGui.inputFloat2(label, v, format, flags)
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_input_float2(label, v, format, flags)
end

function ImGui.inputFloat3(label, v, format, flags)
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_input_float3(label, v, format, flags)
end

function ImGui.inputFloat4(label, v, format, flags)
    format = format or "%.3f"
    flags = flags or 0
    return lib.raia_imgui_input_float4(label, v,  format, flags)
end

function ImGui.inputInt(label, v, step, step_fast, flags)
    step = step or 1
    step_fast = step_fast or 100
    flags = flags or 0
    return lib.raia_imgui_input_int(label, v, step, step_fast, flags)
end

function ImGui.inputInt2(label, v, flags)
    flags = flags or 0
    return lib.raia_imgui_input_int2(label, v, flags)
end

function ImGui.inputInt3(label, v, flags)
    flags = flags or 0
    return lib.raia_imgui_input_int3(label, v, flags)
end

function ImGui.inputInt4(label, v, flags)
    flags = flags or 0
    return lib.raia_imgui_input_int4(label, v, flags)
end

function ImGui.inputDouble(label, v, step, step_fast, format, flags)
    step = step or 0.0
    step_fast = step_fast or 0.0
    format = format or "%.6f"
    flags = flags or 0
    return lib.raia_imgui_input_double(label, v, step, step_fast, format, flags)
end

function ImGui.inputScalar(label, data_type, p_data, p_step, p_step_fast, format, flags)
    p_step = p_step or ffi.null
    p_step_fast = p_step_fast or ffi.null
    format = format or ffi.null
    flags = flags or 0
    return lib.raia_imgui_input_scalar(label, data_type, p_data, p_step, p_step_fast, format, flags)
end

function ImGui.inputScalarN(label, data_type, p_data, components, p_step, p_step_fast, format, flags)
    p_step = p_step or ffi.null
    p_step_fast = p_step_fast or ffi.null
    format = format or ffi.null
    flags = flags or 0
    return lib.raia_imgui_input_scalar_n(label, data_type, p_data, components, p_step, p_step_fast, format, flags)
end

-- ウィジェット: カラーエディター/ピッカー

function ImGui.colorEdit3(label, col, flags)
    flags = flags or 0
    return lib.raia_imgui_color_edit3(label, col, flags)
end

function ImGui.colorEdit4(label, col, flags)
    flags = flags or 0
    return lib.raia_imgui_color_edit4(label, col, flags)
end

function ImGui.colorPicker3(label, col, flags)
    flags = flags or 0
    return lib.raia_imgui_color_picker3(label, col, flags)
end

function ImGui.colorPicker4(label, col, flags, ref_col)
    flags = flags or 0
    ref_col = ref_col or ffi.null
    return lib.raia_imgui_color_picker4(label, col, flags, ref_col)
end

function ImGui.colorButton(desc_id, col_x, col_y, col_z, col_w, flags, size_x, size_y)
    flags = flags or 0
    size_x = size_x or 0
    size_y = size_y or 0
    return lib.raia_imgui_color_button(desc_id, col_x, col_y, col_z, col_w, flags, size_x, size_y)
end

function ImGui.setColorEditOptions(flags)
    lib.raia_imgui_set_color_edit_options(flags)
end

-- ウィジェット: ツリー

function ImGui.treeNode(label)
    return lib.raia_imgui_tree_node(label)
end

function ImGui.treeNode_2(str_id, fmt, ...)
    return lib.raia_imgui_tree_node_2(str_id, string.format(fmt, ...))
end

function ImGui.treeNode_3(ptr_id, fmt, ...)
    return lib.raia_imgui_tree_node_3(ptr_id, string.format(fmt, ...))
end

function ImGui.treeNodeEx(label, flags)
    flags = flags or 0
    return lib.raia_imgui_tree_node_ex(label, flags)
end

function ImGui.treeNodeEx_2(str_id, flags, fmt, ...)
    return lib.raia_imgui_tree_node_ex_2(str_id, flags, string.format(fmt, ...))
end

function ImGui.treeNodeEx_3(ptr_id, flags, fmt, ...)
    return lib.raia_imgui_tree_node_ex_3(ptr_id, flags, string.format(fmt, ...))
end

function ImGui.treePush(str_id)
    lib.raia_imgui_tree_push(str_id)
end

function ImGui.treePush_2(ptr_id)
    lib.raia_imgui_tree_push_2(ptr_id)
end

function ImGui.treePop()
    lib.raia_imgui_tree_pop()
end

function ImGui.getTreeNodeToLabelSpacing()
    return lib.raia_imgui_get_tree_node_to_label_spacing()
end

function ImGui.collapsingHeader(label, flags)
    flags = flags or 0
    return lib.raia_imgui_collapsing_header(label, flags)
end

function ImGui.collapsingHeader_2(label, p_visible, flags)
    flags = flags or 0
    return lib.raia_imgui_collapsing_header_2(label, p_visible, flag)
end

function ImGui.setNextItemOpen(is_open, cond)
    cond = cond or 0
    lib.raia_imgui_set_next_item_open(is_open, cond)
end


-- ウィジェット: セレクタブル

function ImGui.selectable(label, selected, flags, size_x, size_y)
    selected = selected or false
    flags = flags or 0
    size_x = size_x or 0.0
    size_y = size_y or 0.0
    return lib.raia_imgui_selectable(label, selected, flags, size_x, size_y)
end

function ImGui.selectable(label, p_selected, flags, size_x, size_y)
    flags = flags or 0
    size_x = size_x or 0.0
    size_y = size_y or 0.0
    return lib.raia_imgui_selectable_2(label, p_selected, flags, size_x, size_y)
end

-- ウィジェット: リストボックス
function ImGui.beginListBox(label, size_x, size_y)
    size_x = size_x or 0.0
    size_y = size_y or 0.0
    return lib.raia_imgui_begin_list_box(label, size_x, size_y)
end

function ImGui.endListBox()
    lib.raia_imgui_end_list_box()
end

function ImGui.listBox(label, current_item, items, items_count, height_in_items)
    height_in_items = height_in_items or -1
    return lib.raia_imgui_list_box(label, current_item, items, items_count, height_in_items)
end

function ImGui.listBox_2(label, current_item, items_getter, data, items_count, height_in_items)
    height_in_items = height_in_items or -1
    return lib.raia_imgui_list_box_2(label, current_item, items_getter, data, items_count, height_in_items)
end

-- ウィジェット: データプロット

function ImGui.plotLines(label, values, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size_x, graph_size_y, stride)
    values_offset = values_offset or 0
    overlay_text = overlay_text or ffi.null
    scale_min = scale_min or lib.raia_get_flt_max()
    scale_max = scale_max or lib.raia_get_flt_max()
    graph_size_x = graph_size_x or 0
    graph_size_y = graph_size_y or 0
    stride = stride or ffi.sizeof("float")
    lib.raia_imgui_plot_lines(label, values, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size_x, graph_size_y, stride)
end

function ImGui.plotLines_2(label, values_getter, data, values_count, values_offset, overlay_text, scale_min , scale_max, graph_size_x, graph_size_y)
    values_offset = values_offset or 0
    overlay_text = overlay_text or ffi.null
    scale_min = scale_min or lib.raia_get_flt_max()
    scale_max = scale_max or lib.raia_get_flt_max()
    graph_size_x = graph_size_x or 0
    graph_size_y = graph_size_y or 0
    lib.raia_imgui_plot_lines_2(label, values_getter, data, values_count, values_offset, overlay_text, scale_min , scale_max, graph_size_x, graph_size_y)
end

function ImGui.plotHistogram(label, values, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size_x, graph_size_y, stride)
    values_offset = values_offset or 0
    overlay_text = overlay_text or ffi.null
    scale_min = scale_min or lib.raia_get_flt_max()
    scale_max = scale_max or lib.raia_get_flt_max()
    graph_size_x = graph_size_x or 0
    graph_size_y = graph_size_y or 0
    stride = stride or ffi.sizeof("float")
    lib.raia_imgui_plot_histogram(label, values, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size_x, graph_size_y, stride)
end

function ImGui.plotHistogram_2(label, values_getter, data, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size_x, graph_size_y)
    values_offset = values_offset or 0
    overlay_text = overlay_text or ffi.null
    scale_min = scale_min or lib.raia_get_flt_max()
    scale_max = scale_max or lib.raia_get_flt_max()
    graph_size_x = graph_size_x or 0
    graph_size_y = graph_size_y or 0
    lib.raia_imgui_plot_histogram_2(label, values_getter, data, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size_x, graph_size_y)
end

-- ウィジェット: Value() ヘルパー

function ImGui.value(prefix, b)
    lib.raia_imgui_value(prefix, b)
end

function ImGui.value_2(prefix, v)
    lib.raia_imgui_value_2(prefix, v)
end

function ImGui.value_3(prefix, v)
    lib.raia_imgui_value_3(prefix, v)
end

function ImGui.value_4(prefix, v, float_format)
    float_format = float_format or ffi.null
    lib.raia_imgui_value_4(prefix, v, float_format)
end

-- ウィジェット: メニュー

function ImGui.beginMenuBar()
    return lib.raia_imgui_begin_menu_bar()
end

function ImGui.endMenuBar()
    lib.raia_imgui_end_menu_bar()
end

function ImGui.beginMainMenuBar()
    return lib.raia_imgui_begin_main_menu_bar()
end

function ImGui.endMainMenuBar()
    lib.raia_imgui_end_main_menu_bar()
end

function ImGui.beginMenu(label, enabled)
    enabled = enabled or true
    return lib.raia_imgui_begin_menu(label, enabled)
end

function ImGui.endMenu()
    lib.raia_imgui_end_menu()
end

function ImGui.menuItem(label, shortcut, selected, enabled)
    shortcut = shortcut or ffi.null
    selected = selected or false
    enabled = enabled or true
    return lib.raia_imgui_menu_item(label, shortcut, selected, enabled)
end

function ImGui.menuItem_2(label, shortcut, p_selected, enabled)
    enabled = enabled or true
    return lib.raia_imgui_menu_item_2(label, shortcut, p_selected, enabled)
end

-- ツールチップ

function ImGui.beginTooltip()
    return lib.raia_imgui_begin_tooltip()
end

function ImGui.endTooltip()
    lib.raia_imgui_end_tooltip()
end

function ImGui.setTooltip(fmt, ...)
    lib.raia_imgui_set_tooltip(string.format(fmt, ...))
end

function ImGui.beginItemTooltip()
    return lib.raia_imgui_begin_item_tooltip()
end

function ImGui.setItemTooltip(fmt, ...)
    lib.raia_imgui_set_item_tooltip(string.format(fmt, ...))
end

-- ポップアップ・モーダル

function ImGui.beginPopup(str_id, flags)
    flags = flags or 0
    return lib.raia_imgui_begin_popup(str_id, flags)
end

function ImGui.beginPopupModal(name, p_open, flags)
    p_open = p_open or ffi.null
    flags = flags or 0
    return lib.raia_imgui_begin_popup_modal(name, p_open, flags)
end

function ImGui.endPopup()
    lib.raia_imgui_end_popup()
end

function ImGui.openPopup(str_id, popup_flags)
    popup_flags = popup_flags or 0
    lib.raia_imgui_open_popup(str_id, popup_flags)
end

function ImGui.openPopup_2(id, popup_flags)
    popup_flags = popup_flags or 0
    lib.raia_imgui_open_popup_2(id, popup_flags)
end

function ImGui.openPopupOnItemClick(str_id, popup_flags)
    str_id = str_id or ffi.null
    popup_flags = popup_flags or 1
    lib.raia_imgui_open_popup_on_item_click(str_id, popup_flags)
end

function ImGui.closeCurrentPopup()
    lib.raia_imgui_close_current_popup()
end

function ImGui.beginPopupContextItem(str_id, popup_flags)
    str_id = str_id or ffi.null
    popup_flags = popup_flags or 1
    return lib.raia_imgui_begin_popup_context_item(str_id, popup_flags)
end

function ImGui.beginPopupContextWindow(str_id, popup_flags)
    str_id = str_id or ffi.null
    popup_flags = popup_flags or 1
    return lib.raia_imgui_begin_popup_context_window(str_id, popup_flags)
end

function ImGui.beginPopupContextVoid(str_id, popup_flags)
    str_id = str_id or ffi.null
    popup_flags = popup_flags or 1
    return lib.raia_imgui_begin_popup_context_void(str_id, popup_flags)
end

function ImGui.isPopupOpen(str_id, flags)
    flags = flags or 0
    return lib.raia_imgui_is_popup_open(str_id, flags)
end

-- テーブル

function ImGui.beginTable(str_id, column, flags, outer_size_x, outer_size_y, inner_width)
    flags = flags or 0
    outer_size_x = outer_size_x or 0
    outer_size_y = outer_size_y or 0
    inner_width = inner_width or 0.0
    return lib.raia_imgui_begin_table(str_id, column, flags, outer_size_x, outer_size_y, inner_width)
end

function ImGui.endTable()
    lib.raia_imgui_end_table()
end

function ImGui.tableNextRow(row_flags, min_row_height)
    row_flags = row_flags or 0
    min_row_height = min_row_height or 0.0
    lib.raia_imgui_table_next_row(row_flags, min_row_height)
end

function ImGui.tableNextColumn()
    return lib.raia_imgui_table_next_column()
end

function ImGui.tableSetColumnIndex(column_n)
    return lib.raia_imgui_table_set_column_index(column_n)
end

function ImGui.tableSetupColumn(label, flags, init_width_or_weight, user_id)
    flags = flags or 0
    init_width_or_weight = init_width_or_weight or 0.0
    user_id = user_id or 0
    lib.raia_imgui_table_setup_column(label, flags, init_width_or_weight, user_id)
end

function ImGui.tableSetupScrollFreeze(cols, rows)
    lib.raia_imgui_table_setup_scroll_freeze(cols, rows)
end

function ImGui.tableHeadersRow()
    lib.raia_imgui_table_headers_row()
end

function ImGui.tableHeader(label)
    lib.raia_imgui_table_header(label)
end

function ImGui.tableGetSortSpecs()
    return lib.raia_imgui_table_get_sort_specs()
end

function ImGui.tableGetColumnCount()
    return lib.raia_imgui_table_get_column_count()
end

function ImGui.tableGetColumnIndex()
    return lib.raia_imgui_table_get_column_index()
end

function ImGui.tableGetRowIndex()
    return lib.raia_imgui_table_get_row_index()
end

function ImGui.tableGetColumnName(column_n)
    column_n = column_n or -1
    return lib.raia_imgui_table_get_column_name(column_n)
end

function ImGui.tableGetColumnFlags(column_n)
    column_n = column_n or -1
    return lib.raia_imgui_table_get_column_flags(column_n)
end

function ImGui.tableSetColumnEnabled(column_n, v)
    lib.raia_imgui_table_set_column_enabled(column_n, v)
end

function ImGui.tableSetBgColor(target, color, column_n)
    column_n = column_n or -1
    lib.raia_imgui_table_set_bg_color(target, color, column_n)
end

function ImGui.columns(count, id, border)
    count = count or 1
    id = id or ffi.null
    border = border or true
    lib.raia_imgui_columns(count, id, border) -- ここからレガシーなテーブルAPI
end

function ImGui.nextColumn()
    lib.raia_imgui_next_column()
end

function ImGui.getColumnIndex()
    return lib.raia_imgui_get_column_index()
end

function ImGui.getColumnWidth(column_index)
    column_index = column_index or -1
    return lib.raia_imgui_get_column_width(column_index)
end

function ImGui.setColumnWidth(column_index, width)
    lib.raia_imgui_set_column_width(column_index, width)
end

function ImGui.getColumnOffset(column_index)
    column_index = column_index or -1
    return lib.raia_imgui_get_column_offset(column_index)
end

function ImGui.setColumnOffset(column_index, offset_x)
    lib.raia_imgui_set_column_offset(column_index, offset_x)
end

function ImGui.getColumnsCount()
    return lib.raia_imgui_get_columns_count()
end

-- タブバー、タブ

function ImGui.beginTabBar(str_id, flags)
    flags = flags or 0
    return lib.raia_imgui_begin_tab_bar(str_id, flags)
end

function ImGui.endTabBar()
    lib.raia_imgui_end_tab_bar()
end

function ImGui.beginTabItem(label, p_open, flags)
    p_open = p_open or ffi.null
    flags = flags or 0
    return lib.raia_imgui_begin_tab_item(label, p_open, flags)
end

function ImGui.endTabItem()
    lib.raia_imgui_end_tab_item()
end

function ImGui.tabItemButton(label, flags)
    flags = flags or 0
    return lib.raia_imgui_tab_item_button(label, flags)
end

function ImGui.setTabItemClosed(tab_or_docked_window_label)
    lib.raia_imgui_set_tab_item_closed(tab_or_docked_window_label)
end

-- ロギング/キャプチャ

function ImGui.logToTTY(auto_open_depth)
    auto_open_depth = auto_open_depth or -1
    lib.raia_imgui_log_to_tty(auto_open_depth)
end

function ImGui.logToFile(auto_open_depth, filename)
    auto_open_depth = auto_open_depth or -1
    filename = filename or ffi.null
    lib.raia_imgui_log_to_file(auto_open_depth, filename)
end

function ImGui.logToClipboard(auto_open_depth)
    auto_open_depth = auto_open_depth or -1
    lib.raia_imgui_log_to_clipboard(auto_open_depth)
end

function ImGui.logFinish()
    lib.raia_imgui_log_finish()
end

function ImGui.logButtons()
    lib.raia_imgui_log_buttons()
end

function ImGui.logText(fmt, ...)
    lib.raia_imgui_log_text(string.format(fmt, ...))
end


-- 無効化 [BETA API]

function beginDisabled(disabled)
    disabled = disabled or true
    lib.raia_imgui_begin_disabled(disabled)
end

function endDisabled()
    lib.raia_imgui_end_disabled()
end

-- クリッピング

function ImGui.pushClipRect(clip_rect_min_x, clip_rect_min_y, clip_rect_max_x, clip_rect_max_y, intersect_with_current_clip_rect)
    lib.raia_imgui_push_clip_rect(clip_rect_min_x, clip_rect_min_y, clip_rect_max_x, clip_rect_max_y, intersect_with_current_clip_rect)
end

function ImGui.popClipRect()
    lib.raia_imgui_pop_clip_rect()
end

-- フォーカス, アクティブ化

function ImGui.setItemDefaultFocus()
    lib.raia_imgui_set_item_default_focus()
end

function ImGui.setKeyboardFocusHere(offset)
    offset = offset or 0
    lib.raia_imgui_set_keyboard_focus_here(offset)
end

-- オーバーラッピング・モード

function ImGui.setNextItemAllowOverlap()
    lib.raia_imgui_set_next_item_allow_overlap()
end

-- アイテム/ウィジェット ユーティリティとクエリ関数

function ImGui.isItemHovered(flags)
    flags = flags or 0
    return lib.raia_imgui_is_item_hovered(flags)
end

function ImGui.isItemActive()
    return lib.raia_imgui_is_item_active()
end

function ImGui.isItemFocused()
    return lib.raia_imgui_is_item_focused()
end

function ImGui.isItemClicked(mouse_button)
    mouse_button = mouse_button or 0
    return lib.raia_imgui_is_item_clicked(mouse_button)
end

function ImGui.isItemVisible()
    return lib.raia_imgui_is_item_visible()
end

function ImGui.isItemEdited()
    return lib.raia_imgui_is_item_edited()
end

function ImGui.isItemActivated()
    return lib.raia_imgui_is_item_activated()
end

function ImGui.isItemDeactivated()
    return lib.raia_imgui_is_item_deactivated()
end

function ImGui.isItemDeactivatedAfterEdit()
    return lib.raia_imgui_is_item_deactivated_after_edit()
end

function ImGui.isItemToggledOpen()
    return lib.raia_imgui_is_item_toggled_open()
end

function ImGui.isAnyItemHovered()
    return lib.raia_imgui_is_any_item_hovered()
end

function ImGui.isAnyItemActive()
    return lib.raia_imgui_is_any_item_active()
end

function ImGui.isAnyItemFocused()
    return lib.raia_imgui_is_any_item_focused()
end

function ImGui.getItemID()
    return lib.raia_imgui_get_item_id()
end

function ImGui.getItemRectMinX()
    return lib.raia_imgui_get_item_rect_min_x()
end

function ImGui.getItemRectMinY()
    return lib.raia_imgui_get_item_rect_min_y()
end

function ImGui.getItemRectMaxX()
    return lib.raia_imgui_get_item_rect_max_x()
end

function ImGui.getItemRectMaxY()
    return lib.raia_imgui_get_item_rect_max_y()
end

function ImGui.getItemRectSizeX()
    return lib.raia_imgui_get_item_rect_size_x()
end

function ImGui.getItemRectSizeY()
    return lib.raia_imgui_get_item_rect_size_y()
end

-- ビューポート

function ImGui.getMainViewport()
    return lib.raia_imgui_get_main_viewport()
end

-- 背景／前景ドローリスト

function ImGui.getBackgroundDrawList()
    return lib.raia_imgui_get_background_draw_list()
end

function ImGui.getForegroundDrawList()
    return lib.raia_imgui_get_foreground_draw_list()
end

-- その他ユーティリティ

function ImGui.isRectVisible(size_x, size_y)
    return lib.raia_imgui_is_rect_visible(size_x, size_y)
end

function ImGui.isRectVisible_2(rect_min_x, rect_min_y, rect_max_x, rect_max_y)
    return lib.raia_imgui_is_rect_visible_2(rect_min_x, rect_min_y, rect_max_x, rect_max_y)
end

function ImGui.getTime()
    return lib.raia_imgui_get_time()
end

function ImGui.getFrameCount()
    return lib.raia_imgui_get_frame_count()
end

function ImGui.get_draw_list_shared_data()
    return lib.raia_imgui_get_draw_list_shared_data()
end

function ImGui.get_style_color_name(idx)
    return lib.raia_imgui_get_style_color_name(idx)
end

function ImGui.set_state_storage(storage)
    lib.raia_imgui_set_state_storage(storage)
end

function ImGui.get_state_storage()
    return lib.raia_imgui_get_state_storage()
end

function ImGui.begin_child_frame(id, size_x, size_y, flags)
    flags = flags or 0
    return lib.raia_imgui_begin_child_frame(id, size_x, size_y, flags)
end

function ImGui.end_child_frame()
    lib.raia_imgui_end_child_frame()
end

-- テキスト・ユーティリティ

function ImGui.calcTextSizeX(text, text_end, hide_text_after_double_hash, wrap_width)
    text_end = text_end or ffi.null
    hide_text_after_double_hash = hide_text_after_double_hash or false
    wrap_width = wrap_width or -1.0
    return lib.raia_imgui_calc_text_size_x(text, text_end, hide_text_after_double_hash, wrap_width)
end

function ImGui.calcTextSizeY(text, text_end, hide_text_after_double_hash, wrap_width)
    text_end = text_end or ffi.null
    hide_text_after_double_hash = hide_text_after_double_hash or false
    wrap_width = wrap_width or -1.0
    return lib.raia_imgui_calc_text_size_y(text, text_end, hide_text_after_double_hash, wrap_width)
end

-- カラーユーティリティ

function ImGui.colorConvertU32ToFloat4X(in_)
    return lib.raia_imgui_color_convert_u32_to_float4_x(in_)
end

function ImGui.colorConvertU32ToFloat4Y(in_)
    return lib.raia_imgui_color_convert_u32_to_float4_y(in_)
end

function ImGui.colorConvertU32ToFloat4Z(in_)
    return lib.raia_imgui_color_convert_u32_to_float4_z(in_)
end

function ImGui.colorConvertU32ToFloat4W(in_)
    return lib.raia_imgui_color_convert_u32_to_float4_w(in_)
end

function ImGui.colorConvertFloat4ToU32(in_x, in_y, in_z, in_w)
    return lib.raia_imgui_color_convert_float4_to_u32(in_x, in_y, in_z, in_w)
end

function ImGui.colorConvertRgbToHsv(r, g, b, out_h, out_s, out_v)
    lib.raia_imgui_color_convert_rgb_to_hsv(r, g, b, out_h, out_s, out_v)
end

function ImGui.colorConvertHsvToRgb(h, s, v, out_r, out_g, out_b)
    lib.raia_imgui_color_convert_hsv_to_rgb(h, s, v, out_r, out_g, out_b)
end

-- 入力ユーティリティ: キーボード/マウス/ゲームパッド

function ImGui.isKeyDown(key)
    return lib.raia_imgui_is_key_down(key)
end

function ImGui.is_key_pressed(key, repeat_)
    repeat_ = repeat_ or true
    return lib.raia_imgui_is_key_pressed(key, repeat_)
end

function ImGui.isKeyReleased(key)
    return lib.raia_imgui_is_key_released(key)
end

function ImGui.getKeyPressedAmount(key, repeat_delay, rate)
    return lib.raia_imgui_get_key_pressed_amount(key, repeat_delay, rate)
end

function ImGui.getKeyName(key)
    return lib.raia_imgui_get_key_name(key)
end

function ImGui.setNextFrameWantCaptureKeyboard(want_capture_keyboard)
    lib.raia_imgui_set_next_frame_want_capture_keyboard(want_capture_keyboard)
end

-- 入力ユーティリティ： マウス専用

function ImGui.isMouseDown(button)
    return lib.raia_imgui_is_mouse_down(button)
end

function ImGui.isMouseClicked(button, repeat_)
    repeat_ = repeat_ or false
    return lib.raia_imgui_is_mouse_clicked(button, repeat_)
end

function ImGui.isMouseReleased(button)
    return lib.raia_imgui_is_mouse_released(button)
end

function ImGui.isMouseDoubleClicked(button)
    return lib.raia_imgui_is_mouse_double_clicked(button)
end

function ImGui.getMouseClickedCount(button)
    return lib.raia_imgui_get_mouse_clicked_count(button)
end

function ImGui.isMouseHoveringRect(r_min_x, r_min_y, r_max_x, r_max_y, clip)
    clip = clip or true
    return lib.raia_imgui_is_mouse_hovering_rect(r_min_x, r_min_y, r_max_x, r_max_y, clip)
end

function ImGui.isMousePosValid(mouse_pos)
    mouse_pos = mouse_pos or ffi.null
    return lib.raia_imgui_is_mouse_pos_valid(mouse_pos)
end

function ImGui.isAnyMouseDown()
    return lib.raia_imgui_is_any_mouse_down()
end

function ImGui.getMousePosX()
    return lib.raia_imgui_get_mouse_pos_x()
end

function ImGui.getMousePosY()
    return lib.raia_imgui_get_mouse_pos_y()
end

function ImGui.getMousePosOnOpeningCurrentPopupX()
    return lib.raia_imgui_get_mouse_pos_on_opening_current_popup_x()
end

function ImGui.getMousePosOnOpeningCurrentPopupY()
    return lib.raia_imgui_get_mouse_pos_on_opening_current_popup_y()
end

function ImGui.isMouseDragging(button, lock_threshold)
    lock_threshold = lock_threshold or -1.0
    return lib.raia_imgui_is_mouse_dragging(button, lock_threshold)
end

function ImGui.getMouseDragDeltaX(button, lock_threshold)
    button = button or 0
    lock_threshold = lock_threshold or -1.0
    return lib.raia_imgui_get_mouse_drag_delta_x(button, lock_threshold)
end

function ImGui.getMouseDragDeltaY(button, lock_threshold)
    button = button or 0
    lock_threshold = lock_threshold or -1.0
    return lib.raia_imgui_get_mouse_drag_delta_y(button, lock_threshold)
end

function ImGui.resetMouseDragDelta(button)
    button = button or 0
    lib.raia_imgui_reset_mouse_drag_delta(button)
end

function ImGui.getMouseCursor()
    return lib.raia_imgui_get_mouse_cursor()
end

function ImGui.setMouseCursor(cursor_type)
    lib.raia_imgui_set_mouse_cursor(cursor_type)
end

function ImGui.setNextFrameWantCaptureMouse(want_capture_mouse)
    lib.raia_imgui_set_next_frame_want_capture_mouse(want_capture_mouse)
end

-- クリップボードユーティリティ

function ImGui.getClipboardText()
    return lib.raia_imgui_get_clipboard_text()
end

function ImGui.setClipboardText(text)
    lib.raia_imgui_set_clipboard_text(text)
end

-- 設定/.Ini ユーティリティ

function ImGui.loadIniSettingsFromDisk(ini_filename)
    lib.raia_imgui_load_ini_settings_from_disk(ini_filename)
end

function ImGui.loadIniSettingsFromMemory(ini_data, ini_size)
    ini_size = ini_size or 0
    lib.raia_imgui_load_ini_settings_from_memory(ini_data, ini_size)
end

function ImGui.saveIniSettingsToDisk(ini_filename)
    lib.raia_imgui_save_ini_settings_to_disk(ini_filename)
end

function ImGui.saveIniSettingsToMemory(out_ini_size)
    out_ini_size = out_ini_size or ffi.null
    return lib.raia_imgui_save_ini_settings_to_memory(out_ini_size)
end

-- デバッグ・ユーティリティ

function ImGui.debugTextEncoding(text)
    lib.raia_imgui_debug_text_encoding(text)
end

function ImGui.debugCheckVersionAndDataLayout(version_str, sz_io, sz_style, sz_vec2, sz_vec4, sz_drawvert, sz_drawidx)
    return lib.raia_imgui_debug_check_version_and_data_layout(version_str, sz_io, sz_style, sz_vec2, sz_vec4, sz_drawvert, sz_drawidx)
end

-- メモリ・アロケータ

function ImGui.setAllocatorFunctions(alloc_func, free_func, user_data)
    user_data = user_data or ffi.null
    lib.raia_imgui_set_allocator_functions(alloc_func, free_func, user_data)
end

function ImGui.getAllocatorFunctions(p_alloc_func, p_free_func, p_user_data)
    lib.raia_imgui_get_allocator_functions(p_alloc_func, p_free_func, p_user_data)
end

function ImGui.memAlloc(size)
    return lib.raia_imgui_mem_alloc(size)
end

function ImGui.memFree(ptr)
    lib.raia_imgui_mem_free(ptr)
end

-- ここから拡張

-- begin end の予約語回避のため
-- ウィンドウ

function ImGui.beginWindow(name, p_open, flags)
    p_open = p_open or ffi.null
    flags = flags or 0
    return lib.raia_imgui_begin(name, p_open, flags)
end

function ImGui.endWindow()
    lib.raia_imgui_end()
end

-- imgui.cpp

function ImGui.updatePlatformWindows()
    lib.raia_imgui_update_platform_windows()
end

function ImGui.renderPlatformWindowsDefault()
    lib.raia_imgui_render_platform_windows_default()
end

-- impl GLFW

ImGui.GLFW = {}

function ImGui.GLFW.initForOpenGL(window, install_callbacks)
    return lib.raia_imgui_impl_glfw_init_for_opengl(window, install_callbacks)
end

function ImGui.GLFW.newFrame()
    lib.raia_imgui_impl_glfw_new_frame()
end

function ImGui.GLFW.shutdown()
    lib.raia_imgui_impl_glfw_shutdown()
end

-- impl OpenGL3

ImGui.OpenGL3 = {}

function ImGui.OpenGL3.init(glsl_version)
    return lib.raia_imgui_impl_opengl3_init(glsl_version)
end

function ImGui.OpenGL3.newFrame()
    lib.raia_imgui_impl_opengl3_new_frame()
end

function ImGui.OpenGL3.renderDrawData(draw_data)
    lib.raia_imgui_impl_opengl3_render_draw_data(draw_data)
end

function ImGui.OpenGL3.shutdown()
    lib.raia_imgui_impl_opengl3_shutdown()
end

-- IO ユーティリティ

ImGui.IO = {}

function ImGui.IO.setConfigFlags(config_flags)
    lib.raia_imgui_io_set_config_flags(config_flags)
end

function ImGui.IO.setConfigViewportsNoAutoMerge(flag)
    lib.raia_imgui_io_set_config_viewports_no_auto_merge(flag)
end

function ImGui.IO.setConfigViewportsNoTaskBarIcon(flag)
    lib.raia_imgui_io_set_config_viewports_no_task_bar_icon(flag)
end

function ImGui.IO.setFontGlobalScale(num)
    lib.raia_imgui_io_set_font_global_scale(num)
end

function ImGui.IO.getFramerate()
    return lib.raia_imgui_io_get_framerate()
end

function ImGui.IO.setFontDefault(font)
    lib.raia_imgui_io_set_font_default(font)
end

-- IO.Fonts ユーティリティ

ImGui.IO.Fonts = {}

function ImGui.IO.Fonts.addFontDefault()
    return lib.raia_imgui_io_fonts_add_font_default()
end

function ImGui.IO.Fonts.getGlyphRangesJapanese()
    return lib.raia_imgui_io_fonts_get_glyph_ranges_japanese()
end

function ImGui.IO.Fonts.addFontFromFileTTF(filename, size_pixels, font_cfg, glyph_ranges)
    return lib.raia_imgui_io_fonts_add_font_from_file_ttf(filename, size_pixels, font_cfg, glyph_ranges)
end

-- Style ユーティリティ

ImGui.Style = {}

function ImGui.Style.setAlpha(n)
    lib.raia_imgui_style_set_alpha(n)
end

function ImGui.Style.setDisabledAlpha(n)
    lib.raia_imgui_style_set_disabled_alpha(n)
end

function ImGui.Style.setWindowPadding(x, y)
    lib.raia_imgui_style_set_window_padding(x, y)
end

function ImGui.Style.setWindowRounding(n)
    lib.raia_imgui_style_set_window_rounding(n)
end

function ImGui.Style.setWindowBorderSize(n)
    lib.raia_imgui_style_set_window_border_size(n)
end

function ImGui.Style.setWindowMinSize(x, y)
    lib.raia_imgui_style_set_window_min_size(x, y)
end

function ImGui.Style.setWindowTitleAlign(x, y)
    lib.raia_imgui_style_set_window_title_align(x, y)
end

function ImGui.Style.setWindowMenuButtonPosition(n)
    lib.raia_imgui_style_set_window_menu_button_position(n)
end

function ImGui.Style.setChildRounding(n)
    lib.raia_imgui_style_set_child_rounding(n)
end

function ImGui.Style.setChildBorderSize(n)
    lib.raia_imgui_style_set_child_border_size(n)
end

function ImGui.Style.setPopupRounding(n)
    lib.raia_imgui_style_set_popup_rounding(n)
end

function ImGui.Style.setPopupBorderSize(n)
    lib.raia_imgui_style_set_popup_border_size(n)
end

function ImGui.Style.setFramePadding(x, y)
    lib.raia_imgui_style_set_frame_padding(x, y)
end

function ImGui.Style.setFrameRounding(n)
    lib.raia_imgui_style_set_frame_rounding(n)
end

function ImGui.Style.setFrameBorderSize(n)
    lib.raia_imgui_style_set_frame_border_size(n)
end

function ImGui.Style.setItemSpacing(x, y)
    lib.raia_imgui_style_set_item_spacing(x, y)
end

function ImGui.Style.setItemInnerSpacing(x, y)
    lib.raia_imgui_style_set_item_inner_spacing(x, y)
end

function ImGui.Style.setCellPadding(x, y)
    lib.raia_imgui_style_set_cell_padding(x, y)
end

function ImGui.Style.setTouchExtraPadding(x, y)
    lib.raia_imgui_style_set_touch_extra_padding(x, y)
end

function ImGui.Style.setIndentSpacing(n)
    lib.raia_imgui_style_set_indent_spacing(n)
end

function ImGui.Style.setColumnsMinSpacing(n)
    lib.raia_imgui_style_set_columns_min_spacing(n)
end

function ImGui.Style.setScrollbarSize(n)
    lib.raia_imgui_style_set_scrollbar_size(n)
end

function ImGui.Style.setScrollbarRounding(n)
    lib.raia_imgui_style_set_scrollbar_rounding(n)
end

function ImGui.Style.setGrabMinSize(n)
    lib.raia_imgui_style_set_grab_min_size(n)
end

function ImGui.Style.setGrabRounding(n)
    lib.raia_imgui_style_set_grab_rounding(n)
end

function ImGui.Style.setLogSliderDeadzone(n)
    lib.raia_imgui_style_set_log_slider_deadzone(n)
end

function ImGui.Style.setTabRounding(n)
    lib.raia_imgui_style_set_tab_rounding(n)
end

function ImGui.Style.setTabBorderSize(n)
    lib.raia_imgui_style_set_tab_border_size(n)
end

function ImGui.Style.setTabMinWidthForCloseButton(n)
    lib.raia_imgui_style_set_tab_min_width_for_close_button(n)
end

function ImGui.Style.setBolorButtonPosition(n)
    lib.raia_imgui_style_set_bolor_button_position(n)
end

function ImGui.Style.setButtonTextAlign(x, y)
    lib.raia_imgui_style_set_button_text_align(x, y)
end

function ImGui.Style.setSelectableTextAlign(x, y)
    lib.raia_imgui_style_set_selectable_text_align(x, y)
end

function ImGui.Style.setSeparatorTextBorderSize(n)
    lib.raia_imgui_style_set_separator_text_border_size(n)
end

function ImGui.Style.setSeparatorTextAlign(x, y)
    lib.raia_imgui_style_set_separator_text_align(x, y)
end

function ImGui.Style.setSeparatorTextPadding(x, y)
    lib.raia_imgui_style_set_separator_text_padding(x, y)
end

function ImGui.Style.setDisplayWindowPadding(x, u)
    lib.raia_imgui_style_set_display_window_padding(x, y)
end

function ImGui.Style.setDisplaySafeAreaPadding(x, y)
    lib.raia_imgui_style_set_display_safe_area_padding(x, y)
end

function ImGui.Style.setMouseCursorScale(n)
    lib.raia_imgui_style_set_mouse_cursor_scale(n)
end

function ImGui.Style.setAntiAliasedLines(n)
    lib.raia_imgui_style_set_anti_aliased_lines(n)
end

function ImGui.Style.setAntiAliasedLinesUseTex(n)
    lib.raia_imgui_style_set_anti_aliased_lines_use_tex(n)
end

function ImGui.Style.setAntiAliasedFill(n)
    lib.raia_imgui_style_set_anti_aliased_fill(n)
end

function ImGui.Style.setCurveTessellationTol(n)
    lib.raia_imgui_style_set_curve_tessellation_tol(n)
end

function ImGui.Style.setCircleTessellationMaxError(n)
    lib.raia_imgui_style_set_circle_tessellation_max_error(n)
end


function ImGui.Style.scaleAllSizes(n)
    lib.raia_imgui_style_scale_all_sizes(n)
end

function ImGui.Style.setColors(col, red, green, blue, alpha)
    lib.raia_imgui_style_set_colors(col, red, green, blue, alpha)
end

-- その他の汎用 ユーティリティ

function ImGui.intToPtr(value)
    return lib.raia_imgui_int_to_ptr(value)
end

--

return ImGui