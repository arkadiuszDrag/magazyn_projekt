
#include <iostream>

#ifndef DRAGARKADIUSZ_ETAP2_EXCEPTIONS_H
#define DRAGARKADIUSZ_ETAP2_EXCEPTIONS_H


struct ChooseError {
    std::string message;
    explicit ChooseError(std::string msg) : message(std::move(msg)) {}
};

struct NotDigitError: public ChooseError {
    explicit NotDigitError(): ChooseError("Podane znaki nie są liczbą!") {}
};

struct IDError: public ChooseError {
    explicit IDError(): ChooseError("Podane ID nie jest nieprawidłowe!") {}
};


#endif //DRAGARKADIUSZ_ETAP2_EXCEPTIONS_H
