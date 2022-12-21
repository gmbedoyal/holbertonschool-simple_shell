#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        int child = fork();
        if (child == 0)
        {
            execl("/bin/ls", "/bin/ls", "-l", "/tmp", (char *)NULL);
        }
        else
        {
            waitpid(child, NULL, 0);        }
    }

    return 0;
}