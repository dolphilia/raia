//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TRACE_MEMORY_DUMP_H
#define RAIA_SKIA_SK_TRACE_MEMORY_DUMP_H

#ifdef __cplusplus
extern "C" {
#endif

void SkTraceMemoryDump_delete(void *traceMemoryDump); // (SkTraceMemoryDump *traceMemoryDump)
void SkTraceMemoryDump_dumpNumericValue(void *trace_memory_dump, const char *dumpName, const char *valueName, const char *units, unsigned long long value); // (SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *valueName, const char *units, uint64_t value)
void SkTraceMemoryDump_dumpStringValue(void *trace_memory_dump, const char *dumpName, const char *str1, const char *str2); // (SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *str1, const char *str2)
void SkTraceMemoryDump_setMemoryBacking(void *trace_memory_dump, const char *dumpName, const char *backingType, const char *backingObjectId); // (SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *backingType, const char *backingObjectId)
void SkTraceMemoryDump_setDiscardableMemoryBacking(void *trace_memory_dump, const char *dumpName, const void *discardableMemoryObject); // (SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const SkDiscardableMemory *discardableMemoryObject)
int SkTraceMemoryDump_getRequestedDetails(void *trace_memory_dump); // (SkTraceMemoryDump *trace_memory_dump) -> SkTraceMemoryDump::LevelOfDetail
bool SkTraceMemoryDump_shouldDumpWrappedObjects(void *trace_memory_dump); // (SkTraceMemoryDump *trace_memory_dump) -> bool
void SkTraceMemoryDump_dumpWrappedState(void *trace_memory_dump, const char *str, bool b); // (SkTraceMemoryDump *trace_memory_dump, const char *str, bool b)
bool SkTraceMemoryDump_shouldDumpUnbudgetedObjects(void *trace_memory_dump); // (SkTraceMemoryDump *trace_memory_dump) -> bool
void SkTraceMemoryDump_dumpBudgetedState(void *trace_memory_dump, const char *str, bool b); // (SkTraceMemoryDump *trace_memory_dump, const char *str, bool b)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_TRACE_MEMORY_DUMP_H
