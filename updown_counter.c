#include <stdio.h>
#include <stdbool.h> // For boolean type
#include <time.h>    // For clock function

// Function to create a delay
void delay(unsigned int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000);
}

int main() {
    int counter = 0;    // Initialize counter
    int direction = 1;  // 1 for up, -1 for down
    char command;       // Command input
    bool running = false; // Flag to check if counting is active

    while (1) {
        // Check for user input
        if (scanf(" %c", &command) == 1) {
            // Process the command
            if (command == 's') {
                // Start the counter
                if (!running) {
                    printf("Counter started.\n");
                    running = true;
                }
            } else if (command == 'x') {
                // Stop the counter
                if (running) {
                    printf("Counter stopped.\n");
                    running = false;
                }
            } else if (command == 'e') {
                // End the task
                printf("Ending task.\n");
                return 0; // Exit the program
            }
        }
        
        if (running) {
            // Print current value of the counter
            printf("Counter: %d\n", counter);
            
            // Update the counter based on the direction
            counter += direction;
            
            // Check bounds for counting up/down
            if (counter > 15) {
                counter = 15; // Ensure the counter doesn't exceed 15
                direction = -1; // Change direction to down
                printf("Reached maximum value. Changing direction to down.\n");
            } else if (counter < 0) {
                counter = 0; // Ensure the counter doesn't go below 0
                direction = 1; // Change direction to up
                printf("Reached minimum value. Changing direction to up.\n");
            }
            
            // Wait for 1 second using delay function
            delay(1000); // Delay in milliseconds
        }
    }
    
    return 0;
}