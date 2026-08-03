#include "io.h"

int main()
{
    int input1{readNumber()};
    int input2{readNumber()};
    writeAnswer(input1 + input2);
}
