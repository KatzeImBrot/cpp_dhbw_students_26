#include <iostream>
#include "mail_handler.hpp"

void MailHandler::writeMail(Person receiver, std::string txt){
    std::cout << "Mail to " + receiver.get_name() + ": " + txt << std::endl;
}