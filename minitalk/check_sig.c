#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// void check_sig(sigset_t *set)
// {
// 	if (sigismember(set, SIGINT))
// 	{
// 		printf("\nBIT representation for checking SIGINT(signal 2):\n");
// 		printf("1 << 2 = %d (shifting 1 two positions left)\n", (1 << 2));
// 		printf("curr sig mask & (1 << 2) = non-zero means SIGINT is present\n");
// 		printf("this is equivalent to: 0000000000000100 & signal_mask\n");
// 	}
// }

// int main(void)
// {
// 	sigset_t set;

// 	sigemptyset(&set);
// 	sigaddset(&set, SIGBUS);
// 	check_sig(&set);
// 	if (sigismember(&set, SIGINT))
// 		printf("\nresult: SIGINT is");
// 	else
// 		printf("\nresult: SIGINT is not");
// 	return (0);
// }
// #include <stdio.h>

// void print_binary(int num)
// {
//     // We use int i as a counter to move through each bit position
//     // Starting from position 7 (for 8 bits) down to 0
//     printf("%3d in binary: ", num);
    
//     for (int i = 7; i >= 0; i--)
//     {
//         // Break down what happens in each iteration:
//         int shifted = num >> i;     // Shift number right by i positions
//         int bit = shifted & 1;      // Get the last bit using AND with 1
        
//         printf("%d", bit);          // Print the extracted bit
        
//         // Add space every 4 bits for readability
//         if (i % 4 == 0) 
//             printf(" ");
//     }
//     printf("\n");
// }

// void explain_bit_positions(void)
// {
//     printf("\nBit position values:\n");
//     printf("Position:  7  6  5  4  3  2  1  0\n");
//     printf("Value:    128 64 32 16 8  4  2  1\n");
    
//     // Demonstrate how i is used to calculate position values
//     printf("\nCalculating position values using i:\n");
//     for (int i = 7; i >= 0; i--)
//     {
//         int value = 1 << i;  // Shift 1 left by i positions
//         printf("When i = %d: 1 << %d = %3d\n", i, i, value);
//     }
// }

// int main(void)
// {
//     // Example numbers to display in binary
//     int numbers[] = {1, 2, 4, 8, 16};
    
//     printf("Displaying different numbers in binary:\n\n");
//     for (int i = 0; i < 5; i++)
//     {
//         print_binary(numbers[i]);
//     }
    
//     explain_bit_positions();
    
//     return 0;
// }
void handler(int signal)
{
    printf("Stop not allowed\n");
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    sa.sa_handler = &handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa, NULL);

    int x;
    printf("input\n");
    scanf("%d", &x);
    printf("result %d * 5 = %d\n", x, x * 5);
    return (0);
}
