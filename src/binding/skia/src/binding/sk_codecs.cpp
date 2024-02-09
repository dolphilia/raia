//
// Created by dolphilia on 2024/02/02.
//

#include "sk_codecs.h"

/*
namespace SkCodecs {

    using DecodeContext = void*;
    using IsFormatCallback = bool (*)(const void* data, size_t len);
    using MakeFromStreamCallback = std::unique_ptr<SkCodec> (*)(std::unique_ptr<SkStream>, SkCodec::Result*, DecodeContext);

    struct SK_API Decoder {
            // By convention, we use all lowercase letters and go with the primary filename extension.
            // For example "png", "jpg", "ico", "webp", etc
            std::string id;
            IsFormatCallback isFormat;
            MakeFromStreamCallback makeFromStream;
    };

// Add the decoder to the end of a linked list of decoders, which will be used to identify calls to
// SkCodec::MakeFromStream. If a decoder with the same id already exists, this new decoder
// will replace the existing one (in the same position). This is not thread-safe, so make sure all
// initialization is done before the first call.
    void SK_API Register(Decoder d);
}
 */