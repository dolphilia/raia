//
// Created by dolphilia on 2024/01/11.
//

#include "sk_trace_memory_dump.h"

extern "C" {

void SkTraceMemoryDump_delete(SkTraceMemoryDump * traceMemoryDump) {
    delete &traceMemoryDump;
}

void SkTraceMemoryDump_dumpNumericValue(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *valueName, const char *units, uint64_t value) {
    trace_memory_dump->dumpNumericValue(dumpName, valueName, units, value);
}

void SkTraceMemoryDump_dumpStringValue(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *str1, const char *str2) {
    trace_memory_dump->dumpStringValue(dumpName, str1, str2);
}

void SkTraceMemoryDump_setMemoryBacking(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *backingType, const char *backingObjectId) {
    trace_memory_dump->setMemoryBacking(dumpName, backingType, backingObjectId);
}

void SkTraceMemoryDump_setDiscardableMemoryBacking(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const SkDiscardableMemory *discardableMemoryObject) {
    trace_memory_dump->setDiscardableMemoryBacking(dumpName, *discardableMemoryObject);
}

SkTraceMemoryDump::LevelOfDetail SkTraceMemoryDump_getRequestedDetails(SkTraceMemoryDump *trace_memory_dump) {
    return trace_memory_dump->getRequestedDetails();
}

bool SkTraceMemoryDump_shouldDumpWrappedObjects(SkTraceMemoryDump *trace_memory_dump) {
    return trace_memory_dump->shouldDumpWrappedObjects();
}

void SkTraceMemoryDump_dumpWrappedState(SkTraceMemoryDump *trace_memory_dump, const char *str, bool b) {
    trace_memory_dump->dumpWrappedState(str, b);
}

bool SkTraceMemoryDump_shouldDumpUnbudgetedObjects(SkTraceMemoryDump *trace_memory_dump) {
    return trace_memory_dump->shouldDumpUnbudgetedObjects();
}

void SkTraceMemoryDump_dumpBudgetedState(SkTraceMemoryDump *trace_memory_dump, const char *str, bool b) {
    trace_memory_dump->dumpBudgetedState(str, b);
}

}