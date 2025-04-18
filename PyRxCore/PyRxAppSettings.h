#pragma once
class PyRxAppSettings
{
public:
    static const std::filesystem::path& iniPath();
    static const std::tuple<bool, std::wstring> pyexecutable_path();
    static const std::tuple<bool, std::wstring> pyonload_path();
    static std::vector<std::wstring>& getCommandLineArgs();
};

