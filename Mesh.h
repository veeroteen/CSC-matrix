#pragma once

#include <vector>
#include <set>

typedef unsigned index_t;


struct Polygon
{
	index_t vertices[3];
};


template< typename T >
class Point3D
{
public:
	bool operator < (const Point3D & rhs) const
	{
		if( xyz[0] < rhs.xyz[0] )
			return true;
		if( xyz[0] > rhs.xyz[0] )
			return false;
		if( xyz[1] < rhs.xyz[1] )
			return true;
		if( xyz[1] > rhs.xyz[1] )
			return false;
		if( xyz[2] < rhs.xyz[2] )
			return true;
		if( xyz[2] > rhs.xyz[2] ) 
			return false;
		return false;

	}

public:
	union
	{
		T xyz[3];
		struct
		{
			T x, y, z;
		};
	};
};


class Face
{
public:
	std::vector<Polygon> polygons;
};


class Mesh
{
public:
	std::vector<Face> faces;
	std::vector< Point3D<double> > vertices;
};
