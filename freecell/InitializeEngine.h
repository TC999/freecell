// InitializeEngine.h
#pragma once

struct IEngineInterface;
struct IControllerInterface;

// 初始化引擎主流程，controller 可为 nullptr
bool InitializeEngine(IEngineInterface* engine, IControllerInterface* controller);
