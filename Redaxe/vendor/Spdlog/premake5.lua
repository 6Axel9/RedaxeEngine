project "Spdlog"
	kind "StaticLib"
    language "C++"
    cppdialect "C++17"

	targetdir ("%{wks.location}/bin/" .. outputVendorDir .. "/%{prj.name}")
    objdir ("%{wks.location}/temp/" .. outputVendorDir .. "/%{prj.name}")

	files
	{
		"include/**.h",
        "include/**.cpp",
        "src/**.h",
        "src/**.cpp"
	}
	
	includedirs
	{
		"include"
	}

	defines
	{
		"SPDLOG_COMPILED_LIB"
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