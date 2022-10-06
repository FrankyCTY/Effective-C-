// comparing apples with apples
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// float occupies 4 bytes (depends on compiler)

// Vector2 occupies 8 bytes (even counted structure alignment and padding)
struct Vector2
{
    float x, y;
};

struct Vector4
{
    // Type under union share same memory (depends on the biggest data memory size)
    union
    {
        struct
        {
            float x, y, z, w;
        };

        struct
        {
            // Vector2 consists with 2 float = 8 bytes
            // 2 Vector2 = 16 bytes cover the float x, y and z, w correspondingly
            Vector2 v1, v2;
        };
    };
};


int main()
{
    Vector4 v4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    cout << v4.x << endl;
    cout << v4.y << endl;
    cout << v4.z << endl;
    cout << v4.w << endl;
    cout << v4.v1.x << " & " << v4.v1.y << endl;
    cout << v4.v2.x << " & " << v4.v2.y << endl;

    cout << "======================" << endl;

    // Changing the third float in union's struct 1
    v4.z = 8.123f;
    cout << v4.x << endl;
    cout << v4.y << endl;
    cout << v4.z << endl;
    cout << v4.w << endl;
    cout << v4.v1.x << " & " << v4.v1.y << endl;
    // The changes on third float can be accessed and seen in v4.v2.x
    cout << v4.v2.x << " & " << v4.v2.y << endl;

    return 0;
}