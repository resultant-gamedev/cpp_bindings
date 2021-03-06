#ifndef TRANSFORM_H
#define TRANSFORM_H

#if defined(_WIN32)
#  ifdef _GD_CPP_CORE_API_IMPL
#    define GD_CPP_CORE_API __declspec(dllexport)
#  else
#    define GD_CPP_CORE_API __declspec(dllimport)
#  endif
#else
#  define GD_CPP_CORE_API
#endif

#include "Basis.hpp"

#include "Plane.hpp"
#include "Rect3.hpp"

namespace godot {

class GD_CPP_CORE_API Transform {
public:

	Basis basis;
	Vector3 origin;

	void invert();
	Transform inverse() const;

	void affine_invert();
	Transform affine_inverse() const;

	Transform rotated(const Vector3& p_axis,real_t p_phi) const;

	void rotate(const Vector3& p_axis,real_t p_phi);
	void rotate_basis(const Vector3& p_axis,real_t p_phi);

	void set_look_at( const Vector3& p_eye, const Vector3& p_target, const Vector3& p_up );
	Transform looking_at( const Vector3& p_target, const Vector3& p_up ) const;

	void scale(const Vector3& p_scale);
	Transform scaled(const Vector3& p_scale) const;
	void scale_basis(const Vector3& p_scale);
	void translate( real_t p_tx, real_t p_ty, real_t p_tz );
	void translate( const Vector3& p_translation );
	Transform translated( const Vector3& p_translation ) const;

	inline const Basis& get_basis() const { return basis; }
	inline void set_basis(const Basis& p_basis) { basis=p_basis; }

	inline const Vector3& get_origin() const { return origin; }
	inline void set_origin(const Vector3& p_origin) { origin=p_origin; }

	void orthonormalize();
	Transform orthonormalized() const;

	bool operator==(const Transform& p_transform) const;
	bool operator!=(const Transform& p_transform) const;

	Vector3 xform(const Vector3& p_vector) const;
	Vector3 xform_inv(const Vector3& p_vector) const;

	Plane xform(const Plane& p_plane) const;
	Plane xform_inv(const Plane& p_plane) const;

	Rect3 xform(const Rect3& p_aabb) const;
	Rect3 xform_inv(const Rect3& p_aabb) const;

	void operator*=(const Transform& p_transform);
	Transform operator*(const Transform& p_transform) const;

	Transform interpolate_with(const Transform& p_transform, real_t p_c) const;

	Transform inverse_xform(const Transform& t) const;

	void set(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz,real_t tx, real_t ty, real_t tz);

	operator String() const;

	inline Transform(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz,real_t tx, real_t ty, real_t tz) {
		set(xx, xy, xz, yx, yy, yz, zx, zy, zz,tx, ty, tz);
	}

	Transform(const Basis& p_basis, const Vector3& p_origin=Vector3());
	inline Transform() {}

};

}

#endif // TRANSFORM_H
