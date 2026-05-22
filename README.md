# ArgvToCommandLine

It's the inverse of `CommandLineToArgvW` function.

```cxx
std::string  ArgvToCommandLineA(int argc, char    **argv);
std::wstring ArgvToCommandLineW(int argc, wchar_t **argv);

std::string  ArgvToCommandLineA(const std::vector<std::string>&  args);
std::wstring ArgvToCommandLineW(const std::vector<std::wstring>& args);

#ifdef UNICODE
    #define ArgvToCommandLine ArgvToCommandLineW
#else
    #define ArgvToCommandLine ArgvToCommandLineA
#endif
```

License: MIT
