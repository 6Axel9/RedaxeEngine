include "dependencies.lua"

workspace "Redaxe"
    architecture "x86_64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Distro"
    }

	flags
	{
		"MultiProcessorCompile"
	}

outputDir = "%{cfg.buildcfg}"
outputVendorDir = "%{cfg.buildcfg}/vendor"

group "Dependencies"
    include "Redaxe/vendor/Glfw"
    include "Redaxe/vendor/Glad"
    include "Redaxe/vendor/Spdlog"
group ""

include "Redaxe"
include "Sandbox"