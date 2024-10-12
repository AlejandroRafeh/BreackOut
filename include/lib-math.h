


namespace MATH{
    const float kPi = 3.14;
    const float kTau = 6.28;

//////////////////////////////////////////////
// Structs
//////////////////////////////////////////////


////////
//Vectors struct
////////

    typedef struct Vec2 {
        float x, y;
    }Vec2;

    typedef struct Vec3 {
        float x, y, z;
    }Vec3;

    typedef struct Vec4 {
        float x, y, z, w;
    }Vec4;


/////////////
//Arrays
////////////

    typedef struct Mat2 {
        float m[4];
    }Mat2;

    typedef struct Mat3 {
        float m[9];
    }Mat3;

    typedef struct Mat4 {
        float m[16];
    }Mat4;

/////////////////
//Figures
/////////////////

    typedef struct Colour{
        unsigned char r,g,b,a;
    }Colour;

    typedef struct Circle{
        Vec2 pos;
        Colour colour;
        int radius;
    }Circle;

    typedef struct Rectangle{
        Vec2 pos;
        Colour colour;
        int height,width;
    }Rectangle;

////////////////////////////
//////Ray
///////////////////////////

typedef struct Ray {
    Vec2 position;       // Ray position (origin)
    Vec2 direction;      // Ray direction
} Ray;


///////////////////////////////////////////////////////////////////////////
//Vector Functions
///////////////////////////////////////////////////////////////////////////

Vec2 Vec2Add(Vec2 v, Vec2 w);

Vec2 Vec2Subtract(Vec2 v, Vec2 w);

Vec2 Vec2MultiplyScalar(Vec2 v, float scalar);

Vec2 Vec2DivideScalar(Vec2 v, float scalar);

float Vec2Magnitude(Vec2 v);

Vec2 Vec2Normalize(Vec2 v);

bool Vec2IsNormalized(Vec2 v);

Vec2 Vec2PerpendicularMetodo1(Vec2 v);

Vec2 Vec2PerpendicularMetodo2(Vec2 v);

Vec3 Vec3Add(Vec3 v, Vec3 w);

Vec3 Vec3Subtract(Vec3 v, Vec3 w);

Vec3 Vec3MultiplyScalar(Vec3 v, float scalar);

Vec3 Vec3DivideScalar(Vec3 v, float scalar);

float Vec3Magnitude(Vec3 v);

Vec3 Vec3Normalize(Vec3 v);

bool Vec3IsNormalized(Vec3 v);

Vec4 Vec4Add(Vec4 v, Vec4 w);

Vec4 Vec4Subtract(Vec4 v, Vec4 w);

Vec4 Vec4MultiplyScalar(Vec4 v, float scalar);

Vec4 Vec4DivideScalar(Vec4 v, float scalar);

float Vec4Magnitude(Vec4 v);

Vec4 Vec4Normalize(Vec4 v);

bool Vec4IsNormalized(Vec4 v);

float Vec2Dot(Vec2 v1, Vec2 v2);

float Vec3Dot(Vec3 v1, Vec3 v2);

float Vec4Dot(Vec4 v1, Vec4 v2);


////////////////////////////////////////////////////////////////
//Arrays Functions
////////////////////////////////////////////////////////////////


Vec2 MultMat2Vec2(Mat2 mat, Vec2 vec);

Vec3 MultMat3Vec3(Mat3 mat, Vec3 vec);

Vec4 MultMat4Vec4(Mat4 mat, Vec4 vec);

Mat2 Mat2Sum(Mat2 mat1, Mat2 mat2);

Mat3 Mat3Sum(Mat3 mat1, Mat3 mat2);

Mat4 Mat4Sum(Mat4 mat1, Mat4 mat2);

Mat2 Mat2Subtract(Mat2 mat1, Mat2 mat2);

Mat3 Mat3Subtract(Mat3 mat1, Mat3 mat2);

Mat4 Mat4Subtract(Mat4 mat1, Mat4 mat2);

Mat2 Mat2ScalarMultiplication(Mat2 mat, float scalar);

Mat3 Mat3ScalarMultiplication(Mat3 mat, float scalar);

Mat4 Mat4ScalarMultiplication(Mat4 mat, float scalar);

Mat2 Mat2ScalarDivision(Mat2 mat, float scalar);

Mat3 Mat3ScalarDivision(Mat3 mat, float scalar);

Mat4 Mat4ScalarDivision(Mat4 mat, float scalar);

Mat2 Mat2Mult(Mat2 mat1, Mat2 mat2);

Mat3 Mat3Mult(Mat3 mat1, Mat3 mat2);

Mat4 Mat4Mult(Mat4 mat1, Mat4 mat2);

Mat2 Mat2Identity();

Mat3 Mat3Identity();

Mat4 Mat4Identity();

Mat3 Mat3Translate(float tx, float ty);

Mat3 InitAsRotate2D(float angleInRadians);

Mat3 InitAsScale2D(float sx, float sy);

Vec3 Mat3TransformVec3(Mat3 mat, Vec3 vec);

/////////////////////////////////////////////
//Colision detection
/////////////////////////////////////////////

bool IsCirclesColiding(Circle *circle1,Circle *circle2);

}