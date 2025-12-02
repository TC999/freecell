#include <windows.h>
#include "DialogHelper.h" // 假设有这个头文件
#include "EngineHandler.h" // 假设有这个头文件

HINSTANCE g_hInstance = nullptr;

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    g_hInstance = hInstance;
    // 启用堆损坏时终止进程
    HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption, nullptr, 0);

    // 检查是否为平板模式（GetSystemMetrics(67) 通常是SM_CONVERTIBLESLATEMODE）
    if (GetSystemMetrics(67))
    {
        // 设备为平板模式，弹窗提示
        unsigned short flag = 1;
        DialogHelper::ShowMessageBox(0x385, 0x374, 1, 0xFFFE, 0, 0, &flag, false);
        return 1;
    }
    else
    {
        DWORD enabled = 1;
        // 检查注册表或系统设置，是否允许游戏
        SLGetWindowsInformationDWORD(L"Shell-InBoxGames-FreeCell-EnableGame", &enabled);

        // 创建引擎对象
        IEngineInterface* engine = new EngineHandler();
        BOOL failed = TRUE;
        if (engine)
        {
            // 初始化引擎
            failed = !InitializeEngine(engine, 0);
            // 释放引擎对象
            delete engine;
        }
        return failed;
    }
}