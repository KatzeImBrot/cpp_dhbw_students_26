#include <iostream>
#include "person.hpp"
#include "professor.hpp"
#include "student.hpp"
#include "mail_handler.hpp"

int main()
{
    Person Frank("Frank", "Hellweg 3", "frank@web.de");
    Professor Nina("Nina", "Sofienstraße 1", "nina@web.de");
    Student Kai("Kai", "Tollweg 12", "kai@web.de");

    MailHandler myMailHandler;
    myMailHandler.writeMail(Frank, "Hallo Frank, wie geht es dir?");
    myMailHandler.writeMail(Nina, "gut, und dir?");
    myMailHandler.writeMail(Kai, "Hi :)");

    return 0;
}
