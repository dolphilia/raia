//
// Created by dolphilia on 24/08/09.
//

#include "raia_miniaudio.h"

// Version

void raia_ma_version(ma_uint32* pMajor, ma_uint32* pMinor, ma_uint32* pRevision) {
    ma_version(pMajor, pMinor, pRevision);
}

const char* raia_ma_version_string(void) {
    return ma_version_string();
}

// Logging

ma_log_callback raia_ma_log_callback_init(ma_log_callback_proc onLog, void* pUserData) {
    return ma_log_callback_init(onLog, pUserData);
}

ma_result raia_ma_log_init(const ma_allocation_callbacks* pAllocationCallbacks, ma_log* pLog) {
    return ma_log_init(pAllocationCallbacks, pLog);
}

void raia_ma_log_uninit(ma_log* pLog) {
    ma_log_uninit(pLog);
}

ma_result raia_ma_log_register_callback(ma_log* pLog, ma_log_callback callback) {
    return ma_log_register_callback(pLog, callback);
}

ma_result raia_ma_log_unregister_callback(ma_log* pLog, ma_log_callback callback) {
    return ma_log_unregister_callback(pLog, callback);
}

ma_result raia_ma_log_post(ma_log* pLog, ma_uint32 level, const char* pMessage) {
    return ma_log_post(pLog, level, pMessage);
}

ma_result raia_ma_log_postv(ma_log* pLog, ma_uint32 level, const char* pFormat, va_list args) {
    return ma_log_postv(pLog, level, pFormat, args);
}

// TODO
//ma_result ma_log_postf(ma_log* pLog, ma_uint32 level, const char* pFormat, ...) {
//    return ma_log_postf(pLog, level, pFormat)
//}

// Biquad Filtering

ma_biquad_config raia_ma_biquad_config_init(ma_format format, ma_uint32 channels, double b0, double b1, double b2, double a0, double a1, double a2) {
    return ma_biquad_config_init(format, channels, b0, b1, b2, a0, a1, a2);
}

