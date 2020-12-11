#pragma once
#include <Matrix3.h>
#include <Matrix4.h>
#include <Vector4.h>
#include <Vector3.h>
#include <Vector2.h>
#include <cmath>



class UnitTest
{
public:

    static float DEFAULT_TOLERANCE;
    
    UnitTest()
    {
        DEFAULT_TOLERANCE = 0.0001f;
    }

    bool runTests()
    {

    }

    Matrix3 Transpose(Matrix3 mat)
    {
        return Matrix3
        (
            mat.m11, mat.m21, mat.m31,
            mat.m12, mat.m22, mat.m32,
            mat.m13, mat.m23, mat.m33
        );
    }

    Matrix4 Transpose(Matrix4 mat)
    {
        return Matrix4
        (
            mat.m11, mat.m21, mat.m31, mat.m41,
            mat.m12, mat.m22, mat.m32, mat.m42,
            mat.m13, mat.m23, mat.m33, mat.m43,
            mat.m14, mat.m24, mat.m34, mat.m44
        );
    }

    bool compare(float a, float b, float tolerance = DEFAULT_TOLERANCE)
    {
        if (abs(a - b) > tolerance)
            return false;
        return true;
    }

    bool compare(Vector3 a, Vector3 b, float tolerance = DEFAULT_TOLERANCE)
    {
        if (abs(a.x - b.x) > tolerance ||
            abs(a.y - b.y) > tolerance ||
            abs(a.z - b.z) > tolerance)
            return false;
        return true;
    }

    bool compare(Vector4 a, Vector4 b, float tolerance = DEFAULT_TOLERANCE)
    {
        if (abs(a.x - b.x) > tolerance ||
            abs(a.y - b.y) > tolerance ||
            abs(a.z - b.z) > tolerance ||
            abs(a.w - b.w) > tolerance)
            return false;
        return true;
    }

    bool compare(Matrix3 a, Matrix3 b, float tolerance = DEFAULT_TOLERANCE)
    {
        if (abs(a.m11 - b.m11) > tolerance || abs(a.m12 - b.m12) > tolerance || abs(a.m13 - b.m13) > tolerance ||
            abs(a.m21 - b.m21) > tolerance || abs(a.m22 - b.m22) > tolerance || abs(a.m23 - b.m23) > tolerance ||
            abs(a.m31 - b.m31) > tolerance || abs(a.m32 - b.m32) > tolerance || abs(a.m33 - b.m33) > tolerance)
            return false;
        return true;
    }

    bool compare(Matrix4 a, Matrix4 b, float tolerance = DEFAULT_TOLERANCE)
    {
        if (abs(a.m11 - b.m11) > tolerance || abs(a.m12 - b.m12) > tolerance || abs(a.m13 - b.m13) > tolerance || abs(a.m14 - b.m14) > tolerance ||
            abs(a.m21 - b.m21) > tolerance || abs(a.m22 - b.m22) > tolerance || abs(a.m23 - b.m23) > tolerance || abs(a.m24 - b.m24) > tolerance ||
            abs(a.m31 - b.m31) > tolerance || abs(a.m32 - b.m32) > tolerance || abs(a.m33 - b.m33) > tolerance || abs(a.m34 - b.m34) > tolerance ||
            abs(a.m41 - b.m41) > tolerance || abs(a.m42 - b.m42) > tolerance || abs(a.m43 - b.m43) > tolerance || abs(a.m44 - b.m44) > tolerance)
            return false;
        return true;
    }

    bool Vector3Addition()
    {
        Vector3 v3a = Vector3(13.5f, -48.23f, 862);
        Vector3 v3b = Vector3(5, 3.99f, -12);
        Vector3 v3c = v3a + v3b;

        return compare(Vector3(18.5f, -44.24f, 850), v3c);
    }

    bool Vector4Addition()
    {
        Vector4 v4a = Vector4(13.5f, -48.23f, 862, 0);
        Vector4 v4b = Vector4(5, 3.99f, -12, 1);
        Vector4 v4c = v4a + v4b;

        return compare(Vector4(18.5f, -44.24f, 850, 1), v4c);
    }

    bool Vector3Subtraction()
    {
        Vector3 v3a = Vector3(13.5f, -48.23f, 862);
        Vector3 v3b = Vector3(5, 3.99f, -12);
        Vector3 v3c = v3a - v3b;

        return compare(Vector3(8.5f, -52.22f, 874), v3c);
    }

    bool Vector4Subtraction()
    {
        Vector4 v4a = Vector4(13.5f, -48.23f, 862, 0);
        Vector4 v4b = Vector4(5, 3.99f, -12, 1);
        Vector4 v4c = v4a - v4b;

        return compare(Vector4(8.5f, -52.22f, 874, -1), v4c);
    }

