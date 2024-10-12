#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <lib-math.h>

namespace MATH {


///////////////////////////////////////////////////////////////////////////
//Vector Functions
///////////////////////////////////////////////////////////////////////////
Vec2 Vec2Add(Vec2 v, Vec2 w) {
    return {v.x + w.x, v.y + w.y};
}

Vec2 Vec2Subtract(Vec2 v, Vec2 w) {
    return {v.x - w.x, v.y - w.y};
}

Vec2 Vec2MultiplyScalar(Vec2 v, float scalar) {
    return {v.x * scalar, v.y * scalar};
}

Vec2 Vec2DivideScalar(Vec2 v, float scalar) {
    return {v.x / scalar, v.y / scalar};
}

float Vec2Magnitude(Vec2 v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

Vec2 Vec2Normalize(Vec2 v) {
    float magnitude = Vec2Magnitude(v);
    return {v.x / magnitude, v.y / magnitude};
}

bool Vec2IsNormalized(Vec2 v) {
     float magnitude_squared = v.x * v.x + v.y * v.y  ;
     if( magnitude_squared > 0.9999f && magnitude_squared < 1.0001f){
         return true;
    }else{
      return false;
    }
}

Vec2 Vec2PerpendicularMetodo1(Vec2 v) {
    return {-v.y, v.x};
}


Vec2 Vec2PerpendicularMetodo2(Vec2 v) {
    return {v.y, -v.x};
}


Vec3 Vec3Add(Vec3 v, Vec3 w) {
    return {v.x + w.x, v.y + w.y, v.z + w.z};
}

Vec3 Vec3Subtract(Vec3 v, Vec3 w) {
    return {v.x - w.x, v.y - w.y, v.z - w.z};
}

Vec3 Vec3MultiplyScalar(Vec3 v, float scalar) {
    return {v.x * scalar, v.y * scalar, v.z * scalar};
}

Vec3 Vec3DivideScalar(Vec3 v, float scalar) {
    return {v.x / scalar, v.y / scalar, v.z / scalar};
}

float Vec3Magnitude(Vec3 v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vec3 Vec3Normalize(Vec3 v) {
    float magnitude = Vec3Magnitude(v);
    return {v.x / magnitude, v.y / magnitude, v.z / magnitude};
}

bool Vec3IsNormalized(Vec3 v) {
      float magnitude_squared = v.x * v.x + v.y * v.y + v.z * v.z;
     if( magnitude_squared > 0.9999f && magnitude_squared < 1.0001f){
         return true;
    }else{
      return false;
    }
}

Vec4 Vec4Add(Vec4 v, Vec4 w) {
    return {v.x + w.x, v.y + w.y, v.z + w.z, v.w + w.w};
}

Vec4 Vec4Subtract(Vec4 v, Vec4 w) {
    return {v.x - w.x, v.y - w.y, v.z - w.z, v.w - w.w};
}

Vec4 Vec4MultiplyScalar(Vec4 v, float scalar) {
    return {v.x * scalar, v.y * scalar, v.z * scalar, v.w * scalar};
}

Vec4 Vec4DivideScalar(Vec4 v, float scalar) {
    return {v.x / scalar, v.y / scalar, v.z / scalar, v.w / scalar};
}

float Vec4Magnitude(Vec4 v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

Vec4 Vec4Normalize(Vec4 v) {
    float magnitude = Vec4Magnitude(v);
    return {v.x / magnitude, v.y / magnitude, v.z / magnitude, v.w / magnitude};
}

bool Vec4IsNormalized(Vec4 v) {
    float magnitude_squared = v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
     if( magnitude_squared > 0.9999f && magnitude_squared < 1.0001f){
         return true;
    }else{
      return false;
    }
}

float Vec2Dot(Vec2 v1, Vec2 v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

float Vec3Dot(Vec3 v1, Vec3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float Vec4Dot(Vec4 v1, Vec4 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

////////////////////////////////////////////////////////////////
//Arrays Functions
////////////////////////////////////////////////////////////////

Vec2 MultMat2Vec2(Mat2 mat, Vec2 vec) {
        Vec2 tmp = {
            mat.m[0] * vec.x + mat.m[2] * vec.y,
            mat.m[1] * vec.x + mat.m[3] * vec.y
        };
        return tmp;
    };

    Vec3 MultMat3Vec3(Mat3 mat, Vec3 vec) {
        Vec3 tmp = {
            mat.m[0] * vec.x + mat.m[1] * vec.y + mat.m[2] * vec.z,
            mat.m[3] * vec.x + mat.m[4] * vec.y + mat.m[5] * vec.z,
            mat.m[6] * vec.x + mat.m[7] * vec.y + mat.m[8] * vec.z,
        };
        return tmp;
    };

    Vec4 MultMat4Vec4(Mat4 mat, Vec4 vec) {
        Vec4 tmp = {
            mat.m[0] * vec.x + mat.m[1] * vec.y + mat.m[2] * vec.z + mat.m[3] * vec.w,
            mat.m[4] * vec.x + mat.m[5] * vec.y + mat.m[6] * vec.z + mat.m[7] * vec.w,
            mat.m[8] * vec.x + mat.m[9] * vec.y + mat.m[10] * vec.z + mat.m[11] * vec.w,
            mat.m[12] * vec.x + mat.m[13] * vec.y + mat.m[14] * vec.z + mat.m[15] * vec.w,
        };
        return tmp;
    };


  Mat2 Mat2Sum(Mat2 mat1, Mat2 mat2) {
    Mat2 tmp;
    tmp.m[0] = mat1.m[0] + mat2.m[0];
    tmp.m[1] = mat1.m[1] + mat2.m[1];
    tmp.m[2] = mat1.m[2] + mat2.m[2];
    tmp.m[3] = mat1.m[3] + mat2.m[3];
    return tmp;
}

Mat3 Mat3Sum(Mat3 mat1, Mat3 mat2) {
    Mat3 tmp;
    tmp.m[0] = mat1.m[0] + mat2.m[0];
    tmp.m[1] = mat1.m[1] + mat2.m[1];
    tmp.m[2] = mat1.m[2] + mat2.m[2];
    tmp.m[3] = mat1.m[3] + mat2.m[3];
    tmp.m[4] = mat1.m[4] + mat2.m[4];
    tmp.m[5] = mat1.m[5] + mat2.m[5];
    tmp.m[6] = mat1.m[6] + mat2.m[6];
    tmp.m[7] = mat1.m[7] + mat2.m[7];
    tmp.m[8] = mat1.m[8] + mat2.m[8];
    return tmp;
}

Mat4 Mat4Sum(Mat4 mat1, Mat4 mat2) {
    Mat4 tmp;
    tmp.m[0] = mat1.m[0] + mat2.m[0];
    tmp.m[1] = mat1.m[1] + mat2.m[1];
    tmp.m[2] = mat1.m[2] + mat2.m[2];
    tmp.m[3] = mat1.m[3] + mat2.m[3];
    tmp.m[4] = mat1.m[4] + mat2.m[4];
    tmp.m[5] = mat1.m[5] + mat2.m[5];
    tmp.m[6] = mat1.m[6] + mat2.m[6];
    tmp.m[7] = mat1.m[7] + mat2.m[7];
    tmp.m[8] = mat1.m[8] + mat2.m[8];
    tmp.m[9] = mat1.m[9] + mat2.m[9];
    tmp.m[10] = mat1.m[10] + mat2.m[10];
    tmp.m[11] = mat1.m[11] + mat2.m[11];
    tmp.m[12] = mat1.m[12] + mat2.m[12];
    tmp.m[13] = mat1.m[13] + mat2.m[13];
    tmp.m[14] = mat1.m[14] + mat2.m[14];
    tmp.m[15] = mat1.m[15] + mat2.m[15];
    return tmp;
}

Mat2 Mat2Subtract(Mat2 mat1, Mat2 mat2) {
    Mat2 tmp;
    tmp.m[0] = mat1.m[0] - mat2.m[0];
    tmp.m[1] = mat1.m[1] - mat2.m[1];
    tmp.m[2] = mat1.m[2] - mat2.m[2];
    tmp.m[3] = mat1.m[3] - mat2.m[3];
    return tmp;
}

Mat3 Mat3Subtract(Mat3 mat1, Mat3 mat2) {
    Mat3 tmp;
    tmp.m[0] = mat1.m[0] - mat2.m[0];
    tmp.m[1] = mat1.m[1] - mat2.m[1];
    tmp.m[2] = mat1.m[2] - mat2.m[2];
    tmp.m[3] = mat1.m[3] - mat2.m[3];
    tmp.m[4] = mat1.m[4] - mat2.m[4];
    tmp.m[5] = mat1.m[5] - mat2.m[5];
    tmp.m[6] = mat1.m[6] - mat2.m[6];
    tmp.m[7] = mat1.m[7] - mat2.m[7];
    tmp.m[8] = mat1.m[8] - mat2.m[8];
    return tmp;
}

Mat4 Mat4Subtract(Mat4 mat1, Mat4 mat2) {
    Mat4 tmp;
    tmp.m[0] = mat1.m[0] - mat2.m[0];
    tmp.m[1] = mat1.m[1] - mat2.m[1];
    tmp.m[2] = mat1.m[2] - mat2.m[2];
    tmp.m[3] = mat1.m[3] - mat2.m[3];
    tmp.m[4] = mat1.m[4] - mat2.m[4];
    tmp.m[5] = mat1.m[5] - mat2.m[5];
    tmp.m[6] = mat1.m[6] - mat2.m[6];
    tmp.m[7] = mat1.m[7] - mat2.m[7];
    tmp.m[8] = mat1.m[8] - mat2.m[8];
    tmp.m[9] = mat1.m[9] - mat2.m[9];
    tmp.m[10] = mat1.m[10] - mat2.m[10];
    tmp.m[11] = mat1.m[11] - mat2.m[11];
    tmp.m[12] = mat1.m[12] - mat2.m[12];
    tmp.m[13] = mat1.m[13] - mat2.m[13];
    tmp.m[14] = mat1.m[14] - mat2.m[14];
    tmp.m[15] = mat1.m[15] - mat2.m[15];
    return tmp;
}

Mat2 Mat2ScalarMultiplication(Mat2 mat, float scalar) {
    Mat2 tmp;
    tmp.m[0] = mat.m[0] * scalar;
    tmp.m[1] = mat.m[1] * scalar;
    tmp.m[2] = mat.m[2] * scalar;
    tmp.m[3] = mat.m[3] * scalar;
    return tmp;
}

Mat3 Mat3ScalarMultiplication(Mat3 mat, float scalar) {
    Mat3 tmp;
    tmp.m[0] = mat.m[0] * scalar;
    tmp.m[1] = mat.m[1] * scalar;
    tmp.m[2] = mat.m[2] * scalar;
    tmp.m[3] = mat.m[3] * scalar;
    tmp.m[4] = mat.m[4] * scalar;
    tmp.m[5] = mat.m[5] * scalar;
    tmp.m[6] = mat.m[6] * scalar;
    tmp.m[7] = mat.m[7] * scalar;
    tmp.m[8] = mat.m[8] * scalar;
    return tmp;
}

Mat4 Mat4ScalarMultiplication(Mat4 mat, float scalar) {
    Mat4 tmp;
    tmp.m[0] = mat.m[0] * scalar;
    tmp.m[1] = mat.m[1] * scalar;
    tmp.m[2] = mat.m[2] * scalar;
    tmp.m[3] = mat.m[3] * scalar;
    tmp.m[4] = mat.m[4] * scalar;
    tmp.m[5] = mat.m[5] * scalar;
    tmp.m[6] = mat.m[6] * scalar;
    tmp.m[7] = mat.m[7] * scalar;
    tmp.m[8] = mat.m[8] * scalar;
    tmp.m[9] = mat.m[9] * scalar;
    tmp.m[10] = mat.m[10] * scalar;
    tmp.m[11] = mat.m[11] * scalar;
    tmp.m[12] = mat.m[12] * scalar;
    tmp.m[13] = mat.m[13] * scalar;
    tmp.m[14] = mat.m[14] * scalar;
    tmp.m[15] = mat.m[15] * scalar;
    return tmp;
}


Mat2 Mat2ScalarDivision(Mat2 mat, float scalar) {
    Mat2 tmp;
    if (scalar == 0) {
        printf("Error: Division by zero\n");
    } else {
        tmp.m[0] = mat.m[0] / scalar;
        tmp.m[1] = mat.m[1] / scalar;
        tmp.m[2] = mat.m[2] / scalar;
        tmp.m[3] = mat.m[3] / scalar;
    }
    return tmp;
}


Mat3 Mat3ScalarDivision(Mat3 mat, float scalar) {
    Mat3 tmp;
    if (scalar == 0) {
        printf("Error: Division by zero\n");
    } else {
        tmp.m[0] = mat.m[0] / scalar;
        tmp.m[1] = mat.m[1] / scalar;
        tmp.m[2] = mat.m[2] / scalar;
        tmp.m[3] = mat.m[3] / scalar;
        tmp.m[4] = mat.m[4] / scalar;
        tmp.m[5] = mat.m[5] / scalar;
        tmp.m[6] = mat.m[6] / scalar;
        tmp.m[7] = mat.m[7] / scalar;
        tmp.m[8] = mat.m[8] / scalar;
    }
    return tmp;
}


Mat4 Mat4ScalarDivision(Mat4 mat, float scalar) {
    Mat4 tmp;
    if (scalar == 0) {
        printf("Error: Division by zero\n");
    } else {
        tmp.m[0] = mat.m[0] / scalar;
        tmp.m[1] = mat.m[1] / scalar;
        tmp.m[2] = mat.m[2] / scalar;
        tmp.m[3] = mat.m[3] / scalar;
        tmp.m[4] = mat.m[4] / scalar;
        tmp.m[5] = mat.m[5] / scalar;
        tmp.m[6] = mat.m[6] / scalar;
        tmp.m[7] = mat.m[7] / scalar;
        tmp.m[8] = mat.m[8] / scalar;
        tmp.m[9] = mat.m[9] / scalar;
        tmp.m[10] = mat.m[10] / scalar;
        tmp.m[11] = mat.m[11] / scalar;
        tmp.m[12] = mat.m[12] / scalar;
        tmp.m[13] = mat.m[13] / scalar;
        tmp.m[14] = mat.m[14] / scalar;
        tmp.m[15] = mat.m[15] / scalar;
    }
    return tmp;
}



    Mat2 Mat2Mult(Mat2 mat1, Mat2 mat2) {
    Mat2 tmp;
    tmp.m[0] = mat1.m[0] * mat2.m[0] + mat1.m[1] * mat2.m[2];
    tmp.m[1] = mat1.m[0] * mat2.m[1] + mat1.m[1] * mat2.m[3];
    tmp.m[2] = mat1.m[2] * mat2.m[0] + mat1.m[3] * mat2.m[2];
    tmp.m[3] = mat1.m[2] * mat2.m[1] + mat1.m[3] * mat2.m[3];
    return tmp;
}

Mat3 Mat3Mult(Mat3 mat1, Mat3 mat2) {
    Mat3 tmp;
    tmp.m[0] = mat1.m[0] * mat2.m[0] + mat1.m[1] * mat2.m[3] + mat1.m[2] * mat2.m[6];
    tmp.m[1] = mat1.m[0] * mat2.m[1] + mat1.m[1] * mat2.m[4] + mat1.m[2] * mat2.m[7];
    tmp.m[2] = mat1.m[0] * mat2.m[2] + mat1.m[1] * mat2.m[5] + mat1.m[2] * mat2.m[8];
    tmp.m[3] = mat1.m[3] * mat2.m[0] + mat1.m[4] * mat2.m[3] + mat1.m[5] * mat2.m[6];
    tmp.m[4] = mat1.m[3] * mat2.m[1] + mat1.m[4] * mat2.m[4] + mat1.m[5] * mat2.m[7];
    tmp.m[5] = mat1.m[3] * mat2.m[2] + mat1.m[4] * mat2.m[5] + mat1.m[5] * mat2.m[8];
    tmp.m[6] = mat1.m[6] * mat2.m[0] + mat1.m[7] * mat2.m[3] + mat1.m[8] * mat2.m[6];
    tmp.m[7] = mat1.m[6] * mat2.m[1] + mat1.m[7] * mat2.m[4] + mat1.m[8] * mat2.m[7];
    tmp.m[8] = mat1.m[6] * mat2.m[2] + mat1.m[7] * mat2.m[5] + mat1.m[8] * mat2.m[8];
    return tmp;
}

Mat4 Mat4Mult(Mat4 mat1, Mat4 mat2) {
    Mat4 tmp;
    tmp.m[0]  = mat1.m[0]  * mat2.m[0]  + mat1.m[1]  * mat2.m[4]  + mat1.m[2]  * mat2.m[8]  + mat1.m[3]  * mat2.m[12];
    tmp.m[1]  = mat1.m[0]  * mat2.m[1]  + mat1.m[1]  * mat2.m[5]  + mat1.m[2]  * mat2.m[9]  + mat1.m[3]  * mat2.m[13];
    tmp.m[2]  = mat1.m[0]  * mat2.m[2]  + mat1.m[1]  * mat2.m[6]  + mat1.m[2]  * mat2.m[10] + mat1.m[3]  * mat2.m[14];
    tmp.m[3]  = mat1.m[0]  * mat2.m[3]  + mat1.m[1]  * mat2.m[7]  + mat1.m[2]  * mat2.m[11] + mat1.m[3]  * mat2.m[15];
    tmp.m[4]  = mat1.m[4]  * mat2.m[0]  + mat1.m[5]  * mat2.m[4]  + mat1.m[6]  * mat2.m[8]  + mat1.m[7]  * mat2.m[12];
    tmp.m[5]  = mat1.m[4]  * mat2.m[1]  + mat1.m[5]  * mat2.m[5]  + mat1.m[6]  * mat2.m[9]  + mat1.m[7]  * mat2.m[13];
    tmp.m[6]  = mat1.m[4]  * mat2.m[2]  + mat1.m[5]  * mat2.m[6]  + mat1.m[6]  * mat2.m[10] + mat1.m[7]  * mat2.m[14];
    tmp.m[7]  = mat1.m[4]  * mat2.m[3]  + mat1.m[5]  * mat2.m[7]  + mat1.m[6]  * mat2.m[11] + mat1.m[7]  * mat2.m[15];
    tmp.m[8]  = mat1.m[8]  * mat2.m[0]  + mat1.m[9]  * mat2.m[4]  + mat1.m[10] * mat2.m[8]  + mat1.m[11] * mat2.m[12];
    tmp.m[9]  = mat1.m[8]  * mat2.m[1]  + mat1.m[9]  * mat2.m[5]  + mat1.m[10] * mat2.m[9]  + mat1.m[11] * mat2.m[13];
    tmp.m[10] = mat1.m[8]  * mat2.m[2]  + mat1.m[9]  * mat2.m[6]  + mat1.m[10] * mat2.m[10] + mat1.m[11] * mat2.m[14];
    tmp.m[11] = mat1.m[8]  * mat2.m[3]  + mat1.m[9]  * mat2.m[7]  + mat1.m[10] * mat2.m[11] + mat1.m[11] * mat2.m[15];
    tmp.m[12] = mat1.m[12] * mat2.m[0]  + mat1.m[13] * mat2.m[4]  + mat1.m[14] * mat2.m[8]  + mat1.m[15] * mat2.m[12];
    tmp.m[13] = mat1.m[12] * mat2.m[1]  + mat1.m[13] * mat2.m[5]  + mat1.m[14] * mat2.m[9]  + mat1.m[15] * mat2.m[13];
    tmp.m[14] = mat1.m[12] * mat2.m[2]  + mat1.m[13] * mat2.m[6]  + mat1.m[14] * mat2.m[10] + mat1.m[15] * mat2.m[14];
    tmp.m[15] = mat1.m[12] * mat2.m[3]  + mat1.m[13] * mat2.m[7]  + mat1.m[14] * mat2.m[11] + mat1.m[15] * mat2.m[15];
    return tmp;
}

    Mat2 Mat2Identity() {
        Mat2 tmp = {1.0f, 0.0f, 0.0f, 1.0f};
        return tmp;
    }

    Mat3 Mat3Identity() {
        Mat3 tmp = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
        return tmp;
    }

    Mat4 Mat4Identity() {
        Mat4 tmp = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
        return tmp;
    }



Mat3 Mat3Translate(float tx, float ty) {
    Mat3 tmp;
    tmp.m[2] = tx;
    tmp.m[5] = ty;
    return tmp;
}

Mat3 InitAsRotate2D(float angleInRadians) {
     Mat3 tmp;
     float cosTheta = cos(angleInRadians);
     float sinTheta = sin(angleInRadians);
     tmp.m[0] = cosTheta;
     tmp.m[1] = sinTheta;
     tmp.m[3] = -sinTheta;
     tmp.m[4] = cosTheta;
     return tmp;
}

Mat3 InitAsScale2D(float sx, float sy) {
    Mat3 tmp;
    tmp.m[0] = sx;
    tmp.m[4] = sy;
    return tmp;
}

Vec3 Mat3TransformVec3(Mat3 mat, Vec3 vec) {
    Vec3 tmp;
    tmp.x = mat.m[0] * vec.x + mat.m[1] * vec.y + mat.m[2] * vec.z;
    tmp.y = mat.m[3] * vec.x + mat.m[4] * vec.y + mat.m[5] * vec.z;
    tmp.z = mat.m[6] * vec.x + mat.m[7] * vec.y + mat.m[8] * vec.z;
    return tmp;
}



/////////////////////////////////////////////
//Colision detection
/////////////////////////////////////////////

bool IsCirclesColiding(Circle *circle1,Circle *circle2){
    Vec2 distance = Vec2Subtract(circle1->pos,circle2->pos);
    float length = Vec2Magnitude(distance);
    if(length < circle1->radius+circle2->radius){
        return true;
    }

    return false;
}





}

