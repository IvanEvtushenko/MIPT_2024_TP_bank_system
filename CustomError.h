#include <stdexcept>
#include <utility>

#pragma once

class CustomError : public std::exception {
private:
    std::string message;
    int errorCode;
    double arrears = 0;
    size_t client_id = 0;

public:
    CustomError(std::string  message, int errorCode, double arrears = 0, size_t client_id = 0);

    [[nodiscard]] const char* what() const noexcept override;
    [[nodiscard]] int getErrorCode() const;
    [[nodiscard]] double getArrears() const;
    [[nodiscard]] size_t getClientID() const;
};


// 0 - Insufficient funds to perform the operation on the account (in DebitAccount or CreditAccount)
// 1 - It is currently not possible to withdraw money from the account (Deposit)
// 2 - The client does not have sufficient funds to cancel the operation, resulting in an arrears being imposed (Abort)
// 3 - Client in black list (Bank)