    bool Vector3PostScale()
    {
        Vector3 v3a = Vector3(13.5f, -48.23f, 862);
        Vector3 v3c = v3a * 0.256f;

        return compare(Vector3(3.45600008965f, -12.3468809128f, 220.672012329f), v3c);
    }

    bool Vector4PostScale()
    {
        Vector4 v4a = Vector4(13.5f, -48.23f, 862, 0);
        Vector4 v4c = v4a * 4.89f;

        return compare(Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0), v4c);
    }

    bool Vector3PreScale()
    {
        Vector3 v3a = Vector3(13.5f, -48.23f, 862);
        Vector3 v3c = 0.256f * v3a;

        return compare(Vector3(3.45600008965f, -12.3468809128f, 220.672012329f), v3c);
    }

    bool Vector4PreScale()
    {
        Vector4 v4a = Vector4(13.5f, -48.23f, 862, 0);
        Vector4 v4c = 4.89f * v4a;

        return compare(Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0), v4c);
    }

    bool Vector3Dot()
    {
        Vector3 v3a = Vector3(13.5f, -48.23f, 862);
        Vector3 v3b = Vector3(5, 3.99f, -12);
        float dot3 = Vector3::dotProduct(v3a, v3b);

        return compare(dot3, -10468.9375f, DEFAULT_TOLERANCE);
    }

    bool Vector4Dot()
    {
        Vector4 v4a = Vector4(13.5f, -48.23f, 862, 0);
        Vector4 v4b = Vector4(5, 3.99f, -12, 1);
        float dot4 = Vector4::dotProduct(v4a, v4b);

        return compare(dot4, -10468.9375f, DEFAULT_TOLERANCE);
    }

    bool Vector3Cross()
    {
        Vector3 v3a = Vector3(13.5f, -48.23f, 862);
        Vector3 v3b = Vector3(5, 3.99f, -12);
        Vector3 v3c = Vector3::crossProduct(v3a, v3b);

        return compare(v3c, Vector3(-2860.62011719f, 4472.00000000f, 295.01498413f));
    }

    bool Vector4Cross()
    {
        Vector4 v4a = Vector4(13.5f, -48.23f, 862, 0);
        Vector4 v4b = Vector4(5, 3.99f, -12, 1);
        Vector4 v4c = Vector4::crossProduct(v4a, v4b);

        return compare(v4c, Vector4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));
    }

    bool Vector3Magnitude()
    {
        Vector3 v3a = Vector3(13.5f, -48.23f, 862);
        float mag3 = v3a.getMagnitude();

        return compare(mag3, 863.453735352f, DEFAULT_TOLERANCE);
    }

    bool Vector4Magnitude()
    {
        Vector4 v4a = Vector4(13.5f, -48.23f, 862, 0);
        float mag4 = v4a.getMagnitude();

        return compare(mag4, 863.453735352f, DEFAULT_TOLERANCE);
    }

    bool Vector3Normalise()
    {
        Vector3 v3a = Vector3(13.5f, -48.23f, 862);
        v3a = Vector3::normalize(v3a);

        return compare(v3a, Vector3(0.0156349f, -0.0558571f, 0.998316f));
    }

    bool Vector4Normalise()
    {
        Vector4 v4a = Vector4(243, -48.23f, 862, 0);
        v4a = Vector4::normalize(v4a);

        return compare(v4a, Vector4(0.270935f, -0.0537745f, 0.961094f, 0));
    }

    bool Matrix4SetRotateX()
    {
        Matrix4 m4a = Matrix4();
        m4a = Transpose(Matrix4::createRotationX(4.5f));

        return compare(m4a,
            Matrix4(1, 0, 0, 0, 0, -0.210796f, -0.97753f, 0, 0, 0.97753f, -0.210796f, 0, 0, 0, 0, 1));
    }

    bool Matrix4SetRotateY()
    {
        Matrix4 m4b = Matrix4();
        m4b = Transpose(Matrix4::createRotationY(-2.6f));

        return compare(m4b,
            Matrix4(-0.856889f, 0, 0.515501f, 0, 0, 1, 0, 0, -0.515501f, 0, -0.856889f, 0, 0, 0, 0, 1));
    }

    bool Matrix3SetRotate()
    {
        Matrix3 m3c = Matrix3();
        m3c = Matrix3::createRotation(9.62f);

        return compare(m3c,
            Matrix3(-0.981005f, -0.193984f, 0, 0.193984f, -0.981005f, 0, 0, 0, 1));
    }

    bool Matrix4SetRotateZ()
    {
        Matrix4 m4c = Matrix4();
        m4c = Transpose(Matrix4::createRotationZ(0.72f));

        return compare(m4c,
            Matrix4(0.751806f, 0.659385f, 0, 0, -0.659385f, 0.751806f, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));
    }

    bool Vector3MatrixTransform2()
    {
        Matrix3 m3c = Matrix3();
        m3c = Transpose(Matrix3::createRotation(9.62f));

        Vector3 v3a = Vector3(13.5f, -48.23f, 862);
        Vector3 v3c = m3c * v3a;

        return compare(v3c,
            Vector3(-22.5994224548f, 44.6950683594f, 862));
    }

    bool Vector4MatrixTransform()
    {
        Matrix4 m4b = Matrix4();
        m4b = Matrix4::createRotationY(-2.6f);

        Vector4 v4a = Vector4(13.5f, -48.23f, 862, 0);
        Vector4 v4b = m4b * v4a;

        return compare(v4b,
            Vector4(-455.930236816f, -48.2299995422f, -731.678771973f, 0));
    }

    bool Vector4MatrixTransform2()
    {
        Matrix4 m4c = Matrix4();
        m4c = Matrix4::createRotationZ(0.72f);

        Vector4 v4a = Vector4(13.5f, -48.23f, 862, 0);
        Vector4 v4b = m4c * v4a;

        return compare(v4b,
            Vector4(41.951499939f, -27.3578968048f, 862, 0));
    }

    bool Matrix3Multiply()
    {
        Matrix3 m3b = Matrix3();
        m3b = Matrix3::createTranslation(Vector2(2, 3));

        Matrix3 m3c = Matrix3();
        m3c = Matrix3::createTranslation(Vector2(3, 15));

        Matrix3 m4d = Transpose(m3b * m3c);

        return compare(m4d,
            Matrix3(1, 0, 0, 0, 1, 0, 5, 18, 1));
    }

    bool Matrix4Multiply()
    {
        Matrix4 m4b = Matrix4();
        m4b = Matrix4::createRotationY(-2.6f);

        Matrix4 m4c = Matrix4();
        m4c = Matrix4::createRotationZ(0.72f);

        Matrix4 m4d = Transpose(m4c * m4b);

        return compare(m4d,
            Matrix4(-0.644213855267f, -0.565019249916f, 0.515501439571f, 0, -0.659384667873f, 0.751805722713f, 0, 0, -0.387556940317f, -0.339913755655f, -0.856888711452f, 0, 0, 0, 0, 1));
    }                   //m11              m21                m31           m41    m12             m22             m32 m42 m13               m23                 m33          m34 m14 m24 m34 m44                 

    bool Vector3MatrixTranslation()
    {
        // homogeneous point translation
        Matrix3 m3b = Transpose(Matrix3(1, 0, 0,
            0, 1, 0,
            55, 44, 1));

        Vector3 v3a = Vector3(13.5f, -48.23f, 1);

        Vector3 v3b = m3b * v3a;

        return compare(v3b, Vector3(68.5f, -4.23f, 1));
    }

    bool Vector4MatrixTranslation()
    {
        // homogeneous point translation
        Matrix4 m4b = Transpose(Matrix4(1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            55, 44, 99, 1));

        Vector4 v4a = Vector4(13.5f, -48.23f, -54, 1);

        Vector4 v4c = m4b * v4a;
        return compare(v4c, Vector4(68.5f, -4.23f, 45, 1));
    }

    bool Vector4MatrixTranslation2()
    {
        // homogeneous point translation
        Matrix4 m4c = Matrix4();
        m4c = Matrix4::createRotationZ(2.2f);
        m4c.m14 = 55; m4c.m24 = 44; m4c.m34 = 99; m4c.m44 = 1;

        Vector4 v4a = Vector4(13.5f, -48.23f, -54, 1);

        Vector4 v4c = m4c * v4a;
        return compare(v4c, Vector4(86.0490112305f, 83.2981109619f, 45, 1));
    }

    bool Vector3MatrixTranslation3()
    {
        // homogeneous point translation
        Matrix3 m3b = Transpose(Matrix3(1, 0, 0,
            0, 1, 0,
            55, 44, 1));

        Vector3 v3a = Vector3(13.5f, -48.23f, 0);

        Vector3 v3b = m3b * v3a;

        return compare(v3b, Vector3(13.5f, -48.23f, 0));
    }

    bool Vector4MatrixTranslation3()
    {
        // homogeneous point translation
        Matrix4 m4b = Transpose(Matrix4(1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            55, 44, 99, 1));

        Vector4 v4a = Vector4(13.5f, -48.23f, -54, 0);

        Vector4 v4c = m4b * v4a;
        return compare(v4c, Vector4(13.5f, -48.23f, -54, 0));
    }

    bool Vector4MatrixTranslation4()
    {
        // homogeneous point translation
        Matrix4 m4c = Matrix4();
        m4c = Matrix4::createRotationZ(2.2f);
        m4c.m14 = 55; m4c.m24 = 44; m4c.m34 = 99; m4c.m44 = 1;

        Vector4 v4a = Vector4(13.5f, -48.23f, -54, 0);

        Vector4 v4c = m4c * v4a;
        return compare(v4c, Vector4(31.0490131378f, 39.2981109619f, -54, 0));
    }
};

