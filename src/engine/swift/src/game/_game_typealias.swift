extension GLES {
    typealias GLDEBUGPROC = @convention(c) (UInt32, UInt32, UInt32, UInt32, Int32, UnsafePointer<CChar>?, UnsafeRawPointer?) -> Void
}