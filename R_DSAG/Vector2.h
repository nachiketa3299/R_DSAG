#pragma once

namespace r_dsag {
	struct Vector2 {
	public:
		Vector2() = default;
		Vector2(Vector2 const&) = default;
		Vector2(Vector2&&) = default;
		Vector2& operator=(Vector2&&) = default;
		Vector2& operator=(Vector2 const&) = default;
		~Vector2() = default;

	public:
		Vector2(float x, float y);

	public:
		Vector2 operator+(Vector2 const& r) const;
		Vector2 operator-(Vector2 const& r) const;
		friend Vector2 operator*(float c, Vector2 const& r);

		/// <summary>
		/// <paramref name="c"/>가 0인 경우, 벡터의 두 요소가 모두 무한대가 된다.
		/// </summary>
		friend Vector2 operator/(Vector2 const& r, float c);

		bool operator==(Vector2 const& r) const;
		bool operator!=(Vector2 const& r) const;

		float LengthSquared() const;
		float Length() const;

		float DistanceSquared(Vector2 const& r) const;
		float Distance(Vector2 const& r) const;

		/// <summary>
		/// 이 벡터를 정규화한 새 벡터를 반환한다. 만일 벡터의 크기가 0에 너무 근접하면, 영벡터를 반환한다.
		/// </summary>
		/// <returns></returns>
		Vector2 Normalized() const;

		/// <summary>
		/// 이 벡터를 정규화한다. 만일 벡터의 크기가 0에 너무 근접하면, 영 벡터로 만든다.
		/// </summary>
		/// <returns></returns>
		void Normalize();

		Vector2 Cross(Vector2 const& r) const;
		float Dot(Vector2 const& r) const;

	public:
		inline static float Normalize_Tolerance = 1e9f;
		static Vector2 Zero();

		float x{};
		float y{};
	};
}
