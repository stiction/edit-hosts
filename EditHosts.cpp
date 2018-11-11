#include <windows.h>
#include <tchar.h>

#define PATH_BUFFER_SIZE 256
char pathBuffer[PATH_BUFFER_SIZE];
SHELLEXECUTEINFO shExecInfo;

BOOL EditHosts()
{
    const char *path = "%SystemRoot%\\System32\\drivers\\etc\\hosts";
    DWORD size = ExpandEnvironmentStrings(path, pathBuffer, PATH_BUFFER_SIZE);
    if (size == 0 || size > PATH_BUFFER_SIZE)
    {
        return FALSE;
    }

    shExecInfo.cbSize = sizeof(shExecInfo);
    shExecInfo.lpVerb = "runas";
    shExecInfo.lpFile = "notepad.exe";
    shExecInfo.lpParameters = pathBuffer;
    shExecInfo.nShow = SW_SHOWDEFAULT;

    return ShellExecuteEx(&shExecInfo);
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    EditHosts();
    return 0;
}
