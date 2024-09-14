#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void copy_file(const char *source_path, const char *destination_path) {
    FILE *source_file = fopen(source_path, "rb");
    if (source_file == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE *destination_file = fopen(destination_path, "wb");
    if (destination_file == NULL) {
        perror("Error opening destination file");
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, destination_file);
    }

    if (ferror(source_file)) {
        perror("Error reading from source file");
    }

    if (ferror(destination_file)) {
        perror("Error writing to destination file");
    }

    fclose(source_file);
    fclose(destination_file);
}

int main() {
   // const char *source_path = "/ntsrv1/hello.jar";
   // const char *destination_path = "/gnavigator/c$/hello.jar";

    const char *source_path = "/home/yaron/git/git-koskasmail/test/c/a.md";
    const char *destination_path = "/home/yaron/git/git-koskasmail/test/c/c.md";

    copy_file(source_path, destination_path);

    printf("File copied successfully from %s to %s\n", source_path, destination_path);
    return 0;
}
