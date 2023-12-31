workspace "Velox"
  architecture "x64"
  startproject "Sandbox"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Velox"
  location "Velox"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.hpp",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "%{prj.name}/src",
    "%{prj.name}/deplibs/spdlog/include"
  }

  filter "system:windows"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "VX_PLATFORM_WINDOWS",
      "VX_BUILD_DLL"
    }

    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

  filter "configurations:Debug"
    defines "VX_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "VX_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "VX_DIST"
    optimize "On"

project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.hpp",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "Velox/deplibs/spdlog/include",
    "Velox/src"
  }

  links
  {
    "Velox"
  }

  filter "system:windows"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "VX_PLATFORM_WINDOWS"
    }

  filter "configurations:Debug"
    defines "VX_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "VX_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "VX_DIST"
    optimize "On"
