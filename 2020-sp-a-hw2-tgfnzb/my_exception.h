/* Implement (via overriding) a custom exception function here which follows the standard std exception class style for including an error message.
 * We need to be able to catch this exception, and call it's standard message function.
 * When we call that standard message function, it should return an error message:
 *     "Custom error has occurred"
 * If you read the std::exception documentation and examples I gave for the std expection, you will know *what* we are asking for ;)
 * Put the implementation in my_exception.cpp
 */

#ifndef MY_EXCEPT_H
#define MY_EXCEPT_H

#include <exception>

class MyException: public std::exception
{
    public:
        virtual const char * what() const noexcept;
};

#endif

