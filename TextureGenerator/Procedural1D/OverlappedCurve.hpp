//
// Author: Pierre COURTEILLE
//

//----------------------------------------//
// protection double inclusion
//----------------------------------------//
#pragma once

//----------------------------------------//
// define
//----------------------------------------//
namespace Procedural1D
{
	float	ComputeSmoothNoise(const float x, const int octaves, const float OverlapPercent);
	void	OverlappedCurve(const int NbrPoint, const int NbrPerlinNoiseStacked, const float OverlapPercent, const int SizeBuffer, float * BufferNoise[]);
};

// END
