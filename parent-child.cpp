#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    pid_t pid;
    int pipefd[2];  // Pipe untuk komunikasi antara induk dan anak
    char message[] = "Hello from child!";
    char buffer[BUFFER_SIZE];

    // Membuat pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Membuat proses anak
    pid = fork();

    if (pid < 0) {
        // Jika fork gagal
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Kode untuk proses anak
        close(pipefd[0]);  // Menutup sisi baca pipe pada anak

        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Mengirim pesan ke induk melalui pipe
        write(pipefd[1], message, strlen(message) + 1);  // Menulis ke pipe
        printf("Child: Sent message to parent: %s\n", message);

        close(pipefd[1]);  // Menutup sisi tulis pipe pada anak
    }
    else {
        // Kode untuk proses induk
        close(pipefd[1]);  // Menutup sisi tulis pipe pada induk

        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);

        // Membaca pesan dari anak melalui pipe
        read(pipefd[0], buffer, BUFFER_SIZE);  // Membaca dari pipe
        printf("Parent: Received message from child: %s\n", buffer);

        close(pipefd[0]);  // Menutup sisi baca pipe pada induk

        // Menunggu proses anak selesai
        wait(NULL);
        printf("Parent: Child process has finished.\n");
    }

    return 0;
}
