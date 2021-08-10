project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"
    
    targetdir ("%{wks.location}/bin/" .. outputVendorDir .. "/%{prj.name}")
    objdir ("%{wks.location}/temp/" .. outputVendorDir .. "/%{prj.name}")

    files
    {
        "include/glad/glad.h", 
        "include/khr/khrplatform.h",
        "src/**.c"
    }

    includedirs
    {
        "include"
    }
    
    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"