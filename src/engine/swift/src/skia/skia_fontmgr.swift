extension Skia {
    class SkFontMgr {
        public var pointer: SkFontMgrMutablePointer?
        public var handle: sk_font_mgr_t = -1

        // void SkFontMgr_delete(void *font_mgr); // (SkFontMgr *font_mgr)

        deinit {
            if self.handle > -1 {
                static_sk_font_mgr_delete(self.handle)
            } else {
                SkFontMgr_delete(self.pointer)
            }
        }

        // int SkFontMgr_countFamilies(void *font_mgr); // (SkFontMgr *font_mgr) -> int

        func countFamilies() -> Int {
            return Int(SkFontMgr_countFamilies(self.pointer))
        }
        // void SkFontMgr_getFamilyName(void *font_mgr, int index, void *familyName); // (SkFontMgr *font_mgr, int index, SkString *familyName)

        func getFamilyName(index: Int, familyName: SkString)  {
            SkFontMgr_getFamilyName(self.pointer, Int32(index), familyName.pointer)
        }
        // void SkFontMgr_createStyleSet(int sk_font_style_set_out, void *font_mgr, int index); // (int sk_font_style_set_out, SkFontMgr *font_mgr, int index)
        // void SkFontMgr_matchFamily(int sk_font_style_set_out, void *font_mgr, const char familyName[]); // (int sk_font_style_set_out, SkFontMgr *font_mgr, const char familyName[])
        // int SkFontMgr_matchFamilyStyle(void *font_mgr, const char familyName[], const void *font_style); // (SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style) -> sk_typeface_t

        func matchFamilyStyle(familyName: String, font_style: SkFontStyle) -> SkTypeface {
            let handle = SkFontMgr_matchFamilyStyle(self.pointer, familyName, font_style.pointer)
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }

        // int SkFontMgr_matchFamilyStyleCharacter(void *font_mgr, const char familyName[], const void *font_style, const char *bcp47[], int bcp47Count, int character); // (SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style, const char *bcp47[], int bcp47Count, SkUnichar character) -> sk_typeface_t        
        // int SkFontMgr_makeFromData(void *font_mgr, int data, int ttcIndex); // (SkFontMgr *font_mgr, sk_data_t data, int ttcIndex) -> sk_typeface_t

        func makeFromData(data: SkData, ttcIndex: Int) -> SkTypeface {
            let handle = SkFontMgr_makeFromData(self.pointer, data.handle, Int32(ttcIndex))
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
        // int SkFontMgr_makeFromStream(void *font_mgr, int stream_asset, int ttcIndex); // (SkFontMgr *font_mgr, sk_stream_asset_t stream_asset, int ttcIndex) -> sk_typeface_t

        func makeFromStream(stream_asset: SkStreamAsset, ttcIndex: Int) -> SkTypeface {
            let handle = SkFontMgr_makeFromStream(self.pointer, stream_asset.handle, Int32(ttcIndex))
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }
        // int SkFontMgr_makeFromStream_2(void *font_mgr, int stream_asset, const void *font_argments); // (SkFontMgr *font_mgr, sk_stream_asset_t stream_asset, const SkFontArguments *font_argments) -> sk_typeface_t

        func makeFromStream(stream_asset: SkStreamAsset, font_argments: SkFontArguments) -> SkTypeface {
            let handle = SkFontMgr_makeFromStream_2(self.pointer, stream_asset.handle, font_argments.pointer)
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }

        // int SkFontMgr_makeFromFile(void *font_mgr, const char path[], int ttcIndex); // (SkFontMgr *font_mgr, const char path[], int ttcIndex) -> sk_typeface_t

        func makeFromFile(path: String, ttcIndex: Int) -> SkTypeface {
            let handle = SkFontMgr_makeFromFile(self.pointer, path, Int32(ttcIndex))
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }

        // int SkFontMgr_legacyMakeTypeface(void *font_mgr, const char familyName[], int style); // (SkFontMgr *font_mgr, const char familyName[], sk_font_style_t style) -> sk_typeface_t

        func legacyMakeTypeface(familyName: String, style: SkFontStyle) -> SkTypeface {
            let handle = SkFontMgr_legacyMakeTypeface(self.pointer, familyName, style.handle)
            let pointer = static_sk_typeface_get_ptr(handle)
            return SkTypeface(pointer: pointer, handle: handle)
        }

        // bool SkFontMgr_unique(void *font_mgr); // (SkFontMgr *font_mgr) -> bool

        func unique() -> Bool {
            return SkFontMgr_unique(self.pointer)
        }
        // void SkFontMgr_ref(void *font_mgr); // (SkFontMgr *font_mgr)

        func ref() {
            SkFontMgr_ref(self.pointer)
        }
        // void SkFontMgr_unref(void *font_mgr); // (SkFontMgr *font_mgr)

        func unref() {
            SkFontMgr_unref(self.pointer)
        }

        // // static

        init(pointer: SkFontMgrMutablePointer?, handle: sk_font_mgr_t) {
            self.pointer = pointer
            self.handle = handle
        }
        // int SkFontMgr_RefEmpty(); // () -> sk_font_mgr_t

        static func RefEmpty() -> SkFontMgr {
            let handle = SkFontMgr_RefEmpty()
            let pointer = static_sk_font_mgr_get_ptr(handle)
            return SkFontMgr(pointer: pointer, handle: handle)
        }
        // // Legacy
        // int SkFontMgr_RefDefault(); // () -> sk_font_mgr_t

        static func RefDefault() -> SkFontMgr {
            let handle = SkFontMgr_RefDefault()
            let pointer = static_sk_font_mgr_get_ptr(handle)
            return SkFontMgr(pointer: pointer, handle: handle)
        }
    }
}