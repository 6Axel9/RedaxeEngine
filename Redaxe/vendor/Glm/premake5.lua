project "Glm"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("%{wks.location}/bin/" .. outputVendorDir .. "/%{prj.name}")
    objdir ("%{wks.location}/temp/" .. outputVendorDir .. "/%{prj.name}")

	files
	{
		"glm/**.hpp",
		"builder.cpp"
    }
    
	includedirs
	{
		"glm"
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