// types.h
// Common type definitions for the FreeCell project
#pragma once

#include <windows.h>
#include <cstdint>

// Forward declarations for common types
class CardStack;
class CardTable;
class Card;
class FreeCellGame;
class NodeBase;
class NodeSprite;
class NodeEmitter;
class NodeButton;
class NodeLabel;
class XmlNode;
class XmlManager;
class ResourceManager;
class RenderManager;
class Audio;
class Timer;
class Event;
class AnimationDescriptor;
class AnimationState;
class Str;
class DllFileMgr;
class UserInterface;
class TipManager;
class ResourceWMA;
class ResourceWav;
class ResourceBase;
class CommonControllerThread;
class Thread;
class Font;
class TextRenderer;
class Material;
class Particle;

// Interface forward declarations
struct IEngineInterface;
struct IControllerInterface;
struct IEventListener;
struct IStateMachine;

// Struct forward declarations
struct CardAnimation;
struct Move;
struct ScoredMove;
struct TipSource;
struct RenderInitializeOptions;
struct StackGroup;

// Template array type used throughout the codebase
template<typename T>
class _Array {
public:
    _Array() : m_data(nullptr), m_count(0), m_capacity(16) {}
    ~_Array() {
        if (m_data) {
            delete[] m_data;
        }
    }
    
    unsigned int Add(const T& item) {
        if (m_count >= m_capacity) {
            // Grow the array
            unsigned int newCapacity = m_capacity * 2;
            T* newData = new T[newCapacity];
            for (unsigned int i = 0; i < m_count; i++) {
                newData[i] = m_data[i];
            }
            delete[] m_data;
            m_data = newData;
            m_capacity = newCapacity;
        }
        m_data[m_count] = item;
        return m_count++;
    }
    
    T* m_data;
    unsigned int m_count;
    unsigned int m_capacity;
};

// Global variables declarations
extern HINSTANCE g_hInstance;
extern HWND g_hWnd;
extern HWND g_hRenderWindow;
extern bool g_bMediaCenter;
extern bool g_bDebugEnabled;
extern bool g_bDoubleDPI;
extern bool g_bInitializing;
extern bool g_bInInitializer;
extern bool g_bFocusPause;
extern HACCEL g_Accelerator;
extern const wchar_t* g_SETTINGS_SAVE_FILENAME;
extern const wchar_t* g_wszProjectName;
extern unsigned __int64 g_GdiPlusToken;
extern unsigned __int16* g_bstrGDFPath;
extern IEngineInterface* g_pInterface;
extern XmlManager* g_pXmlManager;
extern ResourceManager* g_pResourceManager;
extern RenderManager* g_pRenderManager;
extern Audio* g_pAudio;
extern Timer* g_pTimer;
extern FreeCellGame* g_pFreeCellGame;
extern CommonControllerThread* g_pCommonController;
extern void* g_pSecondTimerCallback;
extern DllFileMgr* qword_1000B10B0;

// External function for Windows 7 licensing check
extern "C" HRESULT WINAPI SLGetWindowsInformationDWORD(PCWSTR pwszValueName, DWORD* pdwValue);
