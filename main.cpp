#include <windows.h>

void disableOverlay();
void _enableOverlay();

int main(int argc, char** argv)
{

    if (argc == 2 && !strcmp("-show", argv[1])) _enableOverlay();

    else
        disableOverlay();

    return 0;
}

void disableOverlay()
{
    HWND hwndHost = NULL;

    while ((hwndHost = FindWindowExW(0, hwndHost, L"NativeHWNDHost", L"")) != NULL)
    {
        if (FindWindowExW(hwndHost, NULL, L"DirectUIHWND", L"") != NULL)
        {
            ShowWindow(hwndHost, SW_MINIMIZE);
        }
    }
}

void _enableOverlay()
{
    HWND hwndHost = NULL;

    while ((hwndHost = FindWindowExW(0, hwndHost, L"NativeHWNDHost", L"")) != NULL)
    {
        if (FindWindowExW(hwndHost, NULL, L"DirectUIHWND", L"") != NULL)
        {
            ShowWindow(hwndHost, SW_NORMAL);
        }
    }
}
