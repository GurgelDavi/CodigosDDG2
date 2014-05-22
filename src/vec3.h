#ifndef vec3_H
#define vec3_H

#include <cmath>
#include <iostream>

class vec3
{
    public:

        /***********
          Variáveis
         ***********/

        //Coordenadas x, y e z do vetor
        double x, y, z;


        /**************
          Construtores
         **************/

        //Construtor do vetor nulo
        vec3() : x(0.0f), y(0.0f), z(0.0f) { }

        //Construtor (x, y, z)
        vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) { }


        /***********
          Destrutor
         ***********/

        //Destrutor
        virtual ~vec3() { }


        /************
          Operadores
         ************/

        //Implementação de std::cout << v;

        friend std::ostream& operator << (std::ostream& os, const vec3& v)
        {
            os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
            return os;
        }

        //Soma das coordenadas de dois vetores
        vec3 operator +(const vec3& v) const
        {
            return vec3( x+v.x, y+v.y, z+v.z );
        }

        //Subtração das coordenadas de dois vetores
        vec3 operator -(const vec3& v) const
        {
            return vec3( x-v.x, y-v.y, z-v.z );
        }

        //Inversão do sinal de um vetor
        vec3 operator -() const
        {
            return vec3(-x,-y,-z);
        }

        //Multiplicação entre as coordenadas de dois vetores
        vec3 operator *(const vec3& v) const
        {
            return vec3( x*v.x, y*v.y, z*v.z );
        }

        //Multiplicação de vetor por escalar
        vec3 operator *(double s) const
        {
            return vec3( s*x, s*y, s*z );
        }

        //Divisão entre as coordenadas de dois vetores
        vec3 operator /(const vec3& v) const
        {
            return vec3( x/v.x, y/v.y, z/v.z );
        }

        //Divisão de vetor por escalar
        vec3 operator /(double s) const
        {
            s = 1.0f/s;
            return vec3( x*s, y*s, z*s );
        }

        //Atribui os valores das coordenadas de um certo vetor (v.x, v.y, v.z) às do vetor (x, y, z)
        vec3& operator =(const vec3& v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            return *this;
        }

        //Soma as coordenadas (x, y, z) a (v.x, v.y, v.z)
        vec3& operator +=(const vec3& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        //Soma as coordenadas (x, y, z) a um escalar
        vec3& operator +=(double s)
        {
            x += s;
            y += s;
            z += s;
            return *this;
        }

        //Subtrai as coordenadas (x, y, z) de (v.x, v.y, v.z)
        vec3& operator -=(const vec3& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        //Subtrai as coordenadas (v.x, v.y, v.z) de um escalar
        vec3& operator -=(double s)
        {
            x -= s;
            y -= s;
            z -= s;
            return *this;
        }

        //Multiplica as coordenadas (x, y, z) com (v.x, v.y, v.z)
        vec3& operator *=(const vec3& v)
        {
            x *= v.x;
            y *= v.y;
            z *= v.z;
            return *this;
        }

        //Multiplica as coordenadas (x, y, z) com escalar
        vec3& operator *=(double s)
        {
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }

        //Divide as coordenadas (x, y, z) com (v.x, v.y, v.z)
        vec3& operator /=(const vec3& v)
        {
            x /= v.x;
            y /= v.y;
            z /= v.z;
            return *this;
        }

        //Divide as coordenadas (x, y, z) com escalar
        vec3& operator /=(double s)
        {
            x /= s;
            y /= s;
            z /= s;
            return *this;
        }

        //Checa se dois vetores são iguais
        bool operator ==(const vec3& v)
        {
            return (x == v.x) && (y == v.y) && (z == v.z);
        }

        //Checa se dois vetores são diferentes
        bool operator !=(const vec3& v)
        {
            return (x != v.x) || (y != v.y) || (z != v.z);
        }


        /*********
          Funções
         *********/

        //Produto vetorial
        vec3 cross(vec3& v) const
        {
            return vec3( y*v.z - z*v.y,
                         z*v.x - x*v.z,
                         x*v.y - y*v.x );
        }

        //Produto escalar
        double dot(vec3& v)
        {
            return x*v.x + y*v.y + z*v.z;
        }

        //Calcula a distância euclidiana
        double length(const vec3& v)
        {
            double dx = x - v.x,
                   dy = y - v.y,
                   dz = z - v.z;
            return sqrt( dx*dx + dy*dy + dz*dz );
        }

        //Calcula o quadrado da distância euclidiana
        double length2(const vec3& v)
        {
            double dx = x - v.x,
                   dy = y - v.y,
                   dz = z - v.z;
            return dx*dx + dy*dy + dz*dz;
        }

        //Calcula a magnitude de um vetor
        double magnitude()
        {
            return sqrt( x*x + y*y + z*z );
        }

        //Calcula o dobro da magnitude de um vetor
        double magnitude2()
        {
            return x*x + y*y + z*z;
        }

        //Normalização do vetor (mantém direção, mas o tamanho do vetor se torna unitário)
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
        vec3 project(vec3& n)
        {
            return vec3( *this - (n * dot(n)) );
        }

        //Retorna o vetor reflexão sobre uma superfície de normal n
        vec3 reflect(vec3& n)
        {
            return vec3( *this - ((n * dot(n)) * 2) );
        }
};

#endif // vec3_H
