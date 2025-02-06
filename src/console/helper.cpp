#ifndef HELPER_H
#define HELPER_H
#include "helper.h"
#include <string>
#include <iomanip>
#include <sstream>

std::string to_string2(double x)
{
    // 创建一个 ostringstream 对象，用于将数值转换为字符串
    std::ostringstream valueStream;
    valueStream << std::scientific << std::setprecision(3) << x;
    std::string valueStr = valueStream.str();
    return valueStr;
}




#endif // HELPER_H
