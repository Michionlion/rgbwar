
struct vec2 {
	float x,y;
	vec2(float,float);
	vec2(void);
	vec2 operator +(const vec2&);
	vec2 operator -(const vec2&);
	vec2 operator *(const float&);
};
