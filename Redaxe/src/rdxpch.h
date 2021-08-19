#pragma once

#include <functional>
#include <algorithm>
#include <iostream>
#include <utility>
#include <memory>
#include <chrono>

#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <list>

#ifdef RDX_PLATFORM_WIN
	#include <Windows.h>
#endif

#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "spdlog/spdlog.h"
#include "imgui.h"
#include "glm.hpp"

#define Log spdlog
#define Gui ImGui
#define Math glm