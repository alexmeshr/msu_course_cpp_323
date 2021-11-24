#include <fstream>
#include <iostream>
#include <mutex>
#include <optional>
#include <string>

#include "logger.hpp"

namespace uni_cpp_practice {

void Logger::set_output(const std::optional<std::string>& file_path) {
  if (!file_path.has_value()) {
    if (file_stream_.has_value()) {
      file_stream_->close();
      file_stream_ = std::nullopt;
    }
    return;
  }

  if (file_stream_.has_value()) {
    file_stream_->close();
  }

  file_stream_ = std::ofstream(file_path.value());

  if (!file_stream_->is_open()) {
    throw std::runtime_error("Failed to create file stream");
  }
}

void Logger::log(const std::string& text) {
  std::mutex vector_mutex;
  vector_mutex.lock();
  std::cout << text << std::endl;
  if (file_stream_.has_value())
    file_stream_.value() << text << std::endl;
  vector_mutex.unlock();
}

Logger::~Logger() {
  if (file_stream_.has_value())
    file_stream_->close();
}

}  // namespace uni_cpp_practice
