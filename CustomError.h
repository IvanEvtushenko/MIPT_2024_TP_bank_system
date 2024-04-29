#include <stdexcept>
#include <utility>

#pragma once

class CustomError : public std::exception {
private:
    std::string message;
    int errorCode;
    double arrears = 0;

public:
    CustomError(std::string  message, int errorCode, double arrears = 0);

    [[nodiscard]] const char* what() const noexcept override;

    [[nodiscard]] int getErrorCode() const;

    [[nodiscard]] double detArrears() const;
};


// 0 - Insufficient funds to perform the operation on the account (in DebitAccount or CreditAccount)
// 1 - It is currently not possible to withdraw money from the account (CreditAccount)
// 2 - The client does not have sufficient funds to cancel the operation, resulting in an arrears being imposed (Abort)