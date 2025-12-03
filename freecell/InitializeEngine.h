// InitializeEngine.h
// Engine initialization function declaration
#pragma once

#include "IEngineInterface.h"

// Initialize the game engine
// Returns true on success, false on failure
bool InitializeEngine(IEngineInterface* engine, IControllerInterface* controller);
