using PrintError = int;

PrintError printData() { return 5; }

int main()
{

    PrintError test = printData();
    auto x{test};
    return 0;
}
