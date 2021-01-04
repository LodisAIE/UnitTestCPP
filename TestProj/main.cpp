#include <Matrix3.h>
#include <Matrix4.h>
#include <Vector3.h>
#include <Vector4.h>
#include <Vector2.h>

Matrix3 Transpose(Matrix3 mat)
{
    return Matrix3
    (
        mat.m11, mat.m21, mat.m31,
        mat.m12, mat.m22, mat.m32,
        mat.m13, mat.m23, mat.m33
    );
}

bool Matrix3Multiply()
{
    Matrix3 m3b = Matrix3();
    m3b = Matrix3::createTranslation(Vector2(2, 3));

    Matrix3 m3c = Matrix3();
    m3c = Matrix3::createTranslation(Vector2(3, 15));

    Matrix3 m4d = Transpose(m3b * m3c);

    return m4d == Matrix3(1, 0, 0, 0, 1, 0, 5, 18, 1);
}

int main()
{
    Matrix3Multiply();
	return 0;
}