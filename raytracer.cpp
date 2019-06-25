#include<iostream>
#include<fstream>
#include "ray.h"

using namespace std;

bool hit_sphere(const vec3& center, float radius, const ray& r) {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius*radius;
	float discriminant = b*b - 4*a*c;
	return (discriminant > 0);
	}

vec3 color(const ray &r) {
	if(hit_sphere(vec3(0, 0, -1), 0.8, r))
		return vec3(1, 0, 0);
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5*(unit_direction.y() + 1.0);
	return vec3(1.0, 1.0, 1.0)*(1.0-t) + vec3(0.5, 0.7, 1.0)*t;
	}

int main() {
	int nx = 500; //image width
	int ny = 500; //image height
	ofstream f;
	f.open("sphere1.ppm");
	f <<"P3\n"<<nx<<" "<<ny<<"\n255\n";
	//generating a matrix of values which describes the image
	const vec3 lower_left_corner(-5.0, -5.0, -1.0);
	const vec3 horizontal(10.0, 0, 0);
	const vec3 vertical(0, 10.0, 0);
	const vec3 origin(0, 0, 0);
	for(int j = ny-1; j >= 0; j--) {
		for(int i = 0; i < nx; i++) {
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			const vec3 ray_dir = lower_left_corner + u*horizontal + v*vertical;
			ray r(origin, ray_dir);
			vec3 col = color(r);
			int ir = int(255.99*col.r());
			int ig = int(255.99*col.g());
			int ib = int(255.99*col.b());
			f<<ir<<" "<<ig<<" "<<ib<<"\n";
			}
		}
	f.close();
	}
