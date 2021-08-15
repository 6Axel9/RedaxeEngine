project "ImGui"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("%{wks.location}/bin/" .. outputVendorDir .. "/%{prj.name}")
    objdir ("%{wks.location}/temp/" .. outputVendorDir .. "/%{prj.name}")

	files
	{
		"backends/imgui_impl_glfw.h",
        "backends/imgui_impl_glfw.cpp",
		"backends/imgui_impl_opengl3.h",
        "backends/imgui_impl_opengl3.cpp",
		"imconfig.h",
		"imgui.h",
		"imgui.cpp",
		"imgui_draw.cpp",
		"imgui_internal.h",
		"imgui_widgets.cpp",
		"imgui_tables.cpp",
		"imstb_rectpack.h",
		"imstb_textedit.h",
		"imstb_truetype.h",
		"imgui_demo.cpp"
	}

	includedirs
	{
		"%{prj.location}",
		"%{IncludeDir.glad}",
        "%{IncludeDir.glfw}",
	}

	links
	{
		"Glfw",
        "Glad"
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"