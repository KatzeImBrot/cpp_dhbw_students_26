#ifndef MAIL_HANDLER_H
#define MAIL_HANDLER_H

#include <iostream>
#include "person.hpp"

class MailHandler{
    public:
    void writeMail(Person receiver, std::string txt);
};

#endif