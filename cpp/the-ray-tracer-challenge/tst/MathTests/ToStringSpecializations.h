#pragma once

#ifndef TOSTRINGSPECIALIZATIONS_H
#define TOSTRINGSPECIALIZATIONS_H

#include <string>
#include "../../vec3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<vec3>(const class vec3& t) { return L"vec3"; }
		}
	}
}

#endif