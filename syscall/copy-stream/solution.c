long syscall(long number, ...);

void _start() {
    char buff[1000];
    int size = 0;
    int size_w = 0;

    while ((size = syscall(0, 0, buff, 1000)) > 0) {
        while ((size_w = syscall(1, 1, buff, size)) > 0) {
            size -= size_w;
        }
    }
    syscall(60, 0);
}