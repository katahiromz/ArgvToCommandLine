// ArgvToCommandLine.cpp --- Inverse of CommandLineToArgvW
// Author: katahiromz
// License: MIT
#include <windows.h>
#include "ArgvToCommandLine.h"

std::string ArgvToCommandLineA(int argc, char **argv)
{
    std::string cmdline;

    for (int iarg = 0; iarg < argc; ++iarg) {
        std::string arg = argv[iarg];

        bool needQuote = arg.empty() || arg.find_first_of(" \t\n\v\"") != std::string::npos;

        if (needQuote)
            cmdline += '"';

        for (size_t j = 0; j < arg.size(); ) {
            size_t bs = 0;
            while (j < arg.size() && arg[j] == '\\') {
                ++j;
                ++bs;
            }

            if (j == arg.size()) {
                cmdline.append(bs * (needQuote ? 2 : 1), '\\');
                break;
            }

            if (arg[j] == '"') {
                cmdline.append(bs * 2 + 1, '\\');
                cmdline += '"';
                ++j;
            } else {
                cmdline.append(bs, '\\');
                cmdline += arg[j++];
            }
        }

        if (needQuote)
            cmdline += '"';

        if (iarg + 1 < argc)
            cmdline += ' ';
    }

    return cmdline;
}

std::wstring ArgvToCommandLineW(int argc, wchar_t **argv)
{
    std::wstring cmdline;

    for (int iarg = 0; iarg < argc; ++iarg) {
        std::wstring arg = argv[iarg];

        bool needQuote = arg.empty() || arg.find_first_of(L" \t\n\v\"") != std::wstring::npos;

        if (needQuote)
            cmdline += L'"';

        for (size_t j = 0; j < arg.size(); ) {
            size_t bs = 0;
            while (j < arg.size() && arg[j] == L'\\') {
                ++j;
                ++bs;
            }

            if (j == arg.size()) {
                cmdline.append(bs * (needQuote ? 2 : 1), L'\\');
                break;
            }

            if (arg[j] == L'"') {
                cmdline.append(bs * 2 + 1, L'\\');
                cmdline += L'"';
                ++j;
            } else {
                cmdline.append(bs, L'\\');
                cmdline += arg[j++];
            }
        }

        if (needQuote)
            cmdline += L'"';

        if (iarg + 1 < argc)
            cmdline += L' ';
    }

    return cmdline;
}

std::string  ArgvToCommandLineA(const std::vector<std::string>& args)
{
    std::string cmdline;

    for (size_t iarg = 0; iarg < args.size(); ++iarg) {
        std::string arg = args[iarg];

        bool needQuote = arg.empty() || arg.find_first_of(" \t\n\v\"") != std::string::npos;

        if (needQuote)
            cmdline += '"';

        for (size_t j = 0; j < arg.size(); ) {
            size_t bs = 0;
            while (j < arg.size() && arg[j] == '\\') {
                ++j;
                ++bs;
            }

            if (j == arg.size()) {
                cmdline.append(bs * (needQuote ? 2 : 1), '\\');
                break;
            }

            if (arg[j] == '"') {
                cmdline.append(bs * 2 + 1, '\\');
                cmdline += '"';
                ++j;
            } else {
                cmdline.append(bs, '\\');
                cmdline += arg[j++];
            }
        }

        if (needQuote)
            cmdline += '"';

        if (iarg + 1 < args.size())
            cmdline += ' ';
    }

    return cmdline;
}

std::wstring ArgvToCommandLineW(const std::vector<std::wstring>& args)
{
    std::wstring cmdline;

    for (size_t iarg = 0; iarg < args.size(); ++iarg) {
        std::wstring arg = args[iarg];

        bool needQuote = arg.empty() || arg.find_first_of(L" \t\n\v\"") != std::wstring::npos;

        if (needQuote)
            cmdline += L'"';

        for (size_t j = 0; j < arg.size(); ) {
            size_t bs = 0;
            while (j < arg.size() && arg[j] == L'\\') {
                ++j;
                ++bs;
            }

            if (j == arg.size()) {
                cmdline.append(bs * (needQuote ? 2 : 1), L'\\');
                break;
            }

            if (arg[j] == L'"') {
                cmdline.append(bs * 2 + 1, L'\\');
                cmdline += L'"';
                ++j;
            } else {
                cmdline.append(bs, L'\\');
                cmdline += arg[j++];
            }
        }

        if (needQuote)
            cmdline += L'"';

        if (iarg + 1 < args.size())
            cmdline += L' ';
    }

    return cmdline;
}
