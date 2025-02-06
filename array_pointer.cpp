// Array와 Pointer를 동일하게 사용할 수 있는 경우 정리

#include <iostream>
using namespace std;

int main()
{
   int arr[] = {1, 2, 3};
   
   cout << arr << endl;     // arr[0]의 주소값 출력
   cout << *arr << endl;    // arr[0]의 주소값 데이터 출력 = arr[0] 요소
   cout << arr[0] << endl;  // arr[0] 요소 출력
   cout << sizeof(arr) << endl; // arr의 크기 3x4B 출력


   int* arr_num = arr;      // arr[0]의 주소값 저장됨

   cout << arr_num << endl; // 동일하게 arr[0]의 주소값 출력
   cout << arr_num[0] << endl;  // 동일하게 arr[0] 요소 출력 
   cout << sizeof(arr_num) << endl; // '주소' 크기 4B or 8B 출력

   // 64bit로 컴파일 하면 포인터의 크기는 8B, 32bit로 컴파일 시 4B가 나온다.


   cout << (arr + 1) << endl;       // arr[1] 주소값 출력
   cout << (arr + 2) << endl;       // arr[2] 주소값 출력
   
   cout << (arr_num + 1) << endl;   // 동일하게 arr[1] 주소값 출력
   cout << (arr_num + 2) << endl;   // 동일하게 arr[2] 주소값 출력


   // 이하는 모두 arr[1] 요소가 출력된다. (=2)
   cout << *arr_num + 1 << endl;    
   cout << arr_num[1] << endl;      
   cout << arr[1] << endl;
   cout << *(arr + 1) << endl;
   
   return 0;
 
}
