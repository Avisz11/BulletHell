workspace "BulletHell"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "BulletHell"
	location "BulletHell"
	kind "ConsoleApp"
	language "C++"

	cppdialect "C++20"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/raylib/include"
	}

	libdirs
	{
		"%{prj.name}/raylib/lib"
	}

	links
	{
		"raylib"
	}


	filter "system:windows"
		systemversion "latest"
