/*
 * vector3.h
 *
 *  Created on: 9 de jul de 2017
 *      Author: paulo
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <cmath>
#include <iostream>

class vector3 {
public:

	double x,y,z;

	vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	};
	vector3(double _x,double _y,double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	};

	friend std::ostream& operator << (std::ostream& os,const vector3& v )
	{
		os << "(" << v.x << "," << v.y <<","<< v.z << ")";
		return os;
	}

//Sobrecarga de operador...
	//adição
	vector3 operator + (const vector3& v)
	{

		return vector3(x+v.x, y+v.y, z+v.z);
	}

	vector3 operator +( double s)
	{
			return vector3(x+s, y+s, z-s);
	}

	//subtração
	vector3 operator - (const vector3& v)const
	{
		return vector3(x-v.x, y-v.y, z-v.z);
	}

	vector3 operator - ()
	{
		return vector3(-x,-y,-z);
	}


	//multipl
	vector3 operator * (const vector3& v)const
	{
		return vector3(x*v.x, y*v.y, z*v.z);
	}

	vector3 operator * (double s) const
	{
			return vector3(x*s, y*s, z*s);
	}

	//divi
	vector3 operator / (const vector3& v) const
	{
		return vector3(x/v.x, y/v.y, z/v.z);
	}

	vector3 operator / (double s) const
	{
			s = 1.0f/s;
			return vector3(x*s, y*s, z*s);
	}

	//atribuição

	vector3 operator = (const vector3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	vector3 operator = (double s)
		{
			x = s;
			y = s;
			z = s;
			return *this;
		}


	vector3 operator +=(const vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	vector3 operator +=(double s)
	{
		x += s;
		y += s;
		z += s;
		return *this;
	}

	vector3 operator -=(const vector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	vector3 operator -=(double s)
	{
		x -= s;
		y -= s;
		z -= s;
		return *this;
	}

	vector3 operator *=(const vector3& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}

	vector3 operator *=(double s)
	{
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}


	vector3 operator /=(const vector3& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return *this;
	}

	vector3 operator /=(double s)
	{
		x /= s;
		y /= s;
		z /= s;
		return *this;
	}


	bool operator ==(const vector3& v)
	{
		return (x == v.x) && (y == v.y) && (z == v.z);
	}


	bool operator !=(const vector3& v)
	{
		return (x != v.x) || (y != v.y) || (z != v.z);
	}

	//Funçoes

	//Produto Vetorial
	vector3 crossp(vector3& v)const
	{
		return vector3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x );
	}

	//Produto Escalar
	double dot (vector3& v)
	{
		return x*v.x + y*v.y + z*v.z;
	}

	//Calculo da Distância Euclidiana
	double length(const vector3& v)
	{
		double dx = x - v.x, dy = y - v.y, dz = z - v.z;
		return sqrt(dx*dx + dy*dy + dz*dz);
	}
	//Calculo d Quadrado da Distância Euclidiana
	double sqrLength(const vector3& v)
	{
		double dx = x - v.x, dy = y - v.y, dz = z - v.z;
		return sqrt(dx*dx + dy*dy + dz*dz);
	}

	//Calcula a magnite de um vetor
	double magnitude()
	{
		return sqrt(x*x+y*y+z*z);
	}
	//Calcula o quadrado da magnite de um vetor
	double sqrMagnitude()
	{
		return x*x+y*y+z*z;
	}

	//Normaliação do vetor

	void normalize()
	{
		double mag = magnitude();

		if (mag > 0.0f)
		{
			double invMag = 1.0f/mag;
			x *= invMag;
			y *= invMag;
			z *= invMag;
		}
	}

	//Retorna o vetor projeção sobre uma superfície de normal n
	vector3 project(vector3& n)
	{
		return vector3( *this - (n * dot(n)) );
	}

	//Retorna o vetor reflexão sobre uma superfície de normal n
	vector3 reflect(vector3& n)
	{
		return vector3( *this - ((n * dot(n)) * 2) );
	}

	virtual ~vector3(){};
};

#endif /* VECTOR3_H_ */
