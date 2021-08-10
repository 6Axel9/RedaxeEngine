project "Sandbox"
    kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputDir .. "/%{prj.name}")
    objdir ("%{wks.location}/temp/" .. outputDir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.redaxe}/include",
        "%{IncludeDir.redaxe}/src",
        "%{IncludeDir.glad}",
        "%{IncludeDir.glfw}"
    }

    defines 
    { 
        "RDX_PLATFORM_WIN"
    }

    links
    {
        "Redaxe"
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