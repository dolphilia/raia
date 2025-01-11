//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TRACE_MEMORY_DUMP_H
#define RAIA_SKIA_SK_TRACE_MEMORY_DUMP_H

#include "include/core/SkTraceMemoryDump.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkTraceMemoryDump_delete(SkTraceMemoryDump * traceMemoryDump);
RAIA_API void SkTraceMemoryDump_dumpNumericValue(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *valueName, const char *units, uint64_t value);
RAIA_API void SkTraceMemoryDump_dumpStringValue(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *str1, const char *str2);
RAIA_API void SkTraceMemoryDump_setMemoryBacking(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *backingType, const char *backingObjectId);
RAIA_API void SkTraceMemoryDump_setDiscardableMemoryBacking(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const SkDiscardableMemory *discardableMemoryObject);
RAIA_API SkTraceMemoryDump::LevelOfDetail SkTraceMemoryDump_getRequestedDetails(SkTraceMemoryDump *trace_memory_dump);
RAIA_API bool SkTraceMemoryDump_shouldDumpWrappedObjects(SkTraceMemoryDump *trace_memory_dump);
RAIA_API void SkTraceMemoryDump_dumpWrappedState(SkTraceMemoryDump *trace_memory_dump, const char *str, bool b);
RAIA_API bool SkTraceMemoryDump_shouldDumpUnbudgetedObjects(SkTraceMemoryDump *trace_memory_dump);
RAIA_API void SkTraceMemoryDump_dumpBudgetedState(SkTraceMemoryDump *trace_memory_dump, const char *str, bool b);
}

#endif //RAIA_SKIA_SK_TRACE_MEMORY_DUMP_H
