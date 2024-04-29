#include "CustomError.h"

#pragma once

CustomError::CustomError(std::string message, int errorCode, double arrears) : message(std::move(message)), errorCode(errorCode), arrears(arrears) {}

const char * CustomError::what() const noexcept { return message.c_str(); }

[[nodiscard]] int CustomError::getErrorCode() const { return errorCode; }

[[nodiscard]] double CustomError::detArrears() const { return arrears; }