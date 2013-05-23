#include "forcesensor.h"


int tty_fd;
void init_readforce() {
    struct termios tio;
    //  struct termios stdio;

    //  fd_set rdset;
    int x1;

    memset(&tio,0,sizeof(tio));
    tio.c_iflag=0;
    tio.c_oflag=0;
    tio.c_cflag=CS8|CREAD|CLOCAL;           // 8n1, see termios.h for more information
    tio.c_lflag=0;
    tio.c_cc[VMIN]=100;
    tio.c_cc[VTIME]=0;
    tio.c_ispeed = B19200;
    tio.c_ospeed = B19200;
    cfsetospeed(&tio,B19200);            // 115200 baud
    cfsetispeed(&tio,B19200);            // 115200 baud
    tty_fd=open("/dev/ttyUSB1", O_RDWR | O_NONBLOCK);
    cfsetospeed(&tio,B19200);            // 115200 baud
    cfsetispeed(&tio,B19200);            // 115200 baud
    x1 = tcsetattr(tty_fd,TCSANOW,&tio);
}


double readforce() {
    int x1,x2,x3,x4,x5,x6,x7,x8,x9;
    double output;
    unsigned char a1,a2,a3,a4,a5,a6,a7,a8,a9;
    char order[2], tmp_output[6];
    order[0]=68;
    order[1]=13;
    output = 0;
    tmp_output[6] = '\0';
    tcflush(tty_fd,TCIOFLUSH);
    write(tty_fd,&order,2);
    tcdrain(tty_fd);
    usleep(10000);
    x1 = read(tty_fd,&a1,1);
    x2 = read(tty_fd,&a2,1);
    x3 = read(tty_fd,&a3,1);
    x4 = read(tty_fd,&a4,1);
    x5 = read(tty_fd,&a5,1);
    x6 = read(tty_fd,&a6,1);
    x7 = read(tty_fd,&a7,1);
    x8 = read(tty_fd,&a8,1);
    x9 = read(tty_fd,&a9,1);
    tmp_output[0] = a1;
    tmp_output[1] = a2;
    tmp_output[2] = a3;
    tmp_output[3] = a4;
    tmp_output[4] = a5;
    tmp_output[5] = a6;
    output = atof(tmp_output);
    return output;
}


void uninit_readforce() {
    close(tty_fd);
}

