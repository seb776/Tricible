#pragma once

namespace Tricible
{
	template<typename T, int borderLeft, int borderRight> T Random();
	template<typename T, int borderLeft, int borderRight> T Random(int x);
	template<typename T, int borderLeft, int borderRight> T Random(int x, int y);
	template<typename T, int borderLeft, int borderRight> T Random(int x, int y, int z);
}

// END
