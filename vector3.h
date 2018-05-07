#pragma once




template<typename T>
class Vec3
{
public:
	Vec3<T>():x(T()),y(T()),z(T())
	{
	}

	Vec3<T>(T x, T y, T z) : x(x), y(y), z(z)
	{
	}
	Vec3<T>(T x) : x(x), y(x), z(x)
	{
	}

	Vec3<T>(const Vec3<T>& p_vec3)
	{
		x = p_vec3.x;
		y = p_vec3.y;
		z = p_vec3.z;
	}

	inline Vec3<T>& operator =(const Vec3<T>& p_vec3) {
		x = p_vec3.x;
		y = p_vec3.y;
		z = p_vec3.z;

		return *this;
	}

	inline Vec3<T>& operator +=(const Vec3<T>& p_vec3) {
		x += p_vec3.x;
		y += p_vec3.y;
		z += p_vec3.z;
		return *this;
	}

	inline Vec3<T>& operator -=(const Vec3<T>& p_vec3) {
		x -= p_vec3.x;
		y -= p_vec3.y;
		z -= p_vec3.z;
		return *this;
	}
	inline Vec3<T>& operator *=(const Vec3<T>& p_vec3) {

		x *= p_vec3.x;
		y *= p_vec3.y;
		z *= p_vec3.z;
		return *this;
	}
	inline Vec3<T>& operator /=(const Vec3<T>& p_vec3) {

		x /= p_vec3.x;
		y /= p_vec3.y;
		z /= p_vec3.z;
		return *this;
	}
	inline Vec3<T> normalize() {
		T l_length = length();
		return Vec3<T>(x / l_length, y / l_length, z / l_length);
	}
	inline T length() {

		return sqrt(x*x + y*y+z*z);
	}


	inline Vec3<T> operator +(const Vec3<T>& rhs) const{
		return Vec3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
	}
	inline Vec3<T> operator -(const Vec3<T>& rhs) const {
		return Vec3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
	}
	inline Vec3<T> operator *(const Vec3<T>& rhs) const {
		return Vec3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
	}
	inline Vec3<T> operator /(const Vec3<T>& rhs) const {
		return Vec3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
	}


	inline Vec3<T> operator +() {
		
		return *this;
	}
	inline Vec3<T> operator -() {

		return Vec3<T>(-x, -y , -z);
	}
	
	
	inline static T dot(const Vec3<T>& lhs, const Vec3<T>& rhs) {
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}
	inline static Vec3<T> normalize(const Vec3<T>& rhs) {

		return Vec3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
	}

	inline Vec3<T> operator *(const T& lhs) {
		return Vec3<T>(lhs * x , lhs * y , lhs * z);
	}



	Vec3::~Vec3()
	{
	}

	T x;
	T y;
	T z;

};


using Vec3f = Vec3<float>;
using Vec3i = Vec3<float>;



