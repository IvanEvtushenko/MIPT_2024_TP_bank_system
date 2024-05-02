#include "CustomError.h"

#pragma once

CustomError::CustomError(std::string message, int errorCode, double arrears, size_t client_id) : message(std::move(message)),
        errorCode(errorCode), arrears(arrears), client_id(client_id) {}

const char * CustomError::what() const noexcept { return message.c_str(); }

[[nodiscard]] int CustomError::getErrorCode() const { return errorCode; }

[[nodiscard]] double CustomError::getArrears() const { return arrears; }

size_t CustomError::getClientID() const { return client_id ;}