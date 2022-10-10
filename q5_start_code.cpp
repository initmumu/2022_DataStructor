#include <iostream>

using namespace std;

int main()
{
    int i,j, **M;
    M = create_integer_matrix(3);
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    destroy_integer_matrix(M, 3);
    return 0;
}
