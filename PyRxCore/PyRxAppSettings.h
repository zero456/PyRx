#pragma once
class PyRxAppSettings
{
public:
    static void tomlTest();
    static const std::tuple<bool, std::wstring> pyexecutable_path();
    static const std::tuple<bool, std::wstring> pyonload_path();
    static std::vector<std::wstring>& getCommandLineArgs();
};

