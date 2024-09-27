#include "pch.h"
#include "CppUnitTest.h"

#include "Vector2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace r_dsag;

namespace RDSAGTEST
{
	TEST_CLASS(Vector2Test) 
	{
	public:
		TEST_METHOD(DefaultConstructorTest) {
			{
				Vector2 vec{};

				Assert::AreEqual(vec.x, 0.0f, L"");
				Assert::AreEqual(vec.y, 0.0f, L"");
			}

			{
				Vector2 vec;

				Assert::AreEqual(vec.x, 0.0f, L"");
				Assert::AreEqual(vec.y, 0.0f, L"");
			}
		}

		TEST_METHOD(CopyConstructorTest) {
			Vector2 o(3, 4);
			Vector2 vec(o);

			Assert::AreEqual(o.x, vec.x, L"");
			Assert::AreEqual(o.y, vec.y, L"");
		}
		
		TEST_METHOD(CustomConstructorTest) {
			{
				Vector2 vec(3.0f, 4.0f);

				Assert::AreEqual(3.0f, vec.x, L"");
				Assert::AreEqual(4.0f, vec.y, L"");
			}

			{
				Vector2 vec{ 3.0f, 4.0f };

				Assert::AreEqual(3.0f, vec.x, L"");
				Assert::AreEqual(4.0f, vec.y, L"");
			}
		}

		TEST_METHOD(Arithmetic_Add) {
			Vector2 v1(3.0f, 4.0f);
			Vector2 v2(4.0f, 3.0f);

			auto const v3 = v1 + v2; // v1.operator+(v2);

			Assert::AreEqual(v3.x, v1.x + v2.x);
			Assert::AreEqual(v3.y, v1.y + v2.y);

			// 원본은 변경되면 안됨
			Assert::AreEqual(v1.x, 3.0f);
			Assert::AreEqual(v1.y, 4.0f);
		}

		TEST_METHOD(Arithmetic_Sub) {
			Vector2 v1(3.0f, 4.0f);
			Vector2 v2(4.0f, 3.0f);

			auto const v3 = v1 - v2; // v1.operator-(v2);

			Assert::AreEqual(v3.x, v1.x - v2.x);
			Assert::AreEqual(v3.y, v1.y - v2.y);

			// 원본은 변경되면 안됨
			Assert::AreEqual(v1.x, 3.0f);
			Assert::AreEqual(v1.y, 4.0f);
		}

		TEST_METHOD(Arithmetic_Mul) {
			Vector2 v1(3.0f, 4.0f);

			auto const c = 3.0f;
			auto const v2 = c * v1;

			Assert::AreEqual(v2.x, c * v1.x);
			Assert::AreEqual(v2.y, c * v1.y);

			// 원본은 변경되면 안됨
			Assert::AreEqual(v1.x, 3.0f);
			Assert::AreEqual(v1.y, 4.0f);
		}

		TEST_METHOD(Arithmetic_DivNonZero) {
			Vector2 v1(3.0f, 4.0f);

			auto const c = 3.0f;
			auto const v2 = v1 / c;

			Assert::AreEqual(v2.x, v1.x / c);
			Assert::AreEqual(v2.y, v1.y / c);

			// 원본은 변경되면 안됨
			Assert::AreEqual(v1.x, 3.0f);
			Assert::AreEqual(v1.y, 4.0f);
		}

		TEST_METHOD(Arithmetic_DivZero) {
			Vector2 v1(3.0f, 4.0f);
			auto const c = 0.0f;

			auto const v2 = v1 / c;

			Assert::IsTrue(std::isinf(v2.x));
			Assert::IsTrue(std::isinf(v2.y));
		}

		TEST_METHOD(Logical_Equality) {
			Vector2 v1(3.0f, 4.0f);
			Vector2 v2(3.0f, 4.0f);

			Assert::IsTrue(v1 == v2);
			Assert::IsFalse(v1 != v2);
			Assert::AreEqual(v1 == v2, !(v1 != v2));
		}

		TEST_METHOD(Length) {
			Vector2 vec(3.0f, 4.0f);
			auto const ls = vec.LengthSquared();
			auto const l = vec.Length();

			Assert::AreEqual(ls, l * l);
			Assert::AreEqual(ls, vec.x * vec.x + vec.y * vec.y);
		}

		TEST_METHOD(Distance) {
			Vector2 v1(3.0f, 4.0f);
			Vector2 v2;

			auto const ds = v1.DistanceSquared(v2);
			auto const d = v1.Distance(v2);

			Assert::AreEqual(ds, d * d);

			auto const dx = v1.x - v2.x;
			auto const dy = v1.y - v2.y;
			Assert::AreEqual(ds, dx * dx + dy * dy);
		}

		TEST_METHOD(Normalized) {

			Vector2 v1(3.0f, 4.0f);

			auto const nv = v1.Normalized();

			Assert::AreEqual(nv.Length(), 1.0f); // 길이가 1이어야 함

			auto const vl = v1.Length();

			Assert::AreEqual(v1.x / vl, nv.x);
			Assert::AreEqual(v1.y / vl, nv.y);

			Vector2 v2(v1); v2.Normalize();

			Assert::AreEqual(nv.x, v2.x);
			Assert::AreEqual(nv.y, v2.y);
		}

		TEST_METHOD(Normalized_Tolerance) {

			Vector2 v1(Vector2::Normalize_Tolerance, Vector2::Normalize_Tolerance);

			auto const nv = v1.Normalized();

			Assert::IsTrue(nv == Vector2::Zero());
		}

		TEST_METHOD(Cross) {
			Vector2 v1(3.0f, 4.0f);
			Vector2 v2(4.0f, 3.0f);

			auto const v3 = v1.Cross(v2);

			Assert::AreEqual(v3.x, v1.x * v2.y);
			Assert::AreEqual(v3.y, v1.y * v2.x);
		}

		TEST_METHOD(Dot) {

			Vector2 v1(3.0f, 4.0f);
			Vector2 v2(4.0f, 3.0f);

			auto const d = v1.Dot(v2);

			Assert::AreEqual(d, v1.x * v2.x + v1.y * v2.y);
		}

	};
}