ma_result raia_ma_biquad_get_heap_size(const ma_biquad_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_biquad_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_biquad_init_preallocated(const ma_biquad_config* pConfig, void* pHeap, ma_biquad* pBQ) {
    return ma_biquad_init_preallocated(pConfig, pHeap, pBQ);
}

ma_result raia_ma_biquad_init(const ma_biquad_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_biquad* pBQ) {
    return ma_biquad_init(pConfig, pAllocationCallbacks, pBQ);
}

void raia_ma_biquad_uninit(ma_biquad* pBQ, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_biquad_uninit(pBQ, pAllocationCallbacks);
}

ma_result raia_ma_biquad_reinit(const ma_biquad_config* pConfig, ma_biquad* pBQ) {
    return ma_biquad_reinit(pConfig, pBQ);
}

ma_result raia_ma_biquad_clear_cache(ma_biquad* pBQ) {
    return ma_biquad_clear_cache(pBQ);
}

ma_result raia_ma_biquad_process_pcm_frames(ma_biquad* pBQ, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_biquad_process_pcm_frames(pBQ, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_biquad_get_latency(const ma_biquad* pBQ) {
    return ma_biquad_get_latency(pBQ);
}

// Low-Pass Filtering

ma_lpf1_config raia_ma_lpf1_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency) {
    return ma_lpf1_config_init(format, channels, sampleRate, cutoffFrequency);
}

ma_lpf2_config raia_ma_lpf2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, double q) {
    return ma_lpf2_config_init(format, channels, sampleRate, cutoffFrequency, q);
}

ma_result raia_ma_lpf1_get_heap_size(const ma_lpf1_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_lpf1_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_lpf1_init_preallocated(const ma_lpf1_config* pConfig, void* pHeap, ma_lpf1* pLPF) {
    return ma_lpf1_init_preallocated(pConfig, pHeap, pLPF);
}

ma_result raia_ma_lpf1_init(const ma_lpf1_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_lpf1* pLPF) {
    return ma_lpf1_init(pConfig, pAllocationCallbacks, pLPF);
}

void raia_ma_lpf1_uninit(ma_lpf1* pLPF, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_lpf1_uninit(pLPF, pAllocationCallbacks);
}

ma_result raia_ma_lpf1_reinit(const ma_lpf1_config* pConfig, ma_lpf1* pLPF) {
    return ma_lpf1_reinit(pConfig, pLPF);
}

ma_result raia_ma_lpf1_clear_cache(ma_lpf1* pLPF) {
    return ma_lpf1_clear_cache(pLPF);
}

ma_result raia_ma_lpf1_process_pcm_frames(ma_lpf1* pLPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_lpf1_process_pcm_frames(pLPF, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_lpf1_get_latency(const ma_lpf1* pLPF) {
    return ma_lpf1_get_latency(pLPF);
}

ma_result raia_ma_lpf2_get_heap_size(const ma_lpf2_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_lpf2_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_lpf2_init_preallocated(const ma_lpf2_config* pConfig, void* pHeap, ma_lpf2* pHPF) {
    return ma_lpf2_init_preallocated(pConfig, pHeap, pHPF);
}

ma_result raia_ma_lpf2_init(const ma_lpf2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_lpf2* pLPF) {
    return ma_lpf2_init(pConfig, pAllocationCallbacks, pLPF);
}

void raia_ma_lpf2_uninit(ma_lpf2* pLPF, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_lpf2_uninit(pLPF, pAllocationCallbacks);
}

ma_result raia_ma_lpf2_reinit(const ma_lpf2_config* pConfig, ma_lpf2* pLPF) {
    return ma_lpf2_reinit(pConfig, pLPF);
}

ma_result raia_ma_lpf2_clear_cache(ma_lpf2* pLPF) {
    return ma_lpf2_clear_cache(pLPF);
}

ma_result raia_ma_lpf2_process_pcm_frames(ma_lpf2* pLPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_lpf2_process_pcm_frames(pLPF, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_lpf2_get_latency(const ma_lpf2* pLPF) {
    return ma_lpf2_get_latency(pLPF);
}

ma_lpf_config raia_ma_lpf_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order) {
    return ma_lpf_config_init(format, channels, sampleRate, cutoffFrequency, order);
}

ma_result raia_ma_lpf_get_heap_size(const ma_lpf_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_lpf_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_lpf_init_preallocated(const ma_lpf_config* pConfig, void* pHeap, ma_lpf* pLPF) {
    return ma_lpf_init_preallocated(pConfig, pHeap, pLPF);
}

ma_result raia_ma_lpf_init(const ma_lpf_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_lpf* pLPF) {
    return ma_lpf_init(pConfig, pAllocationCallbacks, pLPF);
}

void raia_ma_lpf_uninit(ma_lpf* pLPF, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_lpf_uninit(pLPF, pAllocationCallbacks);
}

ma_result raia_ma_lpf_reinit(const ma_lpf_config* pConfig, ma_lpf* pLPF) {
    return ma_lpf_reinit(pConfig, pLPF);
}

ma_result raia_ma_lpf_clear_cache(ma_lpf* pLPF) {
    return ma_lpf_clear_cache(pLPF);
}

ma_result raia_ma_lpf_process_pcm_frames(ma_lpf* pLPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_lpf_process_pcm_frames(pLPF, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_lpf_get_latency(const ma_lpf* pLPF) {
    return ma_lpf_get_latency(pLPF);
}

// High-Pass Filtering

ma_hpf1_config raia_ma_hpf1_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency) {
    return ma_hpf1_config_init(format, channels, sampleRate, cutoffFrequency);
}

ma_hpf2_config raia_ma_hpf2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, double q) {
    return ma_hpf2_config_init(format, channels, sampleRate, cutoffFrequency, q);
}

ma_result raia_ma_hpf1_get_heap_size(const ma_hpf1_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_hpf1_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_hpf1_init_preallocated(const ma_hpf1_config* pConfig, void* pHeap, ma_hpf1* pLPF) {
    return ma_hpf1_init_preallocated(pConfig, pHeap, pLPF);
}

ma_result raia_ma_hpf1_init(const ma_hpf1_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hpf1* pHPF) {
    return ma_hpf1_init(pConfig, pAllocationCallbacks, pHPF);
}

void raia_ma_hpf1_uninit(ma_hpf1* pHPF, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_hpf1_uninit(pHPF, pAllocationCallbacks);
}

ma_result raia_ma_hpf1_reinit(const ma_hpf1_config* pConfig, ma_hpf1* pHPF) {
    return ma_hpf1_reinit(pConfig, pHPF);
}

ma_result raia_ma_hpf1_process_pcm_frames(ma_hpf1* pHPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_hpf1_process_pcm_frames(pHPF, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_hpf1_get_latency(const ma_hpf1* pHPF) {
    return ma_hpf1_get_latency(pHPF);
}

ma_result raia_ma_hpf2_get_heap_size(const ma_hpf2_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_hpf2_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_hpf2_init_preallocated(const ma_hpf2_config* pConfig, void* pHeap, ma_hpf2* pHPF) {
    return ma_hpf2_init_preallocated(pConfig, pHeap, pHPF);
}

ma_result raia_ma_hpf2_init(const ma_hpf2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hpf2* pHPF) {
    return ma_hpf2_init(pConfig, pAllocationCallbacks, pHPF);
}

void raia_ma_hpf2_uninit(ma_hpf2* pHPF, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_hpf2_uninit(pHPF, pAllocationCallbacks);
}

ma_result raia_ma_hpf2_reinit(const ma_hpf2_config* pConfig, ma_hpf2* pHPF) {
    return ma_hpf2_reinit(pConfig, pHPF);
}

ma_result raia_ma_hpf2_process_pcm_frames(ma_hpf2* pHPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_hpf2_process_pcm_frames(pHPF, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_hpf2_get_latency(const ma_hpf2* pHPF) {
    return ma_hpf2_get_latency(pHPF);
}

ma_hpf_config raia_ma_hpf_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order) {
    return ma_hpf_config_init(format, channels, sampleRate, cutoffFrequency, order);
}

ma_result raia_ma_hpf_get_heap_size(const ma_hpf_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_hpf_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_hpf_init_preallocated(const ma_hpf_config* pConfig, void* pHeap, ma_hpf* pLPF) {
    return ma_hpf_init_preallocated(pConfig, pHeap, pLPF);
}

ma_result raia_ma_hpf_init(const ma_hpf_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hpf* pHPF) {
    return ma_hpf_init(pConfig, pAllocationCallbacks, pHPF);
}

void raia_ma_hpf_uninit(ma_hpf* pHPF, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_hpf_uninit(pHPF, pAllocationCallbacks);
}

ma_result raia_ma_hpf_reinit(const ma_hpf_config* pConfig, ma_hpf* pHPF) {
    return ma_hpf_reinit(pConfig, pHPF);
}

ma_result raia_ma_hpf_process_pcm_frames(ma_hpf* pHPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_hpf_process_pcm_frames(pHPF, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_hpf_get_latency(const ma_hpf* pHPF) {
    return ma_hpf_get_latency(pHPF);
}

// Band-Pass Filtering

ma_bpf2_config raia_ma_bpf2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, double q) {
    return ma_bpf2_config_init(format, channels, sampleRate, cutoffFrequency, q);
}

ma_result raia_ma_bpf2_get_heap_size(const ma_bpf2_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_bpf2_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_bpf2_init_preallocated(const ma_bpf2_config* pConfig, void* pHeap, ma_bpf2* pBPF) {
    return ma_bpf2_init_preallocated(pConfig, pHeap, pBPF);
}

ma_result raia_ma_bpf2_init(const ma_bpf2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_bpf2* pBPF) {
    return ma_bpf2_init(pConfig, pAllocationCallbacks, pBPF);
}

void raia_ma_bpf2_uninit(ma_bpf2* pBPF, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_bpf2_uninit(pBPF, pAllocationCallbacks);
}

ma_result raia_ma_bpf2_reinit(const ma_bpf2_config* pConfig, ma_bpf2* pBPF) {
    return ma_bpf2_reinit(pConfig, pBPF);
}

ma_result raia_ma_bpf2_process_pcm_frames(ma_bpf2* pBPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_bpf2_process_pcm_frames(pBPF, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_bpf2_get_latency(const ma_bpf2* pBPF) {
    return ma_bpf2_get_latency(pBPF);
}

ma_bpf_config raia_ma_bpf_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order) {
    return ma_bpf_config_init(format, channels, sampleRate, cutoffFrequency, order);
}

ma_result raia_ma_bpf_get_heap_size(const ma_bpf_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_bpf_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_bpf_init_preallocated(const ma_bpf_config* pConfig, void* pHeap, ma_bpf* pBPF) {
    return ma_bpf_init_preallocated(pConfig, pHeap, pBPF);
}

ma_result raia_ma_bpf_init(const ma_bpf_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_bpf* pBPF) {
    return ma_bpf_init(pConfig, pAllocationCallbacks, pBPF);
}

void raia_ma_bpf_uninit(ma_bpf* pBPF, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_bpf_uninit(pBPF, pAllocationCallbacks);
}

ma_result raia_ma_bpf_reinit(const ma_bpf_config* pConfig, ma_bpf* pBPF) {
    return ma_bpf_reinit(pConfig, pBPF);
}

ma_result raia_ma_bpf_process_pcm_frames(ma_bpf* pBPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_bpf_process_pcm_frames(pBPF, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_bpf_get_latency(const ma_bpf* pBPF) {
    return ma_bpf_get_latency(pBPF);
}

// Notching Filter

ma_notch2_config raia_ma_notch2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double q, double frequency) {
    return ma_notch2_config_init(format, channels, sampleRate, q, frequency);
}

ma_result raia_ma_notch2_get_heap_size(const ma_notch2_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_notch2_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_notch2_init_preallocated(const ma_notch2_config* pConfig, void* pHeap, ma_notch2* pFilter) {
    return ma_notch2_init_preallocated(pConfig, pHeap, pFilter);
}

ma_result raia_ma_notch2_init(const ma_notch2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_notch2* pFilter) {
    return ma_notch2_init(pConfig, pAllocationCallbacks, pFilter);
}

void raia_ma_notch2_uninit(ma_notch2* pFilter, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_notch2_uninit(pFilter, pAllocationCallbacks);
}

ma_result raia_ma_notch2_reinit(const ma_notch2_config* pConfig, ma_notch2* pFilter) {
    return ma_notch2_reinit(pConfig, pFilter);
}

ma_result raia_ma_notch2_process_pcm_frames(ma_notch2* pFilter, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_notch2_process_pcm_frames(pFilter, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_notch2_get_latency(const ma_notch2* pFilter) {
    return ma_notch2_get_latency(pFilter);
}

// Peaking EQ Filter

ma_peak2_config raia_ma_peak2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double q, double frequency) {
    return ma_peak2_config_init(format, channels, sampleRate, gainDB, q, frequency);
}

ma_result raia_ma_peak2_get_heap_size(const ma_peak2_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_peak2_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_peak2_init_preallocated(const ma_peak2_config* pConfig, void* pHeap, ma_peak2* pFilter) {
    return ma_peak2_init_preallocated(pConfig, pHeap, pFilter);
}

ma_result raia_ma_peak2_init(const ma_peak2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_peak2* pFilter) {
    return ma_peak2_init(pConfig, pAllocationCallbacks, pFilter);
}

void raia_ma_peak2_uninit(ma_peak2* pFilter, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_peak2_uninit(pFilter, pAllocationCallbacks);
}

ma_result raia_ma_peak2_reinit(const ma_peak2_config* pConfig, ma_peak2* pFilter) {
    return ma_peak2_reinit(pConfig, pFilter);
}

ma_result raia_ma_peak2_process_pcm_frames(ma_peak2* pFilter, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_peak2_process_pcm_frames(pFilter, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_peak2_get_latency(const ma_peak2* pFilter) {
    return ma_peak2_get_latency(pFilter);
}

// Low Shelf Filter

ma_loshelf2_config raia_ma_loshelf2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double shelfSlope, double frequency) {
    return ma_loshelf2_config_init(format, channels, sampleRate, gainDB, shelfSlope, frequency);
}

ma_result raia_ma_loshelf2_get_heap_size(const ma_loshelf2_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_loshelf2_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_loshelf2_init_preallocated(const ma_loshelf2_config* pConfig, void* pHeap, ma_loshelf2* pFilter) {
    return ma_loshelf2_init_preallocated(pConfig, pHeap, pFilter);
}

ma_result raia_ma_loshelf2_init(const ma_loshelf2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_loshelf2* pFilter) {
    return ma_loshelf2_init(pConfig, pAllocationCallbacks, pFilter);
}

void raia_ma_loshelf2_uninit(ma_loshelf2* pFilter, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_loshelf2_uninit(pFilter, pAllocationCallbacks);
}

ma_result raia_ma_loshelf2_reinit(const ma_loshelf2_config* pConfig, ma_loshelf2* pFilter) {
    return ma_loshelf2_reinit(pConfig, pFilter);
}

ma_result raia_ma_loshelf2_process_pcm_frames(ma_loshelf2* pFilter, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_loshelf2_process_pcm_frames(pFilter, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_loshelf2_get_latency(const ma_loshelf2* pFilter) {
    return ma_loshelf2_get_latency(pFilter);
}

// High Shelf Filter

ma_hishelf2_config raia_ma_hishelf2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double shelfSlope, double frequency) {
    return ma_hishelf2_config_init(format, channels, sampleRate, gainDB, shelfSlope, frequency);
}

ma_result raia_ma_hishelf2_get_heap_size(const ma_hishelf2_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_hishelf2_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_hishelf2_init_preallocated(const ma_hishelf2_config* pConfig, void* pHeap, ma_hishelf2* pFilter) {
    return ma_hishelf2_init_preallocated(pConfig, pHeap, pFilter);
}

ma_result raia_ma_hishelf2_init(const ma_hishelf2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hishelf2* pFilter) {
    return ma_hishelf2_init(pConfig, pAllocationCallbacks, pFilter);
}

void raia_ma_hishelf2_uninit(ma_hishelf2* pFilter, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_hishelf2_uninit(pFilter, pAllocationCallbacks);
}

ma_result raia_ma_hishelf2_reinit(const ma_hishelf2_config* pConfig, ma_hishelf2* pFilter) {
    return ma_hishelf2_reinit(pConfig, pFilter);
}

ma_result raia_ma_hishelf2_process_pcm_frames(ma_hishelf2* pFilter, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_hishelf2_process_pcm_frames(pFilter, pFramesOut, pFramesIn, frameCount);
}

ma_uint32 raia_ma_hishelf2_get_latency(const ma_hishelf2* pFilter) {
    return ma_hishelf2_get_latency(pFilter);
}

// (Delay)

ma_delay_config raia_ma_delay_config_init(ma_uint32 channels, ma_uint32 sampleRate, ma_uint32 delayInFrames, float decay) {
    return ma_delay_config_init(channels, sampleRate, delayInFrames, decay);
}

ma_result raia_ma_delay_init(const ma_delay_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_delay* pDelay) {
    return ma_delay_init(pConfig, pAllocationCallbacks, pDelay);
}

void raia_ma_delay_uninit(ma_delay* pDelay, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_delay_uninit(pDelay, pAllocationCallbacks);
}

ma_result raia_ma_delay_process_pcm_frames(ma_delay* pDelay, void* pFramesOut, const void* pFramesIn, ma_uint32 frameCount) {
    return ma_delay_process_pcm_frames(pDelay, pFramesOut, pFramesIn, frameCount);
}

void raia_ma_delay_set_wet(ma_delay* pDelay, float value) {
    ma_delay_set_wet(pDelay, value);
}

float raia_ma_delay_get_wet(const ma_delay* pDelay) {
    return ma_delay_get_wet(pDelay);
}

void raia_ma_delay_set_dry(ma_delay* pDelay, float value) {
    ma_delay_set_dry(pDelay, value);
}

float raia_ma_delay_get_dry(const ma_delay* pDelay) {
    return ma_delay_get_dry(pDelay);
}

void raia_ma_delay_set_decay(ma_delay* pDelay, float value) {
    ma_delay_set_decay(pDelay, value);
}

float raia_ma_delay_get_decay(const ma_delay* pDelay) {
    return ma_delay_get_decay(pDelay);
}

// (Gainer)

ma_gainer_config raia_ma_gainer_config_init(ma_uint32 channels, ma_uint32 smoothTimeInFrames) {
    return ma_gainer_config_init(channels, smoothTimeInFrames);
}

ma_result raia_ma_gainer_get_heap_size(const ma_gainer_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_gainer_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_gainer_init_preallocated(const ma_gainer_config* pConfig, void* pHeap, ma_gainer* pGainer) {
    return ma_gainer_init_preallocated(pConfig, pHeap, pGainer);
}

ma_result raia_ma_gainer_init(const ma_gainer_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_gainer* pGainer) {
    return ma_gainer_init(pConfig, pAllocationCallbacks, pGainer);
}

void raia_ma_gainer_uninit(ma_gainer* pGainer, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_gainer_uninit(pGainer, pAllocationCallbacks);
}

ma_result raia_ma_gainer_process_pcm_frames(ma_gainer* pGainer, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_gainer_process_pcm_frames(pGainer, pFramesOut, pFramesIn, frameCount);
}

ma_result raia_ma_gainer_set_gain(ma_gainer* pGainer, float newGain) {
    return ma_gainer_set_gain(pGainer, newGain);
}

ma_result raia_ma_gainer_set_gains(ma_gainer* pGainer, float* pNewGains) {
    return ma_gainer_set_gains(pGainer, pNewGains);
}

ma_result raia_ma_gainer_set_master_volume(ma_gainer* pGainer, float volume) {
    return ma_gainer_set_master_volume(pGainer, volume);
}

ma_result raia_ma_gainer_get_master_volume(const ma_gainer* pGainer, float* pVolume) {
    return ma_gainer_get_master_volume(pGainer, pVolume);
}

// (Stereo panner)

ma_panner_config raia_ma_panner_config_init(ma_format format, ma_uint32 channels) {
    return ma_panner_config_init(format, channels);
}

ma_result raia_ma_panner_init(const ma_panner_config* pConfig, ma_panner* pPanner) {
    return ma_panner_init(pConfig, pPanner);
}

ma_result raia_ma_panner_process_pcm_frames(ma_panner* pPanner, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_panner_process_pcm_frames(pPanner, pFramesOut, pFramesIn, frameCount);
}

void raia_ma_panner_set_mode(ma_panner* pPanner, ma_pan_mode mode) {
    ma_panner_set_mode(pPanner, mode);
}

ma_pan_mode raia_ma_panner_get_mode(const ma_panner* pPanner) {
    return ma_panner_get_mode(pPanner);
}

void raia_ma_panner_set_pan(ma_panner* pPanner, float pan) {
    ma_panner_set_pan(pPanner, pan);
}

float raia_ma_panner_get_pan(const ma_panner* pPanner) {
    return ma_panner_get_pan(pPanner);
}

// (Fader)

ma_fader_config raia_ma_fader_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate) {
    return ma_fader_config_init(format, channels, sampleRate);
}

ma_result raia_ma_fader_init(const ma_fader_config* pConfig, ma_fader* pFader) {
    return ma_fader_init(pConfig, pFader);
}

ma_result raia_ma_fader_process_pcm_frames(ma_fader* pFader, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_fader_process_pcm_frames(pFader, pFramesOut, pFramesIn, frameCount);
}

void raia_ma_fader_get_data_format(const ma_fader* pFader, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate) {
    ma_fader_get_data_format(pFader, pFormat, pChannels, pSampleRate);
}

void raia_ma_fader_set_fade(ma_fader* pFader, float volumeBeg, float volumeEnd, ma_uint64 lengthInFrames) {
    ma_fader_set_fade(pFader, volumeBeg, volumeEnd, lengthInFrames);
}

void raia_ma_fader_set_fade_ex(ma_fader* pFader, float volumeBeg, float volumeEnd, ma_uint64 lengthInFrames, ma_int64 startOffsetInFrames) {
    ma_fader_set_fade_ex(pFader, volumeBeg, volumeEnd, lengthInFrames, startOffsetInFrames);
}

float raia_ma_fader_get_current_volume(const ma_fader* pFader) {
    return ma_fader_get_current_volume(pFader);
}


// (Spatializer)

ma_spatializer_listener_config raia_ma_spatializer_listener_config_init(ma_uint32 channelsOut) {
    return ma_spatializer_listener_config_init(channelsOut);
}

ma_result raia_ma_spatializer_listener_get_heap_size(const ma_spatializer_listener_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_spatializer_listener_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_spatializer_listener_init_preallocated(const ma_spatializer_listener_config* pConfig, void* pHeap, ma_spatializer_listener* pListener) {
    return ma_spatializer_listener_init_preallocated(pConfig, pHeap, pListener);
}

ma_result raia_ma_spatializer_listener_init(const ma_spatializer_listener_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_spatializer_listener* pListener) {
    return ma_spatializer_listener_init(pConfig, pAllocationCallbacks, pListener);
}

void raia_ma_spatializer_listener_uninit(ma_spatializer_listener* pListener, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_spatializer_listener_uninit(pListener, pAllocationCallbacks);
}

ma_channel* raia_ma_spatializer_listener_get_channel_map(ma_spatializer_listener* pListener) {
    return ma_spatializer_listener_get_channel_map(pListener);
}

void raia_ma_spatializer_listener_set_cone(ma_spatializer_listener* pListener, float innerAngleInRadians, float outerAngleInRadians, float outerGain) {
    ma_spatializer_listener_set_cone(pListener, innerAngleInRadians, outerAngleInRadians, outerGain);
}

void raia_ma_spatializer_listener_get_cone(const ma_spatializer_listener* pListener, float* pInnerAngleInRadians, float* pOuterAngleInRadians, float* pOuterGain) {
    ma_spatializer_listener_get_cone(pListener, pInnerAngleInRadians, pOuterAngleInRadians, pOuterGain);
}

void raia_ma_spatializer_listener_set_position(ma_spatializer_listener* pListener, float x, float y, float z) {
    ma_spatializer_listener_set_position(pListener, x, y, z);
}

ma_vec3f raia_ma_spatializer_listener_get_position(const ma_spatializer_listener* pListener) {
    return ma_spatializer_listener_get_position(pListener);
}

void raia_ma_spatializer_listener_set_direction(ma_spatializer_listener* pListener, float x, float y, float z) {
    ma_spatializer_listener_set_direction(pListener, x, y, z);
}

ma_vec3f raia_ma_spatializer_listener_get_direction(const ma_spatializer_listener* pListener) {
    return ma_spatializer_listener_get_direction(pListener);
}

void raia_ma_spatializer_listener_set_velocity(ma_spatializer_listener* pListener, float x, float y, float z) {
    ma_spatializer_listener_set_velocity(pListener, x, y, z);
}

ma_vec3f raia_ma_spatializer_listener_get_velocity(const ma_spatializer_listener* pListener) {
    return ma_spatializer_listener_get_velocity(pListener);
}

void raia_ma_spatializer_listener_set_speed_of_sound(ma_spatializer_listener* pListener, float speedOfSound) {
    ma_spatializer_listener_set_speed_of_sound(pListener, speedOfSound);
}

float raia_ma_spatializer_listener_get_speed_of_sound(const ma_spatializer_listener* pListener) {
    return ma_spatializer_listener_get_speed_of_sound(pListener);
}

void raia_ma_spatializer_listener_set_world_up(ma_spatializer_listener* pListener, float x, float y, float z) {
    ma_spatializer_listener_set_world_up(pListener, x, y, z);
}

ma_vec3f raia_ma_spatializer_listener_get_world_up(const ma_spatializer_listener* pListener) {
    return ma_spatializer_listener_get_world_up(pListener);
}

void raia_ma_spatializer_listener_set_enabled(ma_spatializer_listener* pListener, ma_bool32 isEnabled) {
    ma_spatializer_listener_set_enabled(pListener, isEnabled);
}

ma_bool32 raia_ma_spatializer_listener_is_enabled(const ma_spatializer_listener* pListener) {
    return ma_spatializer_listener_is_enabled(pListener);
}

ma_spatializer_config raia_ma_spatializer_config_init(ma_uint32 channelsIn, ma_uint32 channelsOut) {
    return ma_spatializer_config_init(channelsIn, channelsOut);
}

ma_result raia_ma_spatializer_get_heap_size(const ma_spatializer_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_spatializer_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_spatializer_init_preallocated(const ma_spatializer_config* pConfig, void* pHeap, ma_spatializer* pSpatializer) {
    return ma_spatializer_init_preallocated(pConfig, pHeap, pSpatializer);
}

ma_result raia_ma_spatializer_init(const ma_spatializer_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_spatializer* pSpatializer) {
    return ma_spatializer_init(pConfig, pAllocationCallbacks, pSpatializer);
}

void raia_ma_spatializer_uninit(ma_spatializer* pSpatializer, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_spatializer_uninit(pSpatializer, pAllocationCallbacks);
}

ma_result raia_ma_spatializer_process_pcm_frames(ma_spatializer* pSpatializer, ma_spatializer_listener* pListener, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_spatializer_process_pcm_frames(pSpatializer, pListener, pFramesOut, pFramesIn, frameCount);
}

ma_result raia_ma_spatializer_set_master_volume(ma_spatializer* pSpatializer, float volume) {
    return ma_spatializer_set_master_volume(pSpatializer, volume);
}

ma_result raia_ma_spatializer_get_master_volume(const ma_spatializer* pSpatializer, float* pVolume) {
    return ma_spatializer_get_master_volume(pSpatializer, pVolume);
}

ma_uint32 raia_ma_spatializer_get_input_channels(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_input_channels(pSpatializer);
}

ma_uint32 raia_ma_spatializer_get_output_channels(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_output_channels(pSpatializer);
}

void raia_ma_spatializer_set_attenuation_model(ma_spatializer* pSpatializer, ma_attenuation_model attenuationModel) {
    ma_spatializer_set_attenuation_model(pSpatializer, attenuationModel);
}

ma_attenuation_model raia_ma_spatializer_get_attenuation_model(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_attenuation_model(pSpatializer);
}

void raia_ma_spatializer_set_positioning(ma_spatializer* pSpatializer, ma_positioning positioning) {
    ma_spatializer_set_positioning(pSpatializer, positioning);
}

ma_positioning raia_ma_spatializer_get_positioning(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_positioning(pSpatializer);
}

void raia_ma_spatializer_set_rolloff(ma_spatializer* pSpatializer, float rolloff) {
    ma_spatializer_set_rolloff(pSpatializer, rolloff);
}

float raia_ma_spatializer_get_rolloff(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_rolloff(pSpatializer);
}

void raia_ma_spatializer_set_min_gain(ma_spatializer* pSpatializer, float minGain) {
    ma_spatializer_set_min_gain(pSpatializer, minGain);
}

float raia_ma_spatializer_get_min_gain(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_min_gain(pSpatializer);
}

void raia_ma_spatializer_set_max_gain(ma_spatializer* pSpatializer, float maxGain) {
    ma_spatializer_set_max_gain(pSpatializer, maxGain);
}

float raia_ma_spatializer_get_max_gain(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_max_gain(pSpatializer);
}

void raia_ma_spatializer_set_min_distance(ma_spatializer* pSpatializer, float minDistance) {
    ma_spatializer_set_min_distance(pSpatializer, minDistance);
}

float raia_ma_spatializer_get_min_distance(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_min_distance(pSpatializer);
}

void raia_ma_spatializer_set_max_distance(ma_spatializer* pSpatializer, float maxDistance) {
    ma_spatializer_set_max_distance(pSpatializer, maxDistance);
}

float raia_ma_spatializer_get_max_distance(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_max_distance(pSpatializer);
}

void raia_ma_spatializer_set_cone(ma_spatializer* pSpatializer, float innerAngleInRadians, float outerAngleInRadians, float outerGain) {
    ma_spatializer_set_cone(pSpatializer, innerAngleInRadians, outerAngleInRadians, outerGain);
}

void raia_ma_spatializer_get_cone(const ma_spatializer* pSpatializer, float* pInnerAngleInRadians, float* pOuterAngleInRadians, float* pOuterGain) {
    ma_spatializer_get_cone(pSpatializer, pInnerAngleInRadians, pOuterAngleInRadians, pOuterGain);
}

void raia_ma_spatializer_set_doppler_factor(ma_spatializer* pSpatializer, float dopplerFactor) {
    ma_spatializer_set_doppler_factor(pSpatializer, dopplerFactor);
}

float raia_ma_spatializer_get_doppler_factor(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_doppler_factor(pSpatializer);
}

void raia_ma_spatializer_set_directional_attenuation_factor(ma_spatializer* pSpatializer, float directionalAttenuationFactor) {
    ma_spatializer_set_directional_attenuation_factor(pSpatializer, directionalAttenuationFactor);
}

float raia_ma_spatializer_get_directional_attenuation_factor(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_directional_attenuation_factor(pSpatializer);
}

void raia_ma_spatializer_set_position(ma_spatializer* pSpatializer, float x, float y, float z) {
    ma_spatializer_set_position(pSpatializer, x, y, z);
}

ma_vec3f raia_ma_spatializer_get_position(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_position(pSpatializer);
}

void raia_ma_spatializer_set_direction(ma_spatializer* pSpatializer, float x, float y, float z) {
    ma_spatializer_set_direction(pSpatializer, x, y, z);
}

ma_vec3f raia_ma_spatializer_get_direction(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_direction(pSpatializer);
}

void raia_ma_spatializer_set_velocity(ma_spatializer* pSpatializer, float x, float y, float z) {
    ma_spatializer_set_velocity(pSpatializer, x, y, z);
}

ma_vec3f raia_ma_spatializer_get_velocity(const ma_spatializer* pSpatializer) {
    return ma_spatializer_get_velocity(pSpatializer);
}

void raia_ma_spatializer_get_relative_position_and_direction(const ma_spatializer* pSpatializer, const ma_spatializer_listener* pListener, ma_vec3f* pRelativePos, ma_vec3f* pRelativeDir) {
    ma_spatializer_get_relative_position_and_direction(pSpatializer, pListener, pRelativePos, pRelativeDir);
}

// Resampling

ma_linear_resampler_config raia_ma_linear_resampler_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut) {
    return ma_linear_resampler_config_init(format, channels, sampleRateIn, sampleRateOut);
}

ma_result raia_ma_linear_resampler_get_heap_size(const ma_linear_resampler_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_linear_resampler_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_linear_resampler_init_preallocated(const ma_linear_resampler_config* pConfig, void* pHeap, ma_linear_resampler* pResampler) {
    return ma_linear_resampler_init_preallocated(pConfig, pHeap, pResampler);
}

ma_result raia_ma_linear_resampler_init(const ma_linear_resampler_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_linear_resampler* pResampler) {
    return ma_linear_resampler_init(pConfig, pAllocationCallbacks, pResampler);
}

void raia_ma_linear_resampler_uninit(ma_linear_resampler* pResampler, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_linear_resampler_uninit(pResampler, pAllocationCallbacks);
}

ma_result raia_ma_linear_resampler_process_pcm_frames(ma_linear_resampler* pResampler, const void* pFramesIn, ma_uint64* pFrameCountIn, void* pFramesOut, ma_uint64* pFrameCountOut) {
    return ma_linear_resampler_process_pcm_frames(pResampler, pFramesIn, pFrameCountIn, pFramesOut, pFrameCountOut);
}

ma_result raia_ma_linear_resampler_set_rate(ma_linear_resampler* pResampler, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut) {
    return ma_linear_resampler_set_rate(pResampler, sampleRateIn, sampleRateOut);
}

ma_result raia_ma_linear_resampler_set_rate_ratio(ma_linear_resampler* pResampler, float ratioInOut) {
    return ma_linear_resampler_set_rate_ratio(pResampler, ratioInOut);
}

ma_uint64 raia_ma_linear_resampler_get_input_latency(const ma_linear_resampler* pResampler) {
    return ma_linear_resampler_get_input_latency(pResampler);
}

ma_uint64 raia_ma_linear_resampler_get_output_latency(const ma_linear_resampler* pResampler) {
    return ma_linear_resampler_get_output_latency(pResampler);
}

ma_result raia_ma_linear_resampler_get_required_input_frame_count(const ma_linear_resampler* pResampler, ma_uint64 outputFrameCount, ma_uint64* pInputFrameCount) {
    return ma_linear_resampler_get_required_input_frame_count(pResampler, outputFrameCount, pInputFrameCount);
}

ma_result raia_ma_linear_resampler_get_expected_output_frame_count(const ma_linear_resampler* pResampler, ma_uint64 inputFrameCount, ma_uint64* pOutputFrameCount) {
    return ma_linear_resampler_get_expected_output_frame_count(pResampler, inputFrameCount, pOutputFrameCount);
}

ma_result raia_ma_linear_resampler_reset(ma_linear_resampler* pResampler) {
    return ma_linear_resampler_reset(pResampler);
}

ma_resampler_config raia_ma_resampler_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut, ma_resample_algorithm algorithm) {
    return ma_resampler_config_init(format, channels, sampleRateIn, sampleRateOut, algorithm);
}

ma_result raia_ma_resampler_get_heap_size(const ma_resampler_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_resampler_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_resampler_init_preallocated(const ma_resampler_config* pConfig, void* pHeap, ma_resampler* pResampler) {
    return ma_resampler_init_preallocated(pConfig, pHeap, pResampler);
}

ma_result raia_ma_resampler_init(const ma_resampler_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_resampler* pResampler) {
    return ma_resampler_init(pConfig, pAllocationCallbacks, pResampler);
}

void raia_ma_resampler_uninit(ma_resampler* pResampler, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_resampler_uninit(pResampler, pAllocationCallbacks);
}

ma_result raia_ma_resampler_process_pcm_frames(ma_resampler* pResampler, const void* pFramesIn, ma_uint64* pFrameCountIn, void* pFramesOut, ma_uint64* pFrameCountOut) {
    return ma_resampler_process_pcm_frames(pResampler, pFramesIn, pFrameCountIn, pFramesOut, pFrameCountOut);
}

ma_result raia_ma_resampler_set_rate(ma_resampler* pResampler, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut) {
    return ma_resampler_set_rate(pResampler, sampleRateIn, sampleRateOut);
}

ma_result raia_ma_resampler_set_rate_ratio(ma_resampler* pResampler, float ratio) {
    return ma_resampler_set_rate_ratio(pResampler, ratio);
}

ma_uint64 raia_ma_resampler_get_input_latency(const ma_resampler* pResampler) {
    return ma_resampler_get_input_latency(pResampler);
}

ma_uint64 raia_ma_resampler_get_output_latency(const ma_resampler* pResampler) {
    return ma_resampler_get_output_latency(pResampler);
}

ma_result raia_ma_resampler_get_required_input_frame_count(const ma_resampler* pResampler, ma_uint64 outputFrameCount, ma_uint64* pInputFrameCount) {
    return ma_resampler_get_required_input_frame_count(pResampler, outputFrameCount, pInputFrameCount);
}

ma_result raia_ma_resampler_get_expected_output_frame_count(const ma_resampler* pResampler, ma_uint64 inputFrameCount, ma_uint64* pOutputFrameCount) {
    return ma_resampler_get_expected_output_frame_count(pResampler, inputFrameCount, pOutputFrameCount);
}

ma_result raia_ma_resampler_reset(ma_resampler* pResampler) {
    return ma_resampler_reset(pResampler);
}

// Channel Conversion

ma_channel_converter_config raia_ma_channel_converter_config_init(ma_format format, ma_uint32 channelsIn, const ma_channel* pChannelMapIn, ma_uint32 channelsOut, const ma_channel* pChannelMapOut, ma_channel_mix_mode mixingMode) {
    return ma_channel_converter_config_init(format, channelsIn, pChannelMapIn, channelsOut, pChannelMapOut, mixingMode);
}

ma_result raia_ma_channel_converter_get_heap_size(const ma_channel_converter_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_channel_converter_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_channel_converter_init_preallocated(const ma_channel_converter_config* pConfig, void* pHeap, ma_channel_converter* pConverter) {
    return ma_channel_converter_init_preallocated(pConfig, pHeap, pConverter);
}

ma_result raia_ma_channel_converter_init(const ma_channel_converter_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_channel_converter* pConverter) {
    return ma_channel_converter_init(pConfig, pAllocationCallbacks, pConverter);
}

void raia_ma_channel_converter_uninit(ma_channel_converter* pConverter, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_channel_converter_uninit(pConverter, pAllocationCallbacks);
}

ma_result raia_ma_channel_converter_process_pcm_frames(ma_channel_converter* pConverter, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount) {
    return ma_channel_converter_process_pcm_frames(pConverter, pFramesOut, pFramesIn, frameCount);
}

ma_result raia_ma_channel_converter_get_input_channel_map(const ma_channel_converter* pConverter, ma_channel* pChannelMap, size_t channelMapCap) {
    return ma_channel_converter_get_input_channel_map(pConverter, pChannelMap, channelMapCap);
}

ma_result raia_ma_channel_converter_get_output_channel_map(const ma_channel_converter* pConverter, ma_channel* pChannelMap, size_t channelMapCap) {
    return ma_channel_converter_get_output_channel_map(pConverter, pChannelMap, channelMapCap);
}

// Data Conversion

ma_data_converter_config raia_ma_data_converter_config_init_default(void) {
    return ma_data_converter_config_init_default();
}

ma_data_converter_config raia_ma_data_converter_config_init(ma_format formatIn, ma_format formatOut, ma_uint32 channelsIn, ma_uint32 channelsOut, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut) {
    return ma_data_converter_config_init(formatIn, formatOut, channelsIn, channelsOut, sampleRateIn, sampleRateOut);
}

ma_result raia_ma_data_converter_get_heap_size(const ma_data_converter_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_data_converter_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_data_converter_init_preallocated(const ma_data_converter_config* pConfig, void* pHeap, ma_data_converter* pConverter) {
    return ma_data_converter_init_preallocated(pConfig, pHeap, pConverter);
}

ma_result raia_ma_data_converter_init(const ma_data_converter_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_data_converter* pConverter) {
    return ma_data_converter_init(pConfig, pAllocationCallbacks, pConverter);
}

void raia_ma_data_converter_uninit(ma_data_converter* pConverter, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_data_converter_uninit(pConverter, pAllocationCallbacks);
}

ma_result raia_ma_data_converter_process_pcm_frames(ma_data_converter* pConverter, const void* pFramesIn, ma_uint64* pFrameCountIn, void* pFramesOut, ma_uint64* pFrameCountOut) {
    return ma_data_converter_process_pcm_frames(pConverter, pFramesIn, pFrameCountIn, pFramesOut, pFrameCountOut);
}

ma_result raia_ma_data_converter_set_rate(ma_data_converter* pConverter, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut) {
    return ma_data_converter_set_rate(pConverter, sampleRateIn, sampleRateOut);
}

ma_result raia_ma_data_converter_set_rate_ratio(ma_data_converter* pConverter, float ratioInOut) {
    return ma_data_converter_set_rate_ratio(pConverter, ratioInOut);
}

ma_uint64 raia_ma_data_converter_get_input_latency(const ma_data_converter* pConverter) {
    return ma_data_converter_get_input_latency(pConverter);
}

ma_uint64 raia_ma_data_converter_get_output_latency(const ma_data_converter* pConverter) {
    return ma_data_converter_get_output_latency(pConverter);
}

ma_result raia_ma_data_converter_get_required_input_frame_count(const ma_data_converter* pConverter, ma_uint64 outputFrameCount, ma_uint64* pInputFrameCount) {
    return ma_data_converter_get_required_input_frame_count(pConverter, outputFrameCount, pInputFrameCount);
}

ma_result raia_ma_data_converter_get_expected_output_frame_count(const ma_data_converter* pConverter, ma_uint64 inputFrameCount, ma_uint64* pOutputFrameCount) {
    return ma_data_converter_get_expected_output_frame_count(pConverter, inputFrameCount, pOutputFrameCount);
}

ma_result raia_ma_data_converter_get_input_channel_map(const ma_data_converter* pConverter, ma_channel* pChannelMap, size_t channelMapCap) {
    return ma_data_converter_get_input_channel_map(pConverter, pChannelMap, channelMapCap);
}

ma_result raia_ma_data_converter_get_output_channel_map(const ma_data_converter* pConverter, ma_channel* pChannelMap, size_t channelMapCap) {
    return ma_data_converter_get_output_channel_map(pConverter, pChannelMap, channelMapCap);
}

ma_result raia_ma_data_converter_reset(ma_data_converter* pConverter) {
    return ma_data_converter_reset(pConverter);
}

// Format Conversion

void raia_ma_pcm_u8_to_s16(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_u8_to_s16(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_u8_to_s24(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_u8_to_s24(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_u8_to_s32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_u8_to_s32(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_u8_to_f32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_u8_to_f32(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s16_to_u8(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s16_to_u8(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s16_to_s24(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s16_to_s24(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s16_to_s32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s16_to_s32(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s16_to_f32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s16_to_f32(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s24_to_u8(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s24_to_u8(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s24_to_s16(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s24_to_s16(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s24_to_s32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s24_to_s32(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s24_to_f32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s24_to_f32(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s32_to_u8(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s32_to_u8(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s32_to_s16(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s32_to_s16(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s32_to_s24(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s32_to_s24(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_s32_to_f32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_s32_to_f32(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_f32_to_u8(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_f32_to_u8(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_f32_to_s16(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_f32_to_s16(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_f32_to_s24(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_f32_to_s24(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_f32_to_s32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode) {
    ma_pcm_f32_to_s32(pOut, pIn, count, ditherMode);
}

void raia_ma_pcm_convert(void* pOut, ma_format formatOut, const void* pIn, ma_format formatIn, ma_uint64 sampleCount, ma_dither_mode ditherMode) {
    ma_pcm_convert(pOut, formatOut, pIn, formatIn, sampleCount, ditherMode);
}

void raia_ma_convert_pcm_frames_format(void* pOut, ma_format formatOut, const void* pIn, ma_format formatIn, ma_uint64 frameCount, ma_uint32 channels, ma_dither_mode ditherMode) {
    ma_convert_pcm_frames_format(pOut, formatOut, pIn, formatIn, frameCount, channels, ditherMode);
}

void raia_ma_deinterleave_pcm_frames(ma_format format, ma_uint32 channels, ma_uint64 frameCount, const void* pInterleavedPCMFrames, void** ppDeinterleavedPCMFrames) {
    ma_deinterleave_pcm_frames(format, channels, frameCount, pInterleavedPCMFrames, ppDeinterleavedPCMFrames);
}

void raia_ma_interleave_pcm_frames(ma_format format, ma_uint32 channels, ma_uint64 frameCount, const void** ppDeinterleavedPCMFrames, void* pInterleavedPCMFrames) {
    ma_interleave_pcm_frames(format, channels, frameCount, ppDeinterleavedPCMFrames, pInterleavedPCMFrames);
}


// Channel Maps

ma_channel raia_ma_channel_map_get_channel(const ma_channel* pChannelMap, ma_uint32 channelCount, ma_uint32 channelIndex) {
    return ma_channel_map_get_channel(pChannelMap, channelCount, channelIndex);
}

void raia_ma_channel_map_init_blank(ma_channel* pChannelMap, ma_uint32 channels) {
    ma_channel_map_init_blank(pChannelMap, channels);
}

void raia_ma_channel_map_init_standard(ma_standard_channel_map standardChannelMap, ma_channel* pChannelMap, size_t channelMapCap, ma_uint32 channels) {
    ma_channel_map_init_standard(standardChannelMap, pChannelMap, channelMapCap, channels);
}

void raia_ma_channel_map_copy(ma_channel* pOut, const ma_channel* pIn, ma_uint32 channels) {
    ma_channel_map_copy(pOut, pIn, channels);
}

void raia_ma_channel_map_copy_or_default(ma_channel* pOut, size_t channelMapCapOut, const ma_channel* pIn, ma_uint32 channels) {
    ma_channel_map_copy_or_default(pOut, channelMapCapOut, pIn, channels);
}

ma_bool32 raia_ma_channel_map_is_valid(const ma_channel* pChannelMap, ma_uint32 channels) {
    return ma_channel_map_is_valid(pChannelMap, channels);
}

ma_bool32 raia_ma_channel_map_is_equal(const ma_channel* pChannelMapA, const ma_channel* pChannelMapB, ma_uint32 channels) {
    return ma_channel_map_is_equal(pChannelMapA, pChannelMapB, channels);
}

ma_bool32 raia_ma_channel_map_is_blank(const ma_channel* pChannelMap, ma_uint32 channels) {
    return ma_channel_map_is_blank(pChannelMap, channels);
}

ma_bool32 raia_ma_channel_map_contains_channel_position(ma_uint32 channels, const ma_channel* pChannelMap, ma_channel channelPosition) {
    return ma_channel_map_contains_channel_position(channels, pChannelMap, channelPosition);
}

ma_bool32 raia_ma_channel_map_find_channel_position(ma_uint32 channels, const ma_channel* pChannelMap, ma_channel channelPosition, ma_uint32* pChannelIndex) {
    return ma_channel_map_find_channel_position(channels, pChannelMap, channelPosition, pChannelIndex);
}

size_t raia_ma_channel_map_to_string(const ma_channel* pChannelMap, ma_uint32 channels, char* pBufferOut, size_t bufferCap) {
    return ma_channel_map_to_string(pChannelMap, channels, pBufferOut, bufferCap);
}

const char* raia_ma_channel_position_to_string(ma_channel channel) {
    return ma_channel_position_to_string(channel);
}

// Conversion Helpers

ma_uint64 raia_ma_convert_frames(void* pOut, ma_uint64 frameCountOut, ma_format formatOut, ma_uint32 channelsOut, ma_uint32 sampleRateOut, const void* pIn, ma_uint64 frameCountIn, ma_format formatIn, ma_uint32 channelsIn, ma_uint32 sampleRateIn) {
    return ma_convert_frames(pOut, frameCountOut, formatOut, channelsOut, sampleRateOut, pIn, frameCountIn, formatIn, channelsIn, sampleRateIn);
}

ma_uint64 raia_ma_convert_frames_ex(void* pOut, ma_uint64 frameCountOut, const void* pIn, ma_uint64 frameCountIn, const ma_data_converter_config* pConfig) {
    return ma_convert_frames_ex(pOut, frameCountOut, pIn, frameCountIn, pConfig);
}

// Data Source

ma_data_source_config raia_ma_data_source_config_init(void) {
    return ma_data_source_config_init();
}

ma_result raia_ma_data_source_init(const ma_data_source_config* pConfig, ma_data_source* pDataSource) {
    return ma_data_source_init(pConfig, pDataSource);
}

void raia_ma_data_source_uninit(ma_data_source* pDataSource) {
    ma_data_source_uninit(pDataSource);
}

ma_result raia_ma_data_source_read_pcm_frames(ma_data_source* pDataSource, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_data_source_read_pcm_frames(pDataSource, pFramesOut, frameCount, pFramesRead);
}

ma_result raia_ma_data_source_seek_pcm_frames(ma_data_source* pDataSource, ma_uint64 frameCount, ma_uint64* pFramesSeeked) {
    return ma_data_source_seek_pcm_frames(pDataSource, frameCount, pFramesSeeked);
}

ma_result raia_ma_data_source_seek_to_pcm_frame(ma_data_source* pDataSource, ma_uint64 frameIndex) {
    return ma_data_source_seek_to_pcm_frame(pDataSource, frameIndex);
}

ma_result raia_ma_data_source_get_data_format(ma_data_source* pDataSource, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap) {
    return ma_data_source_get_data_format(pDataSource, pFormat, pChannels, pSampleRate, pChannelMap, channelMapCap);
}

ma_result raia_ma_data_source_get_cursor_in_pcm_frames(ma_data_source* pDataSource, ma_uint64* pCursor) {
    return ma_data_source_get_cursor_in_pcm_frames(pDataSource, pCursor);
}

ma_result raia_ma_data_source_get_length_in_pcm_frames(ma_data_source* pDataSource, ma_uint64* pLength) {
    return ma_data_source_get_length_in_pcm_frames(pDataSource, pLength);
}

ma_result raia_ma_data_source_get_cursor_in_seconds(ma_data_source* pDataSource, float* pCursor) {
    return ma_data_source_get_cursor_in_seconds(pDataSource, pCursor);
}

ma_result raia_ma_data_source_get_length_in_seconds(ma_data_source* pDataSource, float* pLength) {
    return ma_data_source_get_length_in_seconds(pDataSource, pLength);
}

ma_result raia_ma_data_source_set_looping(ma_data_source* pDataSource, ma_bool32 isLooping) {
    return ma_data_source_set_looping(pDataSource, isLooping);
}

ma_bool32 raia_ma_data_source_is_looping(const ma_data_source* pDataSource) {
    return ma_data_source_is_looping(pDataSource);
}

ma_result raia_ma_data_source_set_range_in_pcm_frames(ma_data_source* pDataSource, ma_uint64 rangeBegInFrames, ma_uint64 rangeEndInFrames) {
    return ma_data_source_set_range_in_pcm_frames(pDataSource, rangeBegInFrames, rangeEndInFrames);
}

void raia_ma_data_source_get_range_in_pcm_frames(const ma_data_source* pDataSource, ma_uint64* pRangeBegInFrames, ma_uint64* pRangeEndInFrames) {
    ma_data_source_get_range_in_pcm_frames(pDataSource, pRangeBegInFrames, pRangeEndInFrames);
}

ma_result raia_ma_data_source_set_loop_point_in_pcm_frames(ma_data_source* pDataSource, ma_uint64 loopBegInFrames, ma_uint64 loopEndInFrames) {
    return ma_data_source_set_loop_point_in_pcm_frames(pDataSource, loopBegInFrames, loopEndInFrames);
}

void raia_ma_data_source_get_loop_point_in_pcm_frames(const ma_data_source* pDataSource, ma_uint64* pLoopBegInFrames, ma_uint64* pLoopEndInFrames) {
    ma_data_source_get_loop_point_in_pcm_frames(pDataSource, pLoopBegInFrames, pLoopEndInFrames);
}

ma_result raia_ma_data_source_set_current(ma_data_source* pDataSource, ma_data_source* pCurrentDataSource) {
    return ma_data_source_set_current(pDataSource, pCurrentDataSource);
}

ma_data_source* raia_ma_data_source_get_current(const ma_data_source* pDataSource) {
    return ma_data_source_get_current(pDataSource);
}

ma_result raia_ma_data_source_set_next(ma_data_source* pDataSource, ma_data_source* pNextDataSource) {
    return ma_data_source_set_next(pDataSource, pNextDataSource);
}

ma_data_source* raia_ma_data_source_get_next(const ma_data_source* pDataSource) {
    return ma_data_source_get_next(pDataSource);
}

ma_result raia_ma_data_source_set_next_callback(ma_data_source* pDataSource, ma_data_source_get_next_proc onGetNext) {
    return ma_data_source_set_next_callback(pDataSource, onGetNext);
}

ma_data_source_get_next_proc raia_ma_data_source_get_next_callback(const ma_data_source* pDataSource) {
    return ma_data_source_get_next_callback(pDataSource);
}

ma_result raia_ma_audio_buffer_ref_init(ma_format format, ma_uint32 channels, const void* pData, ma_uint64 sizeInFrames, ma_audio_buffer_ref* pAudioBufferRef) {
    return ma_audio_buffer_ref_init(format, channels, pData, sizeInFrames, pAudioBufferRef);
}

void raia_ma_audio_buffer_ref_uninit(ma_audio_buffer_ref* pAudioBufferRef) {
    ma_audio_buffer_ref_uninit(pAudioBufferRef);
}

ma_result raia_ma_audio_buffer_ref_set_data(ma_audio_buffer_ref* pAudioBufferRef, const void* pData, ma_uint64 sizeInFrames) {
    return ma_audio_buffer_ref_set_data(pAudioBufferRef, pData, sizeInFrames);
}

ma_uint64 raia_ma_audio_buffer_ref_read_pcm_frames(ma_audio_buffer_ref* pAudioBufferRef, void* pFramesOut, ma_uint64 frameCount, ma_bool32 loop) {
    return ma_audio_buffer_ref_read_pcm_frames(pAudioBufferRef, pFramesOut, frameCount, loop);
}

ma_result raia_ma_audio_buffer_ref_seek_to_pcm_frame(ma_audio_buffer_ref* pAudioBufferRef, ma_uint64 frameIndex) {
    return ma_audio_buffer_ref_seek_to_pcm_frame(pAudioBufferRef, frameIndex);
}

ma_result raia_ma_audio_buffer_ref_map(ma_audio_buffer_ref* pAudioBufferRef, void** ppFramesOut, ma_uint64* pFrameCount) {
    return ma_audio_buffer_ref_map(pAudioBufferRef, ppFramesOut, pFrameCount);
}

ma_result raia_ma_audio_buffer_ref_unmap(ma_audio_buffer_ref* pAudioBufferRef, ma_uint64 frameCount) {
    return ma_audio_buffer_ref_unmap(pAudioBufferRef, frameCount);
}

ma_bool32 raia_ma_audio_buffer_ref_at_end(const ma_audio_buffer_ref* pAudioBufferRef) {
    return ma_audio_buffer_ref_at_end(pAudioBufferRef);
}

ma_result raia_ma_audio_buffer_ref_get_cursor_in_pcm_frames(const ma_audio_buffer_ref* pAudioBufferRef, ma_uint64* pCursor) {
    return ma_audio_buffer_ref_get_cursor_in_pcm_frames(pAudioBufferRef, pCursor);
}

ma_result raia_ma_audio_buffer_ref_get_length_in_pcm_frames(const ma_audio_buffer_ref* pAudioBufferRef, ma_uint64* pLength) {
    return ma_audio_buffer_ref_get_length_in_pcm_frames(pAudioBufferRef, pLength);
}

ma_result raia_ma_audio_buffer_ref_get_available_frames(const ma_audio_buffer_ref* pAudioBufferRef, ma_uint64* pAvailableFrames) {
    return ma_audio_buffer_ref_get_available_frames(pAudioBufferRef, pAvailableFrames);
}

ma_audio_buffer_config raia_ma_audio_buffer_config_init(ma_format format, ma_uint32 channels, ma_uint64 sizeInFrames, const void* pData, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_audio_buffer_config_init(format, channels, sizeInFrames, pData, pAllocationCallbacks);
}

ma_result raia_ma_audio_buffer_init(const ma_audio_buffer_config* pConfig, ma_audio_buffer* pAudioBuffer) {
    return ma_audio_buffer_init(pConfig, pAudioBuffer);
}

ma_result raia_ma_audio_buffer_init_copy(const ma_audio_buffer_config* pConfig, ma_audio_buffer* pAudioBuffer) {
    return ma_audio_buffer_init_copy(pConfig, pAudioBuffer);
}

ma_result raia_ma_audio_buffer_alloc_and_init(const ma_audio_buffer_config* pConfig, ma_audio_buffer** ppAudioBuffer) {
    return ma_audio_buffer_alloc_and_init(pConfig, ppAudioBuffer);
}

void raia_ma_audio_buffer_uninit(ma_audio_buffer* pAudioBuffer) {
    ma_audio_buffer_uninit(pAudioBuffer);
}

void raia_ma_audio_buffer_uninit_and_free(ma_audio_buffer* pAudioBuffer) {
    ma_audio_buffer_uninit_and_free(pAudioBuffer);
}

ma_uint64 raia_ma_audio_buffer_read_pcm_frames(ma_audio_buffer* pAudioBuffer, void* pFramesOut, ma_uint64 frameCount, ma_bool32 loop) {
    return ma_audio_buffer_read_pcm_frames(pAudioBuffer, pFramesOut, frameCount, loop);
}

ma_result raia_ma_audio_buffer_seek_to_pcm_frame(ma_audio_buffer* pAudioBuffer, ma_uint64 frameIndex) {
    return ma_audio_buffer_seek_to_pcm_frame(pAudioBuffer, frameIndex);
}

ma_result raia_ma_audio_buffer_map(ma_audio_buffer* pAudioBuffer, void** ppFramesOut, ma_uint64* pFrameCount) {
    return ma_audio_buffer_map(pAudioBuffer, ppFramesOut, pFrameCount);
}

ma_result raia_ma_audio_buffer_unmap(ma_audio_buffer* pAudioBuffer, ma_uint64 frameCount) {
    return ma_audio_buffer_unmap(pAudioBuffer, frameCount);
}

ma_bool32 raia_ma_audio_buffer_at_end(const ma_audio_buffer* pAudioBuffer) {
    return ma_audio_buffer_at_end(pAudioBuffer);
}

ma_result raia_ma_audio_buffer_get_cursor_in_pcm_frames(const ma_audio_buffer* pAudioBuffer, ma_uint64* pCursor) {
    return ma_audio_buffer_get_cursor_in_pcm_frames(pAudioBuffer, pCursor);
}

ma_result raia_ma_audio_buffer_get_length_in_pcm_frames(const ma_audio_buffer* pAudioBuffer, ma_uint64* pLength) {
    return ma_audio_buffer_get_length_in_pcm_frames(pAudioBuffer, pLength);
}

ma_result raia_ma_audio_buffer_get_available_frames(const ma_audio_buffer* pAudioBuffer, ma_uint64* pAvailableFrames) {
    return ma_audio_buffer_get_available_frames(pAudioBuffer, pAvailableFrames);
}

// Paged Audio Buffer

ma_result raia_ma_paged_audio_buffer_data_init(ma_format format, ma_uint32 channels, ma_paged_audio_buffer_data* pData) {
    return ma_paged_audio_buffer_data_init(format, channels, pData);
}

void raia_ma_paged_audio_buffer_data_uninit(ma_paged_audio_buffer_data* pData, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_paged_audio_buffer_data_uninit(pData, pAllocationCallbacks);
}

ma_paged_audio_buffer_page* raia_ma_paged_audio_buffer_data_get_head(ma_paged_audio_buffer_data* pData) {
    return ma_paged_audio_buffer_data_get_head(pData);
}

ma_paged_audio_buffer_page* raia_ma_paged_audio_buffer_data_get_tail(ma_paged_audio_buffer_data* pData) {
    return ma_paged_audio_buffer_data_get_tail(pData);
}

ma_result raia_ma_paged_audio_buffer_data_get_length_in_pcm_frames(ma_paged_audio_buffer_data* pData, ma_uint64* pLength) {
    return ma_paged_audio_buffer_data_get_length_in_pcm_frames(pData, pLength);
}

ma_result raia_ma_paged_audio_buffer_data_allocate_page(ma_paged_audio_buffer_data* pData, ma_uint64 pageSizeInFrames, const void* pInitialData, const ma_allocation_callbacks* pAllocationCallbacks, ma_paged_audio_buffer_page** ppPage) {
    return ma_paged_audio_buffer_data_allocate_page(pData, pageSizeInFrames, pInitialData, pAllocationCallbacks, ppPage);
}

ma_result raia_ma_paged_audio_buffer_data_free_page(ma_paged_audio_buffer_data* pData, ma_paged_audio_buffer_page* pPage, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_paged_audio_buffer_data_free_page(pData, pPage, pAllocationCallbacks);
}

ma_result raia_ma_paged_audio_buffer_data_append_page(ma_paged_audio_buffer_data* pData, ma_paged_audio_buffer_page* pPage) {
    return ma_paged_audio_buffer_data_append_page(pData, pPage);
}

ma_result raia_ma_paged_audio_buffer_data_allocate_and_append_page(ma_paged_audio_buffer_data* pData, ma_uint32 pageSizeInFrames, const void* pInitialData, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_paged_audio_buffer_data_allocate_and_append_page(pData, pageSizeInFrames, pInitialData, pAllocationCallbacks);
}

ma_paged_audio_buffer_config raia_ma_paged_audio_buffer_config_init(ma_paged_audio_buffer_data* pData) {
    return ma_paged_audio_buffer_config_init(pData);
}

ma_result raia_ma_paged_audio_buffer_init(const ma_paged_audio_buffer_config* pConfig, ma_paged_audio_buffer* pPagedAudioBuffer) {
    return ma_paged_audio_buffer_init(pConfig, pPagedAudioBuffer);
}

void raia_ma_paged_audio_buffer_uninit(ma_paged_audio_buffer* pPagedAudioBuffer) {
    ma_paged_audio_buffer_uninit(pPagedAudioBuffer);
}

ma_result raia_ma_paged_audio_buffer_read_pcm_frames(ma_paged_audio_buffer* pPagedAudioBuffer, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_paged_audio_buffer_read_pcm_frames(pPagedAudioBuffer, pFramesOut, frameCount, pFramesRead);
}

ma_result raia_ma_paged_audio_buffer_seek_to_pcm_frame(ma_paged_audio_buffer* pPagedAudioBuffer, ma_uint64 frameIndex) {
    return ma_paged_audio_buffer_seek_to_pcm_frame(pPagedAudioBuffer, frameIndex);
}

ma_result raia_ma_paged_audio_buffer_get_cursor_in_pcm_frames(ma_paged_audio_buffer* pPagedAudioBuffer, ma_uint64* pCursor) {
    return ma_paged_audio_buffer_get_cursor_in_pcm_frames(pPagedAudioBuffer, pCursor);
}

ma_result raia_ma_paged_audio_buffer_get_length_in_pcm_frames(ma_paged_audio_buffer* pPagedAudioBuffer, ma_uint64* pLength) {
    return ma_paged_audio_buffer_get_length_in_pcm_frames(pPagedAudioBuffer, pLength);
}

// Ring Buffer

ma_result raia_ma_rb_init_ex(size_t subbufferSizeInBytes, size_t subbufferCount, size_t subbufferStrideInBytes, void* pOptionalPreallocatedBuffer, const ma_allocation_callbacks* pAllocationCallbacks, ma_rb* pRB) {
    return ma_rb_init_ex(subbufferSizeInBytes, subbufferCount, subbufferStrideInBytes, pOptionalPreallocatedBuffer, pAllocationCallbacks, pRB);
}

ma_result raia_ma_rb_init(size_t bufferSizeInBytes, void* pOptionalPreallocatedBuffer, const ma_allocation_callbacks* pAllocationCallbacks, ma_rb* pRB) {
    return ma_rb_init(bufferSizeInBytes, pOptionalPreallocatedBuffer, pAllocationCallbacks, pRB);
}

void raia_ma_rb_uninit(ma_rb* pRB) {
    ma_rb_uninit(pRB);
}

void raia_ma_rb_reset(ma_rb* pRB) {
    ma_rb_reset(pRB);
}

ma_result raia_ma_rb_acquire_read(ma_rb* pRB, size_t* pSizeInBytes, void** ppBufferOut) {
    return ma_rb_acquire_read(pRB, pSizeInBytes, ppBufferOut);
}

ma_result raia_ma_rb_commit_read(ma_rb* pRB, size_t sizeInBytes) {
    return ma_rb_commit_read(pRB, sizeInBytes);
}

ma_result raia_ma_rb_acquire_write(ma_rb* pRB, size_t* pSizeInBytes, void** ppBufferOut) {
    return ma_rb_acquire_write(pRB, pSizeInBytes, ppBufferOut);
}

ma_result raia_ma_rb_commit_write(ma_rb* pRB, size_t sizeInBytes) {
    return ma_rb_commit_write(pRB, sizeInBytes);
}

ma_result raia_ma_rb_seek_read(ma_rb* pRB, size_t offsetInBytes) {
    return ma_rb_seek_read(pRB, offsetInBytes);
}

ma_result raia_ma_rb_seek_write(ma_rb* pRB, size_t offsetInBytes) {
    return ma_rb_seek_write(pRB, offsetInBytes);
}

ma_int32 raia_ma_rb_pointer_distance(ma_rb* pRB) {
    return ma_rb_pointer_distance(pRB);
}

ma_uint32 raia_ma_rb_available_read(ma_rb* pRB) {
    return ma_rb_available_read(pRB);
}

ma_uint32 raia_ma_rb_available_write(ma_rb* pRB) {
    return ma_rb_available_write(pRB);
}

size_t raia_ma_rb_get_subbuffer_size(ma_rb* pRB) {
    return ma_rb_get_subbuffer_size(pRB);
}

size_t raia_ma_rb_get_subbuffer_stride(ma_rb* pRB) {
    return ma_rb_get_subbuffer_stride(pRB);
}

size_t raia_ma_rb_get_subbuffer_offset(ma_rb* pRB, size_t subbufferIndex) {
    return ma_rb_get_subbuffer_offset(pRB, subbufferIndex);
}

void* raia_ma_rb_get_subbuffer_ptr(ma_rb* pRB, size_t subbufferIndex, void* pBuffer) {
    return ma_rb_get_subbuffer_ptr(pRB, subbufferIndex, pBuffer);
}

ma_result raia_ma_pcm_rb_init_ex(ma_format format, ma_uint32 channels, ma_uint32 subbufferSizeInFrames, ma_uint32 subbufferCount, ma_uint32 subbufferStrideInFrames, void* pOptionalPreallocatedBuffer, const ma_allocation_callbacks* pAllocationCallbacks, ma_pcm_rb* pRB) {
    return ma_pcm_rb_init_ex(format, channels, subbufferSizeInFrames, subbufferCount, subbufferStrideInFrames, pOptionalPreallocatedBuffer, pAllocationCallbacks, pRB);
}

ma_result raia_ma_pcm_rb_init(ma_format format, ma_uint32 channels, ma_uint32 bufferSizeInFrames, void* pOptionalPreallocatedBuffer, const ma_allocation_callbacks* pAllocationCallbacks, ma_pcm_rb* pRB) {
    return ma_pcm_rb_init(format, channels, bufferSizeInFrames, pOptionalPreallocatedBuffer, pAllocationCallbacks, pRB);
}

void raia_ma_pcm_rb_uninit(ma_pcm_rb* pRB) {
    ma_pcm_rb_uninit(pRB);
}

void raia_ma_pcm_rb_reset(ma_pcm_rb* pRB) {
    ma_pcm_rb_reset(pRB);
}

ma_result raia_ma_pcm_rb_acquire_read(ma_pcm_rb* pRB, ma_uint32* pSizeInFrames, void** ppBufferOut) {
    return ma_pcm_rb_acquire_read(pRB, pSizeInFrames, ppBufferOut);
}

ma_result raia_ma_pcm_rb_commit_read(ma_pcm_rb* pRB, ma_uint32 sizeInFrames) {
    return ma_pcm_rb_commit_read(pRB, sizeInFrames);
}

ma_result raia_ma_pcm_rb_acquire_write(ma_pcm_rb* pRB, ma_uint32* pSizeInFrames, void** ppBufferOut) {
    return ma_pcm_rb_acquire_write(pRB, pSizeInFrames, ppBufferOut);
}

ma_result raia_ma_pcm_rb_commit_write(ma_pcm_rb* pRB, ma_uint32 sizeInFrames) {
    return ma_pcm_rb_commit_write(pRB, sizeInFrames);
}

ma_result raia_ma_pcm_rb_seek_read(ma_pcm_rb* pRB, ma_uint32 offsetInFrames) {
    return ma_pcm_rb_seek_read(pRB, offsetInFrames);
}

ma_result raia_ma_pcm_rb_seek_write(ma_pcm_rb* pRB, ma_uint32 offsetInFrames) {
    return ma_pcm_rb_seek_write(pRB, offsetInFrames);
}

ma_int32 raia_ma_pcm_rb_pointer_distance(ma_pcm_rb* pRB) {
    return ma_pcm_rb_pointer_distance(pRB);
}

ma_uint32 raia_ma_pcm_rb_available_read(ma_pcm_rb* pRB) {
    return ma_pcm_rb_available_read(pRB);
}

ma_uint32 raia_ma_pcm_rb_available_write(ma_pcm_rb* pRB) {
    return ma_pcm_rb_available_write(pRB);
}

ma_uint32 raia_ma_pcm_rb_get_subbuffer_size(ma_pcm_rb* pRB) {
    return ma_pcm_rb_get_subbuffer_size(pRB);
}

ma_uint32 raia_ma_pcm_rb_get_subbuffer_stride(ma_pcm_rb* pRB) {
    return ma_pcm_rb_get_subbuffer_stride(pRB);
}

ma_uint32 raia_ma_pcm_rb_get_subbuffer_offset(ma_pcm_rb* pRB, ma_uint32 subbufferIndex) {
    return ma_pcm_rb_get_subbuffer_offset(pRB, subbufferIndex);
}

void* raia_ma_pcm_rb_get_subbuffer_ptr(ma_pcm_rb* pRB, ma_uint32 subbufferIndex, void* pBuffer) {
    return ma_pcm_rb_get_subbuffer_ptr(pRB, subbufferIndex, pBuffer);
}

ma_format raia_ma_pcm_rb_get_format(const ma_pcm_rb* pRB) {
    return ma_pcm_rb_get_format(pRB);
}

ma_uint32 raia_ma_pcm_rb_get_channels(const ma_pcm_rb* pRB) {
    return ma_pcm_rb_get_channels(pRB);
}

ma_uint32 raia_ma_pcm_rb_get_sample_rate(const ma_pcm_rb* pRB) {
    return ma_pcm_rb_get_sample_rate(pRB);
}

void raia_ma_pcm_rb_set_sample_rate(ma_pcm_rb* pRB, ma_uint32 sampleRate) {
    ma_pcm_rb_set_sample_rate(pRB, sampleRate);
}

ma_result raia_ma_duplex_rb_init(ma_format captureFormat, ma_uint32 captureChannels, ma_uint32 sampleRate, ma_uint32 captureInternalSampleRate, ma_uint32 captureInternalPeriodSizeInFrames, const ma_allocation_callbacks* pAllocationCallbacks, ma_duplex_rb* pRB) {
    return ma_duplex_rb_init(captureFormat, captureChannels, sampleRate, captureInternalSampleRate, captureInternalPeriodSizeInFrames, pAllocationCallbacks, pRB);
}

ma_result raia_ma_duplex_rb_uninit(ma_duplex_rb* pRB) {
    return ma_duplex_rb_uninit(pRB);
}

// Miscellaneous Helpers

const char* raia_ma_result_description(ma_result result) {
    return ma_result_description(result);
}

void* raia_ma_malloc(size_t sz, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_malloc(sz, pAllocationCallbacks);
}

void* raia_ma_calloc(size_t sz, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_calloc(sz, pAllocationCallbacks);
}

void* raia_ma_realloc(void* p, size_t sz, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_realloc(p, sz, pAllocationCallbacks);
}

void raia_ma_free(void* p, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_free(p, pAllocationCallbacks);
}

void* raia_ma_aligned_malloc(size_t sz, size_t alignment, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_aligned_malloc(sz, alignment, pAllocationCallbacks);
}

void raia_ma_aligned_free(void* p, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_aligned_free(p, pAllocationCallbacks);
}

const char* raia_ma_get_format_name(ma_format format) {
    return ma_get_format_name(format);
}

void raia_ma_blend_f32(float* pOut, float* pInA, float* pInB, float factor, ma_uint32 channels) {
    ma_blend_f32(pOut, pInA, pInB, factor, channels);
}

ma_uint32 raia_ma_get_bytes_per_sample(ma_format format) {
    return ma_get_bytes_per_sample(format);
}

const char* raia_ma_log_level_to_string(ma_uint32 logLevel) {
    return ma_log_level_to_string(logLevel);
}


// Synchronization

ma_result raia_ma_spinlock_lock(volatile ma_spinlock* pSpinlock) {
    return ma_spinlock_lock(pSpinlock);
}

ma_result raia_ma_spinlock_lock_noyield(volatile ma_spinlock* pSpinlock) {
    return ma_spinlock_lock_noyield(pSpinlock);
}

ma_result raia_ma_spinlock_unlock(volatile ma_spinlock* pSpinlock) {
    return ma_spinlock_unlock(pSpinlock);
}

#ifndef MA_NO_THREADING

ma_result raia_ma_mutex_init(ma_mutex* pMutex) {
    return ma_mutex_init(pMutex);
}

void raia_ma_mutex_uninit(ma_mutex* pMutex) {
    ma_mutex_uninit(pMutex);
}

void raia_ma_mutex_lock(ma_mutex* pMutex) {
    ma_mutex_lock(pMutex);
}

void raia_ma_mutex_unlock(ma_mutex* pMutex) {
    ma_mutex_unlock(pMutex);
}

ma_result raia_ma_event_init(ma_event* pEvent) {
    return ma_event_init(pEvent);
}

void raia_ma_event_uninit(ma_event* pEvent) {
    ma_event_uninit(pEvent);
}

ma_result raia_ma_event_wait(ma_event* pEvent) {
    return ma_event_wait(pEvent);
}

ma_result raia_ma_event_signal(ma_event* pEvent) {
    return ma_event_signal(pEvent);
}

#endif  /* MA_NO_THREADING */

// Fence

ma_result raia_ma_fence_init(ma_fence* pFence) {
    return ma_fence_init(pFence);
}

void raia_ma_fence_uninit(ma_fence* pFence) {
    ma_fence_uninit(pFence);
}

ma_result raia_ma_fence_acquire(ma_fence* pFence) {
    return ma_fence_acquire(pFence);
}

ma_result raia_ma_fence_release(ma_fence* pFence) {
    return ma_fence_release(pFence);
}

ma_result raia_ma_fence_wait(ma_fence* pFence) {
    return ma_fence_wait(pFence);
}

// Notification callback

ma_result raia_ma_async_notification_signal(ma_async_notification* pNotification) {
    return ma_async_notification_signal(pNotification);
}

// Simple polling notification

ma_result raia_ma_async_notification_poll_init(ma_async_notification_poll* pNotificationPoll) {
    return ma_async_notification_poll_init(pNotificationPoll);
}

ma_bool32 raia_ma_async_notification_poll_is_signalled(const ma_async_notification_poll* pNotificationPoll) {
    return ma_async_notification_poll_is_signalled(pNotificationPoll);
}

// Event Notification

ma_result raia_ma_async_notification_event_init(ma_async_notification_event* pNotificationEvent) {
    return ma_async_notification_event_init(pNotificationEvent);
}

ma_result raia_ma_async_notification_event_uninit(ma_async_notification_event* pNotificationEvent) {
    return ma_async_notification_event_uninit(pNotificationEvent);
}

ma_result raia_ma_async_notification_event_wait(ma_async_notification_event* pNotificationEvent) {
    return ma_async_notification_event_wait(pNotificationEvent);
}

ma_result raia_ma_async_notification_event_signal(ma_async_notification_event* pNotificationEvent) {
    return ma_async_notification_event_signal(pNotificationEvent);
}

// Slot Allocator

ma_slot_allocator_config raia_ma_slot_allocator_config_init(ma_uint32 capacity) {
    return ma_slot_allocator_config_init(capacity);
}

ma_result raia_ma_slot_allocator_get_heap_size(const ma_slot_allocator_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_slot_allocator_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_slot_allocator_init_preallocated(const ma_slot_allocator_config* pConfig, void* pHeap, ma_slot_allocator* pAllocator) {
    return ma_slot_allocator_init_preallocated(pConfig, pHeap, pAllocator);
}

ma_result raia_ma_slot_allocator_init(const ma_slot_allocator_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_slot_allocator* pAllocator) {
    return ma_slot_allocator_init(pConfig, pAllocationCallbacks, pAllocator);
}

void raia_ma_slot_allocator_uninit(ma_slot_allocator* pAllocator, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_slot_allocator_uninit(pAllocator, pAllocationCallbacks);
}

ma_result raia_ma_slot_allocator_alloc(ma_slot_allocator* pAllocator, ma_uint64* pSlot) {
    return ma_slot_allocator_alloc(pAllocator, pSlot);
}

ma_result raia_ma_slot_allocator_free(ma_slot_allocator* pAllocator, ma_uint64 slot) {
    return ma_slot_allocator_free(pAllocator, slot);
}

ma_job raia_ma_job_init(ma_uint16 code) {
    return ma_job_init(code);
}

ma_result raia_ma_job_process(ma_job* pJob) {
    return ma_job_process(pJob);
}

ma_job_queue_config raia_ma_job_queue_config_init(ma_uint32 flags, ma_uint32 capacity) {
    return ma_job_queue_config_init(flags, capacity);
}

ma_result raia_ma_job_queue_get_heap_size(const ma_job_queue_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_job_queue_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_job_queue_init_preallocated(const ma_job_queue_config* pConfig, void* pHeap, ma_job_queue* pQueue) {
    return ma_job_queue_init_preallocated(pConfig, pHeap, pQueue);
}

ma_result raia_ma_job_queue_init(const ma_job_queue_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_job_queue* pQueue) {
    return ma_job_queue_init(pConfig, pAllocationCallbacks, pQueue);
}

void raia_ma_job_queue_uninit(ma_job_queue* pQueue, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_job_queue_uninit(pQueue, pAllocationCallbacks);
}

ma_result raia_ma_job_queue_post(ma_job_queue* pQueue, const ma_job* pJob) {
    return ma_job_queue_post(pQueue, pJob);
}

ma_result raia_ma_job_queue_next(ma_job_queue* pQueue, ma_job* pJob) {
    return ma_job_queue_next(pQueue, pJob);
}

// DEVICE I/O

#ifndef MA_NO_DEVICE_IO

ma_device_job_thread_config raia_ma_device_job_thread_config_init(void) {
    return ma_device_job_thread_config_init();
}

ma_result raia_ma_device_job_thread_init(const ma_device_job_thread_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_device_job_thread* pJobThread) {
    return ma_device_job_thread_init(pConfig, pAllocationCallbacks, pJobThread);
}

void raia_ma_device_job_thread_uninit(ma_device_job_thread* pJobThread, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_device_job_thread_uninit(pJobThread, pAllocationCallbacks);
}

ma_result raia_ma_device_job_thread_post(ma_device_job_thread* pJobThread, const ma_job* pJob) {
    return ma_device_job_thread_post(pJobThread, pJob);
}

ma_result raia_ma_device_job_thread_next(ma_device_job_thread* pJobThread, ma_job* pJob) {
    return ma_device_job_thread_next(pJobThread, pJob);
}

//---

ma_context_config raia_ma_context_config_init(void) {
    return ma_context_config_init();
}

ma_result raia_ma_context_init(const ma_backend backends[], ma_uint32 backendCount, const ma_context_config* pConfig, ma_context* pContext) {
    return ma_context_init(backends, backendCount, pConfig, pContext);
}

ma_result raia_ma_context_uninit(ma_context* pContext) {
    return ma_context_uninit(pContext);
}

size_t raia_ma_context_sizeof(void) {
    return ma_context_sizeof();
}

ma_log* raia_ma_context_get_log(ma_context* pContext) {
    return ma_context_get_log(pContext);
}

ma_result raia_ma_context_enumerate_devices(ma_context* pContext, ma_enum_devices_callback_proc callback, void* pUserData) {
    return ma_context_enumerate_devices(pContext, callback, pUserData);
}

ma_result raia_ma_context_get_devices(ma_context* pContext, ma_device_info** ppPlaybackDeviceInfos, ma_uint32* pPlaybackDeviceCount, ma_device_info** ppCaptureDeviceInfos, ma_uint32* pCaptureDeviceCount) {
    return ma_context_get_devices(pContext, ppPlaybackDeviceInfos, pPlaybackDeviceCount, ppCaptureDeviceInfos, pCaptureDeviceCount);
}

ma_result raia_ma_context_get_device_info(ma_context* pContext, ma_device_type deviceType, const ma_device_id* pDeviceID, ma_device_info* pDeviceInfo) {
    return ma_context_get_device_info(pContext, deviceType, pDeviceID, pDeviceInfo);
}

ma_bool32 raia_ma_context_is_loopback_supported(ma_context* pContext) {
    return ma_context_is_loopback_supported(pContext);
}

ma_device_config raia_ma_device_config_init(ma_device_type deviceType) {
    return ma_device_config_init(deviceType);
}

ma_result raia_ma_device_init(ma_context* pContext, const ma_device_config* pConfig, ma_device* pDevice) {
    return ma_device_init(pContext, pConfig, pDevice);
}

ma_result raia_ma_device_init_ex(const ma_backend backends[], ma_uint32 backendCount, const ma_context_config* pContextConfig, const ma_device_config* pConfig, ma_device* pDevice) {
    return ma_device_init_ex(backends, backendCount, pContextConfig, pConfig, pDevice);
}

void raia_ma_device_uninit(ma_device* pDevice) {
    ma_device_uninit(pDevice);
}

ma_context* raia_ma_device_get_context(ma_device* pDevice) {
    return ma_device_get_context(pDevice);
}

ma_log* raia_ma_device_get_log(ma_device* pDevice) {
    return ma_device_get_log(pDevice);
}

ma_result raia_ma_device_get_info(ma_device* pDevice, ma_device_type type, ma_device_info* pDeviceInfo) {
    return ma_device_get_info(pDevice, type, pDeviceInfo);
}

ma_result raia_ma_device_get_name(ma_device* pDevice, ma_device_type type, char* pName, size_t nameCap, size_t* pLengthNotIncludingNullTerminator) {
    return ma_device_get_name(pDevice, type, pName, nameCap, pLengthNotIncludingNullTerminator);
}

ma_result raia_ma_device_start(ma_device* pDevice) {
    return ma_device_start(pDevice);
}

ma_result raia_ma_device_stop(ma_device* pDevice) {
    return ma_device_stop(pDevice);
}

ma_bool32 raia_ma_device_is_started(const ma_device* pDevice) {
    return ma_device_is_started(pDevice);
}

ma_device_state raia_ma_device_get_state(const ma_device* pDevice) {
    return ma_device_get_state(pDevice);
}

ma_result raia_ma_device_post_init(ma_device* pDevice, ma_device_type deviceType, const ma_device_descriptor* pPlaybackDescriptor, const ma_device_descriptor* pCaptureDescriptor) {
    return ma_device_post_init(pDevice, deviceType, pPlaybackDescriptor, pCaptureDescriptor);
}

ma_result raia_ma_device_set_master_volume(ma_device* pDevice, float volume) {
    return ma_device_set_master_volume(pDevice, volume);
}

ma_result raia_ma_device_get_master_volume(ma_device* pDevice, float* pVolume) {
    return ma_device_get_master_volume(pDevice, pVolume);
}

ma_result raia_ma_device_set_master_volume_db(ma_device* pDevice, float gainDB) {
    return ma_device_set_master_volume_db(pDevice, gainDB);
}

ma_result raia_ma_device_get_master_volume_db(ma_device* pDevice, float* pGainDB) {
    return ma_device_get_master_volume_db(pDevice, pGainDB);
}

ma_result raia_ma_device_handle_backend_data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    return ma_device_handle_backend_data_callback(pDevice, pOutput, pInput, frameCount);
}

ma_uint32 raia_ma_calculate_buffer_size_in_frames_from_descriptor(const ma_device_descriptor* pDescriptor, ma_uint32 nativeSampleRate, ma_performance_profile performanceProfile) {
    return ma_calculate_buffer_size_in_frames_from_descriptor(pDescriptor, nativeSampleRate, performanceProfile);
}

const char* raia_ma_get_backend_name(ma_backend backend) {
    return ma_get_backend_name(backend);
}

ma_result raia_ma_get_backend_from_name(const char* pBackendName, ma_backend* pBackend) {
    return ma_get_backend_from_name(pBackendName, pBackend);
}

ma_bool32 raia_ma_is_backend_enabled(ma_backend backend) {
    return ma_is_backend_enabled(backend);
}

ma_result raia_ma_get_enabled_backends(ma_backend* pBackends, size_t backendCap, size_t* pBackendCount) {
    return ma_get_enabled_backends(pBackends, backendCap, pBackendCount);
}

ma_bool32 raia_ma_is_loopback_supported(ma_backend backend) {
    return ma_is_loopback_supported(backend);
}

#endif  /* MA_NO_DEVICE_IO */

// Utilities

ma_uint32 raia_ma_calculate_buffer_size_in_milliseconds_from_frames(ma_uint32 bufferSizeInFrames, ma_uint32 sampleRate) {
    return ma_calculate_buffer_size_in_milliseconds_from_frames(bufferSizeInFrames, sampleRate);
}

ma_uint32 raia_ma_calculate_buffer_size_in_frames_from_milliseconds(ma_uint32 bufferSizeInMilliseconds, ma_uint32 sampleRate) {
    return ma_calculate_buffer_size_in_frames_from_milliseconds(bufferSizeInMilliseconds, sampleRate);
}

void raia_ma_copy_pcm_frames(void* dst, const void* src, ma_uint64 frameCount, ma_format format, ma_uint32 channels) {
    ma_copy_pcm_frames(dst, src, frameCount, format, channels);
}

void raia_ma_silence_pcm_frames(void* p, ma_uint64 frameCount, ma_format format, ma_uint32 channels) {
    ma_silence_pcm_frames(p, frameCount, format, channels);
}

void* raia_ma_offset_pcm_frames_ptr(void* p, ma_uint64 offsetInFrames, ma_format format, ma_uint32 channels) {
    return ma_offset_pcm_frames_ptr(p, offsetInFrames, format, channels);
}

const void* raia_ma_offset_pcm_frames_const_ptr(const void* p, ma_uint64 offsetInFrames, ma_format format, ma_uint32 channels) {
    return ma_offset_pcm_frames_const_ptr(p, offsetInFrames, format, channels);
}

void raia_ma_clip_samples_u8(ma_uint8* pDst, const ma_int16* pSrc, ma_uint64 count) {
    ma_clip_samples_u8(pDst, pSrc, count);
}

void raia_ma_clip_samples_s16(ma_int16* pDst, const ma_int32* pSrc, ma_uint64 count) {
    ma_clip_samples_s16(pDst, pSrc, count);
}

void raia_ma_clip_samples_s24(ma_uint8* pDst, const ma_int64* pSrc, ma_uint64 count) {
    ma_clip_samples_s24(pDst, pSrc, count);
}

void raia_ma_clip_samples_s32(ma_int32* pDst, const ma_int64* pSrc, ma_uint64 count) {
    ma_clip_samples_s32(pDst, pSrc, count);
}

void raia_ma_clip_samples_f32(float* pDst, const float* pSrc, ma_uint64 count) {
    ma_clip_samples_f32(pDst, pSrc, count);
}

void raia_ma_clip_pcm_frames(void* pDst, const void* pSrc, ma_uint64 frameCount, ma_format format, ma_uint32 channels) {
    ma_clip_pcm_frames(pDst, pSrc, frameCount, format, channels);
}

void raia_ma_copy_and_apply_volume_factor_u8(ma_uint8* pSamplesOut, const ma_uint8* pSamplesIn, ma_uint64 sampleCount, float factor) {
    ma_copy_and_apply_volume_factor_u8(pSamplesOut, pSamplesIn, sampleCount, factor);
}

void raia_ma_copy_and_apply_volume_factor_s16(ma_int16* pSamplesOut, const ma_int16* pSamplesIn, ma_uint64 sampleCount, float factor) {
    ma_copy_and_apply_volume_factor_s16(pSamplesOut, pSamplesIn, sampleCount, factor);
}

void raia_ma_copy_and_apply_volume_factor_s24(void* pSamplesOut, const void* pSamplesIn, ma_uint64 sampleCount, float factor) {
    ma_copy_and_apply_volume_factor_s24(pSamplesOut, pSamplesIn, sampleCount, factor);
}

void raia_ma_copy_and_apply_volume_factor_s32(ma_int32* pSamplesOut, const ma_int32* pSamplesIn, ma_uint64 sampleCount, float factor) {
    ma_copy_and_apply_volume_factor_s32(pSamplesOut, pSamplesIn, sampleCount, factor);
}

void raia_ma_copy_and_apply_volume_factor_f32(float* pSamplesOut, const float* pSamplesIn, ma_uint64 sampleCount, float factor) {
    ma_copy_and_apply_volume_factor_f32(pSamplesOut, pSamplesIn, sampleCount, factor);
}

void raia_ma_apply_volume_factor_u8(ma_uint8* pSamples, ma_uint64 sampleCount, float factor) {
    ma_apply_volume_factor_u8(pSamples, sampleCount, factor);
}

void raia_ma_apply_volume_factor_s16(ma_int16* pSamples, ma_uint64 sampleCount, float factor) {
    ma_apply_volume_factor_s16(pSamples, sampleCount, factor);
}

void raia_ma_apply_volume_factor_s24(void* pSamples, ma_uint64 sampleCount, float factor) {
    ma_apply_volume_factor_s24(pSamples, sampleCount, factor);
}

void raia_ma_apply_volume_factor_s32(ma_int32* pSamples, ma_uint64 sampleCount, float factor) {
    ma_apply_volume_factor_s32(pSamples, sampleCount, factor);
}

void raia_ma_apply_volume_factor_f32(float* pSamples, ma_uint64 sampleCount, float factor) {
    ma_apply_volume_factor_f32(pSamples, sampleCount, factor);
}

void raia_ma_copy_and_apply_volume_factor_pcm_frames_u8(ma_uint8* pFramesOut, const ma_uint8* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float factor) {
    ma_copy_and_apply_volume_factor_pcm_frames_u8(pFramesOut, pFramesIn, frameCount, channels, factor);
}

void raia_ma_copy_and_apply_volume_factor_pcm_frames_s16(ma_int16* pFramesOut, const ma_int16* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float factor) {
    ma_copy_and_apply_volume_factor_pcm_frames_s16(pFramesOut, pFramesIn, frameCount, channels, factor);
}

void raia_ma_copy_and_apply_volume_factor_pcm_frames_s24(void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float factor) {
    ma_copy_and_apply_volume_factor_pcm_frames_s24(pFramesOut, pFramesIn, frameCount, channels, factor);
}

void raia_ma_copy_and_apply_volume_factor_pcm_frames_s32(ma_int32* pFramesOut, const ma_int32* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float factor) {
    ma_copy_and_apply_volume_factor_pcm_frames_s32(pFramesOut, pFramesIn, frameCount, channels, factor);
}

void raia_ma_copy_and_apply_volume_factor_pcm_frames_f32(float* pFramesOut, const float* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float factor) {
    ma_copy_and_apply_volume_factor_pcm_frames_f32(pFramesOut, pFramesIn, frameCount, channels, factor);
}

void raia_ma_copy_and_apply_volume_factor_pcm_frames(void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount, ma_format format, ma_uint32 channels, float factor) {
    ma_copy_and_apply_volume_factor_pcm_frames(pFramesOut, pFramesIn, frameCount, format, channels, factor);
}

void raia_ma_apply_volume_factor_pcm_frames_u8(ma_uint8* pFrames, ma_uint64 frameCount, ma_uint32 channels, float factor) {
    ma_apply_volume_factor_pcm_frames_u8(pFrames, frameCount, channels, factor);
}

void raia_ma_apply_volume_factor_pcm_frames_s16(ma_int16* pFrames, ma_uint64 frameCount, ma_uint32 channels, float factor) {
    ma_apply_volume_factor_pcm_frames_s16(pFrames, frameCount, channels, factor);
}

void raia_ma_apply_volume_factor_pcm_frames_s24(void* pFrames, ma_uint64 frameCount, ma_uint32 channels, float factor) {
    ma_apply_volume_factor_pcm_frames_s24(pFrames, frameCount, channels, factor);
}

void raia_ma_apply_volume_factor_pcm_frames_s32(ma_int32* pFrames, ma_uint64 frameCount, ma_uint32 channels, float factor) {
    ma_apply_volume_factor_pcm_frames_s32(pFrames, frameCount, channels, factor);
}

void raia_ma_apply_volume_factor_pcm_frames_f32(float* pFrames, ma_uint64 frameCount, ma_uint32 channels, float factor) {
    ma_apply_volume_factor_pcm_frames_f32(pFrames, frameCount, channels, factor);
}

void raia_ma_apply_volume_factor_pcm_frames(void* pFrames, ma_uint64 frameCount, ma_format format, ma_uint32 channels, float factor) {
    ma_apply_volume_factor_pcm_frames(pFrames, frameCount, format, channels, factor);
}

void raia_ma_copy_and_apply_volume_factor_per_channel_f32(float* pFramesOut, const float* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float* pChannelGains) {
    ma_copy_and_apply_volume_factor_per_channel_f32(pFramesOut, pFramesIn, frameCount, channels, pChannelGains);
}

void raia_ma_copy_and_apply_volume_and_clip_samples_u8(ma_uint8* pDst, const ma_int16* pSrc, ma_uint64 count, float volume) {
    ma_copy_and_apply_volume_and_clip_samples_u8(pDst, pSrc, count, volume);
}

void raia_ma_copy_and_apply_volume_and_clip_samples_s16(ma_int16* pDst, const ma_int32* pSrc, ma_uint64 count, float volume) {
    ma_copy_and_apply_volume_and_clip_samples_s16(pDst, pSrc, count, volume);
}

void raia_ma_copy_and_apply_volume_and_clip_samples_s24(ma_uint8* pDst, const ma_int64* pSrc, ma_uint64 count, float volume) {
    ma_copy_and_apply_volume_and_clip_samples_s24(pDst, pSrc, count, volume);
}

void raia_ma_copy_and_apply_volume_and_clip_samples_s32(ma_int32* pDst, const ma_int64* pSrc, ma_uint64 count, float volume) {
    ma_copy_and_apply_volume_and_clip_samples_s32(pDst, pSrc, count, volume);
}

void raia_ma_copy_and_apply_volume_and_clip_samples_f32(float* pDst, const float* pSrc, ma_uint64 count, float volume) {
    ma_copy_and_apply_volume_and_clip_samples_f32(pDst, pSrc, count, volume);
}

void raia_ma_copy_and_apply_volume_and_clip_pcm_frames(void* pDst, const void* pSrc, ma_uint64 frameCount, ma_format format, ma_uint32 channels, float volume) {
    ma_copy_and_apply_volume_and_clip_pcm_frames(pDst, pSrc, frameCount, format, channels, volume);
}

float raia_ma_volume_linear_to_db(float factor) {
    return ma_volume_linear_to_db(factor);
}

float raia_ma_volume_db_to_linear(float gain) {
    return ma_volume_db_to_linear(gain);
}

ma_result raia_ma_mix_pcm_frames_f32(float* pDst, const float* pSrc, ma_uint64 frameCount, ma_uint32 channels, float volume) {
    return ma_mix_pcm_frames_f32(pDst, pSrc, frameCount, channels, volume);
}

// VFS

ma_result raia_ma_vfs_open(ma_vfs* pVFS, const char* pFilePath, ma_uint32 openMode, ma_vfs_file* pFile) {
    return ma_vfs_open(pVFS, pFilePath, openMode, pFile);
}

ma_result raia_ma_vfs_open_w(ma_vfs* pVFS, const wchar_t* pFilePath, ma_uint32 openMode, ma_vfs_file* pFile) {
    return ma_vfs_open_w(pVFS, pFilePath, openMode, pFile);
}

ma_result raia_ma_vfs_close(ma_vfs* pVFS, ma_vfs_file file) {
    return ma_vfs_close(pVFS, file);
}

ma_result raia_ma_vfs_read(ma_vfs* pVFS, ma_vfs_file file, void* pDst, size_t sizeInBytes, size_t* pBytesRead) {
    return ma_vfs_read(pVFS, file, pDst, sizeInBytes, pBytesRead);
}

ma_result raia_ma_vfs_write(ma_vfs* pVFS, ma_vfs_file file, const void* pSrc, size_t sizeInBytes, size_t* pBytesWritten) {
    return ma_vfs_write(pVFS, file, pSrc, sizeInBytes, pBytesWritten);
}

ma_result raia_ma_vfs_seek(ma_vfs* pVFS, ma_vfs_file file, ma_int64 offset, ma_seek_origin origin) {
    return ma_vfs_seek(pVFS, file, offset, origin);
}

ma_result raia_ma_vfs_tell(ma_vfs* pVFS, ma_vfs_file file, ma_int64* pCursor) {
    return ma_vfs_tell(pVFS, file, pCursor);
}

ma_result raia_ma_vfs_info(ma_vfs* pVFS, ma_vfs_file file, ma_file_info* pInfo) {
    return ma_vfs_info(pVFS, file, pInfo);
}

ma_result raia_ma_vfs_open_and_read_file(ma_vfs* pVFS, const char* pFilePath, void** ppData, size_t* pSize, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_vfs_open_and_read_file(pVFS, pFilePath, ppData, pSize, pAllocationCallbacks);
}

ma_result raia_ma_default_vfs_init(ma_default_vfs* pVFS, const ma_allocation_callbacks* pAllocationCallbacks) {
    return ma_default_vfs_init(pVFS, pAllocationCallbacks);
}

// Decoding

#ifndef MA_NO_DECODING

ma_decoding_backend_config raia_ma_decoding_backend_config_init(ma_format preferredFormat, ma_uint32 seekPointCount) {
    return ma_decoding_backend_config_init(preferredFormat, seekPointCount);
}

ma_decoder_config raia_ma_decoder_config_init(ma_format outputFormat, ma_uint32 outputChannels, ma_uint32 outputSampleRate) {
    return ma_decoder_config_init(outputFormat, outputChannels, outputSampleRate);
}

ma_decoder_config raia_ma_decoder_config_init_default(void) {
    return ma_decoder_config_init_default();
}

ma_result raia_ma_decoder_init(ma_decoder_read_proc onRead, ma_decoder_seek_proc onSeek, void* pUserData, const ma_decoder_config* pConfig, ma_decoder* pDecoder) {
    return ma_decoder_init(onRead, onSeek, pUserData, pConfig, pDecoder);
}

ma_result raia_ma_decoder_init_memory(const void* pData, size_t dataSize, const ma_decoder_config* pConfig, ma_decoder* pDecoder) {
    return ma_decoder_init_memory(pData, dataSize, pConfig, pDecoder);
}

ma_result raia_ma_decoder_init_vfs(ma_vfs* pVFS, const char* pFilePath, const ma_decoder_config* pConfig, ma_decoder* pDecoder) {
    return ma_decoder_init_vfs(pVFS, pFilePath, pConfig, pDecoder);
}

ma_result raia_ma_decoder_init_vfs_w(ma_vfs* pVFS, const wchar_t* pFilePath, const ma_decoder_config* pConfig, ma_decoder* pDecoder) {
    return ma_decoder_init_vfs_w(pVFS, pFilePath, pConfig, pDecoder);
}

ma_result raia_ma_decoder_init_file(const char* pFilePath, const ma_decoder_config* pConfig, ma_decoder* pDecoder) {
    return ma_decoder_init_file(pFilePath, pConfig, pDecoder);
}

ma_result raia_ma_decoder_init_file_w(const wchar_t* pFilePath, const ma_decoder_config* pConfig, ma_decoder* pDecoder) {
    return ma_decoder_init_file_w(pFilePath, pConfig, pDecoder);
}

ma_result raia_ma_decoder_uninit(ma_decoder* pDecoder) {
    return ma_decoder_uninit(pDecoder);
}

ma_result raia_ma_decoder_read_pcm_frames(ma_decoder* pDecoder, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_decoder_read_pcm_frames(pDecoder, pFramesOut, frameCount, pFramesRead);
}

ma_result raia_ma_decoder_seek_to_pcm_frame(ma_decoder* pDecoder, ma_uint64 frameIndex) {
    return ma_decoder_seek_to_pcm_frame(pDecoder, frameIndex);
}

ma_result raia_ma_decoder_get_data_format(ma_decoder* pDecoder, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap) {
    return ma_decoder_get_data_format(pDecoder, pFormat, pChannels, pSampleRate, pChannelMap, channelMapCap);
}

ma_result raia_ma_decoder_get_cursor_in_pcm_frames(ma_decoder* pDecoder, ma_uint64* pCursor) {
    return ma_decoder_get_cursor_in_pcm_frames(pDecoder, pCursor);
}

ma_result raia_ma_decoder_get_length_in_pcm_frames(ma_decoder* pDecoder, ma_uint64* pLength) {
    return ma_decoder_get_length_in_pcm_frames(pDecoder, pLength);
}

ma_result raia_ma_decoder_get_available_frames(ma_decoder* pDecoder, ma_uint64* pAvailableFrames) {
    return ma_decoder_get_available_frames(pDecoder, pAvailableFrames);
}

ma_result raia_ma_decode_from_vfs(ma_vfs* pVFS, const char* pFilePath, ma_decoder_config* pConfig, ma_uint64* pFrameCountOut, void** ppPCMFramesOut) {
    return ma_decode_from_vfs(pVFS, pFilePath, pConfig, pFrameCountOut, ppPCMFramesOut);
}

ma_result raia_ma_decode_file(const char* pFilePath, ma_decoder_config* pConfig, ma_uint64* pFrameCountOut, void** ppPCMFramesOut) {
    return ma_decode_file(pFilePath, pConfig, pFrameCountOut, ppPCMFramesOut);
}

ma_result raia_ma_decode_memory(const void* pData, size_t dataSize, ma_decoder_config* pConfig, ma_uint64* pFrameCountOut, void** ppPCMFramesOut) {
    return ma_decode_memory(pData, dataSize, pConfig, pFrameCountOut, ppPCMFramesOut);
}

#endif  /* MA_NO_DECODING */

// Encoding

#ifndef MA_NO_ENCODING

ma_encoder_config raia_ma_encoder_config_init(ma_encoding_format encodingFormat, ma_format format, ma_uint32 channels, ma_uint32 sampleRate) {
    return ma_encoder_config_init(encodingFormat, format, channels, sampleRate);
}

ma_result raia_ma_encoder_init(ma_encoder_write_proc onWrite, ma_encoder_seek_proc onSeek, void* pUserData, const ma_encoder_config* pConfig, ma_encoder* pEncoder) {
    return ma_encoder_init(onWrite, onSeek, pUserData, pConfig, pEncoder);
}

ma_result raia_ma_encoder_init_vfs(ma_vfs* pVFS, const char* pFilePath, const ma_encoder_config* pConfig, ma_encoder* pEncoder) {
    return ma_encoder_init_vfs(pVFS, pFilePath, pConfig, pEncoder);
}

ma_result raia_ma_encoder_init_vfs_w(ma_vfs* pVFS, const wchar_t* pFilePath, const ma_encoder_config* pConfig, ma_encoder* pEncoder) {
    return ma_encoder_init_vfs_w(pVFS, pFilePath, pConfig, pEncoder);
}

ma_result raia_ma_encoder_init_file(const char* pFilePath, const ma_encoder_config* pConfig, ma_encoder* pEncoder) {
    return ma_encoder_init_file(pFilePath, pConfig, pEncoder);
}

ma_result raia_ma_encoder_init_file_w(const wchar_t* pFilePath, const ma_encoder_config* pConfig, ma_encoder* pEncoder) {
    return ma_encoder_init_file_w(pFilePath, pConfig, pEncoder);
}

void raia_ma_encoder_uninit(ma_encoder* pEncoder) {
    ma_encoder_uninit(pEncoder);
}

ma_result raia_ma_encoder_write_pcm_frames(ma_encoder* pEncoder, const void* pFramesIn, ma_uint64 frameCount, ma_uint64* pFramesWritten) {
    return ma_encoder_write_pcm_frames(pEncoder, pFramesIn, frameCount, pFramesWritten);
}

#endif /* MA_NO_ENCODING */

// Generation

#ifndef MA_NO_GENERATION

ma_waveform_config raia_ma_waveform_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, ma_waveform_type type, double amplitude, double frequency) {
    return ma_waveform_config_init(format, channels, sampleRate, type, amplitude, frequency);
}

ma_result raia_ma_waveform_init(const ma_waveform_config* pConfig, ma_waveform* pWaveform) {
    return ma_waveform_init(pConfig, pWaveform);
}

void raia_ma_waveform_uninit(ma_waveform* pWaveform) {
    ma_waveform_uninit(pWaveform);
}

ma_result raia_ma_waveform_read_pcm_frames(ma_waveform* pWaveform, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_waveform_read_pcm_frames(pWaveform, pFramesOut, frameCount, pFramesRead);
}

ma_result raia_ma_waveform_seek_to_pcm_frame(ma_waveform* pWaveform, ma_uint64 frameIndex) {
    return ma_waveform_seek_to_pcm_frame(pWaveform, frameIndex);
}

ma_result raia_ma_waveform_set_amplitude(ma_waveform* pWaveform, double amplitude) {
    return ma_waveform_set_amplitude(pWaveform, amplitude);
}

ma_result raia_ma_waveform_set_frequency(ma_waveform* pWaveform, double frequency) {
    return ma_waveform_set_frequency(pWaveform, frequency);
}

ma_result raia_ma_waveform_set_type(ma_waveform* pWaveform, ma_waveform_type type) {
    return ma_waveform_set_type(pWaveform, type);
}

ma_result raia_ma_waveform_set_sample_rate(ma_waveform* pWaveform, ma_uint32 sampleRate) {
    return ma_waveform_set_sample_rate(pWaveform, sampleRate);
}

ma_pulsewave_config raia_ma_pulsewave_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double dutyCycle, double amplitude, double frequency) {
    return ma_pulsewave_config_init(format, channels, sampleRate, dutyCycle, amplitude, frequency);
}

ma_result raia_ma_pulsewave_init(const ma_pulsewave_config* pConfig, ma_pulsewave* pWaveform) {
    return ma_pulsewave_init(pConfig, pWaveform);
}

void raia_ma_pulsewave_uninit(ma_pulsewave* pWaveform) {
    ma_pulsewave_uninit(pWaveform);
}

ma_result raia_ma_pulsewave_read_pcm_frames(ma_pulsewave* pWaveform, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_pulsewave_read_pcm_frames(pWaveform, pFramesOut, frameCount, pFramesRead);
}

ma_result raia_ma_pulsewave_seek_to_pcm_frame(ma_pulsewave* pWaveform, ma_uint64 frameIndex) {
    return ma_pulsewave_seek_to_pcm_frame(pWaveform, frameIndex);
}

ma_result raia_ma_pulsewave_set_amplitude(ma_pulsewave* pWaveform, double amplitude) {
    return ma_pulsewave_set_amplitude(pWaveform, amplitude);
}

ma_result raia_ma_pulsewave_set_frequency(ma_pulsewave* pWaveform, double frequency) {
    return ma_pulsewave_set_frequency(pWaveform, frequency);
}

ma_result raia_ma_pulsewave_set_sample_rate(ma_pulsewave* pWaveform, ma_uint32 sampleRate) {
    return ma_pulsewave_set_sample_rate(pWaveform, sampleRate);
}

ma_result raia_ma_pulsewave_set_duty_cycle(ma_pulsewave* pWaveform, double dutyCycle) {
    return ma_pulsewave_set_duty_cycle(pWaveform, dutyCycle);
}

ma_noise_config raia_ma_noise_config_init(ma_format format, ma_uint32 channels, ma_noise_type type, ma_int32 seed, double amplitude) {
    return ma_noise_config_init(format, channels, type, seed, amplitude);
}

ma_result raia_ma_noise_get_heap_size(const ma_noise_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_noise_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_noise_init_preallocated(const ma_noise_config* pConfig, void* pHeap, ma_noise* pNoise) {
    return ma_noise_init_preallocated(pConfig, pHeap, pNoise);
}

ma_result raia_ma_noise_init(const ma_noise_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_noise* pNoise) {
    return ma_noise_init(pConfig, pAllocationCallbacks, pNoise);
}

void raia_ma_noise_uninit(ma_noise* pNoise, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_noise_uninit(pNoise, pAllocationCallbacks);
}

ma_result raia_ma_noise_read_pcm_frames(ma_noise* pNoise, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_noise_read_pcm_frames(pNoise, pFramesOut, frameCount, pFramesRead);
}

ma_result raia_ma_noise_set_amplitude(ma_noise* pNoise, double amplitude) {
    return ma_noise_set_amplitude(pNoise, amplitude);
}

ma_result raia_ma_noise_set_seed(ma_noise* pNoise, ma_int32 seed) {
    return ma_noise_set_seed(pNoise, seed);
}

ma_result raia_ma_noise_set_type(ma_noise* pNoise, ma_noise_type type) {
    return ma_noise_set_type(pNoise, type);
}

#endif  /* MA_NO_GENERATION */

// Resource Manager

#ifndef MA_NO_RESOURCE_MANAGER

ma_resource_manager_pipeline_notifications raia_ma_resource_manager_pipeline_notifications_init(void) {
    return ma_resource_manager_pipeline_notifications_init();
}

ma_resource_manager_data_source_config raia_ma_resource_manager_data_source_config_init(void) {
    return ma_resource_manager_data_source_config_init();
}

ma_resource_manager_config raia_ma_resource_manager_config_init(void) {
    return ma_resource_manager_config_init();
}

ma_result raia_ma_resource_manager_init(const ma_resource_manager_config* pConfig, ma_resource_manager* pResourceManager) {
    return ma_resource_manager_init(pConfig, pResourceManager);
}

void raia_ma_resource_manager_uninit(ma_resource_manager* pResourceManager) {
    ma_resource_manager_uninit(pResourceManager);
}

ma_log* raia_ma_resource_manager_get_log(ma_resource_manager* pResourceManager) {
    return ma_resource_manager_get_log(pResourceManager);
}

ma_result raia_ma_resource_manager_register_file(ma_resource_manager* pResourceManager, const char* pFilePath, ma_uint32 flags) {
    return ma_resource_manager_register_file(pResourceManager, pFilePath, flags);
}

ma_result raia_ma_resource_manager_register_file_w(ma_resource_manager* pResourceManager, const wchar_t* pFilePath, ma_uint32 flags) {
    return ma_resource_manager_register_file_w(pResourceManager, pFilePath, flags);
}

ma_result raia_ma_resource_manager_register_decoded_data(ma_resource_manager* pResourceManager, const char* pName, const void* pData, ma_uint64 frameCount, ma_format format, ma_uint32 channels, ma_uint32 sampleRate) {
    return ma_resource_manager_register_decoded_data(pResourceManager, pName, pData, frameCount, format, channels, sampleRate);
}

ma_result raia_ma_resource_manager_register_decoded_data_w(ma_resource_manager* pResourceManager, const wchar_t* pName, const void* pData, ma_uint64 frameCount, ma_format format, ma_uint32 channels, ma_uint32 sampleRate) {
    return ma_resource_manager_register_decoded_data_w(pResourceManager, pName, pData, frameCount, format, channels, sampleRate);
}

ma_result raia_ma_resource_manager_register_encoded_data(ma_resource_manager* pResourceManager, const char* pName, const void* pData, size_t sizeInBytes) {
    return ma_resource_manager_register_encoded_data(pResourceManager, pName, pData, sizeInBytes);
}

ma_result raia_ma_resource_manager_register_encoded_data_w(ma_resource_manager* pResourceManager, const wchar_t* pName, const void* pData, size_t sizeInBytes) {
    return ma_resource_manager_register_encoded_data_w(pResourceManager, pName, pData, sizeInBytes);
}

ma_result raia_ma_resource_manager_unregister_file(ma_resource_manager* pResourceManager, const char* pFilePath) {
    return ma_resource_manager_unregister_file(pResourceManager, pFilePath);
}

ma_result raia_ma_resource_manager_unregister_file_w(ma_resource_manager* pResourceManager, const wchar_t* pFilePath) {
    return ma_resource_manager_unregister_file_w(pResourceManager, pFilePath);
}

ma_result raia_ma_resource_manager_unregister_data(ma_resource_manager* pResourceManager, const char* pName) {
    return ma_resource_manager_unregister_data(pResourceManager, pName);
}

ma_result raia_ma_resource_manager_unregister_data_w(ma_resource_manager* pResourceManager, const wchar_t* pName) {
    return ma_resource_manager_unregister_data_w(pResourceManager, pName);
}

ma_result raia_ma_resource_manager_data_buffer_init_ex(ma_resource_manager* pResourceManager, const ma_resource_manager_data_source_config* pConfig, ma_resource_manager_data_buffer* pDataBuffer) {
    return ma_resource_manager_data_buffer_init_ex(pResourceManager, pConfig, pDataBuffer);
}

ma_result raia_ma_resource_manager_data_buffer_init(ma_resource_manager* pResourceManager, const char* pFilePath, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_buffer* pDataBuffer) {
    return ma_resource_manager_data_buffer_init(pResourceManager, pFilePath, flags, pNotifications, pDataBuffer);
}

ma_result raia_ma_resource_manager_data_buffer_init_w(ma_resource_manager* pResourceManager, const wchar_t* pFilePath, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_buffer* pDataBuffer) {
    return ma_resource_manager_data_buffer_init_w(pResourceManager, pFilePath, flags, pNotifications, pDataBuffer);
}

ma_result raia_ma_resource_manager_data_buffer_init_copy(ma_resource_manager* pResourceManager, const ma_resource_manager_data_buffer* pExistingDataBuffer, ma_resource_manager_data_buffer* pDataBuffer) {
    return ma_resource_manager_data_buffer_init_copy(pResourceManager, pExistingDataBuffer, pDataBuffer);
}

ma_result raia_ma_resource_manager_data_buffer_uninit(ma_resource_manager_data_buffer* pDataBuffer) {
    return ma_resource_manager_data_buffer_uninit(pDataBuffer);
}

ma_result raia_ma_resource_manager_data_buffer_read_pcm_frames(ma_resource_manager_data_buffer* pDataBuffer, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_resource_manager_data_buffer_read_pcm_frames(pDataBuffer, pFramesOut, frameCount, pFramesRead);
}

ma_result raia_ma_resource_manager_data_buffer_seek_to_pcm_frame(ma_resource_manager_data_buffer* pDataBuffer, ma_uint64 frameIndex) {
    return ma_resource_manager_data_buffer_seek_to_pcm_frame(pDataBuffer, frameIndex);
}

ma_result raia_ma_resource_manager_data_buffer_get_data_format(ma_resource_manager_data_buffer* pDataBuffer, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap) {
    return ma_resource_manager_data_buffer_get_data_format(pDataBuffer, pFormat, pChannels, pSampleRate, pChannelMap, channelMapCap);
}

ma_result raia_ma_resource_manager_data_buffer_get_cursor_in_pcm_frames(ma_resource_manager_data_buffer* pDataBuffer, ma_uint64* pCursor) {
    return ma_resource_manager_data_buffer_get_cursor_in_pcm_frames(pDataBuffer, pCursor);
}

ma_result raia_ma_resource_manager_data_buffer_get_length_in_pcm_frames(ma_resource_manager_data_buffer* pDataBuffer, ma_uint64* pLength) {
    return ma_resource_manager_data_buffer_get_length_in_pcm_frames(pDataBuffer, pLength);
}

ma_result raia_ma_resource_manager_data_buffer_result(const ma_resource_manager_data_buffer* pDataBuffer) {
    return ma_resource_manager_data_buffer_result(pDataBuffer);
}

ma_result raia_ma_resource_manager_data_buffer_set_looping(ma_resource_manager_data_buffer* pDataBuffer, ma_bool32 isLooping) {
    return ma_resource_manager_data_buffer_set_looping(pDataBuffer, isLooping);
}

ma_bool32 raia_ma_resource_manager_data_buffer_is_looping(const ma_resource_manager_data_buffer* pDataBuffer) {
    return ma_resource_manager_data_buffer_is_looping(pDataBuffer);
}

ma_result raia_ma_resource_manager_data_buffer_get_available_frames(ma_resource_manager_data_buffer* pDataBuffer, ma_uint64* pAvailableFrames) {
    return ma_resource_manager_data_buffer_get_available_frames(pDataBuffer, pAvailableFrames);
}

ma_result raia_ma_resource_manager_data_stream_init_ex(ma_resource_manager* pResourceManager, const ma_resource_manager_data_source_config* pConfig, ma_resource_manager_data_stream* pDataStream) {
    return ma_resource_manager_data_stream_init_ex(pResourceManager, pConfig, pDataStream);
}

ma_result raia_ma_resource_manager_data_stream_init(ma_resource_manager* pResourceManager, const char* pFilePath, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_stream* pDataStream) {
    return ma_resource_manager_data_stream_init(pResourceManager, pFilePath, flags, pNotifications, pDataStream);
}

ma_result raia_ma_resource_manager_data_stream_init_w(ma_resource_manager* pResourceManager, const wchar_t* pFilePath, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_stream* pDataStream) {
    return ma_resource_manager_data_stream_init_w(pResourceManager, pFilePath, flags, pNotifications, pDataStream);
}

ma_result raia_ma_resource_manager_data_stream_uninit(ma_resource_manager_data_stream* pDataStream) {
    return ma_resource_manager_data_stream_uninit(pDataStream);
}

ma_result raia_ma_resource_manager_data_stream_read_pcm_frames(ma_resource_manager_data_stream* pDataStream, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_resource_manager_data_stream_read_pcm_frames(pDataStream, pFramesOut, frameCount, pFramesRead);
}

ma_result raia_ma_resource_manager_data_stream_seek_to_pcm_frame(ma_resource_manager_data_stream* pDataStream, ma_uint64 frameIndex) {
    return ma_resource_manager_data_stream_seek_to_pcm_frame(pDataStream, frameIndex);
}

ma_result raia_ma_resource_manager_data_stream_get_data_format(ma_resource_manager_data_stream* pDataStream, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap) {
    return ma_resource_manager_data_stream_get_data_format(pDataStream, pFormat, pChannels, pSampleRate, pChannelMap, channelMapCap);
}

ma_result raia_ma_resource_manager_data_stream_get_cursor_in_pcm_frames(ma_resource_manager_data_stream* pDataStream, ma_uint64* pCursor) {
    return ma_resource_manager_data_stream_get_cursor_in_pcm_frames(pDataStream, pCursor);
}

ma_result raia_ma_resource_manager_data_stream_get_length_in_pcm_frames(ma_resource_manager_data_stream* pDataStream, ma_uint64* pLength) {
    return ma_resource_manager_data_stream_get_length_in_pcm_frames(pDataStream, pLength);
}

ma_result raia_ma_resource_manager_data_stream_result(const ma_resource_manager_data_stream* pDataStream) {
    return ma_resource_manager_data_stream_result(pDataStream);
}

ma_result raia_ma_resource_manager_data_stream_set_looping(ma_resource_manager_data_stream* pDataStream, ma_bool32 isLooping) {
    return ma_resource_manager_data_stream_set_looping(pDataStream, isLooping);
}

ma_bool32 raia_ma_resource_manager_data_stream_is_looping(const ma_resource_manager_data_stream* pDataStream) {
    return ma_resource_manager_data_stream_is_looping(pDataStream);
}

ma_result raia_ma_resource_manager_data_stream_get_available_frames(ma_resource_manager_data_stream* pDataStream, ma_uint64* pAvailableFrames) {
    return ma_resource_manager_data_stream_get_available_frames(pDataStream, pAvailableFrames);
}

ma_result raia_ma_resource_manager_data_source_init_ex(ma_resource_manager* pResourceManager, const ma_resource_manager_data_source_config* pConfig, ma_resource_manager_data_source* pDataSource) {
    return ma_resource_manager_data_source_init_ex(pResourceManager, pConfig, pDataSource);
}

ma_result raia_ma_resource_manager_data_source_init(ma_resource_manager* pResourceManager, const char* pName, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_source* pDataSource) {
    return ma_resource_manager_data_source_init(pResourceManager, pName, flags, pNotifications, pDataSource);
}

ma_result raia_ma_resource_manager_data_source_init_w(ma_resource_manager* pResourceManager, const wchar_t* pName, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_source* pDataSource) {
    return ma_resource_manager_data_source_init_w(pResourceManager, pName, flags, pNotifications, pDataSource);
}

ma_result raia_ma_resource_manager_data_source_init_copy(ma_resource_manager* pResourceManager, const ma_resource_manager_data_source* pExistingDataSource, ma_resource_manager_data_source* pDataSource) {
    return ma_resource_manager_data_source_init_copy(pResourceManager, pExistingDataSource, pDataSource);
}

ma_result raia_ma_resource_manager_data_source_uninit(ma_resource_manager_data_source* pDataSource) {
    return ma_resource_manager_data_source_uninit(pDataSource);
}

ma_result raia_ma_resource_manager_data_source_read_pcm_frames(ma_resource_manager_data_source* pDataSource, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_resource_manager_data_source_read_pcm_frames(pDataSource, pFramesOut, frameCount, pFramesRead);
}

ma_result raia_ma_resource_manager_data_source_seek_to_pcm_frame(ma_resource_manager_data_source* pDataSource, ma_uint64 frameIndex) {
    return ma_resource_manager_data_source_seek_to_pcm_frame(pDataSource, frameIndex);
}

ma_result raia_ma_resource_manager_data_source_get_data_format(ma_resource_manager_data_source* pDataSource, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap) {
    return ma_resource_manager_data_source_get_data_format(pDataSource, pFormat, pChannels, pSampleRate, pChannelMap, channelMapCap);
}

ma_result raia_ma_resource_manager_data_source_get_cursor_in_pcm_frames(ma_resource_manager_data_source* pDataSource, ma_uint64* pCursor) {
    return ma_resource_manager_data_source_get_cursor_in_pcm_frames(pDataSource, pCursor);
}

ma_result raia_ma_resource_manager_data_source_get_length_in_pcm_frames(ma_resource_manager_data_source* pDataSource, ma_uint64* pLength) {
    return ma_resource_manager_data_source_get_length_in_pcm_frames(pDataSource, pLength);
}

ma_result raia_ma_resource_manager_data_source_result(const ma_resource_manager_data_source* pDataSource) {
    return ma_resource_manager_data_source_result(pDataSource);
}

ma_result raia_ma_resource_manager_data_source_set_looping(ma_resource_manager_data_source* pDataSource, ma_bool32 isLooping) {
    return ma_resource_manager_data_source_set_looping(pDataSource, isLooping);
}

ma_bool32 raia_ma_resource_manager_data_source_is_looping(const ma_resource_manager_data_source* pDataSource) {
    return ma_resource_manager_data_source_is_looping(pDataSource);
}

ma_result raia_ma_resource_manager_data_source_get_available_frames(ma_resource_manager_data_source* pDataSource, ma_uint64* pAvailableFrames) {
    return ma_resource_manager_data_source_get_available_frames(pDataSource, pAvailableFrames);
}

ma_result raia_ma_resource_manager_post_job(ma_resource_manager* pResourceManager, const ma_job* pJob) {
    return ma_resource_manager_post_job(pResourceManager, pJob);
}

ma_result raia_ma_resource_manager_post_job_quit(ma_resource_manager* pResourceManager) {
    return ma_resource_manager_post_job_quit(pResourceManager);
}

ma_result raia_ma_resource_manager_next_job(ma_resource_manager* pResourceManager, ma_job* pJob) {
    return ma_resource_manager_next_job(pResourceManager, pJob);
}

ma_result raia_ma_resource_manager_process_job(ma_resource_manager* pResourceManager, ma_job* pJob) {
    return ma_resource_manager_process_job(pResourceManager, pJob);
}

ma_result raia_ma_resource_manager_process_next_job(ma_resource_manager* pResourceManager) {
    return ma_resource_manager_process_next_job(pResourceManager);
}

#endif  /* MA_NO_RESOURCE_MANAGER */

// Node Graph

#ifndef MA_NO_NODE_GRAPH

ma_node_config raia_ma_node_config_init(void) {
    return ma_node_config_init();
}

ma_result raia_ma_node_get_heap_size(ma_node_graph* pNodeGraph, const ma_node_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_node_get_heap_size(pNodeGraph, pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_node_init_preallocated(ma_node_graph* pNodeGraph, const ma_node_config* pConfig, void* pHeap, ma_node* pNode) {
    return ma_node_init_preallocated(pNodeGraph, pConfig, pHeap, pNode);
}

ma_result raia_ma_node_init(ma_node_graph* pNodeGraph, const ma_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_node* pNode) {
    return ma_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pNode);
}

void raia_ma_node_uninit(ma_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_node_uninit(pNode, pAllocationCallbacks);
}

ma_node_graph* raia_ma_node_get_node_graph(const ma_node* pNode) {
    return ma_node_get_node_graph(pNode);
}

ma_uint32 raia_ma_node_get_input_bus_count(const ma_node* pNode) {
    return ma_node_get_input_bus_count(pNode);
}

ma_uint32 raia_ma_node_get_output_bus_count(const ma_node* pNode) {
    return ma_node_get_output_bus_count(pNode);
}

ma_uint32 raia_ma_node_get_input_channels(const ma_node* pNode, ma_uint32 inputBusIndex) {
    return ma_node_get_input_channels(pNode, inputBusIndex);
}

ma_uint32 raia_ma_node_get_output_channels(const ma_node* pNode, ma_uint32 outputBusIndex) {
    return ma_node_get_output_channels(pNode, outputBusIndex);
}

ma_result raia_ma_node_attach_output_bus(ma_node* pNode, ma_uint32 outputBusIndex, ma_node* pOtherNode, ma_uint32 otherNodeInputBusIndex) {
    return ma_node_attach_output_bus(pNode, outputBusIndex, pOtherNode, otherNodeInputBusIndex);
}

ma_result raia_ma_node_detach_output_bus(ma_node* pNode, ma_uint32 outputBusIndex) {
    return ma_node_detach_output_bus(pNode, outputBusIndex);
}

ma_result raia_ma_node_detach_all_output_buses(ma_node* pNode) {
    return ma_node_detach_all_output_buses(pNode);
}

ma_result raia_ma_node_set_output_bus_volume(ma_node* pNode, ma_uint32 outputBusIndex, float volume) {
    return ma_node_set_output_bus_volume(pNode, outputBusIndex, volume);
}

float raia_ma_node_get_output_bus_volume(const ma_node* pNode, ma_uint32 outputBusIndex) {
    return ma_node_get_output_bus_volume(pNode, outputBusIndex);
}

ma_result raia_ma_node_set_state(ma_node* pNode, ma_node_state state) {
    return ma_node_set_state(pNode, state);
}

ma_node_state raia_ma_node_get_state(const ma_node* pNode) {
    return ma_node_get_state(pNode);
}

ma_result raia_ma_node_set_state_time(ma_node* pNode, ma_node_state state, ma_uint64 globalTime) {
    return ma_node_set_state_time(pNode, state, globalTime);
}

ma_uint64 raia_ma_node_get_state_time(const ma_node* pNode, ma_node_state state) {
    return ma_node_get_state_time(pNode, state);
}

ma_node_state raia_ma_node_get_state_by_time(const ma_node* pNode, ma_uint64 globalTime) {
    return ma_node_get_state_by_time(pNode, globalTime);
}

ma_node_state raia_ma_node_get_state_by_time_range(const ma_node* pNode, ma_uint64 globalTimeBeg, ma_uint64 globalTimeEnd) {
    return ma_node_get_state_by_time_range(pNode, globalTimeBeg, globalTimeEnd);
}

ma_uint64 raia_ma_node_get_time(const ma_node* pNode) {
    return ma_node_get_time(pNode);
}

ma_result raia_ma_node_set_time(ma_node* pNode, ma_uint64 localTime) {
    return ma_node_set_time(pNode, localTime);
}

ma_node_graph_config raia_ma_node_graph_config_init(ma_uint32 channels) {
    return ma_node_graph_config_init(channels);
}

ma_result raia_ma_node_graph_init(const ma_node_graph_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_node_graph* pNodeGraph) {
    return ma_node_graph_init(pConfig, pAllocationCallbacks, pNodeGraph);
}

void raia_ma_node_graph_uninit(ma_node_graph* pNodeGraph, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_node_graph_uninit(pNodeGraph, pAllocationCallbacks);
}

ma_node* raia_ma_node_graph_get_endpoint(ma_node_graph* pNodeGraph) {
    return ma_node_graph_get_endpoint(pNodeGraph);
}

ma_result raia_ma_node_graph_read_pcm_frames(ma_node_graph* pNodeGraph, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_node_graph_read_pcm_frames(pNodeGraph, pFramesOut, frameCount, pFramesRead);
}

ma_uint32 raia_ma_node_graph_get_channels(const ma_node_graph* pNodeGraph) {
    return ma_node_graph_get_channels(pNodeGraph);
}

ma_uint64 raia_ma_node_graph_get_time(const ma_node_graph* pNodeGraph) {
    return ma_node_graph_get_time(pNodeGraph);
}

ma_result raia_ma_node_graph_set_time(ma_node_graph* pNodeGraph, ma_uint64 globalTime) {
    return ma_node_graph_set_time(pNodeGraph, globalTime);
}

ma_data_source_node_config raia_ma_data_source_node_config_init(ma_data_source* pDataSource) {
    return ma_data_source_node_config_init(pDataSource);
}

ma_result raia_ma_data_source_node_init(ma_node_graph* pNodeGraph, const ma_data_source_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_data_source_node* pDataSourceNode) {
    return ma_data_source_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pDataSourceNode);
}

void raia_ma_data_source_node_uninit(ma_data_source_node* pDataSourceNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_data_source_node_uninit(pDataSourceNode, pAllocationCallbacks);
}

ma_result raia_ma_data_source_node_set_looping(ma_data_source_node* pDataSourceNode, ma_bool32 isLooping) {
    return ma_data_source_node_set_looping(pDataSourceNode, isLooping);
}

ma_bool32 raia_ma_data_source_node_is_looping(ma_data_source_node* pDataSourceNode) {
    return ma_data_source_node_is_looping(pDataSourceNode);
}

ma_splitter_node_config raia_ma_splitter_node_config_init(ma_uint32 channels) {
    return ma_splitter_node_config_init(channels);
}

ma_result raia_ma_splitter_node_init(ma_node_graph* pNodeGraph, const ma_splitter_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_splitter_node* pSplitterNode) {
    return ma_splitter_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pSplitterNode);
}

void raia_ma_splitter_node_uninit(ma_splitter_node* pSplitterNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_splitter_node_uninit(pSplitterNode, pAllocationCallbacks);
}

ma_biquad_node_config raia_ma_biquad_node_config_init(ma_uint32 channels, float b0, float b1, float b2, float a0, float a1, float a2) {
    return ma_biquad_node_config_init(channels, b0, b1, b2, a0, a1, a2);
}

ma_result raia_ma_biquad_node_init(ma_node_graph* pNodeGraph, const ma_biquad_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_biquad_node* pNode) {
    return ma_biquad_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pNode);
}

ma_result raia_ma_biquad_node_reinit(const ma_biquad_config* pConfig, ma_biquad_node* pNode) {
    return ma_biquad_node_reinit(pConfig, pNode);
}

void raia_ma_biquad_node_uninit(ma_biquad_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_biquad_node_uninit(pNode, pAllocationCallbacks);
}

ma_lpf_node_config raia_ma_lpf_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order) {
    return ma_lpf_node_config_init(channels, sampleRate, cutoffFrequency, order);
}

ma_result raia_ma_lpf_node_init(ma_node_graph* pNodeGraph, const ma_lpf_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_lpf_node* pNode) {
    return ma_lpf_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pNode);
}

ma_result raia_ma_lpf_node_reinit(const ma_lpf_config* pConfig, ma_lpf_node* pNode) {
    return ma_lpf_node_reinit(pConfig, pNode);
}

void raia_ma_lpf_node_uninit(ma_lpf_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_lpf_node_uninit(pNode, pAllocationCallbacks);
}

ma_hpf_node_config raia_ma_hpf_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order) {
    return ma_hpf_node_config_init(channels, sampleRate, cutoffFrequency, order);
}

ma_result raia_ma_hpf_node_init(ma_node_graph* pNodeGraph, const ma_hpf_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hpf_node* pNode) {
    return ma_hpf_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pNode);
}

ma_result raia_ma_hpf_node_reinit(const ma_hpf_config* pConfig, ma_hpf_node* pNode) {
    return ma_hpf_node_reinit(pConfig, pNode);
}

void raia_ma_hpf_node_uninit(ma_hpf_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_hpf_node_uninit(pNode, pAllocationCallbacks);
}

ma_bpf_node_config raia_ma_bpf_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order) {
    return ma_bpf_node_config_init(channels, sampleRate, cutoffFrequency, order);
}

ma_result raia_ma_bpf_node_init(ma_node_graph* pNodeGraph, const ma_bpf_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_bpf_node* pNode) {
    return ma_bpf_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pNode);
}

ma_result raia_ma_bpf_node_reinit(const ma_bpf_config* pConfig, ma_bpf_node* pNode) {
    return ma_bpf_node_reinit(pConfig, pNode);
}

void raia_ma_bpf_node_uninit(ma_bpf_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_bpf_node_uninit(pNode, pAllocationCallbacks);
}

ma_notch_node_config raia_ma_notch_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double q, double frequency) {
    return ma_notch_node_config_init(channels, sampleRate, q, frequency);
}

ma_result raia_ma_notch_node_init(ma_node_graph* pNodeGraph, const ma_notch_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_notch_node* pNode) {
    return ma_notch_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pNode);
}

ma_result raia_ma_notch_node_reinit(const ma_notch_config* pConfig, ma_notch_node* pNode) {
    return ma_notch_node_reinit(pConfig, pNode);
}

void raia_ma_notch_node_uninit(ma_notch_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_notch_node_uninit(pNode, pAllocationCallbacks);
}

ma_peak_node_config raia_ma_peak_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double q, double frequency) {
    return ma_peak_node_config_init(channels, sampleRate, gainDB, q, frequency);
}

ma_result raia_ma_peak_node_init(ma_node_graph* pNodeGraph, const ma_peak_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_peak_node* pNode) {
    return ma_peak_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pNode);
}

ma_result raia_ma_peak_node_reinit(const ma_peak_config* pConfig, ma_peak_node* pNode) {
    return ma_peak_node_reinit(pConfig, pNode);
}

void raia_ma_peak_node_uninit(ma_peak_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_peak_node_uninit(pNode, pAllocationCallbacks);
}

ma_loshelf_node_config raia_ma_loshelf_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double q, double frequency) {
    return ma_loshelf_node_config_init(channels, sampleRate, gainDB, q, frequency);
}

ma_result raia_ma_loshelf_node_init(ma_node_graph* pNodeGraph, const ma_loshelf_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_loshelf_node* pNode) {
    return ma_loshelf_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pNode);
}

ma_result raia_ma_loshelf_node_reinit(const ma_loshelf_config* pConfig, ma_loshelf_node* pNode) {
    return ma_loshelf_node_reinit(pConfig, pNode);
}

void raia_ma_loshelf_node_uninit(ma_loshelf_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_loshelf_node_uninit(pNode, pAllocationCallbacks);
}

ma_hishelf_node_config raia_ma_hishelf_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double q, double frequency) {
    return ma_hishelf_node_config_init(channels, sampleRate, gainDB, q, frequency);
}

ma_result raia_ma_hishelf_node_init(ma_node_graph* pNodeGraph, const ma_hishelf_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hishelf_node* pNode) {
    return ma_hishelf_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pNode);
}

ma_result raia_ma_hishelf_node_reinit(const ma_hishelf_config* pConfig, ma_hishelf_node* pNode) {
    return ma_hishelf_node_reinit(pConfig, pNode);
}

void raia_ma_hishelf_node_uninit(ma_hishelf_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_hishelf_node_uninit(pNode, pAllocationCallbacks);
}

ma_delay_node_config raia_ma_delay_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, ma_uint32 delayInFrames, float decay) {
    return ma_delay_node_config_init(channels, sampleRate, delayInFrames, decay);
}

ma_result raia_ma_delay_node_init(ma_node_graph* pNodeGraph, const ma_delay_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_delay_node* pDelayNode) {
    return ma_delay_node_init(pNodeGraph, pConfig, pAllocationCallbacks, pDelayNode);
}

void raia_ma_delay_node_uninit(ma_delay_node* pDelayNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_delay_node_uninit(pDelayNode, pAllocationCallbacks);
}

void raia_ma_delay_node_set_wet(ma_delay_node* pDelayNode, float value) {
    ma_delay_node_set_wet(pDelayNode, value);
}

float raia_ma_delay_node_get_wet(const ma_delay_node* pDelayNode) {
    return ma_delay_node_get_wet(pDelayNode);
}

void raia_ma_delay_node_set_dry(ma_delay_node* pDelayNode, float value) {
    ma_delay_node_set_dry(pDelayNode, value);
}

float raia_ma_delay_node_get_dry(const ma_delay_node* pDelayNode) {
    return ma_delay_node_get_dry(pDelayNode);
}

void raia_ma_delay_node_set_decay(ma_delay_node* pDelayNode, float value) {
    ma_delay_node_set_decay(pDelayNode, value);
}

float raia_ma_delay_node_get_decay(const ma_delay_node* pDelayNode) {
    return ma_delay_node_get_decay(pDelayNode);
}

#endif  /* MA_NO_NODE_GRAPH */

// Engine

#if !defined(MA_NO_ENGINE) && !defined(MA_NO_NODE_GRAPH)

ma_engine_node_config raia_ma_engine_node_config_init(ma_engine* pEngine, ma_engine_node_type type, ma_uint32 flags) {
    return ma_engine_node_config_init(pEngine, type, flags);
}

ma_result raia_ma_engine_node_get_heap_size(const ma_engine_node_config* pConfig, size_t* pHeapSizeInBytes) {
    return ma_engine_node_get_heap_size(pConfig, pHeapSizeInBytes);
}

ma_result raia_ma_engine_node_init_preallocated(const ma_engine_node_config* pConfig, void* pHeap, ma_engine_node* pEngineNode) {
    return ma_engine_node_init_preallocated(pConfig, pHeap, pEngineNode);
}

ma_result raia_ma_engine_node_init(const ma_engine_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_engine_node* pEngineNode) {
    return ma_engine_node_init(pConfig, pAllocationCallbacks, pEngineNode);
}

void raia_ma_engine_node_uninit(ma_engine_node* pEngineNode, const ma_allocation_callbacks* pAllocationCallbacks) {
    ma_engine_node_uninit(pEngineNode, pAllocationCallbacks);
}

ma_sound_config raia_ma_sound_config_init(void) {
    return ma_sound_config_init();
}

ma_sound_config raia_ma_sound_config_init_2(ma_engine* pEngine) {
    return ma_sound_config_init_2(pEngine);
}

ma_sound_group_config raia_ma_sound_group_config_init(void) {
    return ma_sound_group_config_init();
}

ma_sound_group_config raia_ma_sound_group_config_init_2(ma_engine* pEngine) {
    return ma_sound_group_config_init_2(pEngine);
}

ma_engine_config raia_ma_engine_config_init(void) {
    return ma_engine_config_init();
}

ma_result raia_ma_engine_init(const ma_engine_config* pConfig, ma_engine* pEngine) {
    return ma_engine_init(pConfig, pEngine);
}

void raia_ma_engine_uninit(ma_engine* pEngine) {
    ma_engine_uninit(pEngine);
}

ma_result raia_ma_engine_read_pcm_frames(ma_engine* pEngine, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead) {
    return ma_engine_read_pcm_frames(pEngine, pFramesOut, frameCount, pFramesRead);
}

ma_node_graph* raia_ma_engine_get_node_graph(ma_engine* pEngine) {
    return ma_engine_get_node_graph(pEngine);
}

#if !defined(MA_NO_RESOURCE_MANAGER)

ma_resource_manager* raia_ma_engine_get_resource_manager(ma_engine* pEngine) {
    return ma_engine_get_resource_manager(pEngine);
}

#endif

ma_device* raia_ma_engine_get_device(ma_engine* pEngine) {
    return ma_engine_get_device(pEngine);
}

ma_log* raia_ma_engine_get_log(ma_engine* pEngine) {
    return ma_engine_get_log(pEngine);
}

ma_node* raia_ma_engine_get_endpoint(ma_engine* pEngine) {
    return ma_engine_get_endpoint(pEngine);
}

ma_uint64 raia_ma_engine_get_time_in_pcm_frames(const ma_engine* pEngine) {
    return ma_engine_get_time_in_pcm_frames(pEngine);
}

ma_uint64 raia_ma_engine_get_time_in_milliseconds(const ma_engine* pEngine) {
    return ma_engine_get_time_in_milliseconds(pEngine);
}

ma_result raia_ma_engine_set_time_in_pcm_frames(ma_engine* pEngine, ma_uint64 globalTime) {
    return ma_engine_set_time_in_pcm_frames(pEngine, globalTime);
}

ma_result raia_ma_engine_set_time_in_milliseconds(ma_engine* pEngine, ma_uint64 globalTime) {
    return ma_engine_set_time_in_milliseconds(pEngine, globalTime);
}

ma_uint64 raia_ma_engine_get_time(const ma_engine* pEngine) {
    return ma_engine_get_time(pEngine);
}

ma_result raia_ma_engine_set_time(ma_engine* pEngine, ma_uint64 globalTime) {
    return ma_engine_set_time(pEngine, globalTime);
}

ma_uint32 raia_ma_engine_get_channels(const ma_engine* pEngine) {
    return ma_engine_get_channels(pEngine);
}

ma_uint32 raia_ma_engine_get_sample_rate(const ma_engine* pEngine) {
    return ma_engine_get_sample_rate(pEngine);
}

ma_result raia_ma_engine_start(ma_engine* pEngine) {
    return ma_engine_start(pEngine);
}

ma_result raia_ma_engine_stop(ma_engine* pEngine) {
    return ma_engine_stop(pEngine);
}

ma_result raia_ma_engine_set_volume(ma_engine* pEngine, float volume) {
    return ma_engine_set_volume(pEngine, volume);
}

float raia_ma_engine_get_volume(ma_engine* pEngine) {
    return ma_engine_get_volume(pEngine);
}

ma_result raia_ma_engine_set_gain_db(ma_engine* pEngine, float gainDB) {
    return ma_engine_set_gain_db(pEngine, gainDB);
}

float raia_ma_engine_get_gain_db(ma_engine* pEngine) {
    return ma_engine_get_gain_db(pEngine);
}

ma_uint32 raia_ma_engine_get_listener_count(const ma_engine* pEngine) {
    return ma_engine_get_listener_count(pEngine);
}

ma_uint32 raia_ma_engine_find_closest_listener(const ma_engine* pEngine, float absolutePosX, float absolutePosY, float absolutePosZ) {
    return ma_engine_find_closest_listener(pEngine, absolutePosX, absolutePosY, absolutePosZ);
}

void raia_ma_engine_listener_set_position(ma_engine* pEngine, ma_uint32 listenerIndex, float x, float y, float z) {
    ma_engine_listener_set_position(pEngine, listenerIndex, x, y, z);
}

ma_vec3f raia_ma_engine_listener_get_position(const ma_engine* pEngine, ma_uint32 listenerIndex) {
    return ma_engine_listener_get_position(pEngine, listenerIndex);
}

void raia_ma_engine_listener_set_direction(ma_engine* pEngine, ma_uint32 listenerIndex, float x, float y, float z) {
    ma_engine_listener_set_direction(pEngine, listenerIndex, x, y, z);
}

ma_vec3f raia_ma_engine_listener_get_direction(const ma_engine* pEngine, ma_uint32 listenerIndex) {
    return ma_engine_listener_get_direction(pEngine, listenerIndex);
}

void raia_ma_engine_listener_set_velocity(ma_engine* pEngine, ma_uint32 listenerIndex, float x, float y, float z) {
    ma_engine_listener_set_velocity(pEngine, listenerIndex, x, y, z);
}

ma_vec3f raia_ma_engine_listener_get_velocity(const ma_engine* pEngine, ma_uint32 listenerIndex) {
    return ma_engine_listener_get_velocity(pEngine, listenerIndex);
}

void raia_ma_engine_listener_set_cone(ma_engine* pEngine, ma_uint32 listenerIndex, float innerAngleInRadians, float outerAngleInRadians, float outerGain) {
    ma_engine_listener_set_cone(pEngine, listenerIndex, innerAngleInRadians, outerAngleInRadians, outerGain);
}

void raia_ma_engine_listener_get_cone(const ma_engine* pEngine, ma_uint32 listenerIndex, float* pInnerAngleInRadians, float* pOuterAngleInRadians, float* pOuterGain) {
    ma_engine_listener_get_cone(pEngine, listenerIndex, pInnerAngleInRadians, pOuterAngleInRadians, pOuterGain);
}

void raia_ma_engine_listener_set_world_up(ma_engine* pEngine, ma_uint32 listenerIndex, float x, float y, float z) {
    ma_engine_listener_set_world_up(pEngine, listenerIndex, x, y, z);
}

ma_vec3f raia_ma_engine_listener_get_world_up(const ma_engine* pEngine, ma_uint32 listenerIndex) {
    return ma_engine_listener_get_world_up(pEngine, listenerIndex);
}

void raia_ma_engine_listener_set_enabled(ma_engine* pEngine, ma_uint32 listenerIndex, ma_bool32 isEnabled) {
    ma_engine_listener_set_enabled(pEngine, listenerIndex, isEnabled);
}

ma_bool32 raia_ma_engine_listener_is_enabled(const ma_engine* pEngine, ma_uint32 listenerIndex) {
    return ma_engine_listener_is_enabled(pEngine, listenerIndex);
}

#ifndef MA_NO_RESOURCE_MANAGER

ma_result raia_ma_engine_play_sound_ex(ma_engine* pEngine, const char* pFilePath, ma_node* pNode, ma_uint32 nodeInputBusIndex) {
    return ma_engine_play_sound_ex(pEngine, pFilePath, pNode, nodeInputBusIndex);
}

ma_result raia_ma_engine_play_sound(ma_engine* pEngine, const char* pFilePath, ma_sound_group* pGroup) {
    return ma_engine_play_sound(pEngine, pFilePath, pGroup);
}

#endif

#ifndef MA_NO_RESOURCE_MANAGER

ma_result raia_ma_sound_init_from_file(ma_engine* pEngine, const char* pFilePath, ma_uint32 flags, ma_sound_group* pGroup, ma_fence* pDoneFence, ma_sound* pSound) {
    return ma_sound_init_from_file(pEngine, pFilePath, flags, pGroup, pDoneFence, pSound);
}

ma_result raia_ma_sound_init_from_file_w(ma_engine* pEngine, const wchar_t* pFilePath, ma_uint32 flags, ma_sound_group* pGroup, ma_fence* pDoneFence, ma_sound* pSound) {
    return ma_sound_init_from_file_w(pEngine, pFilePath, flags, pGroup, pDoneFence, pSound);
}

ma_result raia_ma_sound_init_copy(ma_engine* pEngine, const ma_sound* pExistingSound, ma_uint32 flags, ma_sound_group* pGroup, ma_sound* pSound) {
    return ma_sound_init_copy(pEngine, pExistingSound, flags, pGroup, pSound);
}

#endif

ma_result raia_ma_sound_init_from_data_source(ma_engine* pEngine, ma_data_source* pDataSource, ma_uint32 flags, ma_sound_group* pGroup, ma_sound* pSound) {
    return ma_sound_init_from_data_source(pEngine, pDataSource, flags, pGroup, pSound);
}

ma_result raia_ma_sound_init_ex(ma_engine* pEngine, const ma_sound_config* pConfig, ma_sound* pSound) {
    return ma_sound_init_ex(pEngine, pConfig, pSound);
}

void raia_ma_sound_uninit(ma_sound* pSound) {
    ma_sound_uninit(pSound);
}

ma_engine* raia_ma_sound_get_engine(const ma_sound* pSound) {
    return ma_sound_get_engine(pSound);
}

ma_data_source* raia_ma_sound_get_data_source(const ma_sound* pSound) {
    return ma_sound_get_data_source(pSound);
}

ma_result raia_ma_sound_start(ma_sound* pSound) {
    return ma_sound_start(pSound);
}

ma_result raia_ma_sound_stop(ma_sound* pSound) {
    return ma_sound_stop(pSound);
}

ma_result raia_ma_sound_stop_with_fade_in_pcm_frames(ma_sound* pSound, ma_uint64 fadeLengthInFrames) {
    return ma_sound_stop_with_fade_in_pcm_frames(pSound, fadeLengthInFrames);
}

ma_result raia_ma_sound_stop_with_fade_in_milliseconds(ma_sound* pSound, ma_uint64 fadeLengthInFrames) {
    return ma_sound_stop_with_fade_in_milliseconds(pSound, fadeLengthInFrames);
}

void raia_ma_sound_set_volume(ma_sound* pSound, float volume) {
    ma_sound_set_volume(pSound, volume);
}

float raia_ma_sound_get_volume(const ma_sound* pSound) {
    return ma_sound_get_volume(pSound);
}

void raia_ma_sound_set_pan(ma_sound* pSound, float pan) {
    ma_sound_set_pan(pSound, pan);
}

float raia_ma_sound_get_pan(const ma_sound* pSound) {
    return ma_sound_get_pan(pSound);
}

void raia_ma_sound_set_pan_mode(ma_sound* pSound, ma_pan_mode panMode) {
    ma_sound_set_pan_mode(pSound, panMode);
}

ma_pan_mode raia_ma_sound_get_pan_mode(const ma_sound* pSound) {
    return ma_sound_get_pan_mode(pSound);
}

void raia_ma_sound_set_pitch(ma_sound* pSound, float pitch) {
    ma_sound_set_pitch(pSound, pitch);
}

float raia_ma_sound_get_pitch(const ma_sound* pSound) {
    return ma_sound_get_pitch(pSound);
}

void raia_ma_sound_set_spatialization_enabled(ma_sound* pSound, ma_bool32 enabled) {
    ma_sound_set_spatialization_enabled(pSound, enabled);
}

ma_bool32 raia_ma_sound_is_spatialization_enabled(const ma_sound* pSound) {
    return ma_sound_is_spatialization_enabled(pSound);
}

void raia_ma_sound_set_pinned_listener_index(ma_sound* pSound, ma_uint32 listenerIndex) {
    ma_sound_set_pinned_listener_index(pSound, listenerIndex);
}

ma_uint32 raia_ma_sound_get_pinned_listener_index(const ma_sound* pSound) {
    return ma_sound_get_pinned_listener_index(pSound);
}

ma_uint32 raia_ma_sound_get_listener_index(const ma_sound* pSound) {
    return ma_sound_get_listener_index(pSound);
}

ma_vec3f raia_ma_sound_get_direction_to_listener(const ma_sound* pSound) {
    return ma_sound_get_direction_to_listener(pSound);
}

void raia_ma_sound_set_position(ma_sound* pSound, float x, float y, float z) {
    ma_sound_set_position(pSound, x, y, z);
}

ma_vec3f raia_ma_sound_get_position(const ma_sound* pSound) {
    return ma_sound_get_position(pSound);
}

void raia_ma_sound_set_direction(ma_sound* pSound, float x, float y, float z) {
    ma_sound_set_direction(pSound, x, y, z);
}

ma_vec3f raia_ma_sound_get_direction(const ma_sound* pSound) {
    return ma_sound_get_direction(pSound);
}

void raia_ma_sound_set_velocity(ma_sound* pSound, float x, float y, float z) {
    ma_sound_set_velocity(pSound, x, y, z);
}

ma_vec3f raia_ma_sound_get_velocity(const ma_sound* pSound) {
    return ma_sound_get_velocity(pSound);
}

void raia_ma_sound_set_attenuation_model(ma_sound* pSound, ma_attenuation_model attenuationModel) {
    ma_sound_set_attenuation_model(pSound, attenuationModel);
}

ma_attenuation_model raia_ma_sound_get_attenuation_model(const ma_sound* pSound) {
    return ma_sound_get_attenuation_model(pSound);
}

void raia_ma_sound_set_positioning(ma_sound* pSound, ma_positioning positioning) {
    ma_sound_set_positioning(pSound, positioning);
}

ma_positioning raia_ma_sound_get_positioning(const ma_sound* pSound) {
    return ma_sound_get_positioning(pSound);
}

void raia_ma_sound_set_rolloff(ma_sound* pSound, float rolloff) {
    ma_sound_set_rolloff(pSound, rolloff);
}

float raia_ma_sound_get_rolloff(const ma_sound* pSound) {
    return ma_sound_get_rolloff(pSound);
}

void raia_ma_sound_set_min_gain(ma_sound* pSound, float minGain) {
    ma_sound_set_min_gain(pSound, minGain);
}

float raia_ma_sound_get_min_gain(const ma_sound* pSound) {
    return ma_sound_get_min_gain(pSound);
}

void raia_ma_sound_set_max_gain(ma_sound* pSound, float maxGain) {
    return ma_sound_set_max_gain(pSound, maxGain);
}

float raia_ma_sound_get_max_gain(const ma_sound* pSound) {
    return ma_sound_get_max_gain(pSound);
}

void raia_ma_sound_set_min_distance(ma_sound* pSound, float minDistance) {
    ma_sound_set_min_distance(pSound, minDistance);
}

float raia_ma_sound_get_min_distance(const ma_sound* pSound) {
    return ma_sound_get_min_distance(pSound);
}

void raia_ma_sound_set_max_distance(ma_sound* pSound, float maxDistance) {
    ma_sound_set_max_distance(pSound, maxDistance);
}

float raia_ma_sound_get_max_distance(const ma_sound* pSound) {
    return ma_sound_get_max_distance(pSound);
}

void raia_ma_sound_set_cone(ma_sound* pSound, float innerAngleInRadians, float outerAngleInRadians, float outerGain) {
    ma_sound_set_cone(pSound, innerAngleInRadians, outerAngleInRadians, outerGain);
}

void raia_ma_sound_get_cone(const ma_sound* pSound, float* pInnerAngleInRadians, float* pOuterAngleInRadians, float* pOuterGain) {
    ma_sound_get_cone(pSound, pInnerAngleInRadians, pOuterAngleInRadians, pOuterGain);
}

void raia_ma_sound_set_doppler_factor(ma_sound* pSound, float dopplerFactor) {
    ma_sound_set_doppler_factor(pSound, dopplerFactor);
}

float raia_ma_sound_get_doppler_factor(const ma_sound* pSound) {
    return ma_sound_get_doppler_factor(pSound);
}

void raia_ma_sound_set_directional_attenuation_factor(ma_sound* pSound, float directionalAttenuationFactor) {
    ma_sound_set_directional_attenuation_factor(pSound, directionalAttenuationFactor);
}

float raia_ma_sound_get_directional_attenuation_factor(const ma_sound* pSound) {
    return ma_sound_get_directional_attenuation_factor(pSound);
}

void raia_ma_sound_set_fade_in_pcm_frames(ma_sound* pSound, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInFrames) {
    ma_sound_set_fade_in_pcm_frames(pSound, volumeBeg, volumeEnd, fadeLengthInFrames);
}

void raia_ma_sound_set_fade_in_milliseconds(ma_sound* pSound, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInMilliseconds) {
    ma_sound_set_fade_in_milliseconds(pSound, volumeBeg, volumeEnd, fadeLengthInMilliseconds);
}

void raia_ma_sound_set_fade_start_in_pcm_frames(ma_sound* pSound, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInFrames, ma_uint64 absoluteGlobalTimeInFrames) {
    ma_sound_set_fade_start_in_pcm_frames(pSound, volumeBeg, volumeEnd, fadeLengthInFrames, absoluteGlobalTimeInFrames);
}

void raia_ma_sound_set_fade_start_in_milliseconds(ma_sound* pSound, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInMilliseconds, ma_uint64 absoluteGlobalTimeInMilliseconds) {
    ma_sound_set_fade_start_in_milliseconds(pSound, volumeBeg, volumeEnd, fadeLengthInMilliseconds, absoluteGlobalTimeInMilliseconds);
}

float raia_ma_sound_get_current_fade_volume(const ma_sound* pSound) {
    return ma_sound_get_current_fade_volume(pSound);
}

void raia_ma_sound_set_start_time_in_pcm_frames(ma_sound* pSound, ma_uint64 absoluteGlobalTimeInFrames) {
    ma_sound_set_start_time_in_pcm_frames(pSound, absoluteGlobalTimeInFrames);
}

void raia_ma_sound_set_start_time_in_milliseconds(ma_sound* pSound, ma_uint64 absoluteGlobalTimeInMilliseconds) {
    ma_sound_set_start_time_in_milliseconds(pSound, absoluteGlobalTimeInMilliseconds);
}

void raia_ma_sound_set_stop_time_in_pcm_frames(ma_sound* pSound, ma_uint64 absoluteGlobalTimeInFrames) {
    ma_sound_set_stop_time_in_pcm_frames(pSound, absoluteGlobalTimeInFrames);
}

void raia_ma_sound_set_stop_time_in_milliseconds(ma_sound* pSound, ma_uint64 absoluteGlobalTimeInMilliseconds) {
    ma_sound_set_stop_time_in_milliseconds(pSound, absoluteGlobalTimeInMilliseconds);
}

void raia_ma_sound_set_stop_time_with_fade_in_pcm_frames(ma_sound* pSound, ma_uint64 stopAbsoluteGlobalTimeInFrames, ma_uint64 fadeLengthInFrames) {
    ma_sound_set_stop_time_with_fade_in_pcm_frames(pSound, stopAbsoluteGlobalTimeInFrames, fadeLengthInFrames);
}

void raia_ma_sound_set_stop_time_with_fade_in_milliseconds(ma_sound* pSound, ma_uint64 stopAbsoluteGlobalTimeInMilliseconds, ma_uint64 fadeLengthInMilliseconds) {
    ma_sound_set_stop_time_with_fade_in_milliseconds(pSound, stopAbsoluteGlobalTimeInMilliseconds, fadeLengthInMilliseconds);
}

ma_bool32 raia_ma_sound_is_playing(const ma_sound* pSound) {
    return ma_sound_is_playing(pSound);
}

ma_uint64 raia_ma_sound_get_time_in_pcm_frames(const ma_sound* pSound) {
    return ma_sound_get_time_in_pcm_frames(pSound);
}

ma_uint64 raia_ma_sound_get_time_in_milliseconds(const ma_sound* pSound) {
    return ma_sound_get_time_in_milliseconds(pSound);
}

void raia_ma_sound_set_looping(ma_sound* pSound, ma_bool32 isLooping) {
    ma_sound_set_looping(pSound, isLooping);
}

ma_bool32 raia_ma_sound_is_looping(const ma_sound* pSound) {
    return ma_sound_is_looping(pSound);
}

ma_bool32 raia_ma_sound_at_end(const ma_sound* pSound) {
    return ma_sound_at_end(pSound);
}

ma_result raia_ma_sound_seek_to_pcm_frame(ma_sound* pSound, ma_uint64 frameIndex) {
    return ma_sound_seek_to_pcm_frame(pSound, frameIndex);
}

ma_result raia_ma_sound_get_data_format(ma_sound* pSound, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap) {
    return ma_sound_get_data_format(pSound, pFormat, pChannels, pSampleRate, pChannelMap, channelMapCap);
}

ma_result raia_ma_sound_get_cursor_in_pcm_frames(ma_sound* pSound, ma_uint64* pCursor) {
    return ma_sound_get_cursor_in_pcm_frames(pSound, pCursor);
}

ma_result raia_ma_sound_get_length_in_pcm_frames(ma_sound* pSound, ma_uint64* pLength) {
    return ma_sound_get_length_in_pcm_frames(pSound, pLength);
}

ma_result raia_ma_sound_get_cursor_in_seconds(ma_sound* pSound, float* pCursor) {
    return ma_sound_get_cursor_in_seconds(pSound, pCursor);
}

ma_result raia_ma_sound_get_length_in_seconds(ma_sound* pSound, float* pLength) {
    return ma_sound_get_length_in_seconds(pSound, pLength);
}

ma_result raia_ma_sound_set_end_callback(ma_sound* pSound, ma_sound_end_proc callback, void* pUserData) {
    return ma_sound_set_end_callback(pSound, callback, pUserData);
}

ma_result raia_ma_sound_group_init(ma_engine* pEngine, ma_uint32 flags, ma_sound_group* pParentGroup, ma_sound_group* pGroup) {
    return ma_sound_group_init(pEngine, flags, pParentGroup, pGroup);
}

ma_result raia_ma_sound_group_init_ex(ma_engine* pEngine, const ma_sound_group_config* pConfig, ma_sound_group* pGroup) {
    return ma_sound_group_init_ex(pEngine, pConfig, pGroup);
}

void raia_ma_sound_group_uninit(ma_sound_group* pGroup) {
    ma_sound_group_uninit(pGroup);
}

ma_engine* raia_ma_sound_group_get_engine(const ma_sound_group* pGroup) {
    return ma_sound_group_get_engine(pGroup);
}

ma_result raia_ma_sound_group_start(ma_sound_group* pGroup) {
    return ma_sound_group_start(pGroup);
}

ma_result raia_ma_sound_group_stop(ma_sound_group* pGroup) {
    return ma_sound_group_stop(pGroup);
}

void raia_ma_sound_group_set_volume(ma_sound_group* pGroup, float volume) {
    ma_sound_group_set_volume(pGroup, volume);
}

float raia_ma_sound_group_get_volume(const ma_sound_group* pGroup) {
    return ma_sound_group_get_volume(pGroup);
}

void raia_ma_sound_group_set_pan(ma_sound_group* pGroup, float pan) {
    ma_sound_group_set_pan(pGroup, pan);
}

float raia_ma_sound_group_get_pan(const ma_sound_group* pGroup) {
    return ma_sound_group_get_pan(pGroup);
}

void raia_ma_sound_group_set_pan_mode(ma_sound_group* pGroup, ma_pan_mode panMode) {
    ma_sound_group_set_pan_mode(pGroup, panMode);
}

ma_pan_mode raia_ma_sound_group_get_pan_mode(const ma_sound_group* pGroup) {
    return ma_sound_group_get_pan_mode(pGroup);
}

void raia_ma_sound_group_set_pitch(ma_sound_group* pGroup, float pitch) {
    ma_sound_group_set_pitch(pGroup, pitch);
}

float raia_ma_sound_group_get_pitch(const ma_sound_group* pGroup) {
    return ma_sound_group_get_pitch(pGroup);
}

void raia_ma_sound_group_set_spatialization_enabled(ma_sound_group* pGroup, ma_bool32 enabled) {
    ma_sound_group_set_spatialization_enabled(pGroup, enabled);
}

ma_bool32 raia_ma_sound_group_is_spatialization_enabled(const ma_sound_group* pGroup) {
    return ma_sound_group_is_spatialization_enabled(pGroup);
}

void raia_ma_sound_group_set_pinned_listener_index(ma_sound_group* pGroup, ma_uint32 listenerIndex) {
    ma_sound_group_set_pinned_listener_index(pGroup, listenerIndex);
}

ma_uint32 raia_ma_sound_group_get_pinned_listener_index(const ma_sound_group* pGroup) {
    return ma_sound_group_get_pinned_listener_index(pGroup);
}

ma_uint32 raia_ma_sound_group_get_listener_index(const ma_sound_group* pGroup) {
    return ma_sound_group_get_listener_index(pGroup);
}

ma_vec3f raia_ma_sound_group_get_direction_to_listener(const ma_sound_group* pGroup) {
    return ma_sound_group_get_direction_to_listener(pGroup);
}

void raia_ma_sound_group_set_position(ma_sound_group* pGroup, float x, float y, float z) {
    ma_sound_group_set_position(pGroup, x, y, z);
}

ma_vec3f raia_ma_sound_group_get_position(const ma_sound_group* pGroup) {
    return ma_sound_group_get_position(pGroup);
}

void raia_ma_sound_group_set_direction(ma_sound_group* pGroup, float x, float y, float z) {
    ma_sound_group_set_direction(pGroup, x, y, z);
}

ma_vec3f raia_ma_sound_group_get_direction(const ma_sound_group* pGroup) {
    return ma_sound_group_get_direction(pGroup);
}

void raia_ma_sound_group_set_velocity(ma_sound_group* pGroup, float x, float y, float z) {
    ma_sound_group_set_velocity(pGroup, x, y, z);
}

ma_vec3f raia_ma_sound_group_get_velocity(const ma_sound_group* pGroup) {
    return ma_sound_group_get_velocity(pGroup);
}

void raia_ma_sound_group_set_attenuation_model(ma_sound_group* pGroup, ma_attenuation_model attenuationModel) {
    ma_sound_group_set_attenuation_model(pGroup, attenuationModel);
}

ma_attenuation_model raia_ma_sound_group_get_attenuation_model(const ma_sound_group* pGroup) {
    return ma_sound_group_get_attenuation_model(pGroup);
}

void raia_ma_sound_group_set_positioning(ma_sound_group* pGroup, ma_positioning positioning) {
    ma_sound_group_set_positioning(pGroup, positioning);
}

ma_positioning raia_ma_sound_group_get_positioning(const ma_sound_group* pGroup) {
    return ma_sound_group_get_positioning(pGroup);
}

void raia_ma_sound_group_set_rolloff(ma_sound_group* pGroup, float rolloff) {
    ma_sound_group_set_rolloff(pGroup, rolloff);
}

float raia_ma_sound_group_get_rolloff(const ma_sound_group* pGroup) {
    return ma_sound_group_get_rolloff(pGroup);
}

void raia_ma_sound_group_set_min_gain(ma_sound_group* pGroup, float minGain) {
    ma_sound_group_set_min_gain(pGroup, minGain);
}

float raia_ma_sound_group_get_min_gain(const ma_sound_group* pGroup) {
    return ma_sound_group_get_min_gain(pGroup);
}

void raia_ma_sound_group_set_max_gain(ma_sound_group* pGroup, float maxGain) {
    ma_sound_group_set_max_gain(pGroup, maxGain);
}

float raia_ma_sound_group_get_max_gain(const ma_sound_group* pGroup) {
    return ma_sound_group_get_max_gain(pGroup);
}

void raia_ma_sound_group_set_min_distance(ma_sound_group* pGroup, float minDistance) {
    ma_sound_group_set_min_distance(pGroup, minDistance);
}

float raia_ma_sound_group_get_min_distance(const ma_sound_group* pGroup) {
    return ma_sound_group_get_min_distance(pGroup);
}

void raia_ma_sound_group_set_max_distance(ma_sound_group* pGroup, float maxDistance) {
    ma_sound_group_set_max_distance(pGroup, maxDistance);
}

float raia_ma_sound_group_get_max_distance(const ma_sound_group* pGroup) {
    return ma_sound_group_get_max_distance(pGroup);
}

void raia_ma_sound_group_set_cone(ma_sound_group* pGroup, float innerAngleInRadians, float outerAngleInRadians, float outerGain) {
    ma_sound_group_set_cone(pGroup, innerAngleInRadians, outerAngleInRadians, outerGain);
}

void raia_ma_sound_group_get_cone(const ma_sound_group* pGroup, float* pInnerAngleInRadians, float* pOuterAngleInRadians, float* pOuterGain) {
    ma_sound_group_get_cone(pGroup, pInnerAngleInRadians, pOuterAngleInRadians, pOuterGain);
}

void raia_ma_sound_group_set_doppler_factor(ma_sound_group* pGroup, float dopplerFactor) {
    ma_sound_group_set_doppler_factor(pGroup, dopplerFactor);
}

float raia_ma_sound_group_get_doppler_factor(const ma_sound_group* pGroup) {
    return ma_sound_group_get_doppler_factor(pGroup);
}

void raia_ma_sound_group_set_directional_attenuation_factor(ma_sound_group* pGroup, float directionalAttenuationFactor) {
    ma_sound_group_set_directional_attenuation_factor(pGroup, directionalAttenuationFactor);
}

float raia_ma_sound_group_get_directional_attenuation_factor(const ma_sound_group* pGroup) {
    return ma_sound_group_get_directional_attenuation_factor(pGroup);
}

void raia_ma_sound_group_set_fade_in_pcm_frames(ma_sound_group* pGroup, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInFrames) {
    ma_sound_group_set_fade_in_pcm_frames(pGroup, volumeBeg, volumeEnd, fadeLengthInFrames);
}

void raia_ma_sound_group_set_fade_in_milliseconds(ma_sound_group* pGroup, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInMilliseconds) {
    ma_sound_group_set_fade_in_milliseconds(pGroup, volumeBeg, volumeEnd, fadeLengthInMilliseconds);
}

float raia_ma_sound_group_get_current_fade_volume(ma_sound_group* pGroup) {
    return ma_sound_group_get_current_fade_volume(pGroup);
}

void raia_ma_sound_group_set_start_time_in_pcm_frames(ma_sound_group* pGroup, ma_uint64 absoluteGlobalTimeInFrames) {
    ma_sound_group_set_start_time_in_pcm_frames(pGroup, absoluteGlobalTimeInFrames);
}

void raia_ma_sound_group_set_start_time_in_milliseconds(ma_sound_group* pGroup, ma_uint64 absoluteGlobalTimeInMilliseconds) {
    ma_sound_group_set_start_time_in_milliseconds(pGroup, absoluteGlobalTimeInMilliseconds);
}

void raia_ma_sound_group_set_stop_time_in_pcm_frames(ma_sound_group* pGroup, ma_uint64 absoluteGlobalTimeInFrames) {
    ma_sound_group_set_stop_time_in_pcm_frames(pGroup, absoluteGlobalTimeInFrames);
}

void raia_ma_sound_group_set_stop_time_in_milliseconds(ma_sound_group* pGroup, ma_uint64 absoluteGlobalTimeInMilliseconds) {
    ma_sound_group_set_stop_time_in_milliseconds(pGroup, absoluteGlobalTimeInMilliseconds);
}

ma_bool32 raia_ma_sound_group_is_playing(const ma_sound_group* pGroup) {
    return ma_sound_group_is_playing(pGroup);
}

ma_uint64 raia_ma_sound_group_get_time_in_pcm_frames(const ma_sound_group* pGroup) {
    return ma_sound_group_get_time_in_pcm_frames(pGroup);
}

#endif  /* MA_NO_ENGINE */
