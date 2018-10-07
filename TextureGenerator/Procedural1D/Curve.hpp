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
	float	ComputeSmoothNoise(const float x);
	void	Curve(const int NbrPoint, const int SizeBuffer, float * BufferNoise[]);
};

// END
