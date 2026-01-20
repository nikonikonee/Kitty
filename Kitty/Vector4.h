#pragma once


namespace SDK::Structs::Unity
{
	struct Vector4
	{
		union
		{
			struct
			{
				float X;
				float Y;
				float Z;
				float W;
			};
			float data[4];
		};

		inline Vector4();
		inline Vector4(float data[]);
		inline Vector4(float value);
		inline Vector4(float x, float y);
		inline Vector4(float x,  float y, float z);
		inline Vector4(float x, float y, float z, float w);
	};

	//Implementation
	Vector4::Vector4() : X(0), Y(0), Z(0), W(0) {}
	Vector4::Vector4(float data[]) : X(data[0]), Y(data[1]), Z(data[2]), W(data[3]) {}
	Vector4::Vector4(float value) : X(value), Y(value), Z(value), W(value) {}
	Vector4::Vector4(float x, float y) : X(x), Y(y), Z(0), W(0) {}
	Vector4::Vector4(float x, float y, float z) : X(x), Y(y), Z(z), W(0) {}
	Vector4::Vector4(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) {}
}