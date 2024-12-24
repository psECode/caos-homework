long syscall(long number, ...);

void _start() {
    char buff[] = "Hello, World!\n";
    int size_w = 0;
    int message_size = sizeof(buff) / sizeof(buff[0]);
    while ((size_w = syscall(1, 1, buff, message_size - 1)) > 0) {
            message_size -= size_w;
    }
    syscall(60, 0);
}