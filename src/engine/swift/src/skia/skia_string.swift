extension Skia {
    class StringView {
        public let handle: string_view_t

        public init(handle: string_view_t) {
            self.handle = handle
        }

        deinit {
            static_string_view_delete(handle)
        }
    }

    protocol SkStringProtocol {
        var pointer: SkStringMutablePointer? { get set }
        var handle: sk_string_t { get set }
        // deinit // void SkString_delete(void *string); // (SkString *string)
        init(pointer: SkStringMutablePointer?, handle: sk_string_t)
        init() // void *SkString_new(); // () -> SkString *
        init(len: UInt) // void *SkString_new_2(unsigned long len); // (size_t len) -> SkString *
        init(text: UnsafePointer<CChar>?) // void *SkString_new_3(const char text[]); // (const char text[]) -> SkString *
        init(text: UnsafePointer<CChar>?, len: UInt) // void *SkString_new_4(const char text[], unsigned long len); // (const char text[], size_t len) -> SkString *
        init(str: SkString) // void *SkString_new_5(const void *str); // (const SkString *str) -> SkString *
        init(str: String) // void *SkString_new_6(const void *str); // (const std::string *str) -> SkString *
        init(view: StringView) // void *SkString_new_7(int view); // (string_view_t view) -> SkString *
        // Methods
        func isEmpty() -> Bool // bool SkString_isEmpty(void *string); // (SkString *string) -> bool
        func size() -> UInt // unsigned long SkString_size(void *string); // (SkString *string) -> size_t
        func data() -> UnsafePointer<CChar>? // const char * SkString_data(void *string); // (SkString *string) -> const char *
        func data() -> UnsafeMutablePointer<CChar>? // char * SkString_data_2(void *string); // (SkString *string) -> char *
        func cStr() -> UnsafePointer<CChar>? // const char * SkString_c_str(void *string); // (SkString *string) -> const char *
        func equals(str: SkString) -> Bool // bool SkString_equals(void *string, const void *str); // (SkString *string, const SkString *str) -> bool
        func equals(text: UnsafePointer<CChar>?) -> Bool // bool SkString_equals_2(void *string, const char text[]); // (SkString *string, const char text[]) -> bool
        func equals(text: UnsafePointer<CChar>?, len: UInt) -> Bool // bool SkString_equals_3(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len) -> bool
        func startsWith(prefixStr: UnsafePointer<CChar>?) -> Bool // bool SkString_startsWith(void *string, const char prefixStr[]); // (SkString *string, const char prefixStr[]) -> bool
        func startsWith(prefixChar: CChar) -> Bool // bool SkString_startsWith_2(void *string, char prefixChar); // (SkString *string, char prefixChar) -> bool
        // bool SkString_endsWith(SkString *string, const char suffixStr[]);
        // bool SkString_endsWith_2(SkString *string, const char suffixChar);
        func contains(substring: UnsafePointer<CChar>?) -> Bool // bool SkString_contains(void *string, const char substring[]); // (SkString *string, const char substring[]) -> bool
        func contains(subchar: CChar) -> Bool // bool SkString_contains_2(void *string, char subchar); // (SkString *string, char subchar) -> bool
        func find(substring: UnsafePointer<CChar>?) -> Int // int SkString_find(void *string, const char substring[]); // (SkString *string, const char substring[]) -> int
        func findLastOf(subchar: CChar) -> Int // int SkString_findLastOf(void *string, char subchar); // (SkString *string, char subchar) -> int
        func reset() // void SkString_reset(void *string); // (SkString *string)
        func resize(len: UInt) // void SkString_resize(void *string, unsigned long len); // (SkString *string, size_t len)
        func set(src: SkString) // void SkString_set(void *string, const void *src); // (SkString *string, const SkString *src)
        func set(text: UnsafePointer<CChar>?) // void SkString_set_2(void *string, const char text[]); // (SkString *string, const char text[])
        func set(text: UnsafePointer<CChar>?, len: UInt) // void SkString_set_3(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len)
        func set(str: StringView) // void SkString_set_4(void *string, int str); // (SkString *string, string_view_t str)
        func insert(offset: UInt, text: UnsafePointer<CChar>?) // void SkString_insert(void *string, unsigned long offset, const char text[]); // (SkString *string, size_t offset, const char text[])
        func insert(offset: UInt, text: UnsafePointer<CChar>?, len: UInt) // void SkString_insert_2(void *string, unsigned long offset, const char text[], unsigned long len); // (SkString *string, size_t offset, const char text[], size_t len)
        func insert(offset: UInt, str: SkString) // void SkString_insert_3(void *string, unsigned long offset, const void *str); // (SkString *string, size_t offset, const SkString *str)
        func insert(offset: UInt, str: StringView) // void SkString_insert_4(void *string, unsigned long offset, int str); // (SkString *string, size_t offset, string_view_t str)
        func insertUnichar(offset: UInt, unichar: Int) // void SkString_insertUnichar(void *string, unsigned long offset, int unichar); // (SkString *string, size_t offset, SkUnichar unichar)
        func insertS32(offset: UInt, value: Int32) // void SkString_insertS32(void *string, unsigned long offset, int value); // (SkString *string, size_t offset, int32_t value)
        func insertS64(offset: UInt, value: Int64, minDigits: Int) // void SkString_insertS64(void *string, unsigned long offset, long long value, int minDigits); // (SkString *string, size_t offset, int64_t value, int minDigits)
        func insertU32(offset: UInt, value: UInt32) // void SkString_insertU32(void *string, unsigned long offset, unsigned int value); // (SkString *string, size_t offset, uint32_t value)
        func insertU64(offset: UInt, value: UInt64, minDigits: Int) // void SkString_insertU64(void *string, unsigned long offset, unsigned long long value, int minDigits); // (SkString *string, size_t offset, uint64_t value, int minDigits)
        func insertHex(offset: UInt, value: UInt32, minDigits: Int) // void SkString_insertHex(void *string, unsigned long offset, unsigned int value, int minDigits); // (SkString *string, size_t offset, uint32_t value, int minDigits)
        func insertScalar(offset: UInt, v: Float) // void SkString_insertScalar(void *string, unsigned long offset, float v); // (SkString *string, size_t offset, SkScalar v)
        func append(text: UnsafePointer<CChar>?) // void SkString_append(void *string, const char text[]); // (SkString *string, const char text[])
        func append(text: UnsafePointer<CChar>?, len: UInt) // void SkString_append_2(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len)
        func append(str: SkString) // void SkString_append_3(void *string, const void *str); // (SkString *string, const SkString *str)
        func append(str: StringView) // void SkString_append_4(void *string, int str); // (SkString *string, string_view_t str)
        func appendUnichar(uni: Int) // void SkString_appendUnichar(void *string, int uni); // (SkString *string, SkUnichar uni)
        func appendS32(value: Int32) // void SkString_appendS32(void *string, int value); // (SkString *string, int32_t value)
        func appendS64(value: Int64, minDigits: Int) // void SkString_appendS64(void *string, long long value, int minDigits); // (SkString *string, int64_t value, int minDigits)
        func appendU32(value: UInt32) // void SkString_appendU32(void *string, unsigned int value); // (SkString *string, uint32_t value)
        func appendU64(value: UInt64, minDigits: Int) // void SkString_appendU64(void *string, unsigned long long value, int minDigits); // (SkString *string, uint64_t value, int minDigits)
        func appendHex(value: UInt32, minDigits: Int) // void SkString_appendHex(void *string, unsigned int value, int minDigits); // (SkString *string, uint32_t value, int minDigits)
        func appendScalar(value: Float) // void SkString_appendScalar(void *string, float value); // (SkString *string, SkScalar value)
        func prepend(text: UnsafePointer<CChar>?) // void SkString_prepend(void *string, const char text[]); // (SkString *string, const char text[])
        func prepend(text: UnsafePointer<CChar>?, len: UInt) // void SkString_prepend_2(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len)
        func prepend(str: SkString) // void SkString_prepend_3(void *string, const void *str); // (SkString *string, const SkString *str)
        func prepend(str: StringView) // void SkString_prepend_4(void *string, int str); // (SkString *string, string_view_t str)
        func prependUnichar(uni: Int) // void SkString_prependUnichar(void *string, int uni); // (SkString *string, SkUnichar uni)
        func prependS32(value: Int32) // void SkString_prependS32(void *string, int value); // (SkString *string, int32_t value)
        func prependS64(value: Int32, minDigits: Int) // void SkString_prependS64(void *string, int value, int minDigits); // (SkString *string, int32_t value, int minDigits)
        func prependHex(value: UInt, minDigits: Int) // void SkString_prependHex(void *string, unsigned int value, int minDigits); // (SkString *string, uint32_t value, int minDigits)
        func prependScalar(value: Float) // void SkString_prependScalar(void *string, float value); // (SkString *string, SkScalar value)
        //void SkString_printf(SkString *string, const char format[],...);
        func printf(format: String, _ args: CVarArg...) // void SkString_printVAList(SkString *string, const char format[], va_list);
        //void SkString_appendf(SkString *string, const char format[],...);
        func appendf(format: String, _ args: CVarArg...) //void SkString_appendVAList(SkString *string, const char format[], va_list);
        //void SkString_prependf(SkString *string, const char format[],...);
        func prependf(format: String, _ args: CVarArg...) //void SkString_prependVAList(SkString *string, const char format[], va_list);
        func remove(offset: UInt, length: UInt) // void SkString_remove(void *string, unsigned long offset, unsigned long length); // (SkString *string, size_t offset, size_t length)
        func swap(other: SkString) // void SkString_swap(void *string, void *other); // (SkString *string, SkString *other)
    }

    class SkString: SkStringProtocol {
        public var pointer: SkStringMutablePointer?
        public var handle: sk_string_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_string_delete(self.handle)
            } else {
                SkString_delete(self.pointer)
            }
        }

        required init(pointer: SkStringMutablePointer?, handle: sk_string_t) {
            self.pointer = pointer
            self.handle = handle
        }

        required init() {
            self.pointer = SkString_new();
            self.handle = -1
        }

        required init(len: UInt) {
            self.pointer = SkString_new_2(len);
            self.handle = -1
        }

        required init(text: UnsafePointer<CChar>?) {
            self.pointer = SkString_new_3(text);
            self.handle = -1
        }
        
        required init(text: UnsafePointer<CChar>?, len: UInt) {
            self.pointer = SkString_new_4(text, len);
            self.handle = -1
        }
        
        required init(str: SkString) {
            self.pointer = SkString_new_5(str.pointer);
            self.handle = -1
        }
        
        required init(str: String) {
            self.pointer = SkString_new_6(str);
            self.handle = -1
        }
        
        required init(view: StringView) {
            self.pointer = SkString_new_7(view.handle);
            self.handle = -1
        }
        
        // Methods

        func isEmpty() -> Bool {
            return SkString_isEmpty(self.pointer)
        }
        
        func size() -> UInt {
            return SkString_size(self.pointer)
        }
        
        func data() -> UnsafePointer<CChar>? {
            return SkString_data(self.pointer)
        }
        
        func data() -> UnsafeMutablePointer<CChar>? {
            return SkString_data_2(self.pointer)
        }
        
        func cStr() -> UnsafePointer<CChar>? {
            return SkString_c_str(self.pointer)
        }
        
        func equals(str: SkString) -> Bool {
            return SkString_equals(self.pointer, str.pointer)
        }
        
        func equals(text: UnsafePointer<CChar>?) -> Bool {
            return SkString_equals_2(self.pointer, text)
        }
        
        func equals(text: UnsafePointer<CChar>?, len: UInt) -> Bool {
            return SkString_equals_3(self.pointer, text, len)
        }
        
        func startsWith(prefixStr: UnsafePointer<CChar>?) -> Bool {
            return SkString_startsWith(self.pointer, prefixStr)
        }
        
        func startsWith(prefixChar: CChar) -> Bool {
            return SkString_startsWith_2(self.pointer, prefixChar)
        }

        // bool SkString_endsWith(SkString *string, const char suffixStr[]);
        // bool SkString_endsWith_2(SkString *string, const char suffixChar);

        func contains(substring: UnsafePointer<CChar>?) -> Bool {
            return SkString_contains(self.pointer, substring)
        }

        func contains(subchar: CChar) -> Bool {
            return SkString_contains_2(self.pointer, subchar)
        }

        func find(substring: UnsafePointer<CChar>?) -> Int {
            return Int(SkString_find(self.pointer, substring))
        }

        func findLastOf(subchar: CChar) -> Int {
            return Int(SkString_findLastOf(self.pointer, subchar))
        }

        func reset() {
            SkString_reset(self.pointer)
        }

        func resize(len: UInt) {
            SkString_resize(self.pointer, len)
        }

        func set(src: SkString) {
            SkString_set(self.pointer, src.pointer)
        }

        func set(text: UnsafePointer<CChar>?) {
            SkString_set_2(self.pointer, text)
        }

        func set(text: UnsafePointer<CChar>?, len: UInt) {
            SkString_set_3(self.pointer, text, len)
        }

        func set(str: StringView) {
            SkString_set_4(self.pointer, str.handle)
        }

        func insert(offset: UInt, text: UnsafePointer<CChar>?) {
            SkString_insert(self.pointer, offset, text)
        }

        func insert(offset: UInt, text: UnsafePointer<CChar>?, len: UInt) {
            SkString_insert_2(self.pointer, offset, text, len)
        }

        func insert(offset: UInt, str: SkString) {
            SkString_insert_3(self.pointer, offset, str.pointer)
        }

        func insert(offset: UInt, str: StringView) {
            SkString_insert_4(self.pointer, offset, str.handle)
        }

        func insertUnichar(offset: UInt, unichar: Int) {
            SkString_insertUnichar(self.pointer, offset, Int32(unichar))
        }

        func insertS32(offset: UInt, value: Int32) {
            SkString_insertS32(self.pointer, offset, value)
        }

        func insertS64(offset: UInt, value: Int64, minDigits: Int) {
            SkString_insertS64(self.pointer, offset, value, Int32(minDigits))
        }

        func insertU32(offset: UInt, value: UInt32) {
            SkString_insertU32(self.pointer, offset, value)
        }
 
        func insertU64(offset: UInt, value: UInt64, minDigits: Int) {
            SkString_insertU64(self.pointer, offset, value, Int32(minDigits))
        }
 
        func insertHex(offset: UInt, value: UInt32, minDigits: Int) {
            SkString_insertHex(self.pointer, offset, value, Int32(minDigits))
        }

        func insertScalar(offset: UInt, v: Float) {
            SkString_insertScalar(self.pointer, offset, v)
        }

        func append(text: UnsafePointer<CChar>?) {
            SkString_append(self.pointer, text)
        }

        func append(text: UnsafePointer<CChar>?, len: UInt) {
            SkString_append_2(self.pointer, text, len)
        }

        func append(str: SkString) {
            SkString_append_3(self.pointer, str.pointer)
        }

        func append(str: StringView) {
            SkString_append_4(self.pointer, str.handle)
        }

        func appendUnichar(uni: Int) {
            SkString_appendUnichar(self.pointer, Int32(uni))
        }

        func appendS32(value: Int32) {
            SkString_appendS32(self.pointer, value)
        }

        func appendS64(value: Int64, minDigits: Int) {
            SkString_appendS64(self.pointer, value, Int32(minDigits))
        }

        func appendU32(value: UInt32) {
            SkString_appendU32(self.pointer, value)
        }

        func appendU64(value: UInt64, minDigits: Int) {
            SkString_appendU64(self.pointer, value, Int32(minDigits))
        }

        func appendHex(value: UInt32, minDigits: Int) {
            SkString_appendHex(self.pointer, value, Int32(minDigits))
        }

        func appendScalar(value: Float) {
            SkString_appendScalar(self.pointer, value)
        }

        func prepend(text: UnsafePointer<CChar>?) {
            SkString_prepend(self.pointer, text)
        }

        func prepend(text: UnsafePointer<CChar>?, len: UInt) {
            SkString_prepend_2(self.pointer, text, len)
        }

        func prepend(str: SkString) {
            SkString_prepend_3(self.pointer, str.pointer)
        }

        func prepend(str: StringView) {
            SkString_prepend_4(self.pointer, str.handle)
        }

        func prependUnichar(uni: Int) {
            SkString_prependUnichar(self.pointer, Int32(uni))
        }

        func prependS32(value: Int32) {
            SkString_prependS32(self.pointer, value)
        }

        func prependS64(value: Int32, minDigits: Int) {
            SkString_prependS64(self.pointer, value, Int32(minDigits))
        }

        func prependHex(value: UInt, minDigits: Int) {
            SkString_prependHex(self.pointer, UInt32(value), Int32(minDigits))
        }

        func prependScalar(value: Float) {
            SkString_prependScalar(self.pointer, value)
        }

        // void SkString_printf(SkString *string, const char format[],...);

        func printf(format: String, _ args: CVarArg...) {
            withVaList(args) { vaList in
                SkString_printVAList(self.pointer, format, vaList)
            }
        }

        // void SkString_appendf(SkString *string, const char format[],...);

        func appendf(format: String, _ args: CVarArg...) {
            withVaList(args) { vaList in
                SkString_appendVAList(self.pointer, format, vaList)
            }
        }

        // void SkString_prependf(SkString *string, const char format[],...);

        func prependf(format: String, _ args: CVarArg...) {
            withVaList(args) { vaList in
                SkString_prependVAList(self.pointer, format, vaList)
            }
        }

        func remove(offset: UInt, length: UInt) {
            SkString_remove(self.pointer, offset, length)
        }

        func swap(other: SkString) {
            SkString_swap(self.pointer, other.pointer)
        }
    }
}