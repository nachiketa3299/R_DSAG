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
		/// <paramref name="c"/>�� 0�� ���, ������ �� ��Ұ� ��� ���Ѵ밡 �ȴ�.
		/// </summary>
		friend Vector2 operator/(Vector2 const& r, float c);

		bool operator==(Vector2 const& r) const;
		bool operator!=(Vector2 const& r) const;

		float LengthSquared() const;
		float Length() const;

		float DistanceSquared(Vector2 const& r) const;
		float Distance(Vector2 const& r) const;

		/// <summary>
		/// �� ���͸� ����ȭ�� �� ���͸� ��ȯ�Ѵ�. ���� ������ ũ�Ⱑ 0�� �ʹ� �����ϸ�, �����͸� ��ȯ�Ѵ�.
		/// </summary>
		/// <returns></returns>
		Vector2 Normalized() const;

		/// <summary>
		/// �� ���͸� ����ȭ�Ѵ�. ���� ������ ũ�Ⱑ 0�� �ʹ� �����ϸ�, �� ���ͷ� �����.
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
