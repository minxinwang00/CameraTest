#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <memory>
#include <vector>
#include <filesystem>
    inline void rm_log_init(const std::string& log_file = "logs/camera.log") {
    std::filesystem::create_directories("logs");
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
        log_file, 1024 * 1024 * 5, 3);

    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};
    auto logger = std::make_shared<spdlog::logger>("rm_log", sinks.begin(), sinks.end());

    logger->set_level(spdlog::level::info);
    logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [thread %t] %v");

    spdlog::set_default_logger(logger);
}

#define RM_LOG_TRACE(...)    spdlog::trace(__VA_ARGS__)
#define RM_LOG_DEBUG(...)    spdlog::debug(__VA_ARGS__)
#define RM_LOG_INFO(...)     spdlog::info(__VA_ARGS__)
#define RM_LOG_WARN(...)     spdlog::warn(__VA_ARGS__)
#define RM_LOG_ERROR(...)    spdlog::error(__VA_ARGS__)
#define RM_LOG_CRITICAL(...) spdlog::critical(__VA_ARGS__)
#include <cstdarg>
#include <cstdio>
#include <vector>
#include <string>
#include <filesystem>

inline void rm_log_printf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    va_list args_copy;
    va_copy(args_copy, args);

    int size = vsnprintf(nullptr, 0, fmt, args_copy);
    va_end(args_copy);

    if (size < 0) {
        va_end(args);
        return;
    }

    std::vector<char> buf(size + 1);
    vsnprintf(buf.data(), buf.size(), fmt, args);
    va_end(args);

    spdlog::info("{}", buf.data());
}

// 宏替换：把 printf 替换成 rm_log_printf
// 注意：这一行必须放在所有系统头文件之后
#define printf(...) rm_log_printf(__VA_ARGS__)
