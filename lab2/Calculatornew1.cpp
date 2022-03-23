#include <iostream>
#include <string>
#include<math.h>
using namespace std;

struct Calculator{

enum operand
{
  cross = '*',
  divv = '/',
  plus = '+',
  min = '-',
  power = 'R'
};
};
Calculator cal;
const char * expressionToParse;
//(5+6)*10/10

char peek()
{
    return * expressionToParse;
}

char get()
{
    return * expressionToParse++;
}

float expression();

float number()
{
    float result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10*result + get() - '0';
    }
    return result;
}

float factor()
{
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get(); // '('
        float result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0; // error
}

float term()
{
    float result = factor();
    while (peek() == cal.operand::cross || peek() ==cal.operand::divv)
        if (get() == cal.operand::cross)
            result *= factor();
        else
            result /= factor();
    return result;
}

float expression()
{
    float result = term();
    while (peek() == cal.operand::plus || peek() == cal.operand::min || peek() == cal.operand::power)
        if (get() == cal.operand::plus)
            result += term();
        else if(get() == cal.operand::min)
            result -= term();
        else
            result = pow(term(),0.5);
    return result;
}


int main(int argc, char *argv[])
{
    std::cout << "--to calculate the SQRT, type R(number) \n for example, to calculate the sqrt for 64, type R(64)"<< std::endl;
    std::cout << "-- to evaluate an exp, just type the expression. \n for example, type (5+6)*10/20 "<< std::endl;
    std::cout << "\n \n";
   std::cout << "Enter your expression: " ;
    char buffer[80];
    std::cin.getline(buffer, sizeof buffer);
    expressionToParse = buffer;
    float result = expression();
    std::cout << "the result:: ";
    std::cout << result << std::endl;
    return 0;
}
