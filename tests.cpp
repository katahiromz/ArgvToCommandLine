// tests.cpp --- The tests of ArgvToCommandLine
// Author: katahiromz
// License: MIT
#include <windows.h>
#include <cassert>
#include <iostream>
#include "ArgvToCommandLine.h"

static void test_entryW(const std::vector<std::wstring>& args)
{
    std::wstring cmd = ArgvToCommandLineW(args);

    int argc = 0;
    LPWSTR* parsed = CommandLineToArgvW(cmd.c_str(), &argc);

    assert((size_t)argc == args.size());
    for (int i = 0; i < argc; ++i)
        assert(args[i] == parsed[i]);

    LocalFree(parsed);
    std::wcout << L"OK: " << cmd << L"\n";
}

static void Test_ArgvToCommandLineW()
{
    test_entryW({ L"prog" });
    test_entryW({ L"prog", L"hello world" });
    test_entryW({ L"prog", L"" });
    test_entryW({ L"prog", L"C:\\path\\" });
    test_entryW({ L"prog", L"\"quoted\"" });
    test_entryW({ L"prog", L"a\\\"b" });
    test_entryW({ L"prog", L"a\\\\b" });
    test_entryW({ L"prog", L" ", L"\t", L"\n" });
}

int main(void)
{
    Test_ArgvToCommandLineW();
    return 0;
}
