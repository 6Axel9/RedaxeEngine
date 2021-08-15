include "dependencies.lua"

workspace "Redaxe"
    architecture "x86_64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
    }

	flags
	{
		"MultiProcessorCompile"
	}

outputDir = "%{cfg.buildcfg}"
outputVendorDir = "%{cfg.buildcfg}/Vendor"

group "Dependencies"
    include "Redaxe/vendor/Glfw"
    include "Redaxe/vendor/Glad"
    include "Redaxe/vendor/SpdLog"
    include "Redaxe/vendor/ImGui"
group ""

include "Redaxe"
include "Sandbox"