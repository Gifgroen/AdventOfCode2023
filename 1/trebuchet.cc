#include <_ctype.h>
#include <iostream>
#include <string>
#include <string_view>
#include <stdio.h>

std::string FindCalibrationValue(std::string_view line)
{
    size_t LeftIndex = 0;
    size_t RightIndex = line.length() - 1;

    for (int Index = 0; Index < line.length(); ++Index)
    {
        if (!isdigit(line[LeftIndex]))
        {
            ++LeftIndex;  
        }
        if (!isdigit(line[RightIndex]))
        {
            --RightIndex;
        }
        if (LeftIndex == RightIndex)
        {
            break;
        }
    }

    if (!isdigit(line[LeftIndex]) || !isdigit(line[RightIndex]))
    {
        return "";
    }
    std::string Result{ line[LeftIndex], line[RightIndex] };
    return Result; 
}

size_t ToNumber(std::string Value)
{
    size_t Term;
    sscanf(Value.c_str(), "%zu", &Term);
    return Term;
}

int main(int argc, char *Argv[])
{
    std::cout << "Trebuchet!?\n";
    
    std::string_view const Inputs[4] = {
        "1abc2",
        "pqr3stu8vwx",
        "a1b2c3d4e5f",
        "treb7uchet"
    };

    
    size_t Sum = 0;
    for (int Index = 0; Index < 4; ++Index)
    {
        std::string Value = FindCalibrationValue(Inputs[Index]);
        if (Value == "") 
        {
            continue;
        }

        Sum += ToNumber(Value);
    }

    std::cout << "calibration = " << Sum << "\n";

    std::string_view Test[3] = {
        "1abcdef",
        "abcdef9",
        "abcdefg"
    };
    size_t SumT = 0;
    for (int Index = 0; Index < 3; ++Index)
    {
        std::string Value = FindCalibrationValue(Test[Index]);
        if (Value == "") 
        {
            continue;
        }
        SumT += ToNumber(Value);
    }
    std::cout << "calibration = " << SumT << "\n";

    return 0;
}

