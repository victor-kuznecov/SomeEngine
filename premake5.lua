workspace "SomeEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Distr"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (sopution folder)
IncludeDir = {}
IncludeDir["GLFW"] = "SomeEngine/vendor/GLFW/include"

include "SomeEngine/vendor/GLFW"

project "SomeEngine"
	location "SomeEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sepch.h"
	pchsource "SomeEngine/src/sepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SE_PLATFORM_WINDOWS",
			"SE_BUILD_DLL"
		}

		postbuildcommands 
		{
			"copy /B /Y ..\\bin\\" .. outputdir .. "\\SomeEngine\\SomeEngine.dll ..\\bin\\" .. outputdir .. "\\Sandbox\\ > nul"
		}

	filter "configurations:Debug"
		defines "SE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Distr"
		defines "SE_DISTR"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SomeEngine/vendor/spdlog/include",
		"SomeEngine/src"
	}

	links 
	{
		"SomeEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SE_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "SE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Distr"
		defines "SE_DISTR"
		buildoptions "/MD"
		optimize "On"