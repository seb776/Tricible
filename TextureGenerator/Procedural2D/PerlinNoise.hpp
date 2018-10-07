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
	float	ComputeSmoothNoise(const float x, const float y);
	void	PerlinNoise(const int NbrPointX, const int NbrPointY, const int SizeBufferX, const int SizeBufferY, float * BufferNoise[]);
};

// END
