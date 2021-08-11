project "Redaxe"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputDir .. "/%{prj.name}")
    objdir ("%{wks.location}/temp/" .. outputDir .. "/%{prj.name}")

    pchheader "rdxpch.h"
    pchsource "src/rdxpch.cpp"

    files
    {
        "include/**.h",
        "include/**.cpp",
        "src/**.h",
        "src/**.cpp"
    }

    defines
	{
        "RDX_PLATFORM_WIN",
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

    includedirs
    {
        "src",
        "%{IncludeDir.glad}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.spdlog}"
    }

    links
	{
		"Glfw",
        "Glad",
        "Spdlog"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "RDX_DEBUG"
		runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "RDX_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Distro"
        defines "RDX_DISTRO"
        runtime "Release"
        optimize "On"