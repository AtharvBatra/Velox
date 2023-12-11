#pragma once

#ifdef VX_PLATFORM_WINDOWS
	#ifdef VX_BUILD_DLL
		#define VELOX_API __declspec(dllexport)
	#else
		#define VELOX_API __declspec(dllimport)
	#endif
#else
#error Velox is only supported on Windows!
#endif

#define BIT(x) (1 << x)
