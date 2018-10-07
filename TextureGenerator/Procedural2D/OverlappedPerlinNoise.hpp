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
namespace Procedural2D
{
	float	ComputeSmoothNoise(const float x, const float y, const int octaves, const float OverlapPercent);
	void	OverlappedPerlinNoise(const int NbrPointX, const int NbrPointY, const int NbrPerlinNoiseStacked, const float OverlapPercent, const int SizeBufferX, const int SizeBufferY, float * BufferNoise[]);
};

// END
