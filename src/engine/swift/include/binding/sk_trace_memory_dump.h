//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TRACE_MEMORY_DUMP_H
#define RAIA_SKIA_SK_TRACE_MEMORY_DUMP_H

#include "include/core/SkTraceMemoryDump.h"

extern "C" {
void SkTraceMemoryDump_delete(SkTraceMemoryDump * traceMemoryDump);
void SkTraceMemoryDump_dumpNumericValue(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *valueName, const char *units, uint64_t value);
void SkTraceMemoryDump_dumpStringValue(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *str1, const char *str2);
void SkTraceMemoryDump_setMemoryBacking(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *backingType, const char *backingObjectId);
void SkTraceMemoryDump_setDiscardableMemoryBacking(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const SkDiscardableMemory *discardableMemoryObject);
SkTraceMemoryDump::LevelOfDetail SkTraceMemoryDump_getRequestedDetails(SkTraceMemoryDump *trace_memory_dump);
bool SkTraceMemoryDump_shouldDumpWrappedObjects(SkTraceMemoryDump *trace_memory_dump);
void SkTraceMemoryDump_dumpWrappedState(SkTraceMemoryDump *trace_memory_dump, const char *str, bool b);
bool SkTraceMemoryDump_shouldDumpUnbudgetedObjects(SkTraceMemoryDump *trace_memory_dump);
void SkTraceMemoryDump_dumpBudgetedState(SkTraceMemoryDump *trace_memory_dump, const char *str, bool b);
}

#endif //RAIA_SKIA_SK_TRACE_MEMORY_DUMP_H
