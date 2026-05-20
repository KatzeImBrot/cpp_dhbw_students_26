
#include "Person.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "MailHandler.hpp"


int main()
{
   Person Frank("Frank", "Hellweg 3", "frank@web.de");
   Professor Nina("Nina", "Sofienstraße 1", "nina@web.de");
   Student Kai("Kai", "Tollweg 12", "kai@web.de");

   MailHandler myMailHandler;

   myMailHandler.writeMail(Frank, Nina, "Hallo Frank, wie geht es dir?");
   myMailHandler.writeMail(Nina, Kai, "gut, und dir?");
   myMailHandler.writeMail(Kai, Frank, "Hi :)");

   return 0;
}