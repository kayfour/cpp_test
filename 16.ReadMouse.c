#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd, bytes;
    unsigned char data[3];

    //open mouse, 이거는 표준으로 파일경로가 지정되어 있으므로 /dev/input 에 입력 장치들에 해당하는 경로를 의미한다.mice는 마우스 인듯
    fd = open("/dev/input/mice",O_RDWR); 

    if(fd == -1){
        printf("Can't found any mouse devices!");
        return -1; //프로그램의 에러는 대부분 이렇게 음수로 나온다. 여기서는 읽을 수 없으니까 그냥 종료한것
    }

    signed char x,y;
    int left,right,middle;
    while(1){
        bytes = read(fd,data,sizeof(data));
        left = data[0] & 0x1;
        right = data[0] & 0x2;
        middle = data[0] & 0x4;
        if(bytes>0){
            x = data[0];y = data[1]; printf("x : %d , y : %d, left : %d, Right : %d, middle : %d \n",x,y,left,right,middle);
        }
    }

    return 0;
    
}