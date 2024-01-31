//
// Created by dolphilia on 2024/01/27.
//

#include "v8_platform.h"

#include "v8.h"
#include "libplatform/libplatform.h"

std::unique_ptr< v8::Platform > v8_platform_NewDefaultPlatform (int thread_pool_size=0, v8::platform::IdleTaskSupport idle_task_support=v8::platform::IdleTaskSupport::kDisabled, v8::platform::InProcessStackDumping in_process_stack_dumping=v8::platform::InProcessStackDumping::kDisabled, std::unique_ptr< v8::TracingController > tracing_controller={}) {
    return v8::platform::NewDefaultPlatform(thread_pool_size, idle_task_support, in_process_stack_dumping, std::move(tracing_controller));
}

std::unique_ptr< v8::Platform > v8_platform_NewSingleThreadedDefaultPlatform (v8::platform::IdleTaskSupport idle_task_support=v8::platform::IdleTaskSupport::kDisabled, v8::platform::InProcessStackDumping in_process_stack_dumping=v8::platform::InProcessStackDumping::kDisabled, std::unique_ptr< v8::TracingController > tracing_controller={}) {
    return v8::platform::NewSingleThreadedDefaultPlatform(idle_task_support, in_process_stack_dumping, std::move(tracing_controller));
}

std::unique_ptr< v8::JobHandle > v8_platform_NewDefaultJobHandle (v8::Platform *platform, v8::TaskPriority priority, std::unique_ptr< v8::JobTask > job_task, size_t num_worker_threads) {
    return v8::platform::NewDefaultJobHandle(platform, priority, std::move(job_task), num_worker_threads);
}

bool v8_platform_PumpMessageLoop (v8::Platform *platform, v8::Isolate *isolate,  v8::platform::MessageLoopBehavior behavior=v8::platform::MessageLoopBehavior::kDoNotWait) {
    return v8::platform::PumpMessageLoop(platform, isolate, behavior);
}

void v8_platform_RunIdleTasks (v8::Platform *platform, v8::Isolate *isolate, double idle_time_in_seconds) {
    v8::platform::RunIdleTasks(platform, isolate, idle_time_in_seconds);
}

void v8_platform_NotifyIsolateShutdown (v8::Platform *platform, v8::Isolate *isolate) {
    v8::platform::NotifyIsolateShutdown(platform, isolate);
}

