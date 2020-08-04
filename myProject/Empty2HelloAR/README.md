# Empty2HelloAR

## native 디버깅 방법

1. run -> edit configurations

2. 탭에서 debugger 클릭

3. Symbol Directories 항목에 + 를 눌름.

4. so 가 있는 디렉토리 선택 (so는 app/build/intermediates/cmake/debug/obj/ 에서 테스트 기기에 맞는 so 선택 x86, arm64 디렉토리 선택)

> 이 과정을 하지 않으면 c++ 디버깅이 안됨. (코틀린 코드만 됨)
