#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    int Array_Data[5][5], newArr[15] = {};
    int k = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> Array_Data[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            //如果元素不為零就存入陣列
            if(Array_Data[i][j] != 0) {
                newArr[k] = Array_Data[i][j];
                k++;
            }
    
    for (int i = 0; i < 15; i++)
        cout << newArr[i] << " ";

    system("pause");
    return 0;
}