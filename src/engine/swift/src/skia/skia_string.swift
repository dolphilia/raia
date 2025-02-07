extension Skia {
    class SkString {
        public var pointer: Skia.SkStringMutablePointer?
        public var handle: sk_string_t = -1

        // void *SkString_new(); // () -> SkString *

        init() {
            self.pointer = SkString_new();
            self.handle = -1
        }
        // void *SkString_new_2(unsigned long len); // (size_t len) -> SkString *

        init(len: UInt) {
            self.pointer = SkString_new_2(len);
            self.handle = -1
        }
        // void *SkString_new_3(const char text[]); // (const char text[]) -> SkString *

        init(text: UnsafePointer<CChar>?) {
            self.pointer = SkString_new_3(text);
            self.handle = -1
        }
        // void *SkString_new_4(const char text[], unsigned long len); // (const char text[], size_t len) -> SkString *

        init(text: UnsafePointer<CChar>?, len: UInt) {
            self.pointer = SkString_new_4(text, len);
            self.handle = -1
        }
        // void *SkString_new_5(const void *str); // (const SkString *str) -> SkString *

        init(str: SkString) {
            self.pointer = SkString_new_5(str.pointer);
            self.handle = -1
        }
        // void *SkString_new_6(const void *str); // (const std::string *str) -> SkString *

        init(str: String) {
            self.pointer = SkString_new_6(str);
            self.handle = -1
        }
        // void *SkString_new_7(int view); // (string_view_t view) -> SkString *

        init(view: StringViewType) {
            self.pointer = SkString_new_7(view.handle);
            self.handle = -1
        }
        // void SkString_delete(void *string); // (SkString *string)

        deinit {
            SkString_delete(self.pointer)
            if self.handle > -1 {
                static_sk_string_delete(self.handle)
            }
        }
        // bool SkString_isEmpty(void *string); // (SkString *string) -> bool

        func isEmpty() -> Bool {
            return SkString_isEmpty(self.pointer)
        }
        // unsigned long SkString_size(void *string); // (SkString *string) -> size_t

        func size() -> UInt {
            return SkString_size(self.pointer)
        }
        // const char * SkString_data(void *string); // (SkString *string) -> const char *

        func data() -> UnsafePointer<CChar>? {
            return SkString_data(self.pointer)
        }
        // char * SkString_data_2(void *string); // (SkString *string) -> char *

        func data() -> UnsafeMutablePointer<CChar>? {
            return SkString_data_2(self.pointer)
        }
        // const char * SkString_c_str(void *string); // (SkString *string) -> const char *

        func cStr() -> UnsafePointer<CChar>? {
            return SkString_c_str(self.pointer)
        }
        // bool SkString_equals(void *string, const void *str); // (SkString *string, const SkString *str) -> bool

        func equals(str: SkString) -> Bool {
            return SkString_equals(self.pointer, str.pointer)
        }
        // bool SkString_equals_2(void *string, const char text[]); // (SkString *string, const char text[]) -> bool

        func equals(text: UnsafePointer<CChar>?) -> Bool {
            return SkString_equals_2(self.pointer, text)
        }
        // bool SkString_equals_3(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len) -> bool

        func equals(text: UnsafePointer<CChar>?, len: UInt) -> Bool {
            return SkString_equals_3(self.pointer, text, len)
        }
        // bool SkString_startsWith(void *string, const char prefixStr[]); // (SkString *string, const char prefixStr[]) -> bool

        func startsWith(prefixStr: UnsafePointer<CChar>?) -> Bool {
            return SkString_startsWith(self.pointer, prefixStr)
        }
        // bool SkString_startsWith_2(void *string, char prefixChar); // (SkString *string, char prefixChar) -> bool

        func startsWith(prefixChar: CChar) -> Bool {
            return SkString_startsWith_2(self.pointer, prefixChar)
        }

        // //bool SkString_endsWith(SkString *string, const char suffixStr[]);
        // //bool SkString_endsWith_2(SkString *string, const char suffixChar);

        // bool SkString_contains(void *string, const char substring[]); // (SkString *string, const char substring[]) -> bool

        func contains(substring: UnsafePointer<CChar>?) -> Bool {
            return SkString_contains(self.pointer, substring)
        }
        // bool SkString_contains_2(void *string, char subchar); // (SkString *string, char subchar) -> bool

        func contains(subchar: CChar) -> Bool {
            return SkString_contains_2(self.pointer, subchar)
        }
        // int SkString_find(void *string, const char substring[]); // (SkString *string, const char substring[]) -> int

        func find(substring: UnsafePointer<CChar>?) -> Int {
            return Int(SkString_find(self.pointer, substring))
        }
        // int SkString_findLastOf(void *string, char subchar); // (SkString *string, char subchar) -> int

        func findLastOf(subchar: CChar) -> Int {
            return Int(SkString_findLastOf(self.pointer, subchar))
        }
        // void SkString_reset(void *string); // (SkString *string)

        func reset() {
            SkString_reset(self.pointer)
        }
        // void SkString_resize(void *string, unsigned long len); // (SkString *string, size_t len)

        func resize(len: UInt) {
            SkString_resize(self.pointer, len)
        }
        // void SkString_set(void *string, const void *src); // (SkString *string, const SkString *src)

        func set(src: SkString) {
            SkString_set(self.pointer, src.pointer)
        }
        // void SkString_set_2(void *string, const char text[]); // (SkString *string, const char text[])

        func set(text: UnsafePointer<CChar>?) {
            SkString_set_2(self.pointer, text)
        }
        // void SkString_set_3(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len)

        func set(text: UnsafePointer<CChar>?, len: UInt) {
            SkString_set_3(self.pointer, text, len)
        }
        // void SkString_set_4(void *string, int str); // (SkString *string, string_view_t str)

        func set(str: StringViewType) {
            SkString_set_4(self.pointer, str.handle)
        }
        // void SkString_insert(void *string, unsigned long offset, const char text[]); // (SkString *string, size_t offset, const char text[])

        func insert(offset: UInt, text: UnsafePointer<CChar>?) {
            SkString_insert(self.pointer, offset, text)
        }
        // void SkString_insert_2(void *string, unsigned long offset, const char text[], unsigned long len); // (SkString *string, size_t offset, const char text[], size_t len)

        func insert(offset: UInt, text: UnsafePointer<CChar>?, len: UInt) {
            SkString_insert_2(self.pointer, offset, text, len)
        }
        // void SkString_insert_3(void *string, unsigned long offset, const void *str); // (SkString *string, size_t offset, const SkString *str)

        func insert(offset: UInt, str: SkString) {
            SkString_insert_3(self.pointer, offset, str.pointer)
        }
        // void SkString_insert_4(void *string, unsigned long offset, int str); // (SkString *string, size_t offset, string_view_t str)

        func insert(offset: UInt, str: StringViewType) {
            SkString_insert_4(self.pointer, offset, str.handle)
        }
        // void SkString_insertUnichar(void *string, unsigned long offset, int unichar); // (SkString *string, size_t offset, SkUnichar unichar)

        func insertUnichar(offset: UInt, unichar: Int) {
            SkString_insertUnichar(self.pointer, offset, Int32(unichar))
        }
        // void SkString_insertS32(void *string, unsigned long offset, int value); // (SkString *string, size_t offset, int32_t value)

        func insertS32(offset: UInt, value: Int32) {
            SkString_insertS32(self.pointer, offset, value)
        }
        // void SkString_insertS64(void *string, unsigned long offset, long long value, int minDigits); // (SkString *string, size_t offset, int64_t value, int minDigits)

        func insertS64(offset: UInt, value: Int64, minDigits: Int) {
            SkString_insertS64(self.pointer, offset, value, Int32(minDigits))
        }
        // void SkString_insertU32(void *string, unsigned long offset, unsigned int value); // (SkString *string, size_t offset, uint32_t value)

        func insertU32(offset: UInt, value: UInt32) {
            SkString_insertU32(self.pointer, offset, value)
        }
        // void SkString_insertU64(void *string, unsigned long offset, unsigned long long value, int minDigits); // (SkString *string, size_t offset, uint64_t value, int minDigits)

        func insertU64(offset: UInt, value: UInt64, minDigits: Int) {
            SkString_insertU64(self.pointer, offset, value, Int32(minDigits))
        }
        // void SkString_insertHex(void *string, unsigned long offset, unsigned int value, int minDigits); // (SkString *string, size_t offset, uint32_t value, int minDigits)

        func insertHex(offset: UInt, value: UInt32, minDigits: Int) {
            SkString_insertHex(self.pointer, offset, value, Int32(minDigits))
        }
        // void SkString_insertScalar(void *string, unsigned long offset, float v); // (SkString *string, size_t offset, SkScalar v)

        func insertScalar(offset: UInt, v: Float) {
            SkString_insertScalar(self.pointer, offset, v)
        }
        // void SkString_append(void *string, const char text[]); // (SkString *string, const char text[])

        func append(text: UnsafePointer<CChar>?) {
            SkString_append(self.pointer, text)
        }
        // void SkString_append_2(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len)

        func append(text: UnsafePointer<CChar>?, len: UInt) {
            SkString_append_2(self.pointer, text, len)
        }
        // void SkString_append_3(void *string, const void *str); // (SkString *string, const SkString *str)

        func append(str: SkString) {
            SkString_append_3(self.pointer, str.pointer)
        }
        // void SkString_append_4(void *string, int str); // (SkString *string, string_view_t str)

        func append(str: StringViewType) {
            SkString_append_4(self.pointer, str.handle)
        }
        // void SkString_appendUnichar(void *string, int uni); // (SkString *string, SkUnichar uni)

        func appendUnichar(uni: Int) {
            SkString_appendUnichar(self.pointer, Int32(uni))
        }
        // void SkString_appendS32(void *string, int value); // (SkString *string, int32_t value)

        func appendS32(value: Int32) {
            SkString_appendS32(self.pointer, value)
        }
        // void SkString_appendS64(void *string, long long value, int minDigits); // (SkString *string, int64_t value, int minDigits)

        func appendS64(value: Int64, minDigits: Int) {
            SkString_appendS64(self.pointer, value, Int32(minDigits))
        }
        // void SkString_appendU32(void *string, unsigned int value); // (SkString *string, uint32_t value)

        func appendU32(value: UInt32) {
            SkString_appendU32(self.pointer, value)
        }
        // void SkString_appendU64(void *string, unsigned long long value, int minDigits); // (SkString *string, uint64_t value, int minDigits)

        func appendU64(value: UInt64, minDigits: Int) {
            SkString_appendU64(self.pointer, value, Int32(minDigits))
        }
        // void SkString_appendHex(void *string, unsigned int value, int minDigits); // (SkString *string, uint32_t value, int minDigits)

        func appendHex(value: UInt32, minDigits: Int) {
            SkString_appendHex(self.pointer, value, Int32(minDigits))
        }
        // void SkString_appendScalar(void *string, float value); // (SkString *string, SkScalar value)

        func appendScalar(value: Float) {
            SkString_appendScalar(self.pointer, value)
        }
        // void SkString_prepend(void *string, const char text[]); // (SkString *string, const char text[])

        func prepend(text: UnsafePointer<CChar>?) {
            SkString_prepend(self.pointer, text)
        }
        // void SkString_prepend_2(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len)

        func prepend(text: UnsafePointer<CChar>?, len: UInt) {
            SkString_prepend_2(self.pointer, text, len)
        }
        // void SkString_prepend_3(void *string, const void *str); // (SkString *string, const SkString *str)

        func prepend(str: SkString) {
            SkString_prepend_3(self.pointer, str.pointer)
        }
        // void SkString_prepend_4(void *string, int str); // (SkString *string, string_view_t str)

        func prepend(str: StringViewType) {
            SkString_prepend_4(self.pointer, str.handle)
        }
        // void SkString_prependUnichar(void *string, int uni); // (SkString *string, SkUnichar uni)

        func prependUnichar(uni: Int) {
            SkString_prependUnichar(self.pointer, Int32(uni))
        }
        // void SkString_prependS32(void *string, int value); // (SkString *string, int32_t value)

        func prependS32(value: Int32) {
            SkString_prependS32(self.pointer, value)
        }
        // void SkString_prependS64(void *string, int value, int minDigits); // (SkString *string, int32_t value, int minDigits)

        func prependS64(value: Int32, minDigits: Int) {
            SkString_prependS64(self.pointer, value, Int32(minDigits))
        }
        // void SkString_prependHex(void *string, unsigned int value, int minDigits); // (SkString *string, uint32_t value, int minDigits)

        func prependHex(value: UInt, minDigits: Int) {
            SkString_prependHex(self.pointer, UInt32(value), Int32(minDigits))
        }
        // void SkString_prependScalar(void *string, float value); // (SkString *string, SkScalar value)

        func prependScalar(value: Float) {
            SkString_prependScalar(self.pointer, value)
        }

        //void SkString_printf(SkString *string, const char format[],...);
        //void SkString_printVAList(SkString *string, const char format[], va_list);
        func printf(format: String, _ args: CVarArg...) {
            withVaList(args) { vaList in
                SkString_printVAList(self.pointer, format, vaList)
            }
        }
        //void SkString_appendf(SkString *string, const char format[],...);
        //void SkString_appendVAList(SkString *string, const char format[], va_list);
        func appendf(format: String, _ args: CVarArg...) {
            withVaList(args) { vaList in
                SkString_appendVAList(self.pointer, format, vaList)
            }
        }
        //void SkString_prependf(SkString *string, const char format[],...);
        //void SkString_prependVAList(SkString *string, const char format[], va_list);
        func prependf(format: String, _ args: CVarArg...) {
            withVaList(args) { vaList in
                SkString_prependVAList(self.pointer, format, vaList)
            }
        }

        // void SkString_remove(void *string, unsigned long offset, unsigned long length); // (SkString *string, size_t offset, size_t length)

        func remove(offset: UInt, length: UInt) {
            SkString_remove(self.pointer, offset, length)
        }
        // void SkString_swap(void *string, void *other); // (SkString *string, SkString *other)

        func swap(other: SkString) {
            SkString_swap(self.pointer, other.pointer)
        }

        // static

        init(pointer: Skia.SkStringMutablePointer?, handle: sk_string_t) {
            self.pointer = pointer
            self.handle = handle
        }
    }
